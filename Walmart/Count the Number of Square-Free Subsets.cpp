class Solution {
public:
    int primeList[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    int checkPrime(int n){
        int ret = 0;
        for(int i = 0; i < 10; i++){
            if(n%primeList[i] == 0){
                n /= primeList[i];
                ret |= 1<<i;
            }
            if(n%primeList[i] == 0) return -1;
        }
        return ret;
    }

    int squareFreeSubsets(vector<int>& nums) {
        int mod = 1e9 + 7, cnt = 0;
        vector<int> bitmap(nums.size());
        for(auto &v : nums){
            auto ret = checkPrime(v);
            if(ret != -1) bitmap[cnt++] = ret;
        }

        int m[1024] = {0};
        int ans = 0;
        while(cnt > 0){
            cnt--;
            for(int k = 0; k < 1024; k++){
                if(m[k] != 0 && (k&bitmap[cnt]) == 0){
                    m[(k|bitmap[cnt])] = (m[(k|bitmap[cnt])] + m[k]) % mod;
                }
            }
            m[bitmap[cnt]]++;
        }
        for(int i = 0; i < 1024; i++){
            ans = (ans + m[i])%mod;
        }
        return ans;
    }
};
