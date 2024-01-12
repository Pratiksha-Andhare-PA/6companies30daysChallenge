class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int sum = 0, rotSum = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            rotSum += nums[i] * i;
        }

        int ans = rotSum;
        for(int i = 1; i < n; i++){
            rotSum += sum - n*nums[n-i];
            ans = max(ans, rotSum);
        }
        return ans;
    }
};
