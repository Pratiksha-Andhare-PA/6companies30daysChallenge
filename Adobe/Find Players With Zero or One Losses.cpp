class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> winner;
        unordered_map<int, int> looser;

        for(auto x : matches){
            winner[x[0]]++;
            looser[x[1]]++;
        }

        vector<vector<int>> ans(2);
        for(auto x : winner){
            if(looser.find(x.first) == looser.end()){ // Won all the matches
                ans[0].push_back(x.first);
            }
        }
        for(auto x : looser){
            if(x.second == 1){ // Lost only 2 match
                ans[1].push_back(x.first);
            }
        }
        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());
        
        return ans;
    }
};
