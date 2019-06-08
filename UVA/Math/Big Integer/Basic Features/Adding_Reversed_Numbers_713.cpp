#include <bits/stdc++.h>

using namespace std;

class BigInteger{
	public:
		string value;
		BigInteger(string value){
			this->value = value;
		}
		BigInteger(){
			this->value = "0";
		}

		char & operator[](int i){
			return value[i];
		}
		void operator = (BigInteger big){
			value = big.value;
		}
		BigInteger operator + (BigInteger bigExternal){
			BigInteger bigLocal(value);
			if(bigLocal.length() >= bigExternal.length()){
				bigLocal.addLeadingZeros(2);
			}else{
				int zeros = (bigExternal.length() - bigLocal.length()) + 2;
				bigLocal.addLeadingZeros(zeros);
			}
			int indexLocal = bigLocal.length()-1, indexExternal = bigExternal.length()-1;
			int carry = 0;
			for(; indexLocal >= 0 && indexExternal >= 0; indexLocal--, indexExternal--){
				int sum = bigLocal.at(indexLocal) + bigExternal.at(indexExternal) + carry;
				carry = sum/10;
				bigLocal[indexLocal] = (sum%10)+'0';
			}
			while(carry){
				int sum = bigLocal.at(indexLocal) + carry;
				carry = sum/10;
				bigLocal[indexLocal] = (sum%10)+'0';
				indexLocal--;
			}
			bigLocal.trimLeadingZeros();
			return bigLocal;
		}
		int at(int i){
			return value[i]-'0';
		}
		void reverse(){
			for(int i = 0; i<value.length()/2; i++){
				swap(value[i], value[value.length()-1-i]);
			}
			trimLeadingZeros();
		}
		int length(){
			return (int)value.length();
		}
		void trimLeadingZeros(){
			while(*value.begin() == '0' && value.size() > 1)
				value.erase(value.begin());
		}

		void addLeadingZeros(int zeros){
			while(zeros--) value = "0" + value;
		}
};

istream & operator >> (istream &in, BigInteger &big){
	in>>big.value;
	return in;
}

ostream & operator <<(ostream &out, BigInteger big){
	out<<big.value;
	return out;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tests;
	BigInteger a,b;
	cin>>tests;
	while(tests-- && cin>>a>>b){
		a.reverse(), b.reverse();
		a = a + b;
		a.reverse();
		cout<<a<<"\n";
	}
	return 0;
}
