#include<bits/stdc++.h>
using namespace std;

void buildTree(int* tree,int treeindex,int* arr,int start,int end){
	if(start==end){
		tree[treeindex]=arr[start];
		return;
	}
	
	int mid=(start+end)/2;
	buildTree(tree,2*treeindex,arr,start,mid);
	buildTree(tree,2*treeindex+1,arr,mid+1,end);
	tree[treeindex] = tree[2*treeindex] + tree[2*treeindex+1];   // sum[0,5] = sum[0,2] + sum[3,5]
	
	return; 
}

void update(int index,int value,int* tree,int treeindex,int* arr,int start,int end){
	if(start==end){  //index = start = end
		arr[index] = value;
		tree[treeindex] = value; 
		return;
	}
	
	int mid =(start+end)/2;
	if(index>mid){
		update(index,value,tree,2*treeindex+1,arr,mid+1,end);
	}
	else{
		update(index,value,tree,2*treeindex,arr,start,mid);
	}
	
	tree[treeindex] = tree[2*treeindex] + tree[2*treeindex+1]; // 
	return;
}

int query(int left,int right,int* tree,int treeindex,int start,int end){
	if(right<start || end<left){  // out of range
		return 0;
	}
	
	if(start>=left && end<=right){
		return tree[treeindex];
	}
	
	int mid = (start+end)/2;
	int ans1 = query(left,right,tree,2*treeindex,start,mid);
	int ans2 = query(left,right,tree,2*treeindex+1,mid+1,end);
	
	return ans1+ans2;
}

int main(){
	int n;  //size of input array
	cin>>n;
	
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int* tree = new int[4*n];
	buildTree(tree,1,arr,0,n-1);
	
	int q;  //no of queries
	cin>>q;
	
	char c;
	int left,right,index,val;
	
	while(q--){
		cin>>c;     //type of query: update or find sum in range[left,right]
		
		if(c=='U'){          //update
			cin>>index>>val;
			update(index,val,tree,1,arr,0,n-1);
		}
		else{                    //sum in range [left,right]
			cin>>left>>right;
			cout<<query(left,right,tree,1,0,n-1)<<endl;
		}
	}
	return 0;
}

