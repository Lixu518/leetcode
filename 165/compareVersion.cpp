#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
int compareVersion(string version1, string version2) {
    int d1 = 0, d2 = 0, i = 0, j = 0;
    string v1, v2;
    while(i < version1.size() || j < version2.size()){
        while(i < version1.size() && version1[i] != '.')
            v1.push_back(version1[i++]);
        d1 = atoi(v1.c_str());
        while(j < version2.size() && version2[j] != '.')
            v2.push_back(version2[j++]);
        d2 = atoi(v2.c_str());
        if (d1 > d2) return 1;
        else if (d1 < d2) return -1;
        v1.clear();
        v2.clear();
        i++;
        j++;
    }
    return 0;
}

int main(){
    string version1 = "0.1.1.2";
    string version2 = "1.1.2";
    cout<<compareVersion(version1, version2)<<endl;
    return 0;
}
