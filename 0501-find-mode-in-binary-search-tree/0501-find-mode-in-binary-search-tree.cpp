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
    int prev = 0;
    int count = 0;
    int maxCount = 0;
    bool hasPrev = false;

    vector<int> ans;

    void helper(TreeNode* root) {
        if (root == nullptr) return;

        // 1. Visit left subtree
        helper(root->left);

        // 2. Process current node
        int curr = root->val;

        if (hasPrev && prev == curr) {
            count++;
        } 
        else {
            count = 1;
        }

        // 3. Update maximum frequency
        if (count > maxCount) {
            maxCount = count;
            ans.clear();
            ans.push_back(curr);
        }
        else if (count == maxCount) {
            ans.push_back(curr);
        }

        prev = curr;
        hasPrev = true;

        // 4. Visit right subtree
        helper(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        helper(root);
        return ans;
    }
};