class WordDictionary {
public:
    unordered_map<int, vector<string>> mp;

    bool check(string &word, string &WordToSearch){
        int i = 0;
        while(i < word.length()){
            if(WordToSearch[i] != '.' && word[i] != WordToSearch[i]) return false;
            i++;
        }
        return true;
    }

    WordDictionary() {
        
    }
    
    void addWord(string word) {
        mp[word.length()].push_back(word);
    }
    
    bool search(string word) {
        if(mp.find(word.length()) == mp.end()) return false;

        for(auto &x : mp[word.length()]){
            bool ans = check(x, word);
            if(ans) return true;
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
