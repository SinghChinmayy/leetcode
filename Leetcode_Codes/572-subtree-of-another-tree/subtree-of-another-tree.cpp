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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // base conditions
        // when root is null->full itteration done and subroot not found
        if(root == nullptr)return false;

        // 1.check current node
        // 2.a.current node matches
        // -> do full subtree match
        if(root->val == subRoot->val){
            // full sub tree matching
            bool isMatch = treeMatch(root, subRoot);
            if(isMatch)return true;
        }
        // 2.b.current node does not give a match
        // ->move to next element of tree
        bool l_check = isSubtree(root->left, subRoot); 
        bool r_check = isSubtree(root->right, subRoot); 
        if(l_check || r_check) return true;
        
        return false;
    }
    bool treeMatch(TreeNode* root, TreeNode* subRoot){
        //base case
        // when both tree and abutree terminates completly
        if(root == nullptr && subRoot == nullptr) return true;
        // case when one ends and other doesnt ->one left incomplete
        if(root == nullptr || subRoot == nullptr) return false;

        // when nodes match recursively check its children
        if(root->val == subRoot->val){
            bool l_check = treeMatch(root->left, subRoot->left); 
            bool r_check = treeMatch(root->right, subRoot->right); 
            if(l_check && r_check) return true;
        }
        return false;
    }
};