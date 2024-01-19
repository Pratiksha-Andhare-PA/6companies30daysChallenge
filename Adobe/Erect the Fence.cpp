class Solution {
public:
    int CW(vector<int> &p1, vector<int> &p2, vector<int> &p3){
        int x1, y1, x2, y2, x3, y3;
        x1 = p1[0], y1 = p1[1];
        x2 = p2[0], y2 = p2[1];
        x3 = p3[0], y3 = p3[1];

        return ((y3-y2)*(x2-x1) - (y2-y1)*(x3-x2));  //((y3-y2)/(x3-x2) - (y2-y1)*(x2-x1));
    }

    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        sort(trees.begin(), trees.end());
        vector<vector<int>> upper;
        vector<vector<int>> lower;

        for(auto tree : trees){
            while(upper.size() > 1 && CW(upper[upper.size()-1], upper[upper.size()-2], tree) > 0){
                upper.pop_back();
            }
            while(lower.size() > 1 && CW(lower[lower.size()-1], lower[lower.size()-2], tree) < 0){
                lower.pop_back();
            }
            upper.push_back(tree);
            lower.push_back(tree);
        }

        vector<vector<int>> ans;
        merge(upper.begin(), upper.end(), lower.begin(), lower.end(), back_inserter(ans));
        auto pts = unique(ans.begin(), ans.end());
        ans.erase(pts, ans.end());

        return ans;
    }
};
