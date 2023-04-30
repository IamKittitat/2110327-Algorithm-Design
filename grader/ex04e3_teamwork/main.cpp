#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> v(m);
    vector<int> doTask(n);
    for(int i = 0;i<m;i++) cin >> v[i];
    sort(v.begin(),v.end());

    double total = 0;
    
    int idx = 0;
    for(int i = 0;i<m;i++){
        doTask[idx] += v[i];
        total += doTask[idx];
        idx = (idx+1)%n;
    }
    cout << setprecision(10) << total/m;

}