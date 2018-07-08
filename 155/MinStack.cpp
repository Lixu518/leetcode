#include<iostream>
#include<stack>
#include<climits>

using namespace std;
class MinStack{
private:
    stack<int> numStack;	
	stack<int> minStack;	
public:
    void push(int value) 
	{
		if(minStack.empty())
		{
			minStack.push(value);
		}
		else
		{
			if(value <= minStack.top())
			{
				minStack.push(value);
			}
		}
		numStack.push(value);
	}
	void pop() 
	{
		if (numStack.empty())
		{
			return;
		}
 
		if (numStack.top() == minStack.top())
		{
			minStack.pop();
		}
		numStack.pop();
	}
	int top() 
	{
		if(!numStack.empty())
			return numStack.top();
	}
	int min() 
	{
		if(!minStack.empty())
			return minStack.top();
	}
};


int main(int argc, const char* argv[]){
    MinStack minstack;
    minstack.push(-1);
    minstack.push(1);
    cout<<minstack.min()<<endl;
    return 0;
}
