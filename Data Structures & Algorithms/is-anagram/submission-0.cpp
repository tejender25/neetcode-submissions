class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        unordered_map<int,int>mp;
        for(char a: s) mp[a-'a']++;
        for(char b: t) mp[b-'a']--;
        for(auto t : mp){
            if(t.second!=0) return false;
        }
        return true;
    }
};
