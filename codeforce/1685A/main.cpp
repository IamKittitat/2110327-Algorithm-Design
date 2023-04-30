#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    for(int i = 0;i<t;i++){
        int n;
        bool ok = true;
        cin >> n;
        vector<int> v(n);
        for(int j = 0;j<n;j++) cin >> v[j];
        sort(v.begin(),v.end());

        for(int i = 1;i<n/2;i++){
			if(v[i] >= v[i+n/2-1]) ok = false;
		}
        if(!ok || n%2 != 0) cout << "NO\n";
        else{
            cout << "YES\n";
            for(int i = 0;i<n/2;i++){
                cout << v[i] << " " << v[i+n/2] << " ";
            }
            cout << "\n";
        }
    }
}

/*
4
3
1 1 2
4
1 9 8 4
4
2 0 2 2
6
1 1 1 11 111 1111
*/