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
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> st;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            int rem = k - front->val;
            if( st.count(rem) ) return true;
            else {
                st.insert(front->val);
                if(front->right) q.push(front->right);
                if(front->left) q.push(front->left);
            }
        }
    return false;
    }
};