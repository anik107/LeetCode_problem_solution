class Solution {
public:
    int numSplits(string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++)mp[s[i]]++;
        set<char>se;
        int cnt=0;
        for(auto x: s){
            mp[x]--;
            se.insert(x);
            if(mp[x]<=0)mp.erase(x);
            if(se.size()==mp.size())cnt++;
        }
        return cnt;
    }
};
