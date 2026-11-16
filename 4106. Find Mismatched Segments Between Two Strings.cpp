class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        vector<vector<string>> ans;
        int left = 0;
        int right; 
        for(right=0; right<s1.size(); right++) {
            if(s1[right] == s2[right]) {
                if(left != right) {
                    ans.push_back(
                        {s1.substr(left, right - left),
                         s2.substr(left, right - left)}
                    );
                }
                left = right + 1;
            }
        }

        if(left != right) {
            ans.push_back(
                {s1.substr(left, right - left),
                 s2.substr(left, right - left)}
            );
        }

        return ans;
    }
};
