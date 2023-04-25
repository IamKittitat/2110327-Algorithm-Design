#include<iostream>
#include<queue>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> s(n),f(n);
    vector<bool> selected(n,false);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for(int i = 0; i<n;i++) cin >> s[i];
    for(int i = 0; i < n;i++){
        cin >> f[i];
        pq.push({f[i],i});
    }
    
    int ans = 0;
    while(!pq.empty()){
        pair<int,int> t = pq.top();
        pq.pop();
        int idx = t.second;
        if(!selected[idx]){
            // cout << idx << endl;
            ans++;
            for(int i = 0;i<n;i++){
                if(s[i] < f[idx]) selected[i] = true;
            }
        }
    }
    cout << ans;
    
}