#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<char> vowels = {'a', 'e', 'i', 'o','u'};
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        int qn = queries.size();
        vector<int> cumSum(n,0);
        if (find(vowels.begin(),vowels.end(),words[0][0]) != vowels.end() && find(vowels.begin(),vowels.end(),words[0][words[0].size() - 1]) != vowels.end()) ++cumSum[0];
        for(int i = 1; i < n; ++i){
            cumSum[i] = cumSum[i - 1] + (find(vowels.begin(),vowels.end(),words[i][0]) != vowels.end() && find(vowels.begin(),vowels.end(),words[i][words[i].size() - 1]) != vowels.end());
        }
        vector<int> result(qn);
        for(int i = 0; i < qn; ++i){
            result[i] = cumSum[queries[i][1]];
            if (queries[i][0] > 0) result[i] -= cumSum[queries[i][0] - 1];
        }
        return result;
    }
};