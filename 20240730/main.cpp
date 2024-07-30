#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size(),ans=0,countb=0;
        for(int i=0;i<n;++i){
            if (s[i]=='a') ans=min(ans+1,countb);
            else ++countb;
        }
        return ans;
    }
};
int main(){
    Solution sol;
    string s = "bbaaaaabb";
    cout<<sol.minimumDeletions(s);
}