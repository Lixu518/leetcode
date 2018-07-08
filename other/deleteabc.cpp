#include<iostream>
using namespace std;
void delete_bac(char * str){
    int location = 0;
    int i = 0;
    while(str[i] != '\0'){
        if(str[i] != 'b'){
            str[location] == str[i];
            i++;
            continue;
        }
        if(str[location] == 'c' && str[location-1] == 'a'){
            location--;
        }
        else{
            location++;
        }
        i++;
    }
    str[location] = '\0';
}

int main(){
    char s[20] = "acacaacacacab";
    cout<<s<<endl;
    delete_bac(s);
    cout<<s<<endl;
    return 0;
}
