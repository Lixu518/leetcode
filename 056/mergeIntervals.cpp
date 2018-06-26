#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Interval{
    int start;
    int end;
    Interval():start(0), end(0){}
    Interval(int s, int e) : start(s), end(e) {}
};

vector<Interval> merge(vector<Interval>& intervals){
    if(intervals.empty() || intervals.size() <= 1)
        return intervals;
    vector<Interval> res;
    res.push_back(intervals[0]);
    sort(intervals.begin(), intervals.end(),[](Interval &a, Interval &b){ return a.start < b.start;});
    for(int i = 1;i < intervals.size();i++){
        if(res.back().end < intervals[i].start)
            res.push_back(intervals[i]);
        else
            res.back().end = max(intervals[i].end, res.back().end);
    }
    return res;
}

int main(){
    vector<Interval>intervals = {{1,3}, {2,6}, {8,10}, {15,18}};
    vector<Interval>res = merge(intervals);
    for(int i = 0;i < res.size();i++){
        cout<<res[i].start<<" "<<res[i].end<<endl;
    }
    return 0;
}
