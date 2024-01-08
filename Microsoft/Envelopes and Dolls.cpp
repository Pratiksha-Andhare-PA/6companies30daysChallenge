class Solution {
public:
    static bool compare(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        if (n == 0) {
            return 0;
        }

        sort(envelopes.begin(), envelopes.end(), compare);

        vector<int> dp;
        for (const auto& env : envelopes) {
            auto it = lower_bound(dp.begin(), dp.end(), env[1]);
            if (it == dp.end()) {
                dp.push_back(env[1]);
            } else {
                *it = env[1];
            }
        }
        return dp.size();
    }
};
