#include<iostream>
#include<vector>

using namespace std;

string solve(int n,int k,vector<int> &v){
    if(k == 0){
        if(n == 0) return "g";
        return "a";
    }

    if(n<v[k-1]) return solve(n,k-1,v);
    if(n>=v[k-1]+k+3) return solve(n-(v[k-1]+k+3),k-1,v);

    n-=v[k-1];
    if(n==0) return "g";
    return "a";
}

int main(){
    int n;
    cin >> n;
    vector<int> v;
    v.push_back(3);
    while(v.back() <= 1e9) v.push_back(v.back()*2+v.size()+3);
    auto it = lower_bound(v.begin(),v.end(),n);
    int k = it - v.begin();
    // cout << k << endl;
    cout << solve(n-1,k,v);
    // for(int i =1;i<n;i++){
    //     auto it = lower_bound(v.begin(),v.end(),i);
    //     int k = it - v.begin();
    //     cout << solve(i-1,k,v) << " ";
    // }
}