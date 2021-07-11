//    stack using array

#include <bits/stdc++.h>
using namespace std;

class stackUsingArray{
  public:
   int* data;
   int capacity;
   int nextIndex;
  
  //constructor
   stackUsingArray(int n){
   	capacity = n;
   	data = new int[capacity];
   	nextIndex=0;
   }
   
   //insertion
   void push(int ele){
   	if(nextIndex==capacity){
   		cout<<"stack is full "<<ele<<" cant be inserted"<<endl;
   		return;
   	}
   	data[nextIndex]=ele;
   	nextIndex++;
   }
   
   //deletion
   int pop(int ele){
   	if(nextIndex==0){
   		cout<<"stack is empty"<<endl;
   		return INT_MIN;
   	}
   	nextIndex--;
   	return nextIndex;
   }
   
   //top most element of stack
   int top(){
   	if(nextIndex==0){
   		return INT_MIN;
   	}
   	return data[nextIndex-1];
   }
};

int main() {
     stackUsingArray myStack(5);
     myStack.push(6);
     myStack.push(10);
     myStack.push(100);
     myStack.push(60);
     myStack.push(16);
     cout<<myStack.top()<<endl;;
	return 0;
}