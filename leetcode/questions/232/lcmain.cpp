#include <bits/stdc++.h>

using namespace std;

class MyQueue {
private:
	stack<int> in, out;

	void flash(void) {
		while (!in.empty()) {
			out.push(in.top());
			in.pop();
		}
	}

public:
	/** Initialize your data structure here. */
	MyQueue() {}

	/** Push element x to the back of queue. */
	void push(int x) {
		in.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		if (out.empty())
			flash();
		int ret = out.top();
		out.pop();
		return ret;
	}

	/** Get the front element. */
	int peek() {
		if (out.empty())
			flash();
		return out.top();
	}

    /** Returns whether the queue is empty. */
	bool empty() {
		if (out.empty() && in.empty())
			return true;
		return false;
	}
};

int main(void)
{
	MyQueue *obj = new MyQueue();
	obj->push(1);
	obj->push(2);

	cout << obj->peek() << endl;
	cout << obj->pop() << endl;
	cout << obj->empty() << endl;


	return 0;
}

