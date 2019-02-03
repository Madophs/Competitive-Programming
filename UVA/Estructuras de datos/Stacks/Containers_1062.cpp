#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    string cadena;
    int letras[26]; 
    vector< stack<int> > valores;
    while(cin>>cadena && cadena!="end"){
        memset(letras,0,sizeof(letras));
        valores.clear();
        for(auto iter = cadena.begin(); iter!=cadena.end(); iter++)++letras[*iter-'A'];
        sort(cadena.begin(),cadena.end());
        int ant = 0, act = 0,cont = 0, c=0;
        for(auto iter = cadena.begin(); iter!=cadena.end(); iter++){
            ant = act;
            act = *iter;
            if(c==0){
                c++;
                continue;
            }
            if(ant == act || ant+1 == act)continue;
            ++cont;
        }
         if(ant == act || ant+1 == act)++cont;
        cout<<cont<<"\n";
    }
    return 0;
}
