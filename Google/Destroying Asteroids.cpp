class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());

        if(mass < asteroids[0]) return false;
        long long wt = mass;
        int n = asteroids.size();
        for(int i = 0; i < n; i++){
            if(wt < asteroids[i]) return false;
            wt += asteroids[i];
        }
        return true;
    }
};
