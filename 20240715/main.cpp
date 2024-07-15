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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        map<int,pair<int,int>> data; //the value contains the left and right child respectively
        set<int> isParent,isChild; // each parents are inserted,deleted when found a child
        for(vector<int> &x:descriptions){
            int parenti=x[0],childi=x[1];
            //the second child
            if (data.find(parenti)!=data.end()){
                if (x[2]==1) data[parenti].first=childi;
                else data[parenti].second=childi;
            }
            else{ //first child
                if (x[2]==1){
                    data[parenti].first=childi;
                    data[parenti].second=-1;
                }
                else {
                    data[parenti].second=childi;
                    data[parenti].first=-1;
                }
            }
            isParent.insert(parenti);
            isChild.insert(childi);
        }
        vector<int> getRoot;
        std::set_difference(isParent.begin(), isParent.end(), isChild.begin(), isChild.end(), std::back_inserter(getRoot));
        TreeNode* result=new TreeNode(getRoot[0]);
        queue<TreeNode*> treeConstruction;
        treeConstruction.push(result);
        while(!treeConstruction.empty()){
            TreeNode* current=treeConstruction.front();
            int currentValue=current->val;
            if (data.find(currentValue)!=data.end()){ //there is a child of the current Node
                pair<int,int> tmp=data[currentValue];
                //has a left child
                if (tmp.first!=-1){
                    current->left=new TreeNode(tmp.first);
                    treeConstruction.push(current->left);
                } //has a right child
                if (tmp.second!=-1){
                    current->right=new TreeNode(tmp.second);
                    treeConstruction.push(current->right);
                }
            }
            treeConstruction.pop();
        }
        return result;
    }
};
int main(){
    Solution s;

}