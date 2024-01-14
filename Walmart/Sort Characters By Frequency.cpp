class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(auto x : s){
            mp[x]++;
        }
        vector<pair<int, int>> v;
        for(auto x : mp){
            v.push_back({x.second, x.first});
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        string ans = "";
        for(auto x : v){
            while(x.first--){
                ans += x.second;
            }
        }
        return ans;
    }
};
