class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        map<int,int>mp;
        for(auto x: barcodes)mp[x]++;
        priority_queue<pair<int,int>>pq;
        for(auto x: mp)pq.push({x.second,x.first});
        vector<int>v;
        while(pq.size()>1){
            pair<int,int> p=pq.top();
            pq.pop();
            v.push_back(p.second);
            p.first--;
            pair<int,int> pp=pq.top();
            pq.pop();
            v.push_back(pp.second);
            pp.first--;
            if(p.first>0)pq.push(p);
            if(pp.first>0)pq.push(pp);
        }
        while(!pq.empty()){
            pair<int,int>p=pq.top();
            pq.pop();
            v.push_back(p.second);
            p.first--;
            if(p.first>0)pq.push(p);
        }
        return v;
    }
};
