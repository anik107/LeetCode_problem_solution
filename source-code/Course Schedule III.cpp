class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        long long sum=0;
        sort(courses.begin(),courses.end(),[](const vector<int> &a,const vector<int> &b){return a[1]<b[1];});
        priority_queue<int>pq;
        for(auto c: courses){
            sum+=c[0];
            int range=c[1];
            pq.push(c[0]);
            while(sum>range){
                sum-=pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};
