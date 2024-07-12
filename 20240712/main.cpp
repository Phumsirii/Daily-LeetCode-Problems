#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int getgain(string &s,int value,string q){
        string tmp="";
        int gain=0;
        for(char &c:s){
            if (!tmp.empty() && c==q[1] && tmp.back()==q[0]){
                gain+=value;
                tmp.pop_back();
            }else tmp+=c;
        }
        s=tmp;
        return gain;
    }
    int maximumGain(string s, int x, int y) {
        int g1,g2;
        if (x>y){
            g1=getgain(s,x,"ab");
            g2=getgain(s,y,"ba");
        }else{
            g1=getgain(s,y,"ba");
            g2=getgain(s,x,"ab");
        }
        return g1+g2;
    }
};
 int main(){
    Solution s;
    cout<<s.maximumGain("cdbcbbaaabab",4,5)<<endl;
    cout<<s.maximumGain("aabbaaxybbaabb",5,4)<<endl;
 }