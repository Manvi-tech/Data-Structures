#include<bits/stdc++.h>
using namespace std;

void BFS(int** edges,int n,bool* visited,int sv){
	queue<int> vertices;
	vertices.push(sv);
	visited[sv]=true;
	
	while(!vertices.empty()){
		int temp = vertices.front();
		vertices.pop();
		cout<<temp<<" ";
		
		for(int i=0;i<n;i++){
			if(edges[temp][i]==1 && visited[i]==false){
				vertices.push(i);
				visited[i] = true;
			}
		}
		
	}
	
	return;
}

int main(){
	
	int n; // no of vertices
	cin>>n;
	
	int** edges = new int*[n];
	for(int i=0;i<n;i++){
		edges[i]=new int[n];
		for(int j=0;j<n;j++)
		edges[i][j]=0;
	}
	
	int e;
	cin>>e;
	
	while(e--){
		int v1,v2;
		cin>>v1>>v2;
		edges[v1][v2]=1;
		edges[v2][v1]=1; // non-directed graph
	}
	
	bool* visited = new bool[n];
	for(int i=0;i<n;i++){
		visited[i]=false; // mark all vertices as unvisited initially
	}
	
	BFS(edges,n,visited,0);
	return 0;
}


