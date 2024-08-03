#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector<int> isInarr(1001,0),isIntarget(1001,0);
        for(int &x:arr) ++isInarr[x];
        for(int &x:target){
            ++isIntarget[x];
            if (isIntarget[x]>isInarr[x]) return false;
        }
        return true;
    }
};
int main(){
    Solution s;
    vector<int> target={1,2,3,4},arr={2,4,1,3};
    cout<<s.canBeEqual(target,arr)<<endl;
}