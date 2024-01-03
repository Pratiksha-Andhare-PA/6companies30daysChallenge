class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        queue<pair<int, int>> q;

        vector<vector<int>> ans(m, vector<int> (n, -1));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(isWater[i][j] == 1){
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        int currHt = 0;
        while(!q.empty()){
            int levelSize = q.size();

            for(int i = 0; i < levelSize; i++){
                pair<int, int> temp = q.front();
                q.pop();

                vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
                for(auto dir : directions){
                    int new_x = temp.first + dir.first;
                    int new_y = temp.second + dir.second;

                    if(new_x < 0 || new_x >= m || new_y < 0 || new_y >= n || ans[new_x][new_y] != -1){
                        continue;
                    }
                    q.push({new_x, new_y});
                    ans[new_x][new_y] = currHt + 1;
                }
            }
            currHt++;
        }
        return ans;
    }
};
