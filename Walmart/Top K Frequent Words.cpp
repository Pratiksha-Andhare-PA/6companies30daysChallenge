class Solution {
public:
    static bool compare(pair<string, int>&p1, pair<string, int>&p2){
        if(p1.second == p2.second){
            return p1.first < p2.first;
        }
        return p1.second > p2.second;
    }

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for(auto x : words){
            mp[x]++;
        }

        vector<pair<string, int>> freqEle(mp.begin(), mp.end());
        sort(freqEle.begin(), freqEle.end(), compare);

        vector<string> ans;
        for(int i = 0; i < k && i < freqEle.size(); i++){
            ans.push_back(freqEle[i].first);
        }
        return ans;
    }
};
