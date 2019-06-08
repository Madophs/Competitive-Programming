#include <bits/stdc++.h>

using namespace std;

class BigInteger{
	public:
		BigInteger();
		BigInteger(string);
		BigInteger(int);
		BigInteger(long long);
		BigInteger operator + (BigInteger);
		BigInteger operator += (BigInteger);
		BigInteger & operator ++();
		BigInteger operator ++(int);
		BigInteger operator - (BigInteger);
		BigInteger operator -= (BigInteger);
		BigInteger & operator --();
		BigInteger operator --(int);
		BigInteger operator * (BigInteger);
		BigInteger operator *= (BigInteger);
		BigInteger operator / (BigInteger);
		BigInteger operator /= (BigInteger);
		BigInteger operator % (BigInteger);
		BigInteger operator %= (BigInteger);
		unsigned int & operator[](int);
		void operator = (BigInteger);
		bool operator == (BigInteger &);
		bool operator != (BigInteger &);
		bool operator < (BigInteger &);
		bool operator <= (BigInteger &);
		bool operator > (BigInteger &);
		bool operator >= (BigInteger &);
		void print();
		int length();
		bool isPositive();
		void readString(string);
		string toString();
		void addToTheBeginning(int val, int cant = 1);
		vector<unsigned int> value;
	private:
		bool positive;
		void addLeadingZeros(int);
		void removeLeadingZeros();
		void makePositiveIfZero();
		unsigned int & getValueAt(int);
		BigInteger addition(BigInteger ,BigInteger );
		BigInteger substraction(BigInteger, BigInteger &);
		BigInteger multiplication(BigInteger, BigInteger);
		BigInteger longMultiplication(BigInteger &, BigInteger &);
		BigInteger karatsubaMultiplication(BigInteger&, BigInteger&);
		BigInteger division(BigInteger &, BigInteger &);
		BigInteger pow(BigInteger &);
		BigInteger pow(int);
};

BigInteger::BigInteger(){
	this->value.emplace_back(0);
	positive = true;
}

BigInteger::BigInteger(string stringValue){
	readString(stringValue);
}

BigInteger::BigInteger(int integerValue){
	string stringValue = to_string(integerValue);
	readString(stringValue);
}

BigInteger::BigInteger(long long LLValue){
	string stringValue = to_string(LLValue);
	readString(stringValue);
}
BigInteger BigInteger::operator + (BigInteger bigNumber){
	return addition(*this,bigNumber);
}

BigInteger BigInteger::operator += (BigInteger bigNumber){
	*this = addition(*this,bigNumber);
	return *this;
}
BigInteger & BigInteger::operator ++ (){
	BigInteger one("1");
	*this = addition(*this,one);
	return *this;
}

BigInteger BigInteger::operator ++ (int){
	BigInteger one("1");
	BigInteger prevCopy = *this;
	*this = addition(*this,one);
	return prevCopy;
}

BigInteger BigInteger::operator - (BigInteger bigNumber){
	bigNumber.positive = !bigNumber.positive;
	return addition(*this, bigNumber);
}

BigInteger BigInteger::operator -= (BigInteger bigNumber){
	bigNumber.positive = !bigNumber.positive;
	*this = addition(*this,bigNumber);
	return *this;
}

BigInteger & BigInteger::operator -- (){
	BigInteger one("1");
	one.positive = false;
	*this = addition(*this,one);
	return *this;
}
BigInteger BigInteger::operator --(int){
	BigInteger one("1");
	one.positive = false;
	BigInteger prevCopy = *this;
	*this = addition(*this,one);
	return prevCopy;
}

BigInteger BigInteger::operator * (BigInteger bigNumber){
	BigInteger result = multiplication(*this,bigNumber);
	return result;
}
unsigned int & BigInteger::operator[](int index){
	return this->value[this->length()-1-index];
}

void BigInteger::operator = (BigInteger bigNumber){
	this->value = bigNumber.value;
	this->positive = bigNumber.positive;
}

bool BigInteger::operator == (BigInteger &bigNumber){
	if(this->positive != bigNumber.positive) return false;
	if(value.size() != bigNumber.length()) return false;
	for(int i = 0; i<bigNumber.length(); i++){
		if(value[i] != bigNumber.value[i]) return false;
	}
	return true;
}

bool BigInteger::operator != (BigInteger &bigNumber){
	if(this->positive != bigNumber.positive) return true;
	if(value.size() != bigNumber.length()) return true;
	for(int i = 0; i<bigNumber.length(); i++){
		if(value[i] != bigNumber.value[i]) return true;
	}
	return false;
}
bool BigInteger::operator < (BigInteger &bigNumber){
	if(!this->positive && !bigNumber.positive){
		if(this->value.size() != bigNumber.value.size()){
			if(this->value.size() > bigNumber.value.size()) return true;
			return false;
		}
		for(int i = this->length()-1; i>=0; i--){
			if(this->value[i] == bigNumber.value[i]) continue;
			if(this->value[i] > bigNumber.value[i]) return true;
		}
		return false;
	}
	if(this->positive != bigNumber.positive){
		if(!this->positive && bigNumber.positive) return true;
		return false;
	}
	if(this->value.size() != bigNumber.value.size()){
		if(this->value.size() < bigNumber.value.size()) return true;
		return false;
	}
	for(int i = this->length()-1; i>=0; i--){
		if(this->value[i] == bigNumber.value[i]) continue;
		if(this->value[i] < bigNumber.value[i]) return true;
	}
	return false;
}

bool BigInteger::operator <= (BigInteger &bigNumber){
	if(!this->positive && !bigNumber.positive){
		if(this->value.size() != bigNumber.value.size()){
			if(this->value.size() > bigNumber.value.size()) return true;
			return false;
		}
		for(int i = this->length()-1; i>=0; i--){
			if(this->value[i] > bigNumber.value[i]) return true;
			if(this->value[i] == bigNumber.value[i]) continue;
			if(this->value[i] < bigNumber.value[i]) return false;
		}
		return true;
	}
	if(this->positive != bigNumber.positive){
		if(!this->positive && bigNumber.positive) return true;
		return false;
	}
	if(this->value.size() != bigNumber.value.size()){
		if(this->length() < bigNumber.value.size()) return true;
		return false;
	}
	for(int i = this->value.size()-1; i>=0; i--){
		if(this->value[i] < bigNumber.value[i]) return true;
		if(this->value[i] == bigNumber.value[i]) continue;
		if(this->value[i] > bigNumber.value[i]) return false;
	}
	return true;
}

bool BigInteger::operator > (BigInteger &bigNumber){
	return !(*this <= bigNumber);
}

bool BigInteger::operator >= (BigInteger &bigNumber){
	return !(*this < bigNumber);
}
istream & operator >> (istream &in,BigInteger &bigInteger){
	string str;
	in>>str;
	bigInteger.readString(str);
	return in;
}

ostream & operator << (ostream &out, BigInteger bigInteger){
	if(!bigInteger.isPositive()) cout<<"-";
	for(int i = 0; i < bigInteger.length(); i++){
		out<<bigInteger[i];
	}
	return out;
}
int BigInteger::length(){
	return this->value.size();
}
bool BigInteger::isPositive(){
	return this->positive;
}
void BigInteger::readString(string str){
	if(str.empty())return;
	value.clear();
	positive = str[0] != '-';
	for(int i = str.length()-1; i>-1+!positive; i--){
		this->value.emplace_back(str[i]-'0');
	}
	removeLeadingZeros();
	makePositiveIfZero();
}

string BigInteger::toString(){
	string ret = "";
	for(int i = this->length()-1; i>=0; i--){
		ret += this->value[i]+'0';
	}
	if(!isPositive()) ret = "-" + ret;
	return ret;
}
void BigInteger::addLeadingZeros(int zeros){
	value.resize(value.size()+zeros);
}

void BigInteger::removeLeadingZeros(){
	while(value.back() == 0 && value.size() > 1)
		value.pop_back();
}
void BigInteger::makePositiveIfZero(){
	if(this->value.size()> 1) return;
	if(!this->getValueAt(0)) positive = true;
}

void BigInteger::addToTheBeginning(int val, int cant){
	if(cant<=0) return;
	value.resize(value.size()+cant,val);
	for(int i = value.size()-1; i>=cant; i--){
		swap(value[i],value[i-cant]);
	}
}

unsigned int & BigInteger::getValueAt(int index){
	return value[index];
}
BigInteger BigInteger::addition(BigInteger big1, BigInteger big2){
	if(big1.isPositive() != big2.isPositive()){
		if(big1.value.size() != big2.value.size()){
			if(big1.value.size() > big2.value.size()){
				return substraction(big1,big2);
			}else{
				return substraction(big2,big1);
			}
		}else{
			for(int i = big1.value.size()-1; i>=0; i--){
				if(big1.value[i] == big2.value[i]) continue;
				if(big1.value[i] > big2.value[i]) return substraction(big1,big2);
				return substraction(big2,big1);
			}
			return BigInteger();
		}
	}

	if(big1.value.size() < big2.value.size()) swap(big1,big2);
	int i = 0, carry = 0, sum;
	big1.addLeadingZeros(1);
	for(; i < big1.length(); i++){
		sum = big1.value[i] + big2.value[i] + carry;
		carry = sum/10;
		big1.value[i] = sum%10;
		if(i+1 == big2.value.size() && ++i) break;
	}
	while(carry)
		sum = big1.value[i] + carry,
		big1.value[i++] = sum%10, carry = sum/10;

	big1.removeLeadingZeros();
	big1.makePositiveIfZero();
	return big1;
}

BigInteger BigInteger::substraction(BigInteger big1, BigInteger &big2){
	big1.addLeadingZeros(1);
	for(int i = 0; i<big1.value.size(); i++){
		if(big1.value[i] < big2.value[i]){
			for(int j = i+1; j<big1.value.size(); j++){
				if(big1.value[j]){
					--big1.value[j];
					break;
				}else{
					big1.value[j] = 9;
				}
			}
			int val1 = big1.value[i]+10, val2 = big2.value[i];
			big1.value[i] = val1-val2;
			if(i+1==big2.value.size()) break;
		}else{
			big1.value[i] = big1.value[i] - big2.value[i];
			if(i+1==big2.value.size()) break;
		}
	}
	big1.removeLeadingZeros();
	big1.makePositiveIfZero();
	return big1;
}

BigInteger BigInteger::multiplication(BigInteger big1, BigInteger big2){
	return karatsubaMultiplication(big1, big2);
}

BigInteger BigInteger::longMultiplication(BigInteger &big1, BigInteger &big2){
	BigInteger result;
	result.value.resize(big1.value.size()+big2.value.size()+1);
	int i,j,carry = 0, product;
	for(i = 0; i<big1.value.size(); i++){
		carry = 0;
		for(j = 0; j<big2.value.size(); j++){
			product = (big2.value[j]*big1.value[i]) + carry + result.value[i+j];
			carry = product/10;
			result.value[i+j] = product%10;
		}
		while(carry)
			product = result.value[i+j] + carry,
			result.value[i+j] = product%10,
			carry = product/10, ++j;
	}
	result.removeLeadingZeros();
	result.positive = big1.positive == big2.positive;
	makePositiveIfZero();
	return result;
}

BigInteger BigInteger::karatsubaMultiplication(BigInteger &big1, BigInteger &big2){
	if(big1.value.size() * big2.value.size() < 6000){
		return longMultiplication(big1,big2);
	}
	int splitSize = (max(big1.value.size(), big2.value.size())+1)>>1;
	BigInteger bigNum1H, bigNum1L, bigNum2H, bigNum2L;
	if(((int)big1.value.size()) - splitSize <= 0){
		bigNum1L.value = big1.value;
	}else{
		bigNum1L.value.assign(big1.value.begin(), big1.value.begin()+splitSize);
		bigNum1H.value.assign(big1.value.begin()+splitSize,big1.value.end());
	}
	if(((int)big2.value.size()) - splitSize <= 0){
		bigNum2L.value = big2.value;
	}else{
		bigNum2L.value.assign(big2.value.begin(), big2.value.begin()+splitSize);
		bigNum2H.value.assign(big2.value.begin()+splitSize,big2.value.end());
	}
	BigInteger sumA = bigNum1H+bigNum1L, sumB = bigNum2H+bigNum2L;
	BigInteger A = karatsubaMultiplication(bigNum1H, bigNum2H);
	BigInteger D = karatsubaMultiplication(bigNum1L, bigNum2L);
	BigInteger E = karatsubaMultiplication(sumA,sumB) - A - D;
	A.addToTheBeginning(0,splitSize<<1);
	E.addToTheBeginning(0,splitSize);
	BigInteger result =  A + E + D;
	if(big1.positive != big2.positive){
		result.positive = false;
	}else{
		result.positive = true;
	}
	result.removeLeadingZeros();
	return result;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	BigInteger limit;
	limit.value.assign(61,0);
	limit[0] = 1;
	vector<BigInteger> upper(1), lower(2);
	upper[0] = BigInteger("1");
	bool turn = true, finish = false;
	cout<<upper[0]<<"\n";
	for(int i = 0; !finish ;++i){
		if(turn){
			for(int y = 0; y<lower.size(); y++){
				if(y) cout<<" ";
				if(y == 0 || y+1 == lower.size()){
					lower[y] = BigInteger("1");
					cout<<1;
				}else{
					lower[y] = upper[y] + upper[y-1];
					if(lower[y]>=limit) finish = true;
					cout<<lower[y];
				}
			}
			cout<<"\n";
			upper.resize(lower.size()+1,BigInteger());
			turn=!turn;
		}else{
			for(int y = 0; y<upper.size(); y++){
				if(y) cout<<" ";
				if(y == 0 || y+1 == upper.size()){
					upper[y] = BigInteger("1");
					cout<<1;
				}else{
					upper[y] = lower[y] + lower[y-1];
					if(upper[y]>=limit) finish = true;
					cout<<upper[y];
				}
			}
			cout<<"\n";
			lower.resize(upper.size()+1, BigInteger());
			turn=!turn;
		}
	}
	return 0;
}
