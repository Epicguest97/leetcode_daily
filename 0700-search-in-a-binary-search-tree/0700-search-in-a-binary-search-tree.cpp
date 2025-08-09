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
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* res = bst(root,val);
        return res;
    }
private:
    TreeNode* bst(TreeNode* root,int val){
        if (!root) return nullptr; 
        if(val==root->val)return root;
        if(val<root->val){
            return bst(root->left,val);
        }
        else{
            return bst(root->right,val);
        }
        return nullptr;
    }
};