class Solution {
public:
    vector<string> ans;
    void generateCombinations(string digits, int i, string &str, vector<string> &letters){
        if(i == digits.size()){
            ans.push_back(str);
            return;
        }
        for(auto ch : letters[digits[i] - '0']){
            str.push_back(ch);
            generateCombinations(digits, i+1, str, letters);
            str.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return ans;
        }
        vector<string> letters = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        string str = "";
        generateCombinations(digits, 0, str, letters);
        return ans;
    }
};
