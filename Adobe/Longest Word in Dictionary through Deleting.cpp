class Solution {
public:
    bool canForm(string word, string s){
        int i = 0, j = 0;
        while(i < s.length() && j < word.length()){
            if(word[j] == s[i]){
                j++;
            }
            i++;
        }
        return j == word.length();
    }

    string findLongestWord(string s, vector<string>& dictionary) {
        string ans = "";
        for(auto str : dictionary){
            if(canForm(str, s)){
                if(str.length() > ans.length() || (str.length() == ans.length() && str < ans)){
                    ans = str;
                }
            }
        }
        return ans;
    }
};
