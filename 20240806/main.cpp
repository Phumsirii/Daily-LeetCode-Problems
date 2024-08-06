#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumPushes(string word) {
        vector<int> alphabetMap(26,0);
        for(char &x:word) alphabetMap[x-'a']++;
        sort(alphabetMap.begin(),alphabetMap.end(),greater<int>());
        int result=0;
        for(int i=0;i<26;++i){
            if (alphabetMap[i]==0) return result;
            result+=(i/8+1)*alphabetMap[i];
        }
        return result;
    }
};
int main(){
    Solution s;
    cout<<s.minimumPushes("aabbccddeeffgghhiiiiii")<<endl;
}