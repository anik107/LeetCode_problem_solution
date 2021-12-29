class Solution {
public:
    string longestPrefix(string s) {
        vector<int>lps(s.size(),0);
        int idx=0;
        int i=1;
        while(i<s.size()){
            if(s[idx]==s[i]){
                lps[i]=idx+1;
                idx++;
                i++;
            }
            else{
                if(idx==0){
                    lps[i]=0;
                    i++;
                }
                else idx=lps[idx-1];
            }
        }
        return s.substr(0,lps.back());
    }
};
