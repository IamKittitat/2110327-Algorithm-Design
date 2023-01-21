#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,x,y,tmp;
    cin >> n;
    for(int i = 0 ;i < n ; i++){
        bool found = false;
        cin >> x >> y;
        set<int> s;
        for(int j = 0 ;j < x;j++){
            cin >> tmp;
            s.insert(tmp);
        }
        for(int j = 0 ; j < y;j++){
            cin >> tmp;
            if(s.find(tmp) != s.end() && !found){
                cout << "YES" << endl;
                cout << "1 " << tmp << endl;
                found = true;
            }
        }
        if(!found){
            cout << "NO" << endl;
        }
    }
}
