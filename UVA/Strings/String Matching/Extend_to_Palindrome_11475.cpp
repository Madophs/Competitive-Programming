#include <bits/stdc++.h>

using namespace std;

vector<int> kmpPattern(string &str){
	vector<int> pattern(str.length()+1);
	pattern[0] = -1;
	int i = 0, j = -1;
	while(i < str.length()){
		while(j > -1 && str[i] != str[j]) j = pattern[j];
		++i,++j;
		pattern[i] = j;
	}
	return pattern;
}

int kmpIndex(string &find, string &text){
	vector<int> pattern = kmpPattern(find);
	int i = 0, j = 0;
	while(i < text.length()){
		while(j > -1 && find[j] != text[i]) j = pattern[j];
		++j, ++i;
	}
	return j;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string line, reversedLine;
	while(cin>>line){
		reversedLine.assign(line.rbegin(), line.rend());
		cout<<line;
		for(int index = kmpIndex(reversedLine, line); index < reversedLine.length(); ++index){
			cout<<reversedLine[index];
		}
		cout<<"\n";
	}
	return 0;
}

/*
Alternative solution (Also coded by me)

#include <bits/stdc++.h>

using namespace std;

void printTheRest(string &str){
	for(int i = str.length()-1; i > -1; --i)cout<<str[i];
	cout<<"\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string line, theRest;
	int i, j;
	while(cin>>line){
		theRest = "";
		i = 0, j = line.length()-1;
		while(i <= j){
			if(line[i] == line[j]){
				++i, --j;
			}else{
				int stepsBack = i - (int)theRest.length();
				theRest.push_back(line[(int)theRest.length()]);
				i = theRest.length(), j += stepsBack;
			}
		}
		cout<<line;
		printTheRest(theRest);
	}
	return 0;
}
*/