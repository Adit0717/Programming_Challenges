/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> result;
    int height(TreeNode* root) {
        if(root == nullptr) return -1;

        int leftH = height(root->left);
        int rightH = height(root->right);

        int currH = 1 + max(leftH, rightH);

        if(result.size() == currH) {
            result.push_back({});
        }

        result[currH].push_back(root->val);
        return currH;
    }

    vector<vector<int>> findLeaves(TreeNode* root) {        
        height(root);
        return result;
    }
};