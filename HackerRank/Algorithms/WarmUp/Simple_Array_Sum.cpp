#include <bits/stdc++.h>

using namespace std;

int main()
{
    int count,var,res;
    count=var=res=0;
    cin>>count;
    while(count--){
        cin>>var;
        res+=var;
    }
    cout<<res<<endl;
    return 0;
}
