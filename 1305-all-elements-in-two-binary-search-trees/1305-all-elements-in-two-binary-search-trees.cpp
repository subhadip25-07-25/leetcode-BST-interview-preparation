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
    vector<int> ans;
  void mergeTwoarray(vector<int>& v1, vector<int>& v2) {
        int i = 0;
        int j = 0;
        int size1 = v1.size();
        int size2 = v2.size();
        while (i < size1 && j < size2) {
            if (v1[i] > v2[j]) {
                ans.push_back(v2[j]);
                j++;
            } else {
                ans.push_back(v1[i]);
                i++;
            }
        }
        while (i < size1) {
            ans.push_back(v1[i]);
            i++;
        }
        while (j < size2) {
            ans.push_back(v2[j]);
            j++;
        }
    }
    void inorder(TreeNode* root, vector<int>& v1) {
        if (root == nullptr) {
            return;
        }
        inorder(root->left, v1);
        v1.push_back(root->val);
        inorder(root->right, v1);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v1;
        vector<int> v2;
        inorder(root1, v1);
        inorder(root2, v2);
        mergeTwoarray( v1 ,v2);
        return ans;
    }
};