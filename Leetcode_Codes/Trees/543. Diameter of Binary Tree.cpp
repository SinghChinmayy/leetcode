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
    int diameterOfBinaryTree(TreeNode* root) {
        // base case
        if(root == NULL) return 0;
        
        // find for current node
        int current_length = 0;

        int left_longest = FindDepth(root->left);
        int right_longest = FindDepth(root->right);
        current_length = left_longest + right_longest;
        
        int l_child_longest = diameterOfBinaryTree(root->left);
        int r_child_longest = diameterOfBinaryTree(root->right);
        if(current_length > l_child_longest && current_length > r_child_longest) return current_length;
        else if(l_child_longest > r_child_longest) return l_child_longest;
        else return r_child_longest;
    }
    int FindDepth(TreeNode* root){
        // base case
        if(root == NULL) return NULL;

        int left_depth = FindDepth(root->left);
        int right_depth = FindDepth(root->right);

        return left_depth > right_depth ? left_depth + 1 : right_depth + 1;
    }
};