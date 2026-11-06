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
    TreeNode*dummyRoot = new TreeNode(-1);
    void helper( TreeNode* root ){
        if( root == nullptr){
            return ;
        }
        helper( root->left);
        dummyRoot->right = root;
         root->left = nullptr;
        dummyRoot = root;
        helper( root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        // store the dummy root cuz it gonna change 
         TreeNode*ans = dummyRoot;
         helper( root);
         return ans->right;
    }
};