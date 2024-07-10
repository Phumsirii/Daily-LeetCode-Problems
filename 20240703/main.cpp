#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int recur(int start,int stop,int step,vector<int> &num){
        if (step==3) return num[stop]-num[start];
        if (start==stop || num[start]==num[stop]) return 0;
        //remove the first element
        int w1=recur(start+1,stop,step+1,num);
        if (w1==0) return 0;
        //remove the last element
        int w2=recur(start,stop-1,step+1,num);
        return min(w1,w2);
    }
    int minDifference(vector<int>& nums) {
        //cast nums so it can be sorted
        vector<int> nums2=nums;
        sort(nums2.begin(),nums2.end());
        int result=recur(0,nums.size()-1,0,nums2);
        return result;
    }
};
int main(){
    Solution solution;
    vector<int> v={3,100,20};
    cout<<solution.minDifference(v)<<"\n";
    for(int i=0;i<v.size();++i) cout<<v[i]<<" ";
}