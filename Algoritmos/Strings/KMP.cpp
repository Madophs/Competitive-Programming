#include <bits/stdc++.h>

using namespace std;

void kmpPreprocess(string &cadena, int *p){
    int i = 0, j = -1;
    p[0] = -1;
    while(i < cadena.length()){
        if(j>=0 && cadena[i]!=cadena[j]) j=p[j];
        ++i,++j;
        p[i] = j;
    }
    for(int x=0; x<cadena.length()+1; x++){
        cout<<p[x]<<" ";
    }
    cout<<endl;
}

void kmpSearch(string &cadena, string &texto, int *p){
    int i = 0, j = 0, cont = 0;
    while(i < texto.length()){
        if(j>=0 && cadena[j]!=texto[i]) j = p[j];
        ++j,++i;
        if(j==cadena.length()){
            cout<<"match at position ["<<i-j<<"]\n";
            j = p[j];
            ++cont;
        }
    }
    cout<<"Number of matches "<<cont<<endl;
}
int main(int argc, char const *argv[])
{
    string texto = "I DO NOT LIKE SEVENTY SEV BUT SEVENTY SEVENTY SEVEN";
    string cadena;
    cin>>cadena;
    int *pattern = new int[cadena.length()+1];
    kmpPreprocess(cadena,pattern);
    kmpSearch(cadena,texto,pattern);
    return 0;
}
