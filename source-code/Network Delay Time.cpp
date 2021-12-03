typedef tuple<int,int>tp;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>v[n+1];
        for (const auto& t : times) {
            v[t[0]].emplace_back(t[1],t[2]);
        }
        const int inf=1e9;
        vector<int>dist(n+1,inf);
        dist[k]=0;
        priority_queue<tp,vector<tp>,greater<tp>>pq;
        pq.emplace(0,k);
        while (!pq.empty()) {
            auto p=pq.top(); 
            pq.pop();
            int u=get<1>(p);
            for (auto& to :v[u]) {
                int v=to.first;
                int w=to.second;
                if (dist[v]>dist[u]+w) {
                    dist[v]=dist[u]+w;
                    pq.emplace(dist[v],v);
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)ans=max(ans,dist[i]);
        return ans==inf ?-1:ans;
    }
};
