#include<iostream>
#include<map>
#include<utility>
#include<vector>
using namespace std;

struct Point{
    int x;
    int y;
    Point():x(0), y(0){}
    Point(int a, int b):x(a), y(b){}
};

int gcd(int a, int b){
    return (b == 0)?a:gcd(b, a%b);
}

int maxPoints(vector<Point>& points){
    if(points.size() <= 2)return points.size();
    int res = 0;
    for(int i = 0;i < points.size();i++){
        map<pair<int, int>, int>hash;
        int duplicate = 1;
        for(int j = i + 1; j < points.size();j++){
            if(points[i].x == points[j].x && points[i].y == points[j].y){
                duplicate++;
                continue;
            }
            int dx = points[i].x - points[j].x;
            int dy = points[i].y - points[j].y;
            int d = gcd(dx, dy);
            hash[make_pair(dx/d, dy/d)]++;
        }
        res = max(res, duplicate);
        for(auto it = hash.begin();it != hash.end();it++){
            res = max(res, it->second + duplicate);
        }
    }
    return res;
}

int main(){
    vector<Point> points = {Point(1,1), Point(3,2), Point(5,3), 
        Point(4,1), Point(2,3), Point(1,4)};
    cout<<"max point in a line: "<<maxPoints(points)<<endl;
    return 0;
}
