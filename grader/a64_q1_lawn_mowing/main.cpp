#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long getTotal(int l,int r,vector<int> &S){
    if(l == 0) return S[r];
    return S[r] - S[l-1];
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL); 
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> A(n),S(n);
    for(int i =0;i<n;i++) cin >> A[i];
    S[0] = A[0] + k;
    for(int i =1;i<n;i++) S[i] = S[i-1] + A[i] + k;

    // for(auto &x : S ) cout << x << " ";
    // cout << "-----\n";
    for(int i = 0;i<m;i++){
        int a;
        long long b;
        cin >> a >> b;
        long long start = getTotal(a,a,S);
        if(b-start > 0){
            auto it = upper_bound(S.begin(),S.end(),S[a] + (b-start));
            it--;
            cout << getTotal(a,it-S.begin(),S) - (it-S.begin()-a+1)*k << "\n";
        } else cout << "0\n";
    }
}

/*
5 5 0
1 2 3 4 5
1 5
1 8
1 9
1 10
1 14

5 4 2
1 1 1 1 1
0 2
0 5
0 10
0 1000

*/