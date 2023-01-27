#include <bits/stdc++.h>

using namespace std;

long long solve(long long start,long long stop,long long c,vector<long long> &t){
    long long m = (start+stop)/2;
    long long tmp = 0;
    for(auto &x : t) tmp += (m/x+1);
    if(start == stop) return m;
    if(tmp > c) return solve(start,m,c,t);
    else if(tmp < c) return solve(m+1,stop,c,t);
    else{
        // cout << "A " << start << " " << stop << " " <<m << " " << tmp << endl;
        bool validT = false;
        vector<long long> mod(t.size());
        for(int i = 0; i<mod.size();i++){
            long long modRes = m%t[i];
            if(modRes == 0) validT = true;
            mod[i] = modRes;
        }
        sort(mod.begin(),mod.end());
        // cout << "B " << m <<" " << t[0] << " " << m%t[0] << endl;
        if(validT) return m;
        else return m - mod[0];
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,a;
    long long c;
    cin >> n >> a;
    vector<long long> t(n);
    for(int i =0 ;i<n;i++) cin >> t[i];
    sort(t.begin(),t.end());
    for(int i = 0;i<a;i++){
        cin >> c;
        cout << solve(0,1e15,c,t) << "\n";
    }
}

/*
102880657508 102880657511 123456789012
102880657510
*/
