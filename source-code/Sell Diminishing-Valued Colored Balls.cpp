typedef long long ll;
class Solution {
public:
    int maxProfit(vector<int>& a, int k) {
        const ll mod=1e9+7;
        ll sum=0;
        int n=a.size();
        auto cmp=[](const pair<ll,ll>& A,const pair<ll,ll>& B){
            return A.first<B.first;
        };
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,decltype(cmp)>pq(cmp);
        map<ll,ll>mp;
        for(int i=0;i<n;i++){
            mp[a[i]]++;
        }
        for(auto x: mp)pq.push({x.first,x.second});
        while(k>0){
            pair<ll,ll>p=pq.top();
            pq.pop();
            ll vala=p.first;
            ll cnta=p.second;
            if(pq.empty()){
                sum+=(vala*(vala+1)/2-(vala-k/cnta)*(vala-k/cnta+1)/2)*cnta;
                ll rem=k%cnta;
                vala=vala-k/cnta;
                sum+=vala*rem;
                sum%=mod;
                break;
            }
            pair<ll,ll>pi=pq.top();
            pq.pop();
            ll valb=pi.first;
            ll cntb=pi.second;
            if(k>(vala-valb)*cnta){
                k-=(vala-valb)*cnta;
                sum+=((vala*(vala+1)/2)-(valb*(valb+1)/2))*cnta;
                sum%=mod;
                pq.push({valb,cnta+cntb});
            }
            else{
                sum+=(vala*(vala+1)/2-(vala-k/cnta)*(vala-k/cnta+1)/2)*cnta;
                ll rem=k%cnta;
                vala=vala-k/cnta;
                sum+=vala*rem;
                sum%=mod;
                break;
            }
        }
        return sum;
    }
};
