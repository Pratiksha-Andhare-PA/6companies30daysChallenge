class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefixCount(n + 1, 0);
        prefixCount[0] = 1; // Initialize with 1 to cover the case when there are k odd numbers from the beginning

        int oddCount = 0, ans = 0;

        for (int i = 0; i < n; i++) {
            oddCount += nums[i] % 2;

            if (oddCount >= k) {
                ans += prefixCount[oddCount - k];
            }

            prefixCount[oddCount]++;
        }

        return ans;
    }
};
