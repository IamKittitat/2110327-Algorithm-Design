#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int tmp = ++n;
    while(1){
        set<int> s;
        bool found = true;
        while(tmp > 0){
            if(s.find(tmp%10) == s.end()){
                s.insert(tmp%10);
                tmp /= 10;
            } else{
                found = false;
                break;
            }
        }

        if(found){
            cout << n;
            exit(0);
        }
        tmp = ++n;
    }


}
