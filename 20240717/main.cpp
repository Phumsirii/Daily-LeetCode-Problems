#include <bits/stdc++.h>
using namespace std;


//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    void recur(TreeNode* &node,vector<int> &toDelete,vector<TreeNode*> &result){
        if (!node) return ;
        recur(node->left,toDelete,result);
        recur(node->right,toDelete,result);
        //if this node needs to be deleted
        if (find(toDelete.begin(),toDelete.end(),node->val)!=toDelete.end()){
            if (node->left) result.push_back(node->left);
            if (node->right) result.push_back(node->right);
            node=nullptr;
        }
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> result;
        if (find(to_delete.begin(),to_delete.end(),root->val)==to_delete.end()) result.push_back(root);
        recur(root,to_delete,result);
        return result;
    }
};

int main(){

}