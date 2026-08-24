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
    void inOrder(TreeNode* root,vector<pair<int,TreeNode*>> & ino){
        TreeNode* temp = root;
        if(!temp) return;
        inOrder(temp->left, ino);
        ino.push_back({temp->val, temp});
        inOrder(temp->right, ino);
    }
    void recoverTree(TreeNode* root) {
        vector<pair<int,TreeNode*> >ino;
        inOrder(root, ino);
        vector<int>cino;
        for(auto ele : ino){
            cino.push_back(ele.first);
        }
        sort(cino.begin(), cino.end());
        int f1 = -1, f2 = -1;

        for(int i = 0; i < ino.size(); i++) {
            if(ino[i].first != cino[i]) {
                if(f1 == -1)
                    f1 = i;
                else
                    f2 = i;
            }
        }
    swap(ino[f1].second->val, ino[f2].second->val);
    }
};