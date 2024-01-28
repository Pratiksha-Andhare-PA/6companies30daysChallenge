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
    int cnt = 0;
    vector<int> helper(TreeNode* root, int dist){
        if(root == NULL) return {0};

        if(root->left == NULL && root->right == NULL) return {1};

        vector<int> left = helper(root->left, dist);
        vector<int> right = helper(root->right, dist);

        for(int x : left){
            for(auto y : right){
                if(x > 0 && y > 0){
                    if(x + y <= dist) cnt++;
                }
            }
        }

        vector<int> ans;
        for(int x : left){
            if(x > 0 && x < dist){
                ans.push_back(x + 1);
            }
        }
        for(int x : right){
            if(x > 0 && x < dist){
                ans.push_back(x + 1);
            }
        }
        return ans;
    }

    int countPairs(TreeNode* root, int distance) {
        helper(root, distance);
        return cnt;
    }
};
