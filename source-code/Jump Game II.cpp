class Solution {
public:
    int jump(vector<int>& a){
        int n=a.size();
        queue<int>q;
        q.push(0);
        bool vis[n+2];
        memset(vis,false,sizeof(vis));
        int depth=0;
        vis[0]=true;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                int idx=q.front();
                q.pop();
                if(idx==n-1)return depth;
                for(int j=1;j<=a[idx];j++){
                    int next_idx=idx+j;
                    if(next_idx>n-1)break;
                    if(vis[next_idx])continue;
                    vis[next_idx]=true;
                    q.push(next_idx);
                }
            }
            depth++;
        }
        return -1;
    }
};
