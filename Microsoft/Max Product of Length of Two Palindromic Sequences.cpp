class Solution {
public:
    bool isPalindrome(string &s){
        int n = s.length();
        int i = 0, j = n-1;

        while(i < j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    void dfs(string &s, int idx, string &s1, string &s2, int &ans){
        if(idx >= s.length()){
            if(isPalindrome(s1) && isPalindrome(s2)){
                int len = s1.length() * s2.length();
			    ans = max(ans, len);
            }
            return;
        }

        // case 1: do not choose
        dfs(s, idx+1, s1, s2, ans);

        // case 2: choose from 1st string
        s1.push_back(s[idx]);
        dfs(s, idx+1, s1, s2, ans);
        s1.pop_back();

        // case 2: choose from 2nd string
        s2.push_back(s[idx]);
        dfs(s, idx+1, s1, s2, ans);
        s2.pop_back();
    }

    int maxProduct(string s) {
        int ans = 0;
        string s1 = "", s2 = "";
        dfs(s, 0, s1, s2, ans);
        
        return ans;
    }
};
