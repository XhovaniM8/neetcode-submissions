class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        struct Key {
            int count[26] = {};
            bool operator==(const Key& other) const {
                return memcmp(count, other.count, sizeof(count)) == 0;
            }
        };

        struct KeyHash {
            size_t operator()(const Key& k) const {
                // Fowler–Noll–Vo hash
                size_t h = 2166136261u; // Offset basis
                for (int i = 0; i < 26; ++i)
                    h = (h ^ k.count[i]) * 16777619; // FNV Prime
                return h;
            }
        };

        unordered_map<Key, vector<string>, KeyHash> res;

        for (const auto& s : strs) {
            Key key;
            for (char c : s) key.count[c - 'a']++;
            res[key].push_back(s);
        }

        vector<vector<string>> result;
        result.reserve(res.size());
        for (auto& [_, group] : res) {
            result.push_back(std::move(group));
        }

        return result;
    }
};