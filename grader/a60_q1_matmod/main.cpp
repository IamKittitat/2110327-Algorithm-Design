#include<iostream>
#include<vector>

using namespace std;

vector<int> matrix_multiply(vector<int> &v,vector<int> &v2,int k){
    vector<int> ans(4);
    ans[0] = (v[0]*v2[0]+v[1]*v2[2])%k;
    ans[1] = (v[0]*v2[1]+v[1]*v2[3])%k;
    ans[2] = (v[0]*v2[2]+v[2]*v2[3])%k;
    ans[3] = (v[1]*v2[2]+v[3]*v2[3])%k;
    return ans;
    
}

vector<int> solve(vector<int> &v,int n,int k){
    for(auto &x : v) x = x%k;
    if(n == 1) return v; // !
    if(n == 2){
        return matrix_multiply(v,v,k);
    }
    vector<int> tmp = solve(v,n/2,k);
    vector<int> tmp2 = matrix_multiply(tmp,tmp,k);
    if(n%2 == 0) return tmp2;
    else return matrix_multiply(tmp2,v,k);
}

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> v(4);
    for(int i =0;i<4;i++) cin >> v[i];
    vector<int> ans = solve(v,n,k);
    for(auto &x : ans) cout << x << " ";
}