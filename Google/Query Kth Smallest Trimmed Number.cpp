class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        for(int i = 0; i < queries.size(); i++){
            int k = queries[i][0];
            int trim = queries[i][1];

            priority_queue<pair<string,int>, vector<pair<string, int>>, greater<pair<string, int>>> pq;
            
            for(int j = 0; j < nums.size(); j++){
                string temp = "";
                for(int l = nums[j].size()-trim; l < nums[j].size(); l++){
                    temp += nums[j][l];
                }
                pq.push({temp, j});
            }
            int idx;
            while(!pq.empty() && k--){
                idx = pq.top().second;
                pq.pop();
            }
            ans.push_back(idx);
        }
        return ans;
    }
};
