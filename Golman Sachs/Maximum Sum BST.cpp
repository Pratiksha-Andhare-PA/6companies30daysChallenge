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

#define pr pair<pair<bool, pair<int, int>>, int> 
int ans;

class Solution {
public:
    pr helper(TreeNode* root){
        if(root == NULL){
            return {{true, {INT_MIN, INT_MAX}}, 0};
        }

        pr leftSubTree = helper(root->left);
        pr rightSubTree = helper(root->right);

        int mxSumLeft = leftSubTree.second;
        int mxSumRight = rightSubTree.second;

        bool isLeftBST = leftSubTree.first.first;
        bool isRightBST = rightSubTree.first.first;

        int leftTreeMin = leftSubTree.first.second.second;
        int leftTreeMax = leftSubTree.first.second.first;

        int rightTreeMin = rightSubTree.first.second.second;
        int rightTreeMax = rightSubTree.first.second.first;

        int treeMax = max(root->val, rightTreeMax);
        int treeMin = min(root->val, leftTreeMin);

        if(isLeftBST && isRightBST && root->val > leftTreeMax && root->val < rightTreeMin){
            int sum = root->val + mxSumLeft + mxSumRight;
            ans = max({ans, mxSumLeft, mxSumRight, sum});

            return {{true, {treeMax, treeMin}}, sum};
        }

        //Not a BST
        int sum = max(mxSumLeft, mxSumRight);
        ans = max(ans, sum);
        return {{false,{treeMax, treeMin}}, sum};
    }

    int maxSumBST(TreeNode* root) {
        ans = 0;
        helper(root);
        return ans;
    }
};
