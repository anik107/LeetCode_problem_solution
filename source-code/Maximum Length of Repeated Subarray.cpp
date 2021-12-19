class Solution {
public:
    vector<int>LPS(vector<int>& s){
    vector<int>lps(s.size());
    int idx=0;
    for(int i=1;i<s.size();){
        if(s[idx]==s[i]){
            lps[i]=idx+1;
            idx++;i++;
        }
        else{
           if(idx!=0)idx=lps[idx-1];
           else{
            lps[i]=idx;
            i++;
           }
        }
    }
    return lps;
    }
    bool kmp(vector<int>& txt,vector<int>& pat){
        vector<int>lps=LPS(pat);
        int i=0,j=0;
        while(i<txt.size()){
            if(txt[i]==pat[j]){
                i++;j++;
            }
            else{
                if(j!=0)j=lps[j-1];
                else i++;
            }
            if(j==pat.size())return true;
        }
        return false;
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int l=0,r=m+2;
        int ans=0;
        while(l<r){
            int mid=l+(r-l)/2;
            bool ok=false;
            if(mid>=1){
                    for(int i=0;i+mid<=m;i++){
                    vector<int>v;
                    for(int j=0;j<mid;j++)v.push_back(nums2[i+j]);
                    if(kmp(nums1,v)){
                        ok=true;
                        break;
                    }
                }
            }
            if(ok)ans=mid,l=mid+1;
            else r=mid;
        }
        return ans;
    }
};
