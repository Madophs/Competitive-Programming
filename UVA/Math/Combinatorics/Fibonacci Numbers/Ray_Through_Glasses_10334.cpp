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
	private:
		vector<unsigned int> value;
		bool positive;
		void addLeadingZeros(int);
		void removeLeadingZeros();
		void makePositiveIfZero();
		unsigned int & getValueAt(int);
		BigInteger addition(BigInteger &,BigInteger &);
		BigInteger substraction(BigInteger, BigInteger &);
		BigInteger multiplication(BigInteger, BigInteger);
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
		if(getValueAt(i) != bigNumber.getValueAt(i)) return false;
	}
	return true;
}

bool BigInteger::operator != (BigInteger &bigNumber){
	if(this->positive != bigNumber.positive) return true;
	if(value.size() != bigNumber.length()) return true;
	for(int i = 0; i<bigNumber.length(); i++){
		if(getValueAt(i) != bigNumber.getValueAt(i)) return true;
	}
	return false;
}
bool BigInteger::operator < (BigInteger &bigNumber){
	if(!this->positive && !bigNumber.positive){
		if(this->length() != bigNumber.length()){
			if(this->length() > bigNumber.length()) return true;
			return false;
		}
		for(int i = this->length()-1; i>=0; i--){
			if(this->getValueAt(i) == bigNumber.getValueAt(i)) continue;
			if(this->getValueAt(i) > bigNumber.getValueAt(i)) return true;
		}
		return false;
	}
	if(this->positive != bigNumber.positive){
		if(!this->positive && bigNumber.positive) return true;
		return false;
	}
	if(this->length() != bigNumber.length()){
		if(this->length() < bigNumber.length()) return true;
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
		if(this->length() != bigNumber.length()){
			if(this->length() > bigNumber.length()) return true;
			return false;
		}
		for(int i = this->length()-1; i>=0; i--){
			if(this->getValueAt(i) > bigNumber.getValueAt(i)) return true;
			if(this->getValueAt(i) == bigNumber.getValueAt(i)) continue;
			if(this->getValueAt(i) < bigNumber.getValueAt(i)) return false;
		}
		return true;
	}
	if(this->positive != bigNumber.positive){
		if(!this->positive && bigNumber.positive) return true;
		return false;
	}
	if(this->length() != bigNumber.length()){
		if(this->length() < bigNumber.length()) return true;
		return false;
	}
	for(int i = this->length()-1; i>=0; i--){
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
		ret += this->getValueAt(i)+'0';
	}
	if(!isPositive()) ret = "-" + ret;
	return ret;
}
void BigInteger::addLeadingZeros(int zeros){
	while(zeros--) value.emplace_back(0);
}

void BigInteger::removeLeadingZeros(){
	while(value.back() == 0 && value.size() > 1)
		value.pop_back();
}
void BigInteger::makePositiveIfZero(){
	if(this->length() > 1) return;
	if(!this->getValueAt(0)) positive = true;
}

void BigInteger::addToTheBeginning(int val, int cant){
	while(cant--) value.insert(value.begin(),val);
}

unsigned int & BigInteger::getValueAt(int index){
	return value[index];
}
BigInteger BigInteger::addition(BigInteger &big1, BigInteger &big2){
	if(big1.isPositive() != big2.isPositive()){
		if(big1.length() != big2.length()){
			if(big1.length() > big2.length()){
				return substraction(big1,big2);
			}else{
				return substraction(big2,big1);
			}
		}else{
			for(int i = big1.length()-1; i>=0; i--){
				if(big1.getValueAt(i) == big2.getValueAt(i)) continue;
				if(big1.getValueAt(i) > big2.getValueAt(i)) return substraction(big1,big2);
				return substraction(big2,big1);
			}
			return BigInteger();
		}
	}

	BigInteger result;
	result.addLeadingZeros(max(big1.length(),big2.length())+1);
	int i = 0, carry = 0, maxLength = max(big1.length(), big2.length());
	for(; i < maxLength; i++){
		int sum = (i<big1.length()?big1.getValueAt(i):0) + (i<big2.length()?big2.getValueAt(i):0) + carry;
		carry = sum/10;
		result.getValueAt(i) = sum%10;
	}
	while(carry) result.getValueAt(i++) = carry, carry = carry/10;
	result.removeLeadingZeros();
	result.positive = big1.positive;
	result.makePositiveIfZero();
	return result;
}

BigInteger BigInteger::substraction(BigInteger big1, BigInteger &big2){
	BigInteger result;
	result.addLeadingZeros(big1.length());
	for(int i = 0; i<big1.length(); i++){
		int diff = 0;
		if(i < big2.length() && big1.getValueAt(i) < big2.getValueAt(i)){
			for(int j = i+1; j<big1.length(); j++){
				if(big1.getValueAt(j)){
					--big1.getValueAt(j);
					break;
				}else{
					big1.getValueAt(j) = 9;
				}
			}
			int val1 = big1.getValueAt(i)+10, val2 = big2.getValueAt(i);
			result.getValueAt(i) = val1-val2;
		}else{
			result.getValueAt(i) = big1.getValueAt(i) - (i<big2.length()?big2.getValueAt(i):0);
		}
	}
	if(!big1.isPositive()){
		result.positive = false;
	}
	result.removeLeadingZeros();
	result.makePositiveIfZero();
	return result;
}

BigInteger BigInteger::multiplication(BigInteger big1, BigInteger big2){
	if(big1.length() == 1 && big2.length() == 1){
		int val1 = atoi(big1.toString().c_str()), val2 = atoi(big2.toString().c_str());;
		BigInteger result(to_string(val1*val2));
		return result;
	}
	if(big1.length() & 1) big1.addLeadingZeros(1);
	if(big2.length() & 1) big2.addLeadingZeros(1);
	int maxLength = max(big1.length(), big2.length());
	big1.addLeadingZeros(maxLength-big1.length());
	big2.addLeadingZeros(maxLength-big2.length());
	BigInteger bigNum1H, bigNum1L, bigNum2H, bigNum2L;
	int splitSize = maxLength>>1;
	bigNum1H.addLeadingZeros(splitSize-1), bigNum1L.addLeadingZeros(splitSize-1),
	bigNum2H.addLeadingZeros(splitSize-1), bigNum2L.addLeadingZeros(splitSize-1);
	for(int i = 0; i<maxLength; i++){
		if(i < splitSize){
			bigNum1H[i] = big1[i];
			bigNum2H[i] = big2[i]; 
		}else{
			bigNum1L[i-splitSize] = big1[i];
			bigNum2L[i-splitSize] = big2[i];
		}
	}
	BigInteger A = multiplication(bigNum1H, bigNum2H);
	BigInteger D = multiplication(bigNum1L, bigNum2L);
	BigInteger E = multiplication(bigNum1H+bigNum1L,bigNum2H+bigNum2L) - A - D;
	A.addToTheBeginning(0,maxLength);
	E.addToTheBeginning(0,maxLength/2);
	BigInteger result =  A + E + D;
	if(big1.isPositive() != big2.isPositive()){
		result.positive = false;
	}else{
		result.positive = true;
	}
	result.removeLeadingZeros();
	return result;
}


BigInteger fibos[1002];

void calculateFibos(){
	BigInteger x(1), y(2),z;
	for(int i = 0; i<1002; i++){
		fibos[i] = x;
		z = x + y;
		x = y;
		y = z;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	calculateFibos();
	int nth;
	while(cin>>nth){
		cout<<fibos[nth]<<"\n";
	}
	return 0;
}
