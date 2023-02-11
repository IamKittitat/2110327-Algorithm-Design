#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(800000);
    v[1] = 1;
    v[2] = 2;
    v[3] = 2;
    int i = 3,k=4;
    while(true){
        for(int j = 0;j<v[i];j++) v[k+j] = i;
        k += v[i];
        i++;
        if(i > v.size() || k+v[i] > v.size()) break;
    }
    vector<int> S(v.size());
    S[0] = 0;
    for(int i =1; i<S.size();i++) S[i] = v[i] + S[i-1];
    for(int i =0;i<n;i++){
        int q;
        cin >> q;  
        auto it = lower_bound(S.begin(),S.end(),q);
        cout << it-S.begin() << endl;
    }
}