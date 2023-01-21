#include <bits/stdc++.h>
#include <cmath>

using namespace std;

int countOne(vector<int> virus,int start,int stop){
    int ans =0;
    for(int i = start;i<stop;i++) if(virus[i] == 1) ans++;
    return ans;
}

pair<bool,int> checkVirus(vector<int> virus,int start,int stop){
    int mid = (start+stop)/2;
    if(stop-start == 2) return {true,countOne(virus,start,stop)};
    pair<bool,int> leftCheck = checkVirus(virus,start,mid);
    if(!leftCheck.first) return {false,leftCheck.second};
    pair<bool,int> rightCheck = checkVirus(virus,mid,stop);
    if(!rightCheck.first) return {false,rightCheck.second};

    int leftOne = leftCheck.second;
    int rightOne = rightCheck.second;

    int diffOne = abs(leftOne - rightOne);
    // cout << "CHECK " << start << " " << stop << " " << diffOne << endl;
    if(diffOne <= 1 && leftCheck.first  && rightCheck.first) return {true,leftOne+rightOne};
    return {false,leftOne+rightOne};
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
        if(checkVirus(virus,0,virusSize).first) cout << "yes\n";
        else cout << "no\n";
    }

}
