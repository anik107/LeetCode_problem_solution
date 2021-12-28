typedef long long ll;
const ll mod=1e9+7;
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int m=roads.size();
        vector<vector<pair<int,int>>>v(n);
        for(auto x: roads){
            v[x[0]].push_back({x[1],x[2]});
            v[x[1]].push_back({x[0],x[2]});
        }
        vector<ll>dis(n,LLONG_MAX);
        vector<ll>path(n,0);
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
        path[0]=1;
        dis[0]=0;
        pq.push({0,0});
        while(!pq.empty()){
            pair<ll,ll>p=pq.top();
            pq.pop();
            for(auto x: v[p.second]){
                ll u=x.first;
                ll w=x.second;
                if(dis[u]>dis[p.second]+w){
                    dis[u]=dis[p.second]+w;
                    path[u]=path[p.second];
                    path[u]%=mod;
                    pq.push({dis[u],u});
                }
                else if(dis[u]==p.first+w){
                    path[u]+=path[p.second];
                    path[u]%=mod;
                }
            }
        }
        return path[n-1];
    }
};
