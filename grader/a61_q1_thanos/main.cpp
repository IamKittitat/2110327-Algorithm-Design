#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long solve(vector<int> &v,int a,int b,int l,int r){
    auto it1 = lower_bound(v.begin(),v.end(),l);
    auto it2 = upper_bound(v.begin(),v.end(),r);
    int amount = it2-it1;
    int len = r-l+1;
    if(len == 1){
        if(amount > 0) return b*amount;
        else return a;
    }
    if(amount == 0) return a;

    int m = (l+r)/2;
    long long halfPower = solve(v,a,b,l,m) + solve(v,a,b,m+1,r);
    long long fullPower = 0;
    if(amount > 0) fullPower = (long long)b*amount*len;
    else fullPower = a;

    return min(halfPower,fullPower);
}

int main(){
    int p,k,a,b;
    cin >> p >> k >> a >> b;
    int len = 1<<p;
    vector<int> v(k);
    for(int i = 0;i<k;i++) cin >> v[i];
    sort(v.begin(),v.end());
    cout << solve(v,a,b,1,len);
}