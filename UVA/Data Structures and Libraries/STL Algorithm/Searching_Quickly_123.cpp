#include <bits/stdc++.h>

using namespace std;

string toUppercaseWord(string line, int i, int j){
	for(; i<j; i++) line[i] = toupper(line[i]);
	return line;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string line, word;
	unordered_set<string> words_to_ignore;
	vector<string> titles;
	while(cin>>line && line!="::") words_to_ignore.insert(line);
	cin.ignore();
	while(getline(cin,line)){
		transform(line.begin(), line.end(), line.begin(), ::tolower);
		titles.emplace_back(line);
	}
	vector< pair<string,pair<int,string>> > ordered_titles;
	for(int i = 0; i<titles.size(); i++){
		int x = 0, y = 0;
		while(y<titles[i].length()){
			while(isalpha(titles[i][y])) ++y;
			string temp = titles[i].substr(x,y-x);
			if(words_to_ignore.find(temp) == words_to_ignore.end()){
				ordered_titles.emplace_back(make_pair(temp, make_pair(i,toUppercaseWord(titles[i],x,y))));
			}
			x = ++y;
		}
	}
	sort(ordered_titles.begin(), ordered_titles.end());
	for(int i = 0; i<ordered_titles.size(); i++)
		cout<<ordered_titles[i].second.second<<"\n";
	return 0;
}