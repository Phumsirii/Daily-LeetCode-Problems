#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        for(int i=1;i<arr.size()-1;++i){
            if (arr[i]%2 && arr[i-1]%2 && arr[i+1]%2) return true;
        }    
        return false;
    }
};
int main(){
    Solution s;
    vector<int> arr1 = {2,6,4,1},arr2={1,2,34,3,4,5,7,23,12},arr3={1};
    cout<<s.threeConsecutiveOdds(arr1)<<endl;
    cout<<s.threeConsecutiveOdds(arr2)<<endl;
    cout<<s.threeConsecutiveOdds(arr3)<<endl;
}