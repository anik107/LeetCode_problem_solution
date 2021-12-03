class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int,int>mp;
        for(auto t: trips){
            mp[t[1]]+=t[0];
            mp[t[2]]-=t[0];
        }
        int sum=0;
        for(auto x: mp){
            sum+=x.second;
            if(sum>capacity)return false;
        }
        return (sum>=0)?true:false;
    }
};
