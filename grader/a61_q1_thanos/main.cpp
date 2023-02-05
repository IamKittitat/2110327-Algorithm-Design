#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long solve(vector<int> &v,int start,int stop,long long a,long long b){
    auto it1 = lower_bound(v.begin(),v.end(),start);
    auto it2 = upper_bound(it1,v.end(),stop);
    long long amount  = it2-it1;

    long long allPower;
    if(amount > 0) allPower = b*amount*(stop-start+1);
    else allPower = a;

    if(start == stop || amount == 0) return allPower;
     
    int m = (start+stop)/2;
    long long halfPower = solve(v,start,m,a,b) + solve(v,m+1,stop,a,b);
    //cout << start << " " << stop << " " << allPower << " " << halfPower << endl;
    return min(allPower,halfPower);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int p,k;
    long long a,b;
    cin >> p >> k >> a >> b;
    vector<int> v(k);
    for(int i = 0; i<k;i++) cin >> v[i];
    sort(v.begin(),v.end());
    cout << solve(v,1,1<<p,a,b);
}