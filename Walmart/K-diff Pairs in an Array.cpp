class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        set<pair<int, int>> s;

        int ans = 0;
        for(int i = 0; i < nums.size()-1; i++){
            for(int j = i+1; j < nums.size(); j++){
                if(abs(nums[i] - nums[j]) == k){
                    if(nums[i] > nums[j]){
                        s.insert({nums[j], nums[i]});    
                    }
                    else{
                        s.insert({nums[i], nums[j]});
                    }
                }
            }
        }
        return s.size();
    }
};
