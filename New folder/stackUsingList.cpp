
                    //  stack using list
#include <iostream>
using namespace std;

class stackNode{
  public: 
  int data;
 stackNode* next;
 
 //constructor
 stackNode(int ele){
 	this->data=ele;
 	this->next=NULL;
 }
};

class stackUsingList{
  public:
  stackNode* head;
  int size;
  
  stackUsingList(){
  	head=NULL;
  	size=0;
  }
  
  void push(int ele){
  	if(head==NULL){
  		head= new stackNode(ele);
  	}else{
  		stackNode* newnode = new stackNode(ele);
  		newnode->next=head;
  		head=newnode;
  	}
     
  	size++;
  }
  
  int pop(){
  	if(head==NULL){
  		return -1;
  	}
  	int ans = head->data;
  	size--;
  	head=head->next;
  	return ans;
  }
  
  int Size(){
  	return size;
  }
  
  int top(){
  	if(head==NULL){
  		return -1;
  	}
  	return head->data;
  }
};

int main() {
	stackUsingList stack;
	cout<<stack.top()<<endl;
	stack.push(20);
	cout<<stack.top()<<endl;
	cout<<stack.Size()<<endl;
	cout<<stack.pop()<<endl;
	
	return 0;
}