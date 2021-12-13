class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int>s;
        vector<int>ret(temp.size(),0);
        for(int i=0;i<temp.size();i++) {
            while(!s.empty() && temp[i]>temp[s.top()]) {
                int idx=s.top();
                ret[idx]=i-idx;
                s.pop();
            }
            s.push(i);
        }
        return ret;
    }
};
