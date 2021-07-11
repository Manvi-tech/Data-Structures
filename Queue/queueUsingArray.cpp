#include <bits/stdc++.h>
using namespace std;



class QueueUsingArray {
	int *data;
	int nextIndex;
	int firstIndex;
	int size;
	int capacity;

	public :
	QueueUsingArray(int s) {
		data = new int[s];
		nextIndex = 0;
		firstIndex = -1;
		size = 0;
		capacity = s;
	}

	int getSize() {
		return size;
	}

	// insert element
	void enqueue(int element) {
		if(size == capacity) {
			cout << "Queue Full ! " << endl;
			return;
		}
		data[nextIndex] = element;
		nextIndex = (nextIndex + 1) % capacity ;
		if(firstIndex == -1) {
			firstIndex = 0;
		}
		size++;
	}
	
	int front() {
		if(size==0) {
			cout << "Queue is empty ! " << endl;
			return 0;
		}
		return data[firstIndex];
	}

	int dequeue() {
		if(size==0) {
			cout << "Queue is empty ! " << endl;
			return 0;
		}
		int ans = data[firstIndex];
		firstIndex = (firstIndex + 1) % capacity;
		size--;
		if(size == 0) {
			firstIndex = -1;
			nextIndex = 0;
		}
		return ans;
	}
};

int main() {
	QueueUsingArray que(5);
	que.enqueue(10);
	que.enqueue(20);
	que.enqueue(30);
	cout<<que.front()<<endl;
	cout<<que.dequeue()<<endl;
	cout<<que.front()<<endl;
	return 0;
}
