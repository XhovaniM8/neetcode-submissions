class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if (s.size() != t.size()) return false;

        // Sort both strings
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        // Compare sorted strings
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != t[i]) {
                return false;
            }
        }

        return true;
    }
};
