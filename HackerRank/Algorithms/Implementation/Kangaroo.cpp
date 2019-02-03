#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int d1,s1,d2,s2;
    cin>>d1>>s1>>d2>>s2;
    int eq1 = (s1-s2), eq2 = (d2-d1);
    bool res = (eq1>0 && eq2>0 && max(eq1,eq2)%min(eq1,eq2)==0) || (eq1==eq2);
    cout<<(res?"YES\n":"NO\n");
    return 0;
}