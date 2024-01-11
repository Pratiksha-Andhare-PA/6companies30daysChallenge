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
    int mxDist = 0;
    int traverse(TreeNode* root, int start){
        if(root == NULL){
            return 0;
        }
        int leftDepth = traverse(root->left, start);
        int rightDepth = traverse(root->right, start);

        int depth = 0;
        if(root->val == start){
            mxDist = max(leftDepth, rightDepth);
            depth = -1;
        }
        else if(leftDepth >= 0 && rightDepth >= 0){
            depth = max(leftDepth, rightDepth) + 1;
        }
        else{
            int dist = abs(leftDepth) + abs(rightDepth);
            mxDist = max(mxDist, dist);
            depth = min(leftDepth, rightDepth) - 1;
        }
        return depth;
    }

    int amountOfTime(TreeNode* root, int start) {
        traverse(root, start);
        return mxDist;
    }
};
