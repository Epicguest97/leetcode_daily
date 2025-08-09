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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        insert(root,val);
        return root;
    }
private:
    void insert(TreeNode*&root,int val){
        TreeNode*temp= new TreeNode(val);
        if(!root){
            root=temp;
            return;
        }
        if(root->val<val && !root->right){
            root->right=temp;
            return;
        }
        if(root->val>val && !root->left){
            root->left=temp;
            return;
        }
        if(root->val<val && root->right)insert(root->right,val);
        if(root->val>val && root->left)insert(root->left,val);
    }
};