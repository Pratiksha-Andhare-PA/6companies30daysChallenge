class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        unordered_map<string, int> mp;
        for(auto x : wordDict){
            mp[x]++;
        }
        vector<bool> dp(n+1, false);
        dp[0] = true;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < i; j++){
                if(dp[j] && mp.find(s.substr(j, i-j)) != mp.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
