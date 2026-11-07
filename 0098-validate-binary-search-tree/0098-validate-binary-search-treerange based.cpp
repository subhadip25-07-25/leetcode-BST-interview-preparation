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
    bool isValidBST(TreeNode* root) {
        if( root == nullptr)return true;
        if( !isValidBST( root ->left) ){// we can store the value in bool left also 
            return false;
        }
        if( prev != nullptr && prev->val >= root->val){// inorder gives sorted order so prev value alawys smaller then root value 
            return false ;
        }
        prev = root;
         if( !isValidBST( root ->right) ){
            return false;
        }
        // we can also store in in right and return left&& right
        return true;
    }
};