class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int ans = 0;
        unordered_map<int, vector<int>> mp;
        for(auto x : reservedSeats){
            mp[x[0]].push_back(x[1]);  //mp => [1 : {2, 3, 8}, 2 : {6}, 3 : {1, 10}]
        }
        ans = (n - mp.size())*2;

        for(auto x : mp){
            bool flag = false;
            vector<bool> filled(11, 0);
            for(auto y : x.second){
                filled[y] = 1;
            }
            // 2, 3, 4, 5
            if(!filled[2] && !filled[3] && !filled[4] && !filled[5]){
                ans++;
                flag = true;
            }

            // 6, 7, 8, 9
            if(!filled[6] && !filled[7] && !filled[8] && !filled[9]){
                ans++;
                flag = true;
            }

            // 4, 5, 6, 7
            if(!flag){
                if(!filled[4] && !filled[5] && !filled[6] && !filled[7]){
                    ans++;
                }
            }
        }
        return ans;
    }
};
