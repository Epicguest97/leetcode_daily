class Solution {
public:
    int maxDiameter = 0;

    int height(TreeNode* node) {
        if (!node) return 0;

        int left = height(node->left);
        int right = height(node->right);

        maxDiameter = max(maxDiameter, left + right); // Update diameter

        return 1 + max(left, right); // Return height
    }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return maxDiameter;
    }
};
