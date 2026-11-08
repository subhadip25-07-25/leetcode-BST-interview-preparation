/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode *bulidBST( ListNode*&current , int st , int end ){
    if (st > end) return nullptr;
    int mid = st + ( end - st)/2;

    // create the left subtree first 
      TreeNode *leftsubtree = bulidBST( current , st , mid -1);
      TreeNode *root = new TreeNode (current->val);
      current = current->next ;
      root->left = leftsubtree;
     root->right = bulidBST(current, mid + 1, end);
     return root ;
   }
    TreeNode* sortedListToBST(ListNode* head) {
        // find the size 
        int size = 0 ;
        ListNode*temp = head;
        while( temp != nullptr){
            temp = temp->next;
            size++;
        }
         return bulidBST(head ,  0 , size-1);
    }
};