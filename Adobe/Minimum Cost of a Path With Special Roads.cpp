class Solution {
public:
     const int INF = 1e9+10;
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        int n=specialRoads.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        vector<int> dist(n,INF);
        
        for(int i=0;i<n;i++){
            dist[i]=abs(specialRoads[i][0]-start[0])+abs(specialRoads[i][1]-start[1])+specialRoads[i][4];
            pq.push({dist[i],i});
        }
        
        int res=abs(target[0]-start[0])+abs(target[1]-start[1]);
        
        while(!pq.empty()){
            auto [total_dist,i] = pq.top();
            pq.pop();
            
            if(total_dist!=dist[i])  continue;
            res=min(res,total_dist+abs(specialRoads[i][2]-target[0])+abs(specialRoads[i][3]-target[1]));
            
            for(int nxt=0;nxt<n;nxt++){
                int val=total_dist+abs(specialRoads[i][2]-specialRoads[nxt][0])+abs(specialRoads[i][3]-specialRoads[nxt][1])+specialRoads[nxt][4];
                if(val < dist[nxt]){
                    dist[nxt]=val;
                    pq.push({dist[nxt],nxt});
                }
            }
        }
        return res;
    }
};
