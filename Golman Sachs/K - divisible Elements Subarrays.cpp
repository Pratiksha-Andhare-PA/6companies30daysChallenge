class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>> s;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            vector<int> arr;
            int divByP = 0;
            for(int j = i; j < n; j++){
                arr.push_back(nums[j]);
                if(nums[j] % p == 0){
                    divByP++;
                }
                if(divByP > k){
                    break;
                }
                s.insert(arr);
            }
        }
        return s.size();
    }
};
