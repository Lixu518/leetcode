#include<iostream>
#include<queue>
using namespace std;
class MyStack{
    public:
        MyStack(){};
        void push(int x){
            que.push(x);
            for(int i = 0;i < que.size() - 1;i++){
                que.push(que.front());
                que.pop();
            }
        }
        int pop(){
            int x = que.front();
            que.pop();
            return x;
        }
        int top(){
            return que.front();
        }
        bool empty(){
            return que.empty();
        }
    private:
        queue<int>que;
};
int main(){
    MyStack st;
    st.push(1);
    st.push(5);
    cout<<"empty()"<<st.empty()<<endl;
    cout<<"top()"<<st.top()<<endl;
    cout<<"pop()"<<st.pop()<<endl;
    return 0;
}

