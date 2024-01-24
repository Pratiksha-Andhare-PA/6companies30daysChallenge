class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_set<string> s;
        for(int i = 0; i < startWords.size(); i++){
            sort(startWords[i].begin(), startWords[i].end());
            s.insert(startWords[i]);
        }

        int ans = 0; string temp = "", x = "";
        for(int i = 0; i < targetWords.size(); i++){
            temp = targetWords[i];
            sort(temp.begin(), temp.end());

            for(int j = 0; j < temp.length(); j++){
                //all possible substrings by removing 1 char
                x = temp.substr(0, j) + temp.substr(j + 1); 
                if(s.find(x) != s.end()){
                    ans++;
                    break;
                }
            }
        } 
        return ans;
    }
};
