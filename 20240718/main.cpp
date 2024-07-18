#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.*/
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
    int cnt=0,dist;

    void getAllParents(TreeNode* node,map<TreeNode*,TreeNode*> &getParent){
        if (!node) return ;
        if (node->left){
            getParent[node->left]=node;
            getAllParents(node->left,getParent);
        }
        if (node->right){
            getParent[node->right]=node;
            getAllParents(node->right,getParent);
        }
        return ;
    }

    bool isLeaf(TreeNode* node){
        if (!node) return false;
        return !(node->left) && !(node->right);
    }

    int bfs(TreeNode* prev,TreeNode* current,int distFromStart,map<TreeNode*,TreeNode*> &getParent){
        if (distFromStart>dist) return 0;
        if (prev && isLeaf(current)) return 1;
        int ans=0;
        if (current->left && current->left!=prev){
            ans+=bfs(current,current->left,distFromStart+1,getParent);
        }
        if (current->right && current->right!=prev) {
            ans+=bfs(current,current->right,distFromStart+1,getParent);
        }
        if (getParent[current] && getParent[current]!=prev) {
            ans+=bfs(current,getParent[current],distFromStart+1,getParent);
        }
        return ans;
    }

    void operate(TreeNode* node,map<TreeNode*,TreeNode*> &getParent){
        if (!node) return;
        if (isLeaf(node)) cnt+=bfs(NULL,node,0,getParent);
        operate(node->left,getParent);
        operate(node->right,getParent);
        return ;
    }

    int countPairs(TreeNode* root, int distance) {
        map<TreeNode*,TreeNode*> getParent;
        getParent[root]=nullptr;
        getAllParents(root,getParent);
        cnt=0;
        dist=distance;
        operate(root,getParent);
        return cnt/2;
    }
};
int main(){

}