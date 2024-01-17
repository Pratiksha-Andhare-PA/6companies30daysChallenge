class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        for(auto &x : words){
            reverse(x.begin(), x.end());
        }
        sort(words.begin(), words.end());

        int n = words.size();
        string str = words[0];
        int ans = 0, wordSize;

        for(int i = 1; i < n; i++){
            wordSize = str.size();
            if(words[i].compare(0, wordSize, str)){
                ans += 1 + wordSize;
            }
            str = words[i];
        }
        ans += str.size() + 1;
        return ans;
    }
};
