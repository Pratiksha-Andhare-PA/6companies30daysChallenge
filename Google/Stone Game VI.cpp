class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        priority_queue<pair<int, pair<int,int>>> pq;

        int Alice=0, Bob=0;

        for(int i=0; i<aliceValues.size(); i++){
            pq.push({aliceValues[i]+bobValues[i], {aliceValues[i], bobValues[i]}});
        }

        while(!pq.empty()){
            Alice += pq.top().second.first;
            pq.pop();
            if(!pq.empty()){
                Bob += pq.top().second.second;
                pq.pop();
            }
        }
        if(Alice == Bob){
            return 0;
        }
        if(Alice > Bob){
            return 1;
        }
        return -1;
    }
};
