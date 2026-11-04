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
    int ans = INT_MAX;
    int prev = -1;
    void  findmindiff( TreeNode* root){
        if( root == nullptr)return;
        findmindiff( root->left);
        int curr = root->val;
        if( prev != -1 ){
            int mindiff = curr - prev;
        
        ans = min( ans , mindiff);
        }
        prev = curr ;
        findmindiff( root->right);
    }
    int getMinimumDifference(TreeNode* root) {
       
        findmindiff( root);
        return ans;
    }
};