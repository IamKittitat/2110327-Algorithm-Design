#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int ip1,ip2,maxPrice=-1,maxPriceQ=-1;
    vector<pair<int,int>> v(n);
    for(int i = 0;i<n;i++){
        cin >> ip1 >> ip2;
        double tmp = ip2/ip1;
        v[i] = {tmp,ip2};
        if(ip1 > maxPrice){
            maxPrice = ip1;
            maxPriceQ = tmp;
        }
    }
    sort(v.begin(),v.end());
    pair<int,int> best = v[v.size()-1];
    if(best.first == maxPriceQ){
        cout << "Poor Alex";
    } else{
        cout << "Happy Alex";
    }
}
