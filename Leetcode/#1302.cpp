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
    int findDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int left = findDepth(root->left);
        int right = findDepth(root->right);

        return 1 + max(left, right);
    }

    int deepestLeavesSum(TreeNode* root) {
        int depth = findDepth(root);
        int result = 0, level = 0;
        queue<TreeNode*> track;
        track.push(root);
        
        while(!track.empty()) {
            int size = track.size();
            level++;
            for(int i = 0; i < size; i++) {
                TreeNode* cLast = track.front();
                track.pop();

                if(level == depth && cLast->left == nullptr && cLast->right == nullptr) {
                    result += cLast->val;
                }                    

                if(cLast->left != nullptr) track.push(cLast->left);
                if(cLast->right != nullptr) track.push(cLast->right);
            }
        }

        return result;
    }
};
//TC - O(n) [DFS] + O(n) [BFS]
//SC - O(n) + O(w)