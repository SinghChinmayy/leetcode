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
    int maxDepth(TreeNode* root) {
        // base case => beyond the leaf node
        if(root == NULL) return 0;

        // counting child nodes
        int left_count = maxDepth(root->left);
        int right_count = maxDepth(root->right);
        return left_count > right_count ? left_count + 1 : right_count + 1;
    }
};