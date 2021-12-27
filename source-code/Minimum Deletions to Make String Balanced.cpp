class Solution {
public:
    int minimumDeletions(string s) {
        stack<char>st;
        int mn=INT_MAX;
        int cnt=0;
        for(auto x: s){
            if(!st.empty() && st.top()=='b' && x=='a'){
                cnt++;
                st.pop();
            }
            else st.push(x);
        }
        mn=min(mn,cnt);
        while(!st.empty())st.pop();
        reverse(s.begin(),s.end());
        cnt=0;
        for(auto x: s){
            if(!st.empty() && st.top()=='a' && x=='b'){
                cnt++;
                st.pop();
            }
            else st.push(x);
        }
        return min(mn,cnt);
    }
};
