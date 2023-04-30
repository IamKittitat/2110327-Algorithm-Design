#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

vector<int> v,S;
int n,m,k;
int ans = INT32_MAX;

void solve(int len,int selected,int total){
    if(len == n){
        if(selected != m) return;
        ans = min(ans,abs(total-k));
    }
    else{
        // Too much || Not enough --> return
        if(total - k > ans || k - (total + (S[len+m-selected-1]-S[len-1])) > ans) return;
        // Can "Dont selected"
        if(len - selected < n - m){
            solve(len+1,selected,total);
        }
        // Can "Selected"
        if(selected < k){
            solve(len+1,selected+1,total+v[len]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m >> k;
    v.resize(n);
    S.resize(n);
    for(int i = 0; i<n;i++) cin >> v[i];
    sort(v.begin(),v.end(),greater<int>());
    S[0] = v[0];
    for(int i = 1;i<n;i++) S[i] = S[i-1] + v[i];
    solve(0,0,0);
    cout << ans;
}
