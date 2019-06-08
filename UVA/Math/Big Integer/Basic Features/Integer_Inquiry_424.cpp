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

		void sumBigInteger(BigInteger &number){
			if(value.length() >= number.value.length()){
				addLeadingZeros(2);
			}else{
				int zeros = (number.value.length() - value.length()) + 2;
				addLeadingZeros(zeros);
			}
			int indexLocal = value.length()-1, indexExternal = number.value.length()-1;
			int carry = 0;
			for(; indexLocal >= 0 && indexExternal >= 0; indexLocal--, indexExternal--){
				int val1 = (value[indexLocal]-'0'), val2 = (number.value[indexExternal]-'0');
				int sum = (val1+val2+carry);
				carry = (sum)/10;
				value[indexLocal] = (sum%10)+'0';
			}
			while(carry){
				int val1 = (value[indexLocal]-'0');
				int sum = (val1+carry);
				carry = sum/10;
				value[indexLocal] = (sum%10)+'0';
				--indexLocal;
			}
			trimLeadingZeros();
		}
		bool operator ==(BigInteger &bigInteger){
			return this->value == bigInteger.value;
		}
		bool operator ==(string value){
			return this->value == value;
		}
		bool operator !=(BigInteger &bigInteger){
			return this->value != bigInteger.value;
		}
		bool operator !=(string value){
			return this->value != value;
		}
	private:
		void addLeadingZeros(int zeros){
			while(zeros--) value = "0" + value; 
		}
		void trimLeadingZeros(){
			while(*value.begin() == '0' && value.size()>1)
				value.erase(value.begin());
		}
};

istream & operator>>(istream &in,BigInteger &bigInteger){
	in>>bigInteger.value;
	return in;
}

ostream & operator<<(ostream &out, const BigInteger &bigInteger){
	out<<bigInteger.value;
	return out;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	BigInteger ans, number;
	while(cin>>number && number!="0"){
		ans.sumBigInteger(number);
	}
	cout<<ans<<endl;
	return 0;
}
