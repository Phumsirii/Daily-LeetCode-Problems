#include <iostream>
#include <queue>
#include <stack>
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
    queue<TreeNode*> tmpQueueOrder;
    vector<TreeNode*> tmpVector;
    TreeNode* reverseOddLevels(TreeNode* root) {
        BFS(root);
        int n = 1;
        while ((1 << n) - 1 < tmpVector.size()){
            int left = (1 << n) - 1;
            int right = (1 << (n+1)) - 2;
            while (left < right){
                swap(tmpVector[left]->val, tmpVector[right]->val);
                left++;
                right--;
            }
            n += 2;
        }
        return root;
    }

    void BFS(TreeNode* node){
        if (!node) return;
        tmpQueueOrder.push(node);
        while(!tmpQueueOrder.empty()){
            TreeNode* tmp = tmpQueueOrder.front();
            tmpQueueOrder.pop();
            tmpVector.push_back(tmp);
            if (tmp->left) tmpQueueOrder.push(tmp->left);
            if (tmp->right) tmpQueueOrder.push(tmp->right);
        }
    }
};

int main(){

}