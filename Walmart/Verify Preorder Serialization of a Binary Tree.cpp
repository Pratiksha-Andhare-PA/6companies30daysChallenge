class Solution {
public:
    bool isValidSerialization(string preorder) {
        vector<string> nodes;
        stringstream ss(preorder);

        string word;
        while(getline(ss, word, ',')){
            nodes.push_back(word);
        }

        int vacancy = 1;
        for(auto node : nodes){
            vacancy--;
            if(vacancy < 0) return false;

            if(node != "#"){
                vacancy += 2;
            }
        }
        return vacancy == 0;
    }
};
