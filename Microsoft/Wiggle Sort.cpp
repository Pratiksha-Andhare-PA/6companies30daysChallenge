class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        /*
        //using priority queue
        int n = nums.size();
        priority_queue<int> pq;
        for(auto x : nums){
            pq.push(x);
        }

        // larger values at odd position, since nums[0] < nums[1]
        int i = 1;
        while(!pq.empty() && i < n){
            nums[i] = pq.top();
            pq.pop();
            i += 2;
        }

        // smaller values at even position
        i = 0;
        while(!pq.empty() && i < n){
            nums[i] = pq.top();
            pq.pop();
            i += 2;
        }*/

        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        int n = nums.size();
        int j = n-1;

        for(int i = 1; i < n; i += 2){
            nums[i] = temp[j];
            j--;
        }

        for(int i = 0; i < n; i += 2){
            nums[i] = temp[j];
            j--;
        }
    }
};
