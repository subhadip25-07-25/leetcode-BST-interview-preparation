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
    int maxsum = 0;
    class nodeinfo {
    public:
        bool isbst;
        int minval;
        int maxval;
        int sum;
        nodeinfo(bool currbst, int currminval, int currmaxval, int currsum) {
            isbst = currbst;
            minval = currminval;
            maxval = currmaxval;
            sum = currsum;
        }
    };
    nodeinfo helper(TreeNode* root) {
        if (root == nullptr) {
            return {true, INT_MAX, INT_MIN, 0};
        }
        nodeinfo left = helper(root->left);
        nodeinfo right = helper(root->right);
        // now we validate the current node
        if (left.isbst == true && right.isbst == true &&
            root->val < right.minval && root->val > left.maxval) {
            // we add sum
            int currsum = root->val + left.sum + right.sum;
            maxsum = max(maxsum, currsum);
            int currmin = min(root->val, left.minval);
            int currmax = max(root->val, right.maxval);
            return nodeinfo(true, currmin, currmax, currsum);
        } else {
            // invalid case
            return nodeinfo(false, INT_MIN, INT_MAX, 0);
        }
    }
    int maxSumBST(TreeNode* root) {
        helper(root);
        return maxsum;
    }
};