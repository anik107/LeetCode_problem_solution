class Solution {
public:
    int lastStoneWeight(vector<int>& a) {
        priority_queue<int>pq;
        for(auto x: a)pq.push(x);
        while(pq.size()>1){
            int x=pq.top();
            pq.pop();
            int y=pq.top();
            pq.pop();
            if(x!=y)pq.push(abs(x-y));
        }
        return (pq.empty())?0:pq.top();
    }
};
