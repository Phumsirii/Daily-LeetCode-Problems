#include <iostream>
using namespace std;
class Solution {
public:
    int minSteps(int n) {
        int ans=0,div=2;
        while(n>1){
            while(n%div==0){
                ans+=div;
                n/=div;
            }
            ++div;
        }
        return ans;
    }
};
int main(){
    Solution s;
    cout<<s.minSteps(6);
}