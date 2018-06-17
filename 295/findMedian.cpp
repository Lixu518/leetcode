#include<iostream>
#include<queue>
using namespace std;
class MedianFinder{
private:
    priority_queue<int>small, large;

public:
    void addNum(int num){
        if(!small.empty() && small.top() > num)
            small.push(num);
        else
            large.push(-num);
        if(small.size() - large.size() == 2){
            large.push(-small.top());
            small.pop();
        }
        if(large.size() - small.size() == 2){
            small.push(-large.top());
            large.pop();
        }
    }
    double findMedian(){
        if(large.size()>small.size())return -large.top();
        else if(large.size()<small.size()) return small.top();
        else return (small.top()-large.top())/2.0;
    }
    MedianFinder(){}
};
