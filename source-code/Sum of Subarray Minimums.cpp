class Solution {
public:
    int sumSubarrayMins(vector<int>& a) {
        const int mod=1e9+7;
        int n=a.size();
        stack<pair<int,int>>s;
        int l[n+2],r[n+2];
        for(int i=0;i<n;i++){
            int cnt=1;
            while(!s.empty() && s.top().first>=a[i]){
                cnt+=s.top().second;
                s.pop();
            }
            l[i]=cnt;
            s.push({a[i],cnt});
        }
        while(!s.empty())s.pop();
        for(int i=n-1;i>=0;i--){
            int cnt=1;
            while(!s.empty() && s.top().first>a[i]){
                cnt+=s.top().second;
                s.pop();
            }
            r[i]=cnt;
            s.push({a[i],cnt});
        }
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=1LL*a[i]*l[i]*r[i];
            sum%=mod;
        }
        return sum;
    }
};
