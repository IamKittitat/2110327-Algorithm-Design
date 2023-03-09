#include<iostream>
#include<vector>

using namespace std;

int solve(vector<int> &v, int q,int l,int r,int ans){
    if(l == r){
        if(v[l] <= q){
            return max(ans,v[l]);
        }
        return ans;
    }

    int m = (l+r)/2;
    if(v[m] < q){
        return solve(v,q,m+1,r,v[m]);
    }
    else return solve(v,q,l,m,ans);
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> v(n);
    for(int i =0;i<n;i++) cin >> v[i];
    for(int i =0;i<m;i++){
        int q;
        cin >> q;
        cout << solve(v,q,0,n-1,-1) << "\n";
    }
}