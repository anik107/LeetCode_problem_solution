class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>>pq;
        if(a>0)pq.push({a,'a'});
        if(b>0)pq.push({b,'b'});
        if(c>0)pq.push({c,'c'});
        string s="";
        while(pq.size()>1){
            pair<int,char>p=pq.top();
            pq.pop();
            pair<int,char>pp=pq.top();
            pq.pop();
            if(p.first>=2){
                s+=p.second;
                s+=p.second;
                p.first-=2;
            }
            else{
                s+=p.second;
                p.first-=1;
            }
            if(pp.first>=2 && pp.first>p.first){
                s+=pp.second;
                s+=pp.second;
                pp.first-=2;
            }
            else{
                s+=pp.second;
                pp.first-=1;
            }
            if(p.first>0)pq.push(p);
            if(pp.first>0)pq.push(pp);
        }
        if(!pq.empty() && pq.top().first>=2){
            s+=pq.top().second;
            s+=pq.top().second;
        }
        else if(!pq.empty()) s+=pq.top().second;
        return s;
    }
};
