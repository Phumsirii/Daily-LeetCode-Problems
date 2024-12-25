#include <iostream>
#include <vector>
#include <queue>

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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> currentLevel;
        vector<int> result;
        if(root) currentLevel.push(root);
        while(!currentLevel.empty()) {
            int currentCount = currentLevel.size();
            int currentMax = INT_MIN;
            while (currentCount--){
                TreeNode* currentNode = currentLevel.front();
                currentMax = max(currentMax, currentNode->val);
                if (currentNode->left) currentLevel.push(currentNode->left);
                if (currentNode->right) currentLevel.push(currentNode->right);
                currentLevel.pop();
            }
            result.push_back(currentMax);
        }
        return result;
    }
};