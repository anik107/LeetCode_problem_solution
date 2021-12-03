typedef tuple<int,int,int> ti;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n,INT_MAX);
        vector<vector<pair<int,int>>>v(n);
        for(const auto&f:flights)v[f[0]].emplace_back(f[1],f[2]);
        priority_queue<ti,vector<ti>,greater<ti>>pq;
        pq.emplace(0,src,0);
        while(!pq.empty()){
            auto p=pq.top();
            int cost=get<0>(p);
            int u=get<1>(p);
            int stops=get<2>(p);
            pq.pop();
            if(u==dst)return cost;
            if(stops>k)continue;
            dist[u]=stops;
            for(auto to:v[u]){
                auto [v,w] = to;
                if(dist[v] == INT_MAX || dist[v] > stops)pq.emplace(cost+w,v,stops+1);
            }
        }
        return -1;
    }
};
