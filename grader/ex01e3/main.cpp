#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &v,int q,int start,int stop,int ans){
    if(start == stop){
        if(v[start] > ans && v[start] <= q) ans = v[start];
        return ans;
    }
    int m = (start+stop)>>1;
    if(v[m] > q) return solve(v,q,start,m,ans);
    else{
        return solve(v,q,m+1,stop,v[m]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m,q;
    cin >> n >> m;
    vector<int> v(n);
    for(int i =0;i<n;i++) cin >> v[i];
    for(int i =0;i<m;i++){
        cin >> q;
        cout << solve(v,q,0,v.size()-1,-1) << "\n";
    }
}
