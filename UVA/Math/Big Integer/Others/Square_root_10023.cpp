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
		bool operator == (BigInteger);
		bool operator != (BigInteger);
		bool operator < (BigInteger);
		bool operator <= (BigInteger);
		bool operator > (BigInteger);
		bool operator >= (BigInteger);
		void print();
		int length();
		bool isPositive();
		bool absGreater(BigInteger &);
		bool absLesser(BigInteger &);
		void readString(string);
		string toString();
		void addToTheBeginning(int val, int cant = 1);
		pair<BigInteger,BigInteger> resultAndRemainder(BigInteger);
		BigInteger ZERO() const;
		BigInteger ONE() const;
		BigInteger pow(int);
		BigInteger sqrt();
		vector<unsigned int> value;
		BigInteger fastDivisionByTwo(BigInteger);
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
		BigInteger longDivision(BigInteger, BigInteger &);
		BigInteger mod(BigInteger, BigInteger&);
};
// Constructors

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

// Relational Operators

bool BigInteger::operator == (BigInteger bigNumber){
	bigNumber.removeLeadingZeros();
	if(this->positive != bigNumber.positive) return false;
	if(value.size() != bigNumber.length()) return false;
	for(int i = 0; i<bigNumber.length(); i++){
		if(value[i] != bigNumber.value[i]) return false;
	}
	return true;
}

bool BigInteger::operator != (BigInteger bigNumber){
	bigNumber.removeLeadingZeros();
	if(this->positive != bigNumber.positive) return true;
	if(value.size() != bigNumber.length()) return true;
	for(int i = 0; i<bigNumber.length(); i++){
		if(value[i] != bigNumber.value[i]) return true;
	}
	return false;
}

bool BigInteger::operator < (BigInteger bigNumber){
	bigNumber.removeLeadingZeros();
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
		if(!this->positive) return true;
		return false;
	}
	if(this->value.size() != bigNumber.value.size()){
		return this->value.size() < bigNumber.value.size();
	}
	for(int i = this->value.size()-1; i>=0; i--){
		if(this->value[i] == bigNumber.value[i]) continue;
		if(this->value[i] < bigNumber.value[i]) return true;
		return false;
	}
	return false;
}

bool BigInteger::operator <= (BigInteger bigNumber){
	bigNumber.removeLeadingZeros();
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
		return false;
	}
	return true;
}

bool BigInteger::operator > (BigInteger bigNumber){
	return !(*this <= bigNumber);
}

bool BigInteger::operator >= (BigInteger bigNumber){
	return !(*this < bigNumber);
}

// Arithmetic Operators

BigInteger BigInteger::operator + (BigInteger bigNumber){
	return addition(*this,bigNumber);
}

BigInteger BigInteger::operator - (BigInteger bigNumber){
	bigNumber.positive = !bigNumber.positive;
	return addition(*this, bigNumber);
}

BigInteger BigInteger::operator * (BigInteger bigNumber){
	return multiplication(*this,bigNumber);
}

BigInteger BigInteger::operator / (BigInteger bigNumber){
	return division(*this, bigNumber);
}

BigInteger BigInteger::operator % (BigInteger bigNumber){
	return mod(*this,bigNumber);
}

// Increment and Decrement Operators

BigInteger BigInteger::operator ++ (int){
	BigInteger one("1");
	BigInteger prevCopy = *this;
	*this = addition(*this,one);
	return prevCopy;
}

BigInteger & BigInteger::operator ++ (){
	BigInteger one("1");
	*this = addition(*this,one);
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

// Assigment Operators

void BigInteger::operator = (BigInteger bigNumber){
	this->value = bigNumber.value;
	this->positive = bigNumber.positive;
}
BigInteger BigInteger::operator += (BigInteger bigNumber){
	*this = addition(*this,bigNumber);
	return *this;
}

BigInteger BigInteger::operator -= (BigInteger bigNumber){
	bigNumber.positive = !bigNumber.positive;
	*this = addition(*this,bigNumber);
	return *this;
}

BigInteger BigInteger::operator *= (BigInteger bigNumber){
	*this =  multiplication(*this,bigNumber);
	return *this;
}

BigInteger BigInteger::operator /= (BigInteger bigNumber){
	*this = *this / bigNumber;
	return *this;
}

BigInteger BigInteger::operator %= (BigInteger bigNumber){
	*this = mod(*this, bigNumber);
	return *this;
}

// Stream Operators

ostream & operator << (ostream &out, BigInteger bigInteger){
	if(!bigInteger.isPositive()) cout<<"-";
	for(int i = 0; i < bigInteger.length(); i++){
		out<<bigInteger[i];
	}
	return out;
}

istream & operator >> (istream &in,BigInteger &bigInteger){
	string str;
	in>>str;
	bigInteger.readString(str);
	return in;
}

// Indexed operators

unsigned int & BigInteger::operator[](int index){
	return this->value[this->length()-1-index];
}

// Functions and methods

int BigInteger::length(){
	return this->value.size();
}

bool BigInteger::isPositive(){
	return this->positive;
}

bool BigInteger::absGreater(BigInteger &bigNumber){
	if(this->value.size() != bigNumber.value.size())
		return this->value.size() > bigNumber.value.size();
	for(int i = this->value.size()-1; i>=0; i--){
		if(this->value[i] == bigNumber.value[i]) continue;
		if(this->value[i] > bigNumber.value[i]) return true;
		return false;
	}
	return false;
}

bool BigInteger::absLesser(BigInteger &bigNumber){
	if(this->value.size() != bigNumber.value.size())
		return this->value.size() < bigNumber.value.size();
	for(int i = this->value.size(); i>=0; i--){
		if(this->value[i] == bigNumber.value[i]) continue;
		if(this->value[i] < bigNumber.value[i]) return true;
		return false;
	}
	return false;
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

BigInteger BigInteger::ZERO() const{
	return BigInteger();
}

BigInteger BigInteger::ONE() const{
	return BigInteger("1");
}

BigInteger BigInteger::pow(int power){
	BigInteger base = *this;
	BigInteger result("1");
	while(power>0){
		if(power & 1){
			result*=base;
			base*=base;
			power>>=1;
		}else{
			base*=base;
			power>>=1;
		}
	}
	return result;
}

BigInteger BigInteger::sqrt(){
	if(!this->positive){
		cout<<"Imaginary number.\n";
		exit(1);
	}
	int zeros = (this->value.size()/2)+1;
	BigInteger x;
	x.value.assign(zeros,0);
	x.value.back() = 1;
	BigInteger prevValue;
	/*while(true){
		if(prevValue == x) return x;
		if(prevValue+1 == x) return prevValue;
		prevValue = x;
		x = (x+(*this/x))/2;
	}
	return x;*/
	do{
		prevValue = x;
		BigInteger temp = *this/prevValue; 
		//clock_t start, end; 
    	//start = clock();



		x = (prevValue + (temp))/2;



		//end = clock(); 
		//double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
		//cout << "Time taken by program is : " << fixed  
		//		<< time_taken << setprecision(5); 
    	//cout << " sec " << "\n";
	}while(x != prevValue);
	return x;
}

BigInteger BigInteger::fastDivisionByTwo(BigInteger dividend){
	BigInteger result;
	result.value.assign(dividend.value.size(),0);
	dividend.addLeadingZeros(1);
	for(int i = dividend.value.size()-1; i>0; i--){
		int val = dividend.value[i-1];
		if(dividend.value[i] & 1){
			if(val == 0 || val == 1){
				result.value[i-1] = 5;
			}else if(val == 2 || val == 3){
				result.value[i-1] = 6;
			}else if(val == 4 || val == 5){
				result.value[i-1] = 7;
			}else if(val == 6 || val == 7){
				result.value[i-1] = 8;
			}else if(val == 8 || val == 9){
				result.value[i-1] = 9;
			}
		}else{
			if(val == 0 || val == 1){
				result.value[i-1] = 0;
			}else if(val == 2 || val == 3){
				result.value[i-1] = 1;
			}else if(val == 4 || val == 5){
				result.value[i-1] = 2;
			}else if(val == 6 || val == 7){
				result.value[i-1] = 3;
			}else if(val == 8 || val == 9){
				result.value[i-1] = 4;
			}
		}
	}
	result.removeLeadingZeros();
	return result;
}

void BigInteger::addLeadingZeros(int zeros){
	value.resize(value.size()+zeros);
}

void BigInteger::removeLeadingZeros(){
	while(value.back() == 0 && value.size() > 1)
		value.pop_back();
}

void BigInteger::makePositiveIfZero(){
	if(this->value.size() > 1) return;
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

BigInteger BigInteger::division(BigInteger &dividend, BigInteger &divisor){
	return longDivision(dividend, divisor);
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
	result.positive = big1.positive == big2.positive;
	result.removeLeadingZeros();
	return result;
}

pair<BigInteger,BigInteger> BigInteger::resultAndRemainder(BigInteger divisor){
	if(divisor == BigInteger()){
		cout<<"Mod by zero.\n";
		exit(1);
	};
	BigInteger dividend = *this;
	if(divisor == BigInteger()) return make_pair(BigInteger(), BigInteger("-1"));
	if(divisor.absGreater(dividend)) return make_pair(BigInteger(),*this);
	bool dividendSign = dividend.positive, divisorSign = divisor.positive;
	dividend.positive = divisor.positive = true;
	BigInteger result, subNumber, bigRemainder;
	int dividendLength = dividend.value.size();
	result.value.resize(dividendLength,0);
	while(true){
		dividend.removeLeadingZeros();
		if(dividend.value.size() >= divisor.value.size()){
			int pos = dividend.value.size() - divisor.value.size();
			subNumber.value.assign(dividend.value.begin() + pos, dividend.value.end());
			if(subNumber < divisor){
				if(dividend.value.size() > divisor.value.size()){
					subNumber.value.insert(subNumber.value.begin(), dividend.value[dividend.value.size()-(divisor.value.size()+1)]);
				}else{
					bigRemainder = subNumber;
					break;
				}
			}
		}else{
			bigRemainder = dividend;
			break;
		}
		int quotient = 0, splitSize = subNumber.value.size();
		int indexPosition = (dividendLength-(subNumber.value.size()+(dividendLength-dividend.value.size())));
		while(divisor <= subNumber){
			subNumber-=divisor;
			++quotient;
		}
		bigRemainder = subNumber;
		result.value[indexPosition] = quotient; 
		int leadingNumbersToRemove = splitSize-bigRemainder.value.size();
		while(leadingNumbersToRemove--) dividend.value.pop_back();
		for(int i = 0; i<bigRemainder.value.size(); i++){
			dividend.value[dividend.value.size()-i-1] = bigRemainder.value[bigRemainder.value.size()-1-i];
		}
	}
	result.removeLeadingZeros();
	result.positive = dividendSign == divisorSign;
	return make_pair(result,bigRemainder);
}

BigInteger BigInteger::longDivision(BigInteger dividend, BigInteger &divisor){
	if(divisor == 2){
		return fastDivisionByTwo(dividend);
	}
	if(divisor == BigInteger()){
		cout<<"Division by zero.\n";
		exit(1);
	};
	if(divisor.absGreater(dividend)) return BigInteger();
	bool dividendSign = dividend.positive, divisorSign = divisor.positive;
	dividend.positive = divisor.positive = true;
	BigInteger result, subNumber, bigRemainder;
	int dividendLength = dividend.value.size();
	result.value.resize(dividendLength,0);
	while(true){
		dividend.removeLeadingZeros();
		if(dividend.value.size() >= divisor.value.size()){
			int pos = dividend.value.size() - divisor.value.size();
			subNumber.value.assign(dividend.value.begin() + pos, dividend.value.end());
			if(subNumber < divisor){
				if(dividend.value.size() > divisor.value.size()){
					subNumber.value.insert(subNumber.value.begin(), dividend.value[dividend.value.size()-(divisor.value.size()+1)]);
				}else{
					bigRemainder = subNumber;
					break;
				}
			}
		}else{
			bigRemainder = dividend;
			break;
		}
		int quotient = 0, splitSize = subNumber.value.size();
		int indexPosition = (dividendLength-(subNumber.value.size()+(dividendLength-dividend.value.size())));
		while(divisor <= subNumber ){
			subNumber-=divisor;
			++quotient;
		}
		bigRemainder = subNumber;
		result.value[indexPosition] = quotient; 
		int leadingNumbersToRemove = splitSize-bigRemainder.value.size();
		while(leadingNumbersToRemove--) dividend.value.pop_back();
		for(int i = 0; i<bigRemainder.value.size(); i++){
			dividend.value[dividend.value.size()-i-1] = bigRemainder.value[bigRemainder.value.size()-1-i];
		}
	}
	result.removeLeadingZeros();
	result.positive = dividendSign == divisorSign;
	return result;
}

BigInteger BigInteger::mod(BigInteger dividend, BigInteger &divisor){
	if(divisor == BigInteger()){
		cout<<"Module by zero.\n";
		exit(1);
	}
	if(divisor.absGreater(dividend)) return BigInteger();
	bool dividendSign = dividend.positive, divisorSign = divisor.positive;
	dividend.positive = divisor.positive = true;
	BigInteger result, subNumber, bigRemainder;
	int dividendLength = dividend.value.size();
	result.value.resize(dividendLength,0);
	while(true){
		dividend.removeLeadingZeros();
		if(dividend.value.size() >= divisor.value.size()){
			int pos = dividend.value.size() - divisor.value.size();
			subNumber.value.assign(dividend.value.begin() + pos, dividend.value.end());
			if(subNumber < divisor){
				if(dividend.value.size() > divisor.value.size()){
					subNumber.value.insert(subNumber.value.begin(), dividend.value[dividend.value.size()-(divisor.value.size()+1)]);
				}else{
					bigRemainder = subNumber;
					break;
				}
			}
		}else{
			bigRemainder = dividend;
			break;
		}
		int quotient = 0, splitSize = subNumber.value.size();
		int indexPosition = (dividendLength-(subNumber.value.size()+(dividendLength-dividend.value.size())));
		while(divisor <= subNumber){
			subNumber-=divisor;
			++quotient;
		}
		bigRemainder = subNumber;
		result.value[indexPosition] = quotient; 
		int leadingNumbersToRemove = splitSize-bigRemainder.value.size();
		while(leadingNumbersToRemove--) dividend.value.pop_back();
		for(int i = 0; i<bigRemainder.value.size(); i++){
			dividend.value[dividend.value.size()-i-1] = bigRemainder.value[bigRemainder.value.size()-1-i];
		}
	}
	result.removeLeadingZeros();
	result.positive = dividendSign == divisorSign;
	return bigRemainder;
}


int main(){
	clock_t start, end, beginning; 
    beginning = clock();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tests;
	BigInteger num, divisor;
	cin>>tests;
	while(tests--){
		cin>>num>>divisor;
		start = clock();
		cout<<"New one"<<endl;

		end = clock(); 
		double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
		cout << "Time taken by program is : " << fixed  
			<< time_taken << setprecision(5); 
		cout << " sec " << "\n";
	}
	return 0;
	for(int i = 0; i<tests; i++){
		cin>>num;
		if(i) cout<<"\n";
		cout<<num.sqrt()<<"\n";		
	}
	end = clock(); 
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
    cout << "Time taken by program is : " << fixed  
         << time_taken << setprecision(5); 
    cout << " sec " << "\n"; 
	return 0;
}
