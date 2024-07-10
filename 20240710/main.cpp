#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(vector<string>& logs) {
        int cnt=0;
        for(string &x:logs){
            if (x=="./") continue;
            else if (cnt!=0 && x=="../") --cnt;
            else if (x!="../") ++cnt;
        }
        return cnt;
    }
};
int main(){
    Solution s;
    vector<string> l1={"d1/","d2/","./","d3/","../","d31/"},l2={"d1/","../","../","../"};
    cout<<s.minOperations(l1)<<endl;
    cout<<s.minOperations(l2)<<endl;
}