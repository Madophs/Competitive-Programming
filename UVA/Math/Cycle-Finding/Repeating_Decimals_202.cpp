#include <bits/stdc++.h>

using namespace std;

class BigDecimal{
	public:
		string value;
		unordered_map<string, pair<string,int> > cycle;
		BigDecimal(){
			this->value = "";
		}
		BigDecimal(string str){
			this->value = str;
		}

		bool operator <= (BigDecimal &big){
			if(this->value.length() != big.value.length())
				return this->value.length() < big.value.length();
			return this->value <= big.value;
		}
		bool operator < (BigDecimal &big){
			if(this->value.length() != big.value.length())
				return this->value.length() < big.value.length();
			return this->value < big.value;
		}
		bool operator >= (BigDecimal &big){
			if(this->value.length() != big.value.length())
				return this->value.length() > big.value.length();
			return this->value >= big.value;
		}
		
		void operator -= (BigDecimal &big){
			BigDecimal dec1, dec2;
			if(*this >= big){
				dec1 = *this;
				dec2 = big;
			}else{
				dec1 = big;
				dec2 = *this;
			}
			int i,j;
			for(i = dec1.value.length()-1, j = dec2.value.length()-1; i>=0 && j>=0; i--,j--){
				if(dec1.value[i] < dec2.value[j]){
					for(int x = i-1; x>=0; x--){
						if(dec1.value[x] != '0'){
							--dec1.value[x];
							break;
						}else{
							dec1.value[x] = '9';
						}
					}
					int val1 = 10 + (dec1.value[i]-'0'), val2 = dec2.value[j] - '0';
					dec1.value[i] = (val1-val2) + '0';
					if(j-1 < 0) break;
				}else{
					int val1 = dec1.value[i] - '0', val2 = dec2.value[j] - '0';
					dec1.value[i] = (val1-val2) + '0';
					if(j-1 < 0) break;
				}
			}
			while(*dec1.value.begin() == '0' && !dec1.value.empty()) dec1.value.erase(dec1.value.begin());
			this->value = dec1.value;
		}
		pair<string,string> division (BigDecimal &big){
			BigDecimal result;
			bool decimalPoint = false, cycleDetected = false;
			BigDecimal dividend = *this, divisor = big;
			int position = 0;
			string cyclePattern;
			while(true){
				while(!dividend.value.empty() && *dividend.value.begin() == '0'){
					result.value += "0";
					dividend.value.erase(dividend.value.begin());
					if(dividend.value.empty()){
						result.value += ".0";
						cyclePattern = "0";
						cycle.insert(make_pair("0",make_pair("0",result.value.length()-1)));
						return make_pair(result.value, cyclePattern);
					}
				}
				BigDecimal chunk;
				int numZeros = 0;
				if(dividend.value.empty()){
					result.value += "0";
					cyclePattern = "0";
					cycle.insert(make_pair("0",make_pair("0",result.value.length()-1)));
					break;
				}
				if(cycleDetected){
					int length = cycle.find(cyclePattern)->second.first.length();
					while(length--){
						result.value.pop_back();
					}
					break;
				}
				chunk.value = dividend.value.substr(0,divisor.value.length());
				position += chunk.value.length();
				if(divisor.value.length() < dividend.value.length()){
					dividend.value = dividend.value.substr(divisor.value.length(),string::npos);
				}else{
					dividend.value = "";
				}
				while(chunk < divisor){
					if(dividend.value.empty()){
						chunk.value += '0';
						if(!decimalPoint){
							if(result.value.empty()){
								result.value = "0.";
								position += 2;
							}else{
								result.value += ".";
								++position;
							}
							decimalPoint = true;
						}
						numZeros++;
					}else{
						chunk.value += *dividend.value.begin();
						dividend.value.erase(dividend.value.begin());
					}
					++position;
				}
				--numZeros;
				int quotient = 0, chunkLength = chunk.value.length();
				unordered_map<string, pair<string,int> >::iterator iter;
				if(decimalPoint){
					if(cycle.find(chunk.value) == cycle.end()){
						cycle.insert(make_pair(chunk.value, make_pair("0",result.value.length())));
						iter = cycle.find(chunk.value);
					}else{
						cyclePattern = chunk.value;
						cycleDetected = true;
					}
				}
				while(chunk >= divisor){
					chunk -= divisor;
					++quotient;
				}
				
				string zeros((numZeros < 0? 0 : numZeros),'0');
				if(decimalPoint){
					if(!cycleDetected){
						string res = zeros;
						res += (quotient + '0');
						iter->second.first = res;
					}
				}
				result.value += zeros;
				result.value += quotient + '0';
				if(chunk.value == "0") chunk.value = "";
				position -= chunk.value.length();
				dividend.value = chunk.value + dividend.value;
			}
			if(!decimalPoint){
				result.value.pop_back();
				result.value += ".0";
				cyclePattern = "0";
				cycle["0"] = make_pair("0",result.value.length()-1);
			}
			return make_pair(result.value, cyclePattern);
		}

		void divisionDecimalCycleFinding(BigDecimal &divisor){
			auto result = division(divisor);
			auto chunk = cycle.find(result.second);
			int pos = result.first.find_first_of('.');
			string firstSplit = result.first.substr(0,chunk->second.second);
			string secondSplit = result.first.substr(chunk->second.second,51);
			int decimalNotInCycle = firstSplit.length() - (pos+1);
			cout<<this->value<<"/"<<divisor.value<<" = "<<firstSplit;
			if(secondSplit.length()+decimalNotInCycle > 50){
				while(secondSplit.length()+decimalNotInCycle > 50) secondSplit.pop_back();
				cout<<"("<<secondSplit<<"...)\n";
			}else{
				cout<<"("<<secondSplit<<")\n";
			}
			int cycleLength = result.first.length() - chunk->second.second;
			cout<<"   "<<cycleLength<<" = number of digits in repeating cycle\n\n";
		}
};

istream & operator >> (istream &in, BigDecimal &big){
	in>>big.value;
	big.cycle.clear();
	return in;

}
ostream & operator << (ostream &out, BigDecimal &big){
	out<<big.value;
	return out;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	BigDecimal a,b;
	while(cin>>a>>b){
		a.divisionDecimalCycleFinding(b);
	}
	return 0;
}
