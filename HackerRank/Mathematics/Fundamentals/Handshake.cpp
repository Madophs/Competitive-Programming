#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tests, people;
    cin>>tests;
    while(tests-- && cin>>people){
        --people;
        int ans = (people*(people+1))/2;
        cout<<ans<<"\n";
    }
    return 0;
}