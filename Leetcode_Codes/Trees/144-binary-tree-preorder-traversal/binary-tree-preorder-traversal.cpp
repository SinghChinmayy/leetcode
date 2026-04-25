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
    vector<int> preorderTraversal(TreeNode* root) {
        // base case 
        if(root == NULL) return {};
        stack<TreeNode*> st;
        vector<int> result;
        st.push(root);
        TreeNode* current = st.top();
        while(!st.empty()){
            result.push_back(current->val);
            if(current->right != NULL) st.push(current->right);
            if(current->left != NULL){
                current = current->left;
            }else{
                current = st.top();
                st.pop();
            }
        }
        return result;
    }
};