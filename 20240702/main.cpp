#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> num1,num2,result;
    void recur(int it1,int it2){
        if (it1<0 || it2<0) return;
        //intersection found
        if (num1[it1]==num2[it2]){
            result.push_back(num1[it1]);
            return recur(it1-1,it2-1);
        }
        //not intersecting
        if (num1[it1]>num2[it2]) return recur(it1-1,it2);
        return recur(it1,it2-1);
    }
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        num1=nums1;
        num2=nums2;
        sort(num1.begin(),num1.end());
        sort(num2.begin(),num2.end());
        recur(nums1.size()-1,nums2.size()-1);
        return result;
    }
};
int main(){
    Solution solution;
    vector<int> nums1={4,9,5},nums2={9,4,9,8,4};
    for(int &x:solution.intersect(nums1,nums2)) cout<<x<<" ";
    cout<<"\n";
}