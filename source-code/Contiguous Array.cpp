class Solution {
public:
    int findMaxLength(vector<int>& v) {
        int n=v.size();
        map<int,int>mp;
        int mx=0;
        int sum=0;
        mp[0]=-1;
        for(int i=0;i<n;i++){
            sum+=(v[i]==0)?-1:1;
            if(mp.find(sum)!=mp.end())mx=max(mx,i-mp[sum]);
            else mp[sum]=i;
        }
        return mx;
    }
};
