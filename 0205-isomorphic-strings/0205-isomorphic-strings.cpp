class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        
        int map_st[256] = {0};
        int map_ts[256] = {0};
        
        for (int i = 0; i < s.size(); i++) {
            char c1 = s[i];
            char c2 = t[i];
            
            if (map_st[c1] == 0 && map_ts[c2] == 0) {
                map_st[c1] = c2;
                map_ts[c2] = c1;
            } else if (map_st[c1] != c2 || map_ts[c2] != c1) {
                return false;
            }
        }
        return true;
    }
};
