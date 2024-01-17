class Solution {
public:
    vector<vector<int>> dp;
    int mod = 1e9 + 7;

    int solve(vector<int> &nums, int prevIdx, int currIdx, int mask){
        if(currIdx == nums.size()){
            return 1;
        }
        if(dp[prevIdx+1][mask] != -1){
            return dp[prevIdx + 1][mask];
        }
        int ans = 0;
        for(int j = 0; j < nums.size(); j++){
            if((mask & (1 << j)) > 0){  // jth bit is sey => included
                continue;
            }
            if(prevIdx == -1 || nums[prevIdx] % nums[j] == 0 || nums[j] % nums[prevIdx] == 0){
                ans = (ans + solve(nums, j, currIdx + 1, mask | (1 << j))) % mod;
            } // set the jth bit after using
        }
        return dp[prevIdx + 1][mask] = ans;
    }

    int specialPerm(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n+1, vector<int>(1 << 14, -1));
        return solve(nums, -1, 0, 0);
    }
};
