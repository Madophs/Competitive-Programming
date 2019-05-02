#include <bits/stdc++.h>

using namespace std;

unordered_map<char,char> layout;

void mapKeys(){
	layout['`'] = '`';
	layout['4'] = 'q';
	layout['5'] = 'j';
	layout['6'] = 'l';
	layout['7'] = 'm';
	layout['8'] = 'f';
	layout['9'] = 'p';
	layout['0'] = '/';
	layout['-'] = '[';
	layout['='] = ']';
	layout['q'] = '4';
	layout['w'] = '5';
	layout['e'] = '6';
	layout['r'] = '.';
	layout['t'] = 'o';
	layout['y'] = 'r';
	layout['u'] = 's';
	layout['i'] = 'u';
	layout['o'] = 'y';
	layout['p'] = 'b';
	layout['['] = ';';
	layout[']'] = '=';
	layout['\\'] = '\\';
	layout['a'] = '7';
	layout['s'] = '8';
	layout['d'] = '9';
	layout['f'] = 'a';
	layout['g'] = 'e';
	layout['h'] = 'h';
	layout['j'] = 't';
	layout['k'] = 'd';
	layout['l'] = 'c';
	layout[';'] = 'k';
	layout['\''] = '-';
	layout['z'] = '0';
	layout['x'] = 'z';
	layout['c'] = 'x';
	layout['v'] = ',';
	layout['b'] = 'i';
	layout['n'] = 'n';
	layout['m'] = 'w';
	layout[','] = 'v';
	layout['.'] = 'g';
	layout['/'] = '\'';
	layout['~'] = '~';
	layout['!'] = '!';
	layout['@'] = '@';
	layout['#'] = '#';
	layout['$'] = 'Q';
	layout['%'] = 'J';
	layout['^'] = 'L';
	layout['&'] = 'M';
	layout['*'] = 'F';
	layout['('] = 'P';
	layout[')'] = '?';
	layout['_'] = '{';
	layout['+'] = '}';
	layout['Q'] = '$';
	layout['W'] = '%';
	layout['E'] = '^';
	layout['R'] = '>';
	layout['T'] = 'O';
	layout['Y'] = 'R';
	layout['U'] = 'S';
	layout['I'] = 'U';
	layout['O'] = 'Y';
	layout['P'] = 'B';
	layout['{'] = ':';
	layout['}'] = '+';
	layout['|'] = '|';
	layout['A'] = '&';
	layout['S'] = '*';
	layout['D'] = '(';
	layout['F'] = 'A';
	layout['G'] = 'E';
	layout['H'] = 'H';
	layout['J'] = 'T';
	layout['K'] = 'D';
	layout['L'] = 'C';
	layout[':'] = 'K';
	layout['"'] = '_';
	layout['Z'] = ')';
	layout['X'] = 'Z';
	layout['C'] = 'X';
	layout['V'] = '<';
	layout['B'] = 'I';
	layout['N'] = 'N';
	layout['M'] = 'W';
	layout['<'] = 'V';
	layout['>'] = 'G';
	layout['?'] = '"';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string line;
	mapKeys();
	while(getline(cin,line)){
		transform(line.begin(), line.end(), line.begin(),[&](char c){
			if(layout.find(c) != layout.end())
				return layout.find(c)->second;
			return c;
		});
		cout<<line<<"\n";
	}
	return 0;
}
