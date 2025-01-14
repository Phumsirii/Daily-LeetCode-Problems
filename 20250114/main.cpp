#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int count = 0;
        unordered_set<int> setA,setB;
        int n = A.size();
        vector<int> result(n);
        for(int i = 0; i < n; ++i){
            setA.insert(A[i]);
            setB.insert(B[i]);
            if(A[i] == B[i]){
                ++count;
            }else{
                if (setB.find(A[i]) != setB.end()) ++count;
                if (setA.find(B[i]) != setA.end()) ++count;
            }
            result[i] = count;
        }
        return result;
    }
};