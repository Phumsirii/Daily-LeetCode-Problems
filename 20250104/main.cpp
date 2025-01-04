#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<int> firstIdx(26, -1), lastIdx(26, -1);
        for (int i = 0; i < n; i++) {
            int idx = s[i] - 'a';
            if (firstIdx[idx] == -1) {
                firstIdx[idx] = i;
            }
            lastIdx[idx] = i;
        }
        int result = 0;
        for(int i = 0; i < 26; ++i){
            if (firstIdx[i] == -1) continue;
            unordered_set<int> between;
            for (int j = firstIdx[i] + 1; j < lastIdx[i]; j++) between.insert(s[j] - 'a');
            result += between.size();
        }
        return result;
    }
};