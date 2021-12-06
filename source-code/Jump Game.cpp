class Solution {
public:
    bool canJump(vector<int>& a) {
        int n=a.size();
        queue<int>q;
        bool vis[n+2];
        memset(vis,false,sizeof(vis));
        q.push(0);
        vis[0]=true;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                int idx=q.front();
                q.pop();
                if(idx==n-1)return true;
                for(int j=1;j<=a[idx];j++){
                    int nxt_idx=idx+j;
                    if(nxt_idx==n-1)return true;
                    if(nxt_idx>n-1)break;
                    if(vis[nxt_idx])continue;
                    q.push(nxt_idx);
                    vis[nxt_idx]=true;
                }
            }
        }
        return false;
    }
};
