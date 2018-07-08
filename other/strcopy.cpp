#include<iostream>
#include<cassert>
using namespace std;


char* strcpy(char *strDest, const char *strSrc)
{
    if(strDest == NULL || strSrc == NULL) return NULL;
    char* address = strDest;
    while((*strDest++ = *strSrc++) != '\0') ;
    return address;
}
 
 
int main()
{
    char a[7] = "abcdef";
    char b[4] = "ABC";
    strcpy(a,b);
    cout<<a<<endl;
    return 0;
}
