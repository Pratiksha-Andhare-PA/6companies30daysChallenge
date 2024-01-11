class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, 1), hash(n+1);
        int maxi = 1, lastIdx = 0;

        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            hash[i] = i;
            for(int j = 0; j < i; j++){
                if(nums[i]%nums[j] == 0 && dp[i] < dp[j]+1){
                    dp[i] = dp[j] + 1;
                    hash[i] = j;
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
                lastIdx = i;
            }
        }
        vector<int> v;
        while(hash[lastIdx] != lastIdx){
            v.push_back(nums[lastIdx]);
            lastIdx = hash[lastIdx];
        }
        v.push_back(nums[lastIdx]);
        reverse(v.begin(), v.end());
        return v;
        
    }
};
