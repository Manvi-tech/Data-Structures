//    min stack

#include <bits/stdc++.h>
using namespace std;

class myStack{
public:
    stack<int> s;
    int curr_min;
    
    myStack(){
    	curr_min=INT_MAX;
    }
    
    void push(int ele){
    	if(ele<curr_min){
    		s.push(2*ele - curr_min);
    		curr_min=ele;
    	}
    	else{
    		s.push(ele);
    	}
    }
    
    void pop(){
    	if(s.empty()){
    		return;
    	}
    	else{
    		if(s.top() <= curr_min){
    			curr_min = 2*curr_min - s.top();
    		}
    		s.pop();
    	}
    }
    
    int getMin(){
    	return curr_min;
    }
};

int main() {
	
	myStack st;
	st.push(3);
	st.push(1);
	cout<<st.getMin()<<endl;
	st.pop();
	cout<<st.getMin()<<endl;
	return 0;
}