#include <iostream>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
char minusculas(char letra){
	return std::tolower(letra);
}
bool espacio(char letra){
	return letra==' ';
}
int main(){
	string ana="",diana="";
	int casos=0;
	cin>>casos;
	cin.ignore();
	while(casos--){
		getline(cin,ana);
		getline(cin,diana);
		string::iterator iter;
		std::transform(ana.begin(), ana.end(),ana.begin(),minusculas);
		std::transform(diana.begin(), diana.end(),diana.begin(),minusculas);
		iter=std::remove_if(ana.begin(),ana.end(),espacio);
		ana.resize(iter-ana.begin());
		iter=std::remove_if(diana.begin(),diana.end(),espacio);
		diana.resize(iter-diana.begin());
		std::sort(ana.begin(),ana.end());
		std::sort(diana.begin(),diana.end());
		if(ana==diana){
			cout<<"SI"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
