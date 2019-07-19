#include <bits/stdc++.h>

using namespace std;

const int INF = (int)1e9;
vector<string> text;

vector<int> kmpPattern(string &str){
	vector<int> pattern(str.length()+1);
	pattern[0] = -1;
	int i = 0, j = -1;
	while(i < str.length()){
		while(j > -1 && str[i] != str[j]) j = pattern[j];
		++i, ++j;
		pattern[i] = j;
	}
	return pattern;
}

pair<int,int> kmpMatching(string &word, vector<int> &pattern, int &initRow, int &initCol, int incRow, int incCol){
	int j = 0;
	pair<int, int> result(INF, INF);
	while(initRow < text.size() && initCol < text.back().length() && initRow >= 0 && initCol >= 0){
		while(j > -1 && word[j] != text[initRow][initCol]) j = pattern[j];
		++j, initRow += incRow, initCol += incCol;
		if(j == word.length()){
			pair<int,int> tempResult(initRow + ((int)word.length()*incRow*-1), initCol + ((int)word.length()*incCol*-1));
			if(result > tempResult) result = tempResult;			
			j = pattern[j];
		}
	}
	return result;
}

pair<int, int> getCoordinatesSubtask(string &word, vector<int> &pattern, int initRow, int initCol, int incRow, int incCol){
	pair<int, int> result(INF, INF), tempResult;
	if(incCol){
		int finalIndex = initCol + (word.length()*incCol);
		if(finalIndex > text.back().length() && finalIndex < -1)
			return result;
	}
	if(incRow){
		int finalIndex = initRow + (word.length()*incRow);
		if(finalIndex > text.size() && finalIndex < -1)
			return result;
	}
	tempResult = kmpMatching(word, pattern, initRow, initCol, incRow, incCol);
	if(result > tempResult) result = tempResult;
	incCol *= -1, incRow *= -1;
	initRow += incRow, initCol += incCol;
	tempResult = kmpMatching(word, pattern, initRow, initCol, incRow, incCol);
	if(result > tempResult) result = tempResult;
	return result;
}

pair<int, int> getCoordinates(string &word){
	vector<int> pattern = kmpPattern(word);
	pair<int, int> result(INF,INF), tempResult;
	for(int row = 0; row < text.size(); ++row){
		tempResult = getCoordinatesSubtask(word, pattern, row, 0, 0, 1);
		if(result > tempResult) result = tempResult;
		tempResult = getCoordinatesSubtask(word, pattern, row, 0, 1, 1);
		if(result > tempResult) result = tempResult;
		tempResult = getCoordinatesSubtask(word, pattern, row, text.back().length()-1, 1, -1);
		if(result > tempResult) result = tempResult;
	}
	for(int col = 0; col < text.back().length(); ++col){
		tempResult = getCoordinatesSubtask(word, pattern, 0, col, 1, 0);
		if(result > tempResult) result = tempResult;
		tempResult = getCoordinatesSubtask(word, pattern, 0, col, 1, 1);
		if(result > tempResult) result = tempResult;
		tempResult = getCoordinatesSubtask(word, pattern, 0, col, 1, -1);
		if(result > tempResult) result = tempResult;
	}
	return result;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, width, height, numWords;
	string line, word;
	cin>>t;
	while(t-- && cin>>height>>width){
		text.clear();
		while(height-- && cin>>line){
			transform(line.begin(), line.end(), line.begin(),::tolower);
			text.emplace_back(line);
		}
		cin>>numWords;
		while(numWords-- && cin>>word){
			transform(word.begin(), word.end(), word.begin(), ::tolower);
			pair<int, int> ans = getCoordinates(word);
			cout<<ans.first+1<<" "<<ans.second+1<<"\n";
		}
		if(t) cout<<"\n";
	}
	return 0;
}
