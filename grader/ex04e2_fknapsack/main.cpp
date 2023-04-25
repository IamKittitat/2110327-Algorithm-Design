#include<iostream>
#include<iomanip>
#include<queue>
#include<vector>

using namespace std;

int main(){
    double maxW;
    int n;
    cin >> maxW >> n;
    vector<double> w(n),v(n);
    for(int i = 0;i<n;i++) cin >> v[i];
    for(int i = 0;i<n;i++) cin >> w[i];
    priority_queue<pair<double,int>> pq;
    for(int i = 0; i<n;i++) pq.push({v[i]/w[i],i});
    double maxV = 0;
    while(maxW > 0 && !pq.empty()){
        pair<double,int> t = pq.top();
        pq.pop();
        int idx = t.second;
        if(w[idx] > maxW){
            maxV += (maxW/w[idx])*v[idx];
            maxW = 0;
        } else{
            maxW -= w[idx];
            maxV += v[idx];
        }
    }
    cout << setprecision(7) << maxV;
}