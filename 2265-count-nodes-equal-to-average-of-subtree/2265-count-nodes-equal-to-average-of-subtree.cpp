class Solution {
public:
    int ans = 0;

    vector<int> dfs(TreeNode* root) {
        if (root == NULL) {
            return {0, 0};
        }

        vector<int> left = dfs(root->left);
        vector<int> right = dfs(root->right);

        int sum = left[0] + right[0] + root->val;
        int count = left[1] + right[1] + 1;

        if (sum / count == root->val) {
            ans++;
        }

        return {sum, count};
    }

    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};