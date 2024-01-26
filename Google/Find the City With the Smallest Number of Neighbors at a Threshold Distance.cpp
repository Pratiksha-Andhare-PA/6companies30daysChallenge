class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        //2D matrix to store dist of every pt from every other pt
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        for(auto x : edges){
            dist[x[0]][x[1]] = x[2];
            dist[x[1]][x[0]] = x[2];
        }

        //dist to itself Ex : dist[0][0] = 0
        for(int i = 0; i < n; i++){
            dist[i][i] = 0; 
        }

        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(dist[i][k] == INT_MAX || dist[k][j] == INT_MAX){
                        continue;
                    }
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int cntCity = n;
        int cityNo = -1;

        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = 0; j < n; j++){
                if(dist[i][j] <= distanceThreshold){
                    cnt++;
                }
            }
            //city with less no. of connected cities is found
            if(cntCity >= cnt){
                cntCity = cnt;
                cityNo = i;
            }
        }
        return cityNo;
    }
};
