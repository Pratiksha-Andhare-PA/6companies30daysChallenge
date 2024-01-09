class Solution {
public:
    /*
    //brute force approach
    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                int last = -1;
                bool flag = true;
                for(int k = 0; k < n; k++){
                    if(k >= i && k <= j){
                        continue;
                    }
                    if(last >= nums[k]){
                        flag = false;
                        break;
                    }
                    last = nums[k];
                }
                if(flag){
                    ans++;
                }
            }
        }
        return ans;
    }*/


    //Optimized approach => O(N)
    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();
        int right = n - 1;
        while (right && nums[right - 1] < nums[right]) {
            right--;
        }

        if (right == 0) {
            return (long long)(n + 1) * n / 2;
        }

        long long ans = n - right + 1;
        for (int left = 0; left == 0 || nums[left - 1] < nums[left]; left++) {
            while (right < n && nums[left] >= nums[right]) {
                right++;
            }
            ans += n - right + 1;
        }
        return ans;
    }
};
