class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i = 0; i < n ; i++){
            if(pq.size()<k){
                pq.push({nums[i],i});
            }
            else if(!pq.empty() && pq.top().first < nums[i]){
                pq.pop();
                pq.push({nums[i], i});
            }
        }
        vector<pair<int, int>> temp;
        while(!pq.empty()){
            temp.push_back({pq.top().second, pq.top().first});
            pq.pop();
        }
        sort(temp.begin(), temp.end());
        
        vector<int> ans;
        for(auto x : temp){
            ans.push_back(x.second);
        }
        
        return ans;
    }
};
