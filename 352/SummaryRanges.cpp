#include<iostream>
#include<vector>
using namespace std;
struct Interval{
    int start;
    int end;
    Interval(): start(0), end(0){}
    Interval(int s, int e): start(s), end(e){}
};

class SummaryRanges{
private:
    vector<Interval> v;

public:
    SummaryRanges(){}
    void addNum(int val){
        Interval cur(val, val);
        vector<Interval>res;
        int pos = 0;
        for(auto a:v){
            if(a.start > cur.end + 1){
                res.push_back(a);
            }else if(a.end + 1 < cur.start){
                res.push_back(a);
                ++pos;
            }else{
                cur.start = min(cur.start, a.start);
                cur.end = max(cur.end, a.end);
            }
        }
        res.insert(res.begin() + pos, cur);
        v = res;
    }

    vector<Interval> getIntervals(){
        return v;
    }
};

int main(){
    SummaryRanges obj;
    obj.addNum(1);
    obj.addNum(3);
    obj.addNum(7);
    obj.addNum(2);
    obj.addNum(6);
    vector<Interval> param_2 = obj.getIntervals();
    for(auto inte:param_2)
        cout<<inte.start<<" "<<inte.end<<endl;
    return 0;
}
