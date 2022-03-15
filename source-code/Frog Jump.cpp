class Solution {
public:
    bool canCross(vector<int>& a) {
       int n=a.size();
       multiset<int>ms;
       for(int i=0;i<n;i++){
        ms.insert(a[i]);
       }
       set<pair<int,int>>s;
       s.insert({a[0],0});
       while(!s.empty()){
        pair<int,int>p=*s.begin();
        if(p.first==a[n-1]){
            return true;
        }
        s.erase(s.begin());
        ms.erase(p.first);
        int x=p.first+p.second+1;
        int y=p.first+p.second-1;
        int z=p.first+p.second;
        if(ms.find(x)!=ms.end())s.insert({x,p.second+1});
        if(ms.find(y)!=ms.end())s.insert({y,p.second-1});
        if(ms.find(z)!=ms.end())s.insert({z,p.second});
       }
        return false;
    }
};
