#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setfill('0');
	int bytes[100];
	int pointer, tests;
	string line;
	cin>>tests;
	cin.ignore();
	for(int t = 1; t<=tests; t++){
		getline(cin,line);
		memset(bytes,0,sizeof bytes);
		pointer = 0;
		for(int i = 0; i<line.length(); i++){
			if(line[i] == '>'){
				++pointer;
			}else if(line[i] == '<'){
				--pointer;
			}else if(line[i] == '+'){
				++bytes[pointer];
			}else if(line[i] == '-'){
				--bytes[pointer];
			}
			if(pointer>=100) pointer = 0;
			if(pointer<0) pointer = 99;
			if(bytes[pointer]<-255 || bytes[pointer]>255) cout<<"hello"<<endl;
		}
		cout<<"Case "<<dec<<t<<":";
		for(int i = 0; i<100; i++){
			if(bytes[i]<0 || bytes[i]>255){
				stringstream ss;
				ss<<hex<<bytes[i];
				string value = ss.str();
				for(auto &c: value) c = toupper(c);
				cout<<" "<<setw(2)<<right<<value.substr((value.length()-2),2);
			}else{
				cout<<" "<<setw(2)<<right<<hex<<uppercase<<bytes[i];
			}
			
		}
		cout<<"\n";
	}
	return 0;
}