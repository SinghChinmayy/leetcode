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
// assume are different keeps track of if they are different; but does not tell if they are same
int are_diff = 0;
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // handling null
        if(p == nullptr && q == nullptr) return true;
        if(p == nullptr ) return false;
        if(q == nullptr ) return false;

        // check p == q
        if(are_diff == 1) return false;
        if(p->val != q->val){
            are_diff = 1;
            return false;
            }
        bool l_check = isSameTree(p->left, q->left);
        bool r_check = isSameTree(p->right, q->right);
        if(l_check == false || r_check == false) return false;
        return true;
    }
};