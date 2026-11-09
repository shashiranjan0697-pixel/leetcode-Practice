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
    void traverse(TreeNode* root, vector<int> &pre) {

        if(!root) return;

        if(!root->left && !root->right){
            pre.push_back(root->val);
        }

        traverse(root->left, pre);
        traverse(root->right, pre);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> pre1;
        vector<int> pre2;

        traverse(root1, pre1);
        traverse(root2, pre2);

    return pre1 == pre2;
    }
};