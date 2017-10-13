//Dijkstra Implementation

#include <iostream>	
#include <fstream>

using namespace std;

ifstream fin("a.in");	//input file

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
	if (smaller != 1) {
		dij(smaller);
		return 0;
	}
	//return 0;
}

int main() {
	//reading number of nodes
	fin >> N;
	
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

	while (!fin.eof()) {	//reading till end of file 
		fin >> a >> b >> w;
		am[a][b] = w;		//updating matrix
		am[a][b] = w;
	}

	//running dijkstra function
	dij(1);
	
	//output
	for (int i = 1; i <= N; i++) {
		cout << distances[i] << " ";
	}
}