#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countPrefix(int num,vector<int> nums){
        int count=0;
        int n=nums.size();
        for(int i=0,j=0;i<n;++i){
            while(j<n && nums[j]-nums[i]<=num) ++j;
            count+=j-i-1;
        }
        return count;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int left=0,right=nums[n-1]-nums[0];
        while(left<right){
            int mid=(left+right)/2;
            if (countPrefix(mid,nums)<k) left=mid+1;
            else right=mid;
        }
        return left;
    }
};
int main(){
    Solution s;
    vector<int> nums={1,6,1};
    cout<<s.smallestDistancePair(nums,3);
}