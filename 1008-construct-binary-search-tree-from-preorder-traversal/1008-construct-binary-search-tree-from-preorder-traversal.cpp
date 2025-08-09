class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index=0;
        return build(preorder,index,INT_MAX);
    }
private:
    TreeNode* build(vector<int>& preorder, int& index, int bound) {
        if (index == preorder.size() || preorder[index] > bound) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[index++]);
        root->left = build(preorder, index, root->val);
        root->right = build(preorder, index, bound);
        return root;
    }
};