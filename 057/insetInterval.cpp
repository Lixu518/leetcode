#include<iostream>
#include<vector>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

vector<Interval> insert(vector<Interval>& intervals, Interval newInterval){
    if(intervals.empty()){
        intervals.push_back(newInterval);
        return intervals;
    }
    vector<Interval>res;
    for(int i = 0;i < intervals.size();i++){
        if(intervals[i].end < newInterval.start){
            res.push_back(intervals[i]);
        }else if(intervals[i].start > newInterval.end){
            res.push_back(newInterval);
            newInterval = intervals[i];
        }else{
            newInterval.start = min(intervals[i].start, newInterval.start);
            newInterval.end = max(intervals[i].end, newInterval.end);
        }
    }
    res.push_back(newInterval);
    return res;
}

int main(){
    vector<Interval>intervals = {{1,2},{3,5},{6,7},{8,10},{12,16}};
    Interval newInterval = {4, 8};
    vector<Interval> res = insert(intervals, newInterval);
    for(int i = 0;i < res.size();i++){
        cout<<res[i].start<<" "<<res[i].end<<endl;
    }
    return 0;
}
