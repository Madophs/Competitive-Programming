#include <bits/stdc++.h>

using namespace std;

string multiply(string &a, string &b){
	bool signedA = a[0] == '-';
	bool signedB = b[0] == '-';
	int digitsA = a.length()-signedA, digitsB = b.length()-signedB, carry;
	string ret(digitsA+digitsB,'0');
	int pos = ret.length(), index = 0;
	for(int i = a.length()-1; i >= signedA; i--){
		--pos, index = 0, carry = 0;
		for(int j = b.length()-1; j >= signedB; j--){
			int res = (((int)a[i]-'0') * ((int)b[j]-'0')) + carry + ((int)ret[pos-index]-'0');
			carry = res/10;
			res%=10;
			ret[pos-index] = (char)(res+'0');
			++index;
		}
		if(carry) ret[pos-index] = (char)(carry+'0');
	}
	while(ret.size() > 1 && ret[0] == '0') ret.erase(ret.begin());
	if((signedA && !signedB) || (!signedA && signedB)) ret = "-"+ret;
	return ret;
}

bool greaterThan(string &a, string &b){
	bool signedA = a[0] == '-';
	bool signedB = b[0] == '-';
	if(!signedA && signedB) return true;
	if(signedA && !signedB) return false;
	if(!signedB && !signedA){
		if(a.length() != b.length()){
			return a.length() > b.length();
		}else{
			return a > b;
		}
	}
	if(a.length() != b.length()){
		return a.length() < b.length();
	}
	return a < b;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string multi, ans;
	string value, limit = "-999999", INF = to_string((int)-1e9);
	while(cin>>value){
		vector<string> numbers;
		do{
			numbers.emplace_back(value);
		}while(cin>>value && value != limit);
		ans = INF;
		for(int i = 0; i<numbers.size(); i++){
			multi = "1";
			for(int j = i; j<numbers.size(); j++){
				multi = multiply(multi,numbers[j]);
				if(greaterThan(multi,ans)) ans = multi;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}