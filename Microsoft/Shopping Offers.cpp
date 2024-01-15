class Solution {
public:
    string getKey(vector<int> &needs){
        string key = "";
        for(int i = 0; i < needs.size(); i++){
            key += to_string(needs[i]) + ",";
        }
        return key;
    }

    bool isValidOffer(const vector<int> &offer, vector<int> &needs){
        for(int i = 0; i < needs.size(); i++){
            if(offer[i] > needs[i]){
                return false;
            }
        }
        return true;
    }

    void applyOffer(vector<int> &needs, const vector<int> &offer){
        for(int i = 0; i < needs.size(); i++){
            needs[i] -= offer[i];
        }
    }

    int minCost(vector<int> &price, vector<vector<int>> &special, vector<int> &needs, unordered_map<string, int> &dp){
        string key = getKey(needs);

        if(dp.find(key) != dp.end()){
            return dp[key];
        }

        //cost without using special offer
        int cost = 0;
        for(int i = 0; i < needs.size(); i++){
            cost += needs[i]*price[i];
        }

        for(const vector<int>& offer : special){
            if(isValidOffer(offer, needs)){
                vector<int> updateNeeds(needs);
                applyOffer(updateNeeds, offer);
                
                cost = min(cost, offer.back() + minCost(price, special, updateNeeds, dp)); 
            }
        }
        dp[key] = cost;
        return cost;
    }

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        unordered_map<string, int> dp;
        return minCost(price, special, needs, dp);
    }
};
