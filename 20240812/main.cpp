#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(int &num:nums){
            pq.push(num);
            if (pq.size()>k) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size()>k) pq.pop();
        return pq.top();
    }
};