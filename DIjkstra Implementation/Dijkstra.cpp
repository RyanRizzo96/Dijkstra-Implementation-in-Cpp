//Dijkstra Implementation
//File Sample Input: 
//6		--> number of nodes
//1 3 3		--> Node 1 to 3 with weight 3
//2 4 1		--> Node 2 to 4 with weight 1
//2 5 3		--> Node 2 to 5 with weight 3
//3 2 2		--> Node 3 to 2 with weight 2
//3 5 1		--> Node 3 to 5 with weight 1
//5 6 6		--> Node 5 to 6 with weight 6
//File Sample Output: (distance from node 1 to node 1, 2, 3, 4, 5 and 6 respectively)
// 0 5 3 6 4 10
//Node 1 to node 1: 0
//Node 1 to node 2: 5	
//Node 1 to node 3: 3
//Node 1 to node 4: 6
//Node 1 to node 5: 4
//Node 1 to node 6: 10

#include "C:/Program Files/VS2012Schemas/header.txt"	//directory

using namespace std;

//Declare an input file stream (ifstream) variable.
ifstream inFile;

int N;				//number of nodes
int a, b, w;			//Node a to Node b and weight w
int node_matrix[100][100];	//2D node matrix
int path_matrix[100][100];	//2D matrix to store paths
int distances[100];		//1-D array distance
int visited[100];		//Set initally to 0

//dijkstra function. gets current node
int dijkstra(int x) {
	visited[x] = 1;		//sets current node as visited, marked as 1. They were all 0 before

	//updates the nodes
	for (int i = 1; i <= N; i++) {		//for all the nodes (1 to 6)
		//check if they are not visited and they are connected
		if ((visited[i] == 0) && (node_matrix[x][i] != -1)) {		
			//if distancefrom node 1 (0) + distance in node matrix of node + next node is less than the distance in the distances array then this is the new shortest path, update
			//OR if distance in array distance is -1, update aswell. This will be true for the first round.
			if ((distances[x] + node_matrix[x][i] < distances[i]) || (distances[i] == -1)) {
				distances[i] = distances[x] + node_matrix[x][i];		//update i
				//here we are storing shortest path.
				//the for loop goes through the columns setting all longer distances to 0, therefore we are left only with the node with the shortest distance
				for (int j = 1; j <= N; j++) {
					path_matrix[j][i] = 0;
				}
				//update node with shortest distance
				path_matrix[x][i] = i;
			}
		}
	}
	//after updating all the nodes, we are going to select a new node
	int new_node = -1, smaller_weight = -1;
	//for all the nodes, going to check which will be the next node
	for (int i = 0; i <= N; i++) {
		//node should not be visited and the distance should be greater than 0. smaller_weight should be bigger than current distance or else equal to -1
		if ((visited[i] == 0) && (distances[i] >= 0) && ((smaller_weight > distances[i]) || (smaller_weight == -1))) {
			smaller_weight = distances[i];	//distance from node 1 to 2 is now the smallest weight
			new_node = i;					//new node is now 4
		}
	}

	if (new_node != -1) {
		dijkstra(new_node); //run dijkstra function with new node. First run new node will be 4
		return 0;
	}
	return 0;
}

int main() {

	//Open the file stream. Path names in MS Windows use backslashes (\). Because the backslash is also the string escape character, 
	//it must be doubled. If the full path is not given, most systems will look in the directory that contains the object program.

	inFile.open("C:\\Users\\ryanr\\Desktop\\MCAST Degree 2\\Engineering Project (2)\\DIjkstra\\DIjkstra Implementation\\dijkstra.txt");
	
	//Check that the file was opened.For example, the open fails if the file doesn't exist, or if it can't be read 
	//because another program is writing it.A failure can be detected with code like that below using the !(logical not) operator
	if (!inFile) {
		cerr << "Unable to open file \n";
		cout << errno;		//call errno to give more insight reagrding the error
		exit(1);		// call system to stop
	}

	//reading number of nodes
	inFile >> N;
	//for all nodes fill in node_matrix and set to -1
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			node_matrix[i][j] = -1;	//setting all to -1 meaning there is no connection between nodes
			path_matrix[i][j] = 0;	//no path establsihed.
		}
	}

	//initializing distance
	for (int i = 0; i <= N; i++) {
		distances[i] = -1;	//setting distance to -1 (or infinity)
	}

	//initializing root
	distances[1] = 0;		//distance of 1 set to 0

	while (!inFile.eof()) {	//reading till end of file 
		inFile >> a >> b >> w;
		node_matrix[a][b] = w;		//updating matrix
		//this line is vital for correct functionality.
		//make sure to update both paths TO and FROM each node
		node_matrix[b][a] = w;		
	}

	//running dijkstra function
	dijkstra(1);
	
	//output
	for (int i = 1; i <= N; i++) {
		cout <<"Distance from Node 1 to Node " << i << " is: " << distances[i] << endl;
	}
	cout << endl;

	int i = 0;
	for (int row_node = 1; row_node <= N; row_node++) {
		for (int col_path = 1; col_path <= N; col_path++) {
			if (i % 5 == 0) {
				cout << endl;
			}
			i++;
			cout << path_matrix[row_node][col_path];
		}
	}
	cout << endl;
	cout << endl;

	for (int row_node = 1; row_node <= N; row_node++) {
		for (int col_path = 1; col_path <= N; col_path++) {
			if(path_matrix[row_node][col_path] != 0) {
				if (row_node == 1) {
					//cout << path_matrix[row_node][col_path] << " <- " << col_path << endl;
					cout << row_node<< " -> " << path_matrix[row_node][col_path] << endl;
				}
				else {
					//cout << path_matrix[row_node][col_path] << " <- " << col_path << " <- 1" << endl;
					cout << "1 -> " << row_node << " -> " << path_matrix[row_node][col_path] << endl;
				}
			}
		}
	}
}