#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &v, int start, int stop, int q,int idxAns,int ans){
    int m = (start+stop)/2;
    if(start == stop){
        if(v[m] >= ans && v[m] <= q) return start;
        return idxAns;
    }
    if(v[m] > q) return solve(v,start,m,q,idxAns,ans); // move left
    else return solve(v,m+1,stop,q,m,v[m]); // move right
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m,q;
    cin >> n >> m;
    vector<int> v(n);
    for(int i = 0;i<n;i++) cin >> v[i];
    for(int i = 0;i<m;i++){
        cin >> q;
        cout << solve(v,0,v.size()-1,q,-1,-1) << "\n";
    }
}
