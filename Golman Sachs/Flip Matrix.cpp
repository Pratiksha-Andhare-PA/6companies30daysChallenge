class Solution {
    set<int> s;
    int m, n, p;
public:
    Solution(int m, int n) {
        this->m = m;
        this->n = n;
        this->p = m*n;
    }
    
    vector<int> flip() {
        int random = rand()%p;
        // generate random no. until new index not generated 
        while(s.find(random) != s.end()){
            random = rand()%p;
        }
        s.insert(random);
        int r = random/n;
        int c = random%n;

        return {r, c};
    }
    
    void reset() {
        s.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
