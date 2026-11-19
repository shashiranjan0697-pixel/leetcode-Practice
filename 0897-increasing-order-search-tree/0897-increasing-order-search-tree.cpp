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
    void dfs(TreeNode* root,vector<int>& traverse){
        if(!root) return;

        traverse.push_back(root->val);
        dfs(root->left, traverse);
        dfs(root->right, traverse);        

    }

    TreeNode* increasingBST(TreeNode* root) {
        vector<int> traverse;
        dfs(root, traverse);

        sort(traverse.begin(), traverse.end());

        TreeNode* dummy = new TreeNode(-1);
        TreeNode* temp = dummy;

        for(int i=0; i<traverse.size(); i++) {
            temp->right = new TreeNode(traverse[i]);
            temp = temp->right;
        }
    return dummy->right;
    }
};