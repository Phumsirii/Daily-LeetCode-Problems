#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> dp;
    vector<int> tail;
    int maxStones(int currentPosition,int maxK){
        if (currentPosition+maxK*2>=tail.size()) return tail[currentPosition];
        if (dp[currentPosition][maxK]>0) return dp[currentPosition][maxK];
        int forBob=1e9;
        for(int i=1;i<=maxK*2;++i) forBob=min(forBob,maxStones(currentPosition+i,max(maxK,i)));
        return dp[currentPosition][maxK]=tail[currentPosition]-forBob;
    }
    int stoneGameII(vector<int>& piles) {
        dp=vector<vector<int>>(piles.size(),vector<int> (piles.size(),0));
        tail=vector<int> (piles.size(),piles[piles.size()-1]);
        for(int i=piles.size()-2;i>=0;--i) tail[i]=tail[i+1]+piles[i];
        return maxStones(0,1);
    }
};
int main(){
    Solution s;
    vector<int> piles = {2,7,9,4,4};
    cout<<s.stoneGameII(piles);
}