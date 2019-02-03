#include <iostream>
#include <bitset>

using namespace std;

int main(){
	unsigned long num=0;
	cin>>num;
	while(num!=0){
		unsigned int cont=0;
		string s =(bitset<32>(num)).to_string();
		int pos = s.find_first_of('1');
		for(unsigned int x=0; x<s.length(); x++){
			if(s.at(x)=='0') continue;
			++cont;
		}
		cout<<"The parity of "<<s.substr(pos,s.length()-pos)<<" is "<<cont<<" (mod 2)."<<endl;

		cin>>num;
	}
	return 0;
}
