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
/*   GIVES TLE
class Solution {
public:
 int maxi = -1;
 int mini = -1;

 void findMinMax( TreeNode* root, int key){
       if( root == nullptr)return ;
       if( root->val > key){
            maxi = root->val;
           findMinMax( root->left, key);
       }
       else if( root ->val< key  ){
           mini = root->val;
           findMinMax( root->right , key );
       }
       else{
           mini = root ->val;
           maxi = root->val;
       }

   }
   vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
       vector<vector<int>>ans;
       for( int i = 0 ; i< queries.size(); i++){
           mini = -1;
           maxi = -1;
           findMinMax( root ,queries[i] );
           ans.push_back({mini , maxi});
       }

       return ans ;
   }
};*/
class Solution {
public:
    vector<int> inorder;
    void construct(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        construct(root->left);
        inorder.push_back(root->val);
        construct(root->right);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        construct(root);
        vector<vector<int>> ans;
        for (int i = 0; i < queries.size(); i++) {
            int lb = lower_bound(inorder.begin(), inorder.end(), queries[i]) -
                     inorder.begin();
                     int mini = -1;
                     int maxi = -1;
                     int key = queries[i];
            // lb gives equals or just greater value of key first element
            if (lb< inorder.size() &&  inorder[lb] == key) {
                 mini = inorder[lb];
                 maxi = inorder[lb];
            } else {
                if( lb < inorder.size()){
                   maxi= inorder[lb];
                }
                if(lb > 0 ){
                   mini = inorder[lb-1];
                }
            }
            ans.push_back( {mini , maxi});
        }
        return ans;
    }

};