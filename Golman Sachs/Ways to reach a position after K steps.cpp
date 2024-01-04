class Solution {
public:
    int mod = 1e9+7;
    long long dp[4011][2011];
    int Ways(int startPos, int endPos, int idx, int k){
        if(idx > k){
            return 0;
        }
        if(idx == k){
            return startPos == endPos;
        }
        if(dp[startPos + 1001][idx] != -1){
            return (dp[startPos + 1001][idx]) % mod;
        }

        long long right = Ways(startPos+1, endPos, idx+1, k);
        long long left = Ways(startPos-1, endPos, idx+1, k);

        return dp[startPos + 1001][idx] = (left + right)%mod;
    }

    int numberOfWays(int startPos, int endPos, int k) {
        memset(dp, -1, sizeof(dp));
        return (int)Ways(startPos, endPos, 0, k);
    }
};
