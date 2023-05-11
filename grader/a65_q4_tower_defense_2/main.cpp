#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m,k,w;
    cin >> n >> m >> k >> w;
    // idx , hp
    map<int,int> data;
    int total = 0;
    vector<int> monsidx(m);
    for(int i = 0;i<m;i++) cin >> monsidx[i];
    for(int i = 0;i<m;i++){
        int hp;
        cin >> hp;
        total += hp;
        data[monsidx[i]] += hp;
    }

    int last = 0;
    for(auto &p : data){
        int i = p.first, hp = p.second;
        int from = max(i-w,last+1);
        int to = min(i+w,n);
        int amount = to - from + 1;
        amount = min(amount,hp);
        amount = min(amount,k);

        total -= amount;
        last = from+amount-1;
        k-= amount;
        if(k == 0) break;
    }
    cout << total;
}