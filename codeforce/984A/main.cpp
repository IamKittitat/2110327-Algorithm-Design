#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0;i<n;i++) cin >> v[i];
    sort(v.begin(),v.end());
    if(v.size()%2 == 0){
        cout << v[v.size()/2-1];
    } else{
        cout << v[v.size()/2];
    }
}
