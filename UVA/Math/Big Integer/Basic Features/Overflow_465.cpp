#include <bits/stdc++.h>

using namespace std;

class BigInteger{
	public:
		string value;
		BigInteger(){
			this->value = "0";
		}
		BigInteger(int value){
			this->value = to_string(value);
		}
		void sum(BigInteger &bigInteger){
			if(value.length() >= bigInteger.value.length()){
				addLeadingZeros(2);
			}else{
				int zeros = (bigInteger.value.length() - value.length()) + 2;
				addLeadingZeros(zeros);
			}	
			int indexLocal = value.length()-1, indexExternal = bigInteger.value.length()-1;
			int carry = 0;
			for(; indexLocal >= 0 && indexExternal >= 0; indexLocal--, indexExternal--){
				int val1 = value[indexLocal]-'0', val2 = bigInteger.value[indexExternal]-'0';
				int sum = (val1+val2+carry);
				carry = sum/10;
				value[indexLocal] = (sum%10)+'0';
			}
			while(carry){
				int val = (value[indexLocal]-'0') + carry;
				carry = val/10;
				value[indexLocal] = (val%10)+'0';
				--indexLocal;
			}
			trimLeadingZeros();
		}

		void multiply(BigInteger &bigInteger){
			string result(value.length()+bigInteger.value.length()+3,'0');
			int i,j, carry = 0, pos = result.length(), index = 0;
			for(i = value.length()-1; i>=0; i--){
				carry = 0, --pos, index = 0;
				for(j = bigInteger.value.length()-1; j>=0; j--){
					int val1 = value[i]-'0', val2 = bigInteger.value[j]-'0';
					int product = (val1*val2)+carry + (result[pos-index]-'0');
					carry = product/10;
					result[pos-index] = (product%10)+'0';
					++index;
				}
				while(carry){
					result[pos-index] = (carry%10)+'0';
					carry/=10;
					++index;
				}
			}
			value = result;
			trimLeadingZeros();
		}
		
		bool operator > (BigInteger &bigInteger){
			if(value.length() != bigInteger.value.length()){
				if(value.length() > bigInteger.value.length()) return true;
				else return false;
			}
			return value.length() == bigInteger.value.length() && value > bigInteger.value;
		}

		void trimLeadingZeros(){
			while(*value.begin() == '0' && value.size() > 1)
				value.erase(value.begin());
		}

		void addLeadingZeros(int zeros){
			while(zeros--) value = "0" + value;
		}
};

istream & operator >> (istream &in, BigInteger &bigInteger){
	in>>bigInteger.value;
	return in;
}

ostream & operator << (ostream &out, const BigInteger &bigInteger){
	out<<bigInteger.value;
	return out;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string line;
	int maxValue = numeric_limits<int>::max();
	BigInteger a, b, limit(maxValue);
	char opChar;
	while(getline(cin,line)){
		stringstream ss(line);
		ss>>a>>opChar>>b;
		cout<<line<<"\n";
		a.trimLeadingZeros(), b.trimLeadingZeros();
		if(a > limit){
			cout<<"first number too big\n";
		}
		if(b > limit){
			cout<<"second number too big\n";
		}
		if(opChar == '+'){
			a.sum(b);
		}else{
			a.multiply(b);
		}
		if(a > limit){
			cout<<"result too big\n";
		}
	}
	return 0;
}
