#include <bits/stdc++.h>
#include <cmath>

using namespace std;

bool checkVirus(vector<int> virus,int start,int stop){
    int mid = (start+stop)/2;
    if(stop-start == 2){
        if((virus[start] == 0 && virus[start+1] ==1)) return true;
        else return false;
    }
    vector<int> newVirus = virus;
    auto l = start;
    auto r = mid-1;
    while(l < r){
        swap(newVirus[l++],newVirus[r--]);
    }
    bool aValid = checkVirus(virus,start,mid) || checkVirus(newVirus,start,mid);
    bool bValid = checkVirus(virus,mid,stop);
    if(aValid && bValid) return true;
    else return false;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,k,tmp;
    cin >> n >> k;
    int virusSize = pow(2,k);
    for(int i = 0; i < n; i++){
        vector<int> virus(virusSize);
        for(int j = 0; j < virusSize; j++){
            cin >> tmp;
            virus[j] = tmp;
        }
        if(checkVirus(virus,0,virusSize)) cout << "yes\n";
        else cout << "no\n";
    }

}
