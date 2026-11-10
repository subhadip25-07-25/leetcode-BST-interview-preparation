/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorder;
    TreeNode* makeBST(vector<int>& inorder, int st, int end) {
     
        if( st > end ){
            return nullptr;
        }
        int mid = st + (end - st) / 2;
        TreeNode* root = new TreeNode(inorder[mid]);
        root->left = makeBST( inorder , st , mid- 1);
        root->right = makeBST( inorder , mid+1 , end);
        return root ;
    }
    void construct(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        construct(root->left);
        inorder.push_back(root->val);
        construct(root->right);
    }
    TreeNode* balanceBST(TreeNode* root) { 
        construct(root);
        int end = inorder.size()-1;
      return   makeBST( inorder , 0 , end);
         }
};