#include<iostream>
#include<string>
using namespace std;
bool isValidSerialization(string preorder){
    int capacity = 1;
    preorder += ",";
    for(int i = 0;i < preorder.size();++i){
        if(preorder[i] != ',')continue;
        if(--capacity < 0) return false;
        if(preorder[i - 1] != '#') capacity += 2;
    }
    return capacity == 0;
}

int main(){
    string preorder = "9,3,4,#,#,1,#,#,2,#,6,#,#";
    cout<<"Is "<<preorder<<" valid serialization? "<<isValidSerialization(preorder)<<endl;
    return 0;
}
