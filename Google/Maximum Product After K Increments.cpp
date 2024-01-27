class Solution {
public:
    int mod = 1e9 + 7;
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto x : nums){
            pq.push(x);
        }

        while(k--){
            int temp = pq.top();
            pq.pop();
            temp++;
            pq.push(temp);
        }

        long long ans = 1;
        while(!pq.empty()){
            ans *= pq.top();
            ans = ans % mod;
            pq.pop();
        }
        return ans;
    }
};
