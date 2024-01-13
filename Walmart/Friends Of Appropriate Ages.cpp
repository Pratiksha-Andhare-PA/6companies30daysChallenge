class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int n = ages.size();
        sort(ages.begin(), ages.end());

        int ans = 0;
        unordered_map<int, int> mp;
        for(int i = n-1; i >= 0; i--){
            if(ages[i] <= 14){ // acc to constraint
                break;
            }
            int temp = 0.5 * ages[i] + 7; // min age to send a frnd request
            int y = upper_bound(ages.begin(), ages.end(), temp) - ages.begin();

            ans += (i - y);
            ans += mp[ages[i]];
            mp[ages[i]]++;
        }
        return ans;
    }
};
