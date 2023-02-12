#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

pair<bool,int> solve(vector<int> &v,int l,int r){
    if(r-l == 1){
        int total = 0;
        for(int i = l ;i<=r;i++) if(v[i] == 1) total++;
        return {true,total};
    }
    int m = (l+r)/2;
    pair<bool,int> left = solve(v,l,m);
    if(!left.first) return {false,-1};
    pair<bool,int> right = solve(v,m+1,r);
    if(!right.first) return {false,-1};

    if(abs(right.second-left.second) > 1) return {false,-1};
    return {true,right.second+left.second};

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,k,tmp;
    cin >> n >> k;
    int len = pow(2,k);
    vector<int> v(len);
    for(int i =0;i<n;i++){
        for(int j =0;j<len;j++) cin >> v[j];
        pair<bool,int> ans = solve(v,0,len-1);
        if(ans.first) cout << "yes\n";
        else cout << "no\n";
    }
}
