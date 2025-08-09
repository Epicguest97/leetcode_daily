class Solution {
public:
    vector<int> result;

    vector<int> rightSideView(TreeNode* root) {
        dfs(root, 0);
        return result;
    }

private:
    void dfs(TreeNode* node, int depth) {
        if (!node) return;
        if (depth == result.size()) {
            result.push_back(node->val);
        }
        dfs(node->right, depth + 1);
        dfs(node->left, depth + 1);
    }
};
