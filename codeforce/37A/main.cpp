#include <bits/stdc++.h>

using namespace std;

int main()
{
    map<int,int> m;
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        int tmp;
        cin >> tmp;
        m[tmp]++;
    }
    int highest = 0;
    for(auto &x : m){
        if(x.second > highest) highest = x.second;
    }
    cout << highest << " " << m.size() ;
}
