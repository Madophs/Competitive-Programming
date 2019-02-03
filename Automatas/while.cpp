#include <bits/stdc++.h>

using namespace std;

int tablaAutomata(int f, int c){
    int tabla[17][14]={
        //w  h   i  l  e (  L <=>! ) {  \n ;   } " "
        { 1,17,17,17,17,17,17,17,17,17,17,17,17,17}, // Estado 0
        {17, 2,17,17,17,17,17,17,17,17,17,17,17,17}, // Estado 1
        {17,17, 3,17,17,17,17,17,17,17,17,17,17,17}, // Estado 2
        {17,17,17, 4,17,17,17,17,17,17,17,17,17,17}, // Estado 3
        {17,17,17,17, 5,17,17,17,17,17,17,17,17,17}, // Estado 4
        {17,17,17,17,17, 6,17,17,17,17,17,17,17,17}, // Estado 5
        {17,17,17,17,17,17, 7,17,17,17,17,17,17, 6}, // Estado 6
        {17,17,17,17,17,17,17, 8,17,17,17,17,17, 7}, // Estado 7
        {17,17,17,17,17,17, 9,17,17,17,17,17,17, 8}, // Estado 8
        {17,17,17,17,17,17,17,17,10,17,17,17,17, 9}, // Estado 9
        {17,17,17,17,17,17,17,17,17,11,17,17,17,17}, // Estado 10
        {17,17,17,17,17,17,17,17,17,17,12,17,17,17}, // Estado 11
        {17,17,17,17,17,17,13,17,17,17,17,17,17,17}, // Estado 12
        {17,17,17,17,17,17,17,17,17,17,17,14,17,17}, // Estado 13
        {17,17,17,17,17,17,17,17,17,17,15,17,17,17}, // Estado 14
        {17,17,17,17,17,17,17,17,17,17,17,17,16,17}, // Estado 15
        {17,17,17,17,17,17,17,17,17,17,17,17,17,17}  // Estado 16
    };
    if(c =='w' && f==0){
        return 1;
    }else if(c=='h' && f==1){
        return 2;
    }else if(c=='i' && f==2){
        return 3;
    }else if(c=='l' && f==3){
        return 4;
    }else if(c=='e' && f==4){
        return 5;
    }else if(c=='(' && f==5){
        return 6;
    }else if((c=='>' || c=='=' || c=='<') && f==7){
        return 8;
    }else if(c==')' && f==9){
        return 10;
    }else if(c=='{' && f==10){
        return 11;
    }else if(c=='}' && f==15){
        return 16;
    }else if(c=='\n' && (f==14 || f==11)){
        switch(f){
            case 14:
                return 15;
                break;
            case 11:
                return 12;
                break;
        }
    }else if(((c>='a' && c<='z') ||(c>='A' && c<='Z')) && (f==6 || f==8 || 
        f==12)){
        switch(f){
            case 6:
                return 7;
                break;
            case 8:
                return 9;
                break;
            case 12:
                return 13;
                break;
        }
        }else if(c==' ' && (f>=6 && f<=9)){
            return f;
        }else if(c==';' && f==13){
            return 14;
        }
        return 17;
}
int main(){
    ios::sync_with_stdio(false);
    string cadena="",aux;
    
    cadena = "while(  n = j  ){\nZ;\n}";
    bool continua=true;
    while(continua){
        cout<<"Ingrese un automata de la forma\n(EOF = fin del automata)\n"
        "Para salir en una linea escriba exit\n"
        "while(x<y){\n"
        "x;\n"
        "}\n";
        bool salto=false;
        cadena="";
        while(getline(cin,aux) && !aux.empty()){
            if(aux=="exit"){
                continua=false;
                break;
            }
            if(salto)cadena+="\n";
            cadena+=aux;
            salto=true;
        }
        if(!continua)break;
        cout<<cadena<<endl;
        int estado=0;
        for(auto iter = cadena.begin(); iter!=cadena.end(); iter++){
            estado=tablaAutomata(estado,*iter);
            if(*iter=='\n'){
                cout<<setw(4)<<setfill(' ')<<left<<"\\n"<<" -> 
                "<<setw(2)<<setfill('0')<<right<<(estado==17?-1:estado)<<endl;
            }else if(*iter==' '){
                cout<<setw(4)<<setfill(' ')<<left<<"\" \""<<" -> 
                "<<setw(2)<<setfill('0')<<right<<(estado==17?-1:estado)<<endl;
            }else{
                cout<<setw(4)<<setfill(' ')<<left<<*iter<<" -> 
                "<<setw(2)<<setfill('0')<<right<<(estado==17?-1:estado)<<endl;
            }
        }
        cout<<endl;
        if(estado==16){
            cout<<"El automata esta escrito correctamente"<<endl;
        }else{
            cout<<"El automata esta mal escrito"<<endl;
        }
        string prueba="while( d >t){\nh;\n}";
        regex mientras("^while\\( *[a-z|A-Z] *[<|>|=]\\ *[a-z|A-Z]\\ 
        *\\)\\{\n[a-z|A-Z];\n\\}$");
        if(regex_match(cadena,mientras)){
            cout<<"La cadena es valida"<<endl;
        }else{
            cout<<"La cadena no es valida"<<endl;
        }
		cout<<endl;
	}
	cout<<"Hasta la vista"<<endl;
	return 0;
}

