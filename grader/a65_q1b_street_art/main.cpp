#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

long long ans = 0;

long long solve(long long b,long long c,vector<long long> &y){
    long long amount = upper_bound(y.begin(),y.end(),c) - lower_bound(y.begin(),y.end(),b);
    if(amount == 0) return 0;
    long long fc =0,sc =0 ,tc =0;
    if(c-b+1 >= 3){
        long long u = (c-b+1)/3, v = (c-b+2)/3;
        long long b1 = b,e1 = b+u-1, b2 = b+u, e2 = b+u+v-1, b3 = b+u+v,e3=c;
        fc = solve(b1,e1,y);
        sc = solve(b2,e2,y);
        tc = solve(b3,e3,y);
    }
    return amount + fc + sc + tc - min(min(fc,sc),tc);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    long long w,n;
    cin >> w >> n;
    vector<long long> y(n);
    for(int i =0;i<n;i++) cin >> y[i];
    sort(y.begin(),y.end());
    cout << solve(1,w,y);;
}

