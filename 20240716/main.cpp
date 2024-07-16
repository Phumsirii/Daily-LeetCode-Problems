#include <bits/stdc++.h>
using namespace std;

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
    string pathToNode(TreeNode* node,int value){
        if (!node) return "F"; //Failed to find the value
        if (node->val==value) return "";
        string leftTry="L"+pathToNode(node->left,value);
        string rightTry="R"+pathToNode(node->right,value);
        if (leftTry.back()=='F') return rightTry;
        return leftTry;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string rootToStart=pathToNode(root,startValue);
        string rootToDest=pathToNode(root,destValue);
        while(rootToStart.front()==rootToDest.front()){
            rootToStart=rootToStart.substr(1,rootToStart.length()-1);
            rootToDest=rootToDest.substr(1,rootToDest.length()-1);
        }
        string startToIntersect=string(rootToStart.length(),'U');
        return startToIntersect+rootToDest;
    }
};
int main(){

}