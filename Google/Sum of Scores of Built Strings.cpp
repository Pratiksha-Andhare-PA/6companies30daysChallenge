class Solution {
public:
    vector<long long> helper(string str){
        long long n = str.length();
        long long l = 0, r = 0;

        vector<long long> zarr(n);
        for(long long i = 1; i < n; i++){
            if(i > r){
                l = r = i;
                while(r < n && str[r] == str[r - l]){
                    r++;
                }
                zarr[i] = r - l;
                r--;
            }
            else{
                long long idx = i - l;
                if(i + zarr[idx] <= r){
                    zarr[i] = zarr[idx];
                }
                else{
                    l = i;
                    while(r < n && str[r] == str[r - l]){
                        r++;
                    }
                    zarr[i] = r - l;
                    r--;
                }
            }
        }
        return zarr;
    }

    long long sumScores(string s) {
        vector<long long> zarr = helper(s);
        return accumulate(zarr.begin(), zarr.end(), 0LL) + s.length();
    }
};
