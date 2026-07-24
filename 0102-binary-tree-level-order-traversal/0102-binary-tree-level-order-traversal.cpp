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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode*>q;    // node , level
        q.push(root);

        while(!q.empty()){

            vector<int> res;
            int n = q.size();
            for(int i=0;i<n;i++){
                auto font = q.front();
                q.pop();
                res.push_back(font->val);

                if(font->right) q.push(font->right);
                if(font->left) q.push(font->left);

            }
            reverse(res.begin(),res.end());
            if(res.size()!=0) ans.push_back(res);
        }
    return ans;
    }
};