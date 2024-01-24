class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> ans;
        vector<int> indices_a;
        vector<int> indices_b;

        int sL = s.length();
        int aL = a.length();
        int bL = b.length();

        for(int i = 0; i <= (sL - aL); i++){
            if(s.substr(i, aL) == a){
                indices_a.push_back(i);
            }
        }

        for(int j = 0; j <= (sL - bL); j++){
            if(s.substr(j, bL) == b){
                indices_b.push_back(j);
            }
        }

        for(int i = 0; i < indices_a.size(); i++){
            for(int j = 0; j < indices_b.size(); j++){
                if(abs(indices_a[i] - indices_b[j]) <= k){
                    ans.push_back(indices_a[i]);
                    break;
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
