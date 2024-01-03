class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        long long ans = 0;
        int mod = 1e9 + 7;
        vector<long long> dp(n+1, 0);
        dp[1] = 1;

        for(int i = 1; i <= n; i++){
            if(dp[i]){
                for(int j = i+delay; j <= min(i+forget-1, n); j++){
                    dp[j] += dp[i];
                    dp[j] %= mod;
                }
            }
        }

        for(int i = n-forget+1; i <= n; i++){
            ans += dp[i];
            ans = ans % mod;
        }
        return ans;
    }
};
