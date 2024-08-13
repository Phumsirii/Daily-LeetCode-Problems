#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void recur(int target,int it,vector<int> &lookahead,int n,vector<int> &candidates,vector<int> &draft,vector<vector<int>> &result){
        if (target==0){
            result.push_back(draft);
            return ;
        }
        if (it==n) return ;
        //current is too low    
        if (lookahead[it]<target) return;
        //current is too high
        if (candidates[it]>target) return;
        //try considering 'it'th element
        for(int i=it;i<n && target>=candidates[i];++i){
            if (i==it || candidates[i]!=candidates[i-1]){
                draft.push_back(candidates[i]);
                recur(target-candidates[i],i+1,lookahead,n,candidates,draft,result);
                draft.pop_back();
            }
        }
        return ;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        int n=candidates.size();
        vector<int> lookahead(n);
        lookahead[n-1]=candidates[n-1];
        for(int i=n-2;i>=0;--i) lookahead[i]=lookahead[i+1]+candidates[i];
        vector<int> draft;
        vector<vector<int>> result;
        recur(target,0,lookahead,n,candidates,draft,result);
        return result;
    }
};
int main(){

}