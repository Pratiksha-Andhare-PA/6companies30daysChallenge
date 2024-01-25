class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int ans = 0, st = 0, en = 0;
        
        while(en < nums.size()){
            if(mp[nums[en]] < k){
                mp[nums[en]]++;
                en++;
            }
            else{
                mp[nums[st]]--;
                st++;
            }
            ans = max(ans, en - st);
        }
        return ans;
    }
};
