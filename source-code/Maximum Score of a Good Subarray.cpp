class Solution {
public:
    int maximumScore(vector<int>& a, int k) {
        int n=a.size();
        stack<pair<int,int>>s;
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
        long long mx=0LL;
        for(int i=0;i<n;i++){
            int id1=i-l[i]+1;
            int id2=i+r[i]-1;
            if(id1<=k && k<=id2)mx=max(mx,1LL*a[i]*(id2-id1+1));
        }
        return mx;
    }
};
