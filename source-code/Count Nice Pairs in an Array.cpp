class Solution {
public:
    int countNicePairs(vector<int>& a) {
        const long long mod=1e9+7;
        int n=a.size();
        unordered_map<long long,long long>mp;
        long long cnt=0;
        for(int i=0;i<n;i++){
            int x=a[i];
            int sum=0;
            while(x){
                sum=10*sum+(x%10);
                x/=10;
            }
            if(mp.find(a[i]-sum)!=mp.end()){
                cnt+=mp[a[i]-sum];
                cnt%=mod;
            }
            mp[a[i]-sum]++;
        }
        return cnt%mod;
    }
};
