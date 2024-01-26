class Solution {
public:
    void make_xarr(vector<int> &xarr, vector<vector<int>> &buildings){
        for(auto b : buildings){
            xarr.push_back(b[0]);
            xarr.push_back(b[1]);
        }
        unique(begin(xarr), end(xarr));
        sort(begin(xarr), end(xarr));
    }

    int get_max(priority_queue<pair<int, int>> &pq, int x){
        int mxH = 0;
        while(!pq.empty()){
            auto temp = pq.top();
            if(temp.second <= x){
                pq.pop();
            }
            else{
                mxH = temp.first;
                break;
            }
        }
        return mxH;
    }

    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        int n = buildings.size();
        vector<vector<int>> ans;
        vector<int> xarr(2*n);

        make_xarr(xarr, buildings);
        priority_queue<pair<int, int>> pq;
        int prevH = 0, i = 0;
        for(auto it : xarr){
            while(i < n && buildings[i][0] == it){
                pq.push({buildings[i][2], buildings[i][1]});
                i++;
            }
            int mxH = get_max(pq, it);
            if(prevH != mxH){
                ans.push_back(vector<int> {(int)it, mxH});
            }
            prevH = mxH;
        }
        return ans;
    }
};
