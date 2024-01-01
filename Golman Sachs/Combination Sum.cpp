class Solution {
public:
    vector<vector<int>> ans;
    void Solve(vector<int> &arr, int i, int k, int n){
        if(arr.size() == k && n == 0){
            ans.push_back(arr);
            return;
        }
        if(arr.size() == k && n != 0){
            return;
        }

        for(int j = i; j <= 9; j++){
            arr.push_back(j);
            Solve(arr, j+1, k, n-j);
            arr.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr;
        Solve(arr, 1, k, n);
        return ans;
    }
};
