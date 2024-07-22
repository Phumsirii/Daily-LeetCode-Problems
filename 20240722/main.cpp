#include <bits/stdc++.h>
using namespace std;

class person{
public:
    int height;
    string name;
    person(){};
    bool operator<(const person &other) const {
        return this->height > other.height;
    }
};

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n=names.size();
        vector<person> sortedOrder(n);
        for(int i=0;i<n;++i){
            sortedOrder[i].height=heights[i];
            sortedOrder[i].name=names[i];
        }
        sort(sortedOrder.begin(),sortedOrder.end());
        vector<string> result(n);
        for(int i=0;i<n;++i) result[i]=sortedOrder[i].name;
        return result;
    }
};

int main(){
    Solution s;
    vector<string> names = {"Mary","John","Emma"};
    vector<int> heights = {180,165,170};
    vector<string> result=s.sortPeople(names,heights);
    for(string &s:result) cout<<s<<" ";
}