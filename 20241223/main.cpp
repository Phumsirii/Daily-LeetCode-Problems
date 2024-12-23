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
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> tmpNodes;
        tmpNodes.push(root);
        int result = 0;
        while(!tmpNodes.empty()){
            int levelSize = tmpNodes.size();
            vector<int> levelValues(levelSize);
            for(int i = 0; i < levelSize; i++){
                TreeNode* node = tmpNodes.front();
                tmpNodes.pop();
                levelValues[i] = node->val;
                if(node->left){
                    tmpNodes.push(node->left);
                }
                if(node->right){
                    tmpNodes.push(node->right);
                }
            }
            vector<int> sortedLevelValues = levelValues;
            sort(sortedLevelValues.begin(), sortedLevelValues.end());
            unordered_map<int, int> currentIndex;
            for(int i = 0; i < levelSize; i++){
                currentIndex[levelValues[i]] = i;
            }
            for(int i = 0; i < levelSize; i++){
                if (levelValues[i] != sortedLevelValues[i]){
                    ++result;
                    int index = currentIndex[sortedLevelValues[i]];
                    currentIndex[levelValues[i]] = index;
                    swap(levelValues[i], levelValues[index]);
                }
            }
        }
        return result;
    }
};

int main(){
    int n = (2 << 3);
    cout << n<<endl;
}