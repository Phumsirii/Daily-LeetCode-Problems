#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans=0,numWaterBottles=numBottles;
        while(numBottles>=numExchange){
            ans+=numWaterBottles;
            numWaterBottles=numBottles/numExchange;
            numBottles=numWaterBottles+(numBottles%numExchange);
        }
        return ans+numWaterBottles;
    }
};
int main(){
    Solution solution;
    cout<<solution.numWaterBottles(9,3)<<endl;
    cout<<solution.numWaterBottles(15,4)<<endl;
}