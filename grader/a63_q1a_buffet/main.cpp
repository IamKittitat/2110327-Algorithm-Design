#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,k,m;
    cin >> n >> k >> m;
    vector<int> v(n+1),S(n+1);
    for(int i =1;i<=n;i++) cin >> v[i];
    S[1] = v[1]-m;
    for(int i =1;i<=n;i++) S[i] = S[i-1] + (v[i]-m);

    // for(auto &x : S ) cout << x << " ";
    // cout << endl;

    for(int i =0;i<k;i++){
        int p,w;
        cin >> p >> w;
        if(S[p]-S[p-1] < w){
            int find = S[p] + (w - (S[p]-S[p-1]));
            // cout << "F " << find << endl;
            auto it = lower_bound(S.begin()+p,S.end(),find);
            cout << it - S.begin() << "\n";
        } else{
            cout << p << "\n";
        }
    }
}

/*
7 5 2
4 6 2 7 3 5 9
1 1
1 6
1 14
4 7
6 3
*/