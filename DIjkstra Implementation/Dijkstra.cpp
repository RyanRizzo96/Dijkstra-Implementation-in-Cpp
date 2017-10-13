//Dijkstra Implementation

#include "C:/Program Files/VS2012Schemas/header.txt"	//directory

//using namespace std;

//reading input file

//Declare an input file stream (ifstream) variable.
ifstream inFile;

int N;					//number of nodes
int a, b, w;			//Node a to Node b and weight w
int am[100][100];
int distances[100];		//1-D array distance
int visited[100];		//Set initally to 0

//dijkstra function. gets current node
int dij(int x) {
	visited[x] = 1;		//sets current node as visited, marked as 1. They were all 0 before

	//updates the nodes
	for (int i = 1; i <= N; i++) {		//for all the nodes
		//check if they are not visited and they are connected
		if ((visited[i] == 0) && (am[x][i] != -1)) {		
			//if distance of x + matrix is more than the distance that i already has or if distance of i is infinity, update
			if ((distances[x] + am[x][i] < distances[i]) || (distances[i] == -1)) {
				distances[i] = distances[x] + am[x][i];		//update i
			}
		}
	}
	//after updating all the nodes, we are going to select a new node
	int smaller = -1, smaller_weight = -1;
	//for all the nodes, going to check which will be the next node
	for (int i = 0; i <= N; i++) {
		//node should not be visited and the distane should be greater than 0. smaller_weight should be bigger than current distance or esle equal to -1
		if ((visited[i] == 0) && (distances[i] >= 0) && ((smaller_weight > distances[i]) || (smaller_weight == -1))) {
			smaller_weight = distances[i];	//
			smaller = i;
		}
	}

	if (smaller != -1) {
		dij(smaller);
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
		cout << errno;
		exit(1);   // call system to stop
	}

	//reading number of nodes
	inFile >> N;
	
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			am[i][j] = -1;	//setting all to -1 meaning there is no connection between nodes
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
		am[a][b] = w;		//updating matrix
		am[a][b] = w;
	}

	//running dijkstra function
	dij(1);
	
	//output
	for (int i = 1; i <= N; i++) {
		cout << distances[i] << " ";
	}
	//keep_window_open();
	
}