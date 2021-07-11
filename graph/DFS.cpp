#include<bits/stdc++.h>
using namespace std;

void DFS(int** edges,int n,bool* visited,int sv){
	cout<<sv<<" ";
	visited[sv]=true;
	
	for(int i=0;i<n;i++){
		if(i==sv)
		continue;
		
		if(edges[sv][i]==1 && visited[i]==false)
		DFS(edges,n,visited,i);
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
	
	DFS(edges,n,visited,0);
	return 0;
}



