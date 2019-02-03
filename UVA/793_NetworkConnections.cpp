#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
using namespace std;

class FindUnion{
public:
	FindUnion(int tam){
		alt.assign(tam+1,0);
		for(int x=0; x<=tam; x++){
			vec.push_back(x);
		}
	}
	void setUnion(int a , int b){
		if(!esUnion(a,b)){
			int r1=getUnion(a), r2=getUnion(b);
			if(alt[r1]<alt[r2]){
				vec[r1]=r2;
			}else{
				vec[r2]=r1;
			}
			if(alt[r1]==alt[r2]){
				++alt[r2];
			}
		}
	}
	bool esUnion(int a, int b){
		int r1=getUnion(a);
		int r2=getUnion(b);
		if(r1==r2)return true;
		return false;
	}

	int getUnion(int var){
		if(var==vec[var])return var;
		return getUnion(vec[var]);
	}
private:
	vector<int> vec,alt;
};
int main(){
	int c=0;
	bool di=false;
	cin>>c;
	cin.get();
	while(c--){
		if(di)cout<<endl;
		di=true;
		int com=0,yes=0,no=0;
		cin>>com;
		FindUnion f(com);
		string cadena="";
		cin.ignore();
		getline(cin,cadena);
		while(cadena.length()>0){
			int a[2];
			int cont=-1;
			char *p = strtok((char*)cadena.c_str()," ");
			while(p!=NULL){
				if(cont>=0){
					a[cont]=atoi(p);
				}
				p=strtok(NULL," ");
				++cont;
			}
			if(cadena.at(0)=='c'){
				f.setUnion(a[0],a[1]);
			}else{
				if(f.esUnion(a[0],a[1])){
					++yes;
				}else{
					++no;
				}
			}
			getline(cin,cadena);
		}
		cout<<yes<<","<<no<<endl;
	}
	return 0;
}
