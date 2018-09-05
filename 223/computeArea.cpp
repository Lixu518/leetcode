#include<iostream>
#include<cmath>
using namespace std;
int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int sum = (C - A) * (D - B) + (G - E) * (H - F);
    if(E >= C || F >= D || A >= G || B >= H) return sum;
    return sum - (min(G, C) - max(A, E)) * (min(D, H) - max(B, F));
}

int main(){
    cout<<"the Area is:"<<computeArea(-3, 0, 3, 4, 0, -1, 9, 2)<<endl;
    return 0;
}
