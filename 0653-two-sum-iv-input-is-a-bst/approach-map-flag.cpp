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
    bool flag = false;

    bool isPresent(TreeNode* root, int k, unordered_map<int, int>& mp) {
        if (root == nullptr) return false;

        isPresent(root->left, k, mp);

        if (mp.count(k - root->val)) {
            flag = true;
            return true;
        }

        mp[root->val]++;
        isPresent(root->right, k, mp);
        return flag;
    }

    bool findTarget(TreeNode* root, int k) {
        unordered_map<int, int> mp;
        return isPresent(root, k, mp);
    }
};