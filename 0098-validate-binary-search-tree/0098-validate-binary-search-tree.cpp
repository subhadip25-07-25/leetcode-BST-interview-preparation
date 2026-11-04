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
  
    bool RangeBasedChecking( TreeNode* root , long long minrange , long long maxrange ){
        if(root == nullptr) return true;
            if( root ->val >= maxrange || root ->val <= minrange)return false ;
             bool left = RangeBasedChecking( root ->left , minrange , root ->val);
              bool  right = RangeBasedChecking( root->right , root->val , maxrange );
            return ( left && right);
    }
    bool isValidBST(TreeNode* root) {
       return  RangeBasedChecking( root  , LONG_MIN , LONG_MAX);
    }
};