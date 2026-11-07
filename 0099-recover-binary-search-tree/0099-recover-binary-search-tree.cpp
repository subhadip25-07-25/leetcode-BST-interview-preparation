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
TreeNode*prev = nullptr;
TreeNode*firstV = nullptr;
TreeNode*middleV = nullptr;
TreeNode*lastV = nullptr;
    void findPos(TreeNode* root ){
        if( root == nullptr)return;
        findPos( root->left);
        if( prev !=nullptr && prev->val >= root->val){
            if( firstV==nullptr){// means it the first violation 
               firstV= prev;
               middleV= root;

            }else{
                // its 2nd violation 
                lastV = root;
            }
        }
            prev = root ;
            findPos(root->right);
        
    }
    void recoverTree(TreeNode* root) {
         findPos( root );
         if( lastV== nullptr){
            //means no 2nd violation 
            swap( firstV->val ,middleV->val );
         }else{
            //here is 2nd violation 
            swap ( firstV->val , lastV->val);
         }
    }
};