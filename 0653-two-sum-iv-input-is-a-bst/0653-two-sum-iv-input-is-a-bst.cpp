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
 
   bool isPresent(TreeNode* root, int k , unordered_map<int ,int>&mp){
    if( root == nullptr)return false;
    if(isPresent( root->left , k , mp )){
        return true;
    };
    if( mp.count( k - root->val)){
      
        return true ;
    }
    mp[root->val]++;
    return isPresent(root->right , k , mp );
    
   }
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int ,int>mp;
        return ( isPresent(root , k , mp));
    }
};