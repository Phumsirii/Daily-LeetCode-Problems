#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
}; 
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        int tmp=0;
        ListNode *current=head->next;
        ListNode *newhead,*prev;
        //prev indicates the prev node in the new list
        //deal with the first element
        while(!current && current->val!=0){
            tmp+=current->val;
            current=current->next;
        }
        current=current->next;
        //finish with the head
        newhead=new ListNode(tmp);
        prev=newhead;
        tmp=0;
        while(current){
            while(current->val!=0){
                tmp+=current->val;
                current=current->next;
            }
            current=current->next;
            ListNode *newnode=new ListNode(tmp);
            prev->next=newnode;
            prev=newnode;
            tmp=0;
        }
        return newhead;
    }
};
int main(){
    cout<<"DONE\n";
}