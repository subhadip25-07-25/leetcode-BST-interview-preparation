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
    vector<TreeNode*>anstree(int st , int end){
        vector<TreeNode*>ans;
        if(st>end){
            ans.push_back(NULL);
            return ans;
        }
        for(int i = st ; i<= end; i++){
         vector  <TreeNode*> leftsubtree= anstree(st, i-1);
          vector <TreeNode*> rightsubtree= anstree(i+1,end);
        
          for(auto left:leftsubtree){
             for(auto right:rightsubtree){
                     TreeNode* root = new TreeNode(i);
                     root->left=left;
                     root->right = right;
                     ans.push_back(root);    
                }
             }
         }
         return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        return anstree(1, n);
    }
};