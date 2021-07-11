   
//    queue using linked list

#include <bits/stdc++.h>
using namespace std;

class Node{
	public:
	int data;
	Node* next;
	
	Node(int x){
		this->data = x;
		this->next = NULL;
	}
};

class queueUsingList{
  public:
    Node* head;
    Node* tail;
    int listSize;
    
    queueUsingList(){
    	this->head=NULL;
    	this->tail=NULL;
    	this->listSize=0;
    }
    void push(int x){
    	if(head==NULL){
    		head = new Node(x);
    		tail=head;
    	}else{
    		tail->next = new Node(x);
    		tail=tail->next;
    		
    	}
    	listSize++;
    	return;
    }
    
    void pop(){
    	if(head==NULL){return;}
    	Node* temp=head;
    	head=head->next;
    	temp->next=NULL;
    	cout<<temp->data<<" is popped"<<endl;
    	delete temp;
    	listSize--;
    	return;
    }
    
    int top(){
    	if(head==NULL){return -1;}
    	return head->data;
    }
    
    int size(){
    	return listSize;
    }
};

int main() {
    queueUsingList que;
    que.push(5);
    que.push(10);
    cout<<que.top()<<endl;
    que.pop();
    cout<<que.size()<<endl;
	return 0;
}