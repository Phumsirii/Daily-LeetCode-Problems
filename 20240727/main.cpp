#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<int>> dp(26,vector<int> (26,1e9));
        for(int i=0;i<26;++i) dp[i][i]=0;
        int vectorSize=original.size();
        for(int i=0;i<vectorSize;++i){
            char originalChar=original[i];
            char changedChar=changed[i];
            dp[originalChar-'a'][changedChar-'a']=min(dp[originalChar-'a'][changedChar-'a'],cost[i]);
        }
        long long ans=0;
        for(int k=0;k<26;++k){
            for(int i=0;i<26;++i){
                for(int j=0;j<26;++j) dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
        int stringSize=source.size();
        for(int i=0;i<stringSize;++i){
            if (dp[source[i]-'a'][target[i]-'a']==1e9) return -1;
            ans+=dp[source[i]-'a'][target[i]-'a'];
        } 
        return ans;
    }
};
int main(){
    Solution s;
    string source = "abcd", target = "acbe";
    vector<char> original = {'a','b','c','c','e','d'}, changed = {'b','c','b','e','b','e'};
    vector<int> cost = {2,5,5,1,2,20};
    cout<<s.minimumCost(source,target,original,changed,cost);
}