class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> mpSec;
        unordered_map<char, int> mpGs;

        int n = secret.length(), bulls = 0;
        for (int i = 0; i < n; i++) {
            if (secret[i] == guess[i]) {
                bulls++;
            } else {
                mpSec[secret[i]]++;
                mpGs[guess[i]]++;
            }
        }

        int cows = 0;
        for(auto &[key, val] : mpSec){
            cows += min(val, mpGs[key]);
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
