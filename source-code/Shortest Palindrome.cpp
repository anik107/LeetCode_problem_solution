class Solution {
public:
    string shortestPalindrome(string s) {
        string t=s;
        reverse(t.begin(),t.end());
        string pat=s+"#"+t;
        vector<int>lps(pat.size(),0);
        int idx=0;
        int i=1;
        while(i<pat.size()){
            if(pat[idx]==pat[i]){
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
        int x=s.size()-lps.back();
        return t.substr(0,x)+s;
    }
};
