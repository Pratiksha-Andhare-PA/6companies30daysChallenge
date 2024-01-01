class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        unordered_map<string, vector<int>> mp;
        for(int i = 0; i < access_times.size(); i++){
            mp[access_times[i][0]].push_back(stoi(access_times[i][1]));
        }
        for(auto x : mp){
            sort(x.second.begin(), x.second.end());
        }

        vector<string> ans;
        for(auto x : mp){
            vector<int> temp = x.second;
            sort(temp.begin(), temp.end());
            for(int i = 2; i < temp.size(); i++){
                if(temp[i] - temp[i-2] < 100){
                    ans.push_back(x.first);
                    break;
                }
            }
        }
        return ans;
    }
};
