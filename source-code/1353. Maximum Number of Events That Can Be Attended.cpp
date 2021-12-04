class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        auto cmp=[](int a,int b){
            return a>b;
        };
        priority_queue<int,vector<int>,decltype(cmp)>pq(cmp);
        int n=events.size();
        int i=0,cnt=0;
        for(int day=1;day<=1e6;day++){
            while(!pq.empty() && day>pq.top())pq.pop();
            while(i<n && events[i][0]==day){
                pq.push(events[i][1]);
                i++;
            }
            if(!pq.empty()){
                cnt++;
                pq.pop();
            }
            if(pq.empty() && i==n)break;
        }
        return cnt;
    }
};
