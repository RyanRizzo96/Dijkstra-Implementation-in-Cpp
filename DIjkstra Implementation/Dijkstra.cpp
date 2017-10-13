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