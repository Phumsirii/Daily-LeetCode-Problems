#include <bits/stdc++.h>
using namespace std;
int passThePillow(int n, int time) {
    time=time%(2*n-2);
    if (time/n==0) return time+1;
    return n-(time%(n-1));       
}
int main(){
    cout<<passThePillow(4,7)<<endl;
    cout<<passThePillow(4,5)<<endl;
    cout<<passThePillow(3,2)<<endl;
}