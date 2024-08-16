#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n=arrays.size();
        vector<int> maxElements(n),minElements(n);
        for(int i=0;i<n;++i){
            maxElements[i]=arrays[i][max_element(arrays[i].begin(),arrays[i].end())-arrays[i].begin()];
            minElements[i]=arrays[i][min_element(arrays[i].begin(),arrays[i].end())-arrays[i].begin()];
        }
        int maxIndex=max_element(maxElements.begin(),maxElements.end())-maxElements.begin();
        int minIndex=min_element(minElements.begin(),minElements.end())-minElements.begin();
        if (maxIndex!=minIndex) return maxElements[maxIndex]-minElements[minIndex];
        int secondMax=-1e9,secondMin=1e9;
        for(int i=0;i<n;++i){
            if (i!=maxIndex && maxElements[i]>=secondMax) secondMax=maxElements[i];
            if (i!=minIndex && minElements[i]<=secondMin) secondMin=minElements[i];
        }
        return max(abs(maxElements[maxIndex]-secondMin),abs(secondMax-minElements[minIndex]));
    }
};
int main(){
    Solution s;
    vector<vector<int>> arrays={{1,5},{3,4}};
    cout<<s.maxDistance(arrays);
}