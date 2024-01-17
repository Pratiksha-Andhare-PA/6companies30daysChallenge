class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> v = nums;
        priority_queue<pair<int, int>> pq;

        pq.push({v[0], 0});
        int ans = v[0];

        for(int i = 1; i < n; i++){
            while(!pq.empty() && (i - pq.top().second > k)){
                pq.pop();
            }

            v[i] = max(v[i], v[i] + pq.top().first);
            pq.push({v[i], i});

            ans = max(ans, v[i]);
        }
        return ans;
    }
};
