class Solution {
public:
    int f(int i, string &s, unordered_map<string, int> &mp, vector<int> &dp){
        if(i >= s.size()) return 0;
        if(dp[i] != -1) return dp[i];

        int ans = s.size();
        string str = "";
        for(int idx = i; idx < s.size(); idx++){
            str += s[idx];
            int extra = str.size();
            if(mp.find(str) != mp.end()){
                extra = 0;
            }
            int nextSearch = f(idx+1, s, mp, dp);
            ans = min(ans, extra+nextSearch);
        }
        return dp[i] = ans;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_map<string, int> mp;
        vector<int> dp(s.size(), -1);
        for(auto x : dictionary){
            mp[x] = 1;
        }
        return f(0, s, mp, dp);
    }
};
