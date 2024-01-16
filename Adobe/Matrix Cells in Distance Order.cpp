class Solution {
public:
    static bool compare(pair<pair<int, int>, int> &p1, pair<pair<int, int>, int> &p2){
        return p1.second < p2.second;
    }

    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<pair<pair<int, int>, int>> ans;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                int dist = abs(rCenter-i) + abs(cCenter-j);
                ans.push_back({{i,j}, dist});
            }
        }
        sort(ans.begin(), ans.end(), compare);

        vector<vector<int>> res;
        for(auto x : ans){
            res.push_back({x.first.first, x.first.second});
        }
        return res;
    }
};
