class DataStream {
    int k;
    int value;
    int cnt;
public:
    DataStream(int value, int k) {
        this->k = k;
        this->value = value;
        cnt = 0;
    }
    
    bool consec(int num) {
        if(num == value){
            cnt++;
        }
        else{
            cnt = 0;
        }
        return cnt >= k;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */
