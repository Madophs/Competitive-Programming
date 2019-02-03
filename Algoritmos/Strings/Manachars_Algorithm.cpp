#include <bits/stdc++.h>

using namespace std;

#define SIZE 100000 + 1

int p[SIZE * 2];

// Transform S into new string with special characters inserted.
string convertToNewString(const string &s) {
    string newString = "@";

    for (int i = 0; i < s.size(); i++) {
        newString += "#" + s.substr(i, 1);
    }

    newString += "#$";
    return newString;
}

string longestPalindromeSubstring(const string &s) {
    string text = convertToNewString(s);
    int center = 0,mirror = 0, r = 0;
    int longest = 0, indexLongest = 0;
    for(int i = 1; i<text.length(); i++){
        mirror = 2*center-i;
        if(i < r){
            p[i] = min(p[mirror],r-i);
        }
        while(text[i - p[i] - 1] == text[i + p[i] + 1]){
            ++p[i];
        }
        if(i + p[i] > r){
            center = i;
            r = i+p[i];
        }
        if(p[i]>longest){
            longest = p[i];
            indexLongest = i;
        }
    }
    return s.substr((indexLongest-1-longest)/2,p[indexLongest]);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s = "abacdedcaba";
    cout << longestPalindromeSubstring(s)<<endl;
	return 0;
}