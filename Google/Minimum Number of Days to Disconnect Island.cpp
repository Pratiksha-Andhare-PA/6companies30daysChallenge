class Solution {
public:
    int totalLand(vector<vector<int>> &grid){
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int cnt = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    visited[i][j] = 1;
                    cnt++;

                    while(!q.empty()){
                        int row = q.front().first;
                        int col = q.front().second;
                        q.pop();

                        int delRow[] = {-1, 0, 1, 0};
                        int delCol[] = {0, 1, 0, -1};

                        for(int i = 0; i < 4; i++){
                            int nRow = row + delRow[i];
                            int nCol = col + delCol[i];
                            
                            if(nRow >= 0 && nRow < grid.size() && nCol >= 0 && nCol < grid[0].size() && !visited[nRow][nCol] && grid[nRow][nCol] == 1){
                                q.push({nRow, nCol});
                                visited[nRow][nCol] = 1;
                            }
                        }
                    }
                }
            }
        }
        return cnt;
    }

    int minDays(vector<vector<int>>& grid) {
        int initialLand = totalLand(grid);
        if(initialLand == 0 || initialLand >= 2) return 0;

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    grid[i][j] = 0;

                    int newLand = totalLand(grid);
                    if(newLand != 1) return 1;
                    grid[i][j] = 1;
                }
            }
        }
        return 2;
    }
};
