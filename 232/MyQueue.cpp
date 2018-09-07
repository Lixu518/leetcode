#include<iostream>
#include<stack>
using namespace std;
class MyQueue{
private:
    stack<int>s;
public:
    MyQueue(){}
    void push(int x){
        stack<int>t;
        while(!s.empty()){
            t.push(s.top());
            s.pop();
        }
        s.push(x);
        while(!t.empty()){
            s.push(t.top());
            t.pop();
        }
    }
    int pop(){
        int x = s.top();
        s.pop();
        return x;
    }

    int peek(){
        return s.top();
    }

    bool empty(){
        return s.empty();
    }
};

int main(){
    MyQueue q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout<<"pop()"<<q.pop()<<endl;
    cout<<"peek()"<<q.peek()<<endl;
    return 0;
}

