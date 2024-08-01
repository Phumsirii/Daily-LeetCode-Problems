#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int countSeniors(vector<string>& details) {
        int result=0;
        for (string &x:details){
            if (x[11]>'6' || (x[11]=='6' && x[12]!='0')) ++result;
        }    
        return result;
    }
};
int main(){
    Solution s;
    vector<string> details = {"7868190130M7522","5303914400F9211","9273338290F4010"};
    cout<<s.countSeniors(details);
}