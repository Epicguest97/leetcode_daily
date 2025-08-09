class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            if (!root->left && !root->right) {
                delete root;
                return nullptr;
            } else if (!root->left) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (!root->right) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            } else {
                TreeNode* succ = getSuccessor(root);
                root->val = succ->val;
                root->right = deleteNode(root->right, succ->val);
            }
        }
        return root;
    }

private:
    TreeNode* getSuccessor(TreeNode* node) {
        TreeNode* curr = node->right;
        while (curr && curr->left) {
            curr = curr->left;
        }
        return curr;
    }
};
