#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int> pq;
        for(int &x:nums) pq.push(x);
        int n=nums.size();
        vector<int> result(n);
        for(int i=n-1;i>=0;--i){
            result[i]=pq.top();
            pq.pop();
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<int> nums = {5,2,3,1};
    vector<int> result=s.sortArray(nums);
    for(int &x: result) cout<<x<<" ";
}