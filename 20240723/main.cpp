#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> freq;
    Solution(){freq=vector<int>(201,0);};
    bool customComparator(int &a,int &b) {
        if (freq[a+100]!=freq[b+100])return freq[a+100]<freq[b+100];
        return a>b;
    }
    vector<int> frequencySort(vector<int>& nums) {
        freq=vector<int> (201);
        for(int &x:nums) ++freq[x+100];
        sort(nums.begin(),nums.end(),[this](int a,int b){
            return customComparator(a,b);
            });
        return nums;
    }
};
int main(){
    Solution s;
    vector<int> nums = {1,1,2,2,2,3};
    s.frequencySort(nums);
    for(int &x:nums) cout<<x<<" ";
}