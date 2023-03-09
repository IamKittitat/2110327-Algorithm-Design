#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,w,k;
    cin >> n >> w >> k;
    vector<int> vl(n),vr(n);
    for(int i =0;i<n;i++) cin >> vl[i];
    for(int i =0;i<n;i++) cin >> vr[i];
    vector<vector<int>> dpl(2,vector<int>(n)),dpr(2,vector<int>(n));
    // dpl : last billboard is on the left
    // dpl[0][j] : at pos j and not place billboard at j
    // dpl[1][j] : at pos j and place billboard at j

    dpl[0][0] = 0; dpr[0][0] = 0;
    dpl[1][0] = vl[0]; dpr[1][0] = vr[0];
    for(int i = 1;i<n;i++){
        dpl[0][i] = max(dpl[0][i-1],dpl[1][i-1]);
        dpr[0][i] = max(dpr[0][i-1],dpr[1][i-1]);

        if(i-w-1 >= 0){
            dpl[1][i] = max(dpr[0][i-w-1],dpr[1][i-w-1]) + vl[i];
            dpr[1][i] = max(dpl[0][i-w-1],dpl[1][i-w-1]) + vr[i];
        } else{
            dpl[1][i] = vl[i];
            dpr[1][i] = vr[i];
        }
    }

    cout << max(max(dpl[0][n-1],dpl[1][n-1]),max(dpr[0][n-1],dpr[1][n-1]));

}