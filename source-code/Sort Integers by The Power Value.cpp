#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
class Solution {
public:
    typedef pair<int,int> node;
    typedef tree<node, null_type, less<node>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
    int solve(int n){
        queue<int>q;
        q.push(n);
        int cnt=0;
        while(!q.empty()){
            int sz=q.size();
            set<int>s;
            for(int i=0;i<sz;i++){
                int x=q.front();
                if(x==1)return cnt;
                q.pop();
                if(x&1)s.insert(3*x+1);
                else s.insert(x/2);
            }
            for(auto x: s)q.push(x);
            cnt++;
        }
        return 0;
    }
    int getKth(int lo, int hi, int k) {
        ordered_set s;
        for(int i=lo;i<=hi;i++){
            s.insert({solve(i),i});
        }
        pair<int,int> p=*s.find_by_order(k-1);
        return p.second;
    }
};
