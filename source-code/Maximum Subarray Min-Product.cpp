class Solution {
public:
    typedef long long ll;
    int maxSumMinProduct(vector<int>& a) {
        const ll mod=1e9+7;
        stack<pair<int,int>>s;
        int n=a.size();
        int l[n+2];
        int r[n+2];
        for(int i=0;i<n;i++){
            int cnt=1;
            while(!s.empty() && s.top().first>a[i]){
                cnt+=s.top().second;
                s.pop();
            }
            l[i]=cnt;
            s.push({a[i],cnt});
        }
        while(!s.empty())s.pop();
        for(int i=n-1;i>=0;i--){
            int cnt=1;
            while(!s.empty() && s.top().first>=a[i]){
                cnt+=s.top().second;
                s.pop();
            }
            r[i]=cnt;
            s.push({a[i],cnt});
        }
        ll ans=0LL;
        ll sum[n+2];
        sum[0]=a[0];
        for(int i=1;i<n;i++)sum[i]=sum[i-1]+a[i];
        for(int i=0;i<n;i++){
            int id1=i-l[i]+1;
            int id2=i+r[i]-1;
            ll x;
            if(id1>0)x=sum[id2]-sum[id1-1];
            else x=sum[id2];
            ans=max(ans,x*a[i]);
        }
        return ans%mod;
    }
};
