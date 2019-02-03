#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n;
    int last[n];
    for(int x=0; x<n && cin>>last[x];x++);
    cin>>m;
    int original[m];
    for(int x=0; x<m && cin>>original[x]; x++);
    sort(last,last+n);
    sort(original,original+m);
    int i=0,j=0;
    int ant = -1;
    while(i<m || j < n){
        if(i<m && j < n){
            if(original[i]==last[j]){
                ++i,++j;
            }else if(original[i] < last[j]){
                if(ant!=original[i])cout<<original[i]<<" ";
                ant = original[i];
                ++i;
            }
        }else{
            for(; i<m; i++){
                if(ant!=original[i])cout<<original[i]<<" ";
                ant = original[i];
            }
        }
    }
    cout<<endl;
    return 0;
}