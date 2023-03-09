#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

bool solve(vector<int> &v,int l,int r){
    if(r-l == 1){
        if(v[l] == 0 && v[r] == 1) return true;
        return false;
    }

    int m = (l+r)/2;
    vector<int> rev_v = v;
    int start = l, stop = m;
    while(start < stop) swap(rev_v[start++],rev_v[stop--]);
    bool first = solve(v,l,m) || solve(rev_v,l,m);
    bool second = solve(v,m+1,r);
    return first && second;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,k;
    cin >> n >> k;
    int len = pow(2,k);
    vector<int> v(len);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<len;j++) cin >> v[j];
        if(solve(v,0,len-1)) cout << "yes\n";
        else cout << "no\n";
    }
}