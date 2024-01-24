class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int mxh = 1, mxv = 1, curr = 1;
        for(int i = 1; i < hBars.size(); i++){
            if(hBars[i] == hBars[i-1] + 1){  // check for adj horizontal bars
                curr++;
            }
            else{
                curr = 1;
            }
            mxh = max(mxh, curr);
        }

        curr = 1;
        for(int i = 1; i < vBars.size(); i++){
            if(vBars[i] == vBars[i-1] + 1){  // check for adj vertical bars
                curr++;
            }
            else curr = 1;
            mxv = max(mxv, curr);
        }
        return min(mxh + 1, mxv + 1) * min(mxh + 1, mxv + 1); // area
    }
};
