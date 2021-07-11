#include<bits/stdc++.h>
using namespace std;

class edge{
	public:
	int v1,v2,wt;
};

void kruskal(edge*,int);
int findParent(int,int*);
bool compare(edge e1,edge e2){
	return e1.wt<e2.wt;
}

int main(){
	int n,e;
	cin>>n>>e;
	
   edge* edges= new edge[e];
   int i=0;
	while(i<e){
		cin>>edges[i].v1>>edges[i].v2>>edges[i].wt;
	   i++;
	}
	
	sort(edges,edges+e,compare);
	kruskal(edges,n);
	
	return 0;
}

int findParent(int v,int* parent){
	if(parent[v]==v)
	  return v;
	  
	return findParent(parent[v],parent);  
}

void kruskal(edge* ptr,int n){
	
	int* parent = new int[n];
	for(int i=0;i<n;i++){
		parent[i]=i;
	}
	
	edge* output = new edge[n-1];
	
	int j=0; // to iterate over ptr to pick n-1 edges
	int count =0; // to stop when count = n-1, ensuring n-1 edges have been picked
	
	while(count<n-1){
		int sourcePar = findParent(ptr[j].v1,parent);
		int destPar = findParent(ptr[j].v2,parent);
		
		if(sourcePar != destPar){
			output[count]=ptr[j];
			parent[sourcePar] = parent[destPar];
			count++;
		}
		j++;
	} 
	
	for(int i=0;i<n-1;i++){   //print MST
		cout<<output[i].v1<<" "<<output[i].v2<<" "<<output[i].wt<<endl;
	}
	
	return;
}

