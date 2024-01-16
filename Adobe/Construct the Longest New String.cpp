class Solution {
public:
    int longestString(int x, int y, int z) {
        int ans = 0;
        int k = min(x, y);

        ans += 4*k; // AA=>2 BB=>2 & k equal no. of pairs

        x -= k;
        y -= k;
        ans += 2*z; 
        // AB can be added at end when string started with AA and ends with BB (AA BB AB) &&
        // AB can be added at start when string ends with AA and started with BB(AB BB AA)
        if(x > 0 || y > 0) ans += 2;
        return ans;        
    }
};
