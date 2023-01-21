#include <bits/stdc++.h>

using namespace std;

void gen_barcode(int b,int len,vector<int> &sol,int a,int white){
    if(len < b){
        if(len - white < b - a){
            sol[len] = 0;
            gen_barcode(b,len+1,sol,a,white);
        }
        if(white < a){
            sol[len] = 1;
            gen_barcode(b,len+1,sol,a,white+1);
        }
    } else{
        for(auto &x : sol) cout << x;
        cout << "\n";
    }
}

int main()
{
    int a,b;
    cin >> a >> b;
    vector<int> sol(b);
    gen_barcode(b,0,sol,a,0);
}
