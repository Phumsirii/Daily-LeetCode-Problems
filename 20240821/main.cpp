#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int recur(int start,int stop,vector<vector<int>> &dp,string &s){
        if (start>stop) return 0;
        if (dp[start][stop]!=-1) return dp[start][stop];
        int minPossible=1+recur(start+1,stop,dp,s);
        for(int i=start+1;i<=stop;++i){
            if (s[i]==s[start]) minPossible=min(minPossible,recur(start,i-1,dp,s)+recur(i+1,stop,dp,s));
        }
        return dp[start][stop]=minPossible;
    }
    int strangePrinter(string s) {
        s=removeConsecutive(s);
        int n=s.size();
        vector<vector<int>> dp(n,vector<int> (n,-1));
        return recur(0,n-1,dp,s);
    }
    string removeConsecutive(string &s){
        int n=s.size();
        int it=0;
        string result="";
        while(it<n){
            result+=s[it];
            while(it<n && s[it+1]==s[it]) ++it;
            ++it;
        }
        return result;
    }
};
int main(){
    Solution s;
    cout<<s.strangePrinter("aabbb");
}