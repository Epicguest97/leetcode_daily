class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> list;
        inorder(root, list);

        int left = 0, right = list.size() - 1;
        while (left < right) {
            int sum = list[left] + list[right];
            if (sum == k) return true;
            else if (sum < k) left++;
            else right--;
        }
        return false;
    }

private:
    void inorder(TreeNode* root, vector<int>& list) {
        if (!root) return;
        inorder(root->left, list);
        list.push_back(root->val);
        inorder(root->right, list);
    }
};
