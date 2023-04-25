#include<iostream>
#include<iomanip>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> v(m);
    for(int i = 0;i<m;i++) cin >> v[i];
    sort(v.begin(),v.end());
    priority_queue<int,vector<int>,greater<int>> pq;
    double ans = 0;
    for(int i = 0;i<n;i++) pq.push(0);
    for(int i = 0;i<m;i++){
        int t = pq.top();
        pq.pop();
        t += v[i];
        pq.push(t);
        ans += t;
    }
    cout << setprecision(7) <<  ans/m;

}