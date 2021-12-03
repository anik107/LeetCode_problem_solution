typedef tuple<double,int>tp;
class Solution {
public:
    double mincostToHireWorkers(vector<int>& a, vector<int>& b, int k) {
        vector<tp>v;
        int n=a.size();
        for(int i=0;i<n;i++){
            v.push_back(make_tuple(1.0*b[i]/a[i],a[i]));
        }
        sort(v.begin(),v.end());
        int cnt=0;
        priority_queue<int>pq;
        for(int i=0;i<k;i++){
            cnt+=get<1>(v[i]);
            pq.push(get<1>(v[i]));
        }
        double ans=cnt*get<0>(v[k-1]);
        for(int i=k;i<n;i++){
            pq.push(get<1>(v[i]));
            cnt+=get<1>(v[i]);
            cnt-=pq.top();
            pq.pop();
            ans=min(ans,cnt*get<0>(v[i]));
        }
        return ans;
    }
};
