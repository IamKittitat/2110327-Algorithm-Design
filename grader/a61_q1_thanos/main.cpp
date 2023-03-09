#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long solve(vector<int> &v,int A,int B,int l,int r){
    int amount = upper_bound(v.begin(),v.end(),r) - lower_bound(v.begin(),v.end(),l);
    if(l == r){
        if(amount == 0) return A;
        return B*amount;
    }
    if(amount == 0) return A;

    int m = (l+r)/2;
    long long half = solve(v,A,B,l,m) + solve(v,A,B,m+1,r);
    long long total = amount > 0 ? (long long)B*amount*(r-l+1) : A;   

    return min(total,half);
}

int main(){
    int p,k,A,B;
    cin >> p >> k >> A >> B;
    vector<int> v(k);
    for(int i=0;i<k;i++) cin >> v[i];
    sort(v.begin(),v.end());
    cout << solve(v,A,B,1,1<<p);
}