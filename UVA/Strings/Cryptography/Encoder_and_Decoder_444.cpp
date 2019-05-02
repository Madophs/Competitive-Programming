#include <bits/stdc++.h>

using namespace std;

string reverseASCII(char c){
	string str = to_string(((int)(c)));
	for(int i = 0; i<str.length()/2; i++){
		swap(str[i], str[str.length()-1-i]);
	}
	return str;
}

string encode(string message){
	string encodedMessage = "";
	for(auto iter = message.rbegin(); iter != message.rend(); iter++){
		encodedMessage += reverseASCII(*iter);
	}
	return encodedMessage;
}

bool validCharacter(char c){
	if(isalpha(c)) return true;
	return c == ' ' || c == '.' || c == ':' || c == ';' || c == '?' || c == '!' || c == ',';
}

string decode(string message){
	string strASCIIValue = "", decodedMessage = "";
	for(int i = 0; i<message.length();){
		strASCIIValue += message[i];
		char character = (char)atoi(strASCIIValue.c_str());
		while(i < message.length() && !validCharacter(character)){
			strASCIIValue = message[++i] + strASCIIValue;
			character = (char)atoi(strASCIIValue.c_str());
		}
		++i;
		decodedMessage = character + decodedMessage;
		strASCIIValue = "";
	}
	return decodedMessage;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string line;
	while(getline(cin,line)){
		if(isdigit(line[0])){
			cout<<decode(line)<<"\n";
		}else{
			cout<<encode(line)<<"\n";
		}
	}
	return 0;
}
