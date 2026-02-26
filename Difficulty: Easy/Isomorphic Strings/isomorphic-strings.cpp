class Solution {
  public:
    bool areIsomorphic(string &s1, string &s2) {
        
        unordered_map<char, char> mp1, mp2;
        int n = s1.size();
        for(int i = 0; i < n; i++) {
            char c1 = s1[i];
            char c2 = s2[i];
            
            if(mp1.find(c1) != mp1.end() && mp1[c1] != c2 || 
               mp2.find(c2) != mp2.end() && mp2[c2] != c1) {
                   
                   return false;
            } else {
                mp1[c1] = c2;
                mp2[c2] = c1;
            }
        }
        return true;
    }
};