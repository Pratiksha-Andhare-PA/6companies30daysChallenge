class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();
        int ans = 0;
        int left = 0, right = 0;
        int currCost = 0;

        while(right < n){
            currCost += abs(s[right] - t[right]);

            while(left <= right && currCost > maxCost){
                currCost -= abs(s[left] - t[left]);
                left++;
            }
            ans = max(ans, right - left + 1);
            right++;
        }
        return ans;
    }
};
