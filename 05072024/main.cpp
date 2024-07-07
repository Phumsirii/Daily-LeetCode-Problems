#include <bits/stdc++.h>
using namespace std;
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans={1000000,-1};
        //position of first or lastest local critical points
        int first,latest,it=1;
        ListNode *current=head->next,*prev=head;
        //find the first one
        bool firstfound=false;
        while(current->next!=nullptr){
            //found the first critical
            if ((current->val<prev->val && current->val<current->next->val)||(current->val>prev->val && current->val>current->next->val)){
                first=it;
                latest=it;
                firstfound=true;
            }
            ++it;
            prev=current;
            current=current->next;
            if (firstfound) break;
        }
        //no critical points found
        if (!firstfound) return vector<int> {-1,-1};
        while(current->next!=nullptr){
            //found critical
            if ((current->val<prev->val && current->val<current->next->val)||(current->val>prev->val && current->val>current->next->val)){
                ans[0]=min(ans[0],it-latest);
                latest=it;
            }
            ++it;
            prev=current;
            current=current->next;
        }
        if (ans[0]==1000000) return vector<int> {-1,-1};
        ans[1]=latest-first;
        return ans;
    }
};
int main(){

}