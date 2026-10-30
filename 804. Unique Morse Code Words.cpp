class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

        unordered_set<string> set;
        int cnt = 0;
        for(auto word : words){
            string check = "";
            for(int i=0; i<word.size(); i++){
                check += morse[word[i] - 'a'];
            }

            if(!set.contains(check))
                cnt++;

            set.insert(check);
        }

        return cnt;
    }
};
