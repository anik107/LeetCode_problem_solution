class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k==num.size())return "0";
        stack<char>s;
        for(auto x: num){
            while(!s.empty() && s.top()>x && k>0){
                s.pop();
                k--;
            }
            s.push(x);
        }
        while(k>0){
            s.pop();
            k--;
        }
        string ans="";
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        while(ans.back()=='0' && ans.size()>1)ans.pop_back();
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
