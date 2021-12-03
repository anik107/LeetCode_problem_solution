class Solution {
public:
    bool canReach(string s, int mn, int mx) {
        int n=s.size();
        queue<int>q;
        q.push(0);
        int cur=0;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            if(u==n-1){
                return true;
            }
            for(int i=max(u+mn,cur);i<=min(u+mx,n-1);i++){
                if(s[i]=='0')q.push(i);
            }
            cur=min(u+mx+1,n);
        }
        return false;
    }
};
