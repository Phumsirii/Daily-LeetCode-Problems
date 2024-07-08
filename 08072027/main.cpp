#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<bool> eliminated(n,false);
        int it=-1;
        //eliminate n-1 times
        for(int i=1;i<n;++i){
            int count=0;
            while(count<k){
                it=(it+1)%n;
                if(!eliminated[it]) ++count;
            }
            eliminated[it]=true;
        }
        while(eliminated[it]) it=(it+1)%n;
        return it+1;
    }
};
int main(){
    Solution solution;
    cout<<solution.findTheWinner(5,2)<<endl;
    cout<<solution.findTheWinner(6,5)<<endl;
    cout<<solution.findTheWinner(3,1)<<endl;
}