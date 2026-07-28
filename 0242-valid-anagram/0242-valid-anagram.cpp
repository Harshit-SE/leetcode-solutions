class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=s.size();
        int m=t.size();
        unordered_map<char,int>count;
        for(int i=0;i<n;i++){
            count[s[i]]++;
        }
        for(int i=0;i<m;i++){
            count[t[i]]--;
        }
        for (auto it : count) {
    if (it.second != 0) {
        return false;
    }
}
return true;
        
    }
};