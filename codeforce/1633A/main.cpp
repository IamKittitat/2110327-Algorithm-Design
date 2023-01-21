#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,ip;
    cin >> n;
    for(int i = 0; i< n; i++){
        cin >> ip;
        int tmp = ip;
        bool found = false;
        for(int i = 0; i<ip%10+1;i++){
            if(tmp%7 == 0){
                cout << tmp << endl;
                found = true;
                break;
            }
            tmp--;
        }
        tmp = ip;
        if(!found){
            for(int i = 0 ; i < (ip-ip%10 -1);i++){
                if(tmp%7 == 0){
                    cout << tmp << endl;;
                    break;
                }
                tmp++;
            }
        }
    }
}
