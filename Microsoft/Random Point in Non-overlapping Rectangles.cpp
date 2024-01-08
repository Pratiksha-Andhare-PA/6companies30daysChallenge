class Solution {
public:
    vector<vector<int>> rects;
    Solution(vector<vector<int>>& rects) : rects(rects) {
    }
    
    vector<int> pick() {
        vector<int> selected;
        int totalArea = 0;

        for(auto x : rects){
            int area = (x[2] - x[0] + 1)*(x[3] - x[1] + 1);
            totalArea += area;

            if(rand() % totalArea < area){
                selected = x;
            }
        }
        int x = rand() % (selected[2] - selected[0] + 1) + selected[0];
        int y = rand() % (selected[3] - selected[1] + 1) + selected[1];

        return {x, y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
