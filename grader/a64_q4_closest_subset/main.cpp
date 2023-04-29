#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

vector<int> v;
int n,m,k;
int ans = INT32_MAX;

int minSum(int needed,int idx){
    int ans = 0;
    for(int i = idx;i<n && needed > 0;i++,needed--){
        ans += v[i];
    }
    return ans;
}

void solve(int len,int selected,int total){
    if(len == n){
        if(selected != m) return;
        ans = min(ans,abs(total-k));
    }
    else{
        // Too much || Not enough --> return
        if(total - k > ans || k - (total + minSum(m-selected,len)) > ans) return;
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
    for(int i = 0; i<n;i++) cin >> v[i];
    sort(v.begin(),v.end());
    solve(0,0,0);
    cout << ans;
}
