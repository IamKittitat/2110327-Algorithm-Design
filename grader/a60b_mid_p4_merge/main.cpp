#include <iostream>
#include <vector>

using namespace std;

int total=1,k;
bool haveAns = true;

void solve(vector<int> &v,int l,int r){
    //cout << l << " " << r <<  " " << total << endl;
    if(r - l == 1 || total>k) return;

    int m = (l+r)/2;
    swap(v[m-1],v[m]);
    total +=2;

    if(total<k) solve(v,l,m);
    if(total<k) solve(v,m,r);
}

int main(){
    int n;
    cin >> n >> k;
    if(k%2==0) {cout << -1; return 0;}
    vector<int> v(n);
    for(int i =0;i<n;i++) v[i]=i+1;
    solve(v,0,n);

    if(total != k){
        cout << -1;
    } 
    else for(auto &x : v) cout << x << " ";
}