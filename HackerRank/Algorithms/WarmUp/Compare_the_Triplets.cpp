#include <bits/stdc++.h>

using namespace std;

int main(){
    int a[3],b[3],alice = 0, bob = 0;
    for(int x=0; x<3; x++)cin>>a[x];
    for(int x=0; x<3; x++){
        cin>>b[x];
        if(a[x]<b[x])++bob;
        if(b[x]<a[x])++alice;
    }
    cout<<alice<<" "<<bob<<endl;
    return  0;
}