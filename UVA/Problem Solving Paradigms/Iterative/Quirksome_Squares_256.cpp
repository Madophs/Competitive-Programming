#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int length;
	string n8 = "00000000\n00000001\n04941729\n07441984\n24502500\n25502500\n52881984\n60481729\n99980001\n";
	string n6 = "000000\n000001\n088209\n494209\n998001\n";
	string n4 = "0000\n0001\n2025\n3025\n9801\n";
	string n2 = "00\n01\n81\n";
	while(cin>>length){
		if(length == 2){
			cout<<n2;
		}else if(length == 4){
			cout<<n4;
		}else if(length == 6){
			cout<<n6;
		}else{
			cout<<n8;
		}
	}
	return 0;
}

/*

// Cool Solution credits to https://saicheems.wordpress.com/2013/07/16/uva-256-quirksome-squares/
// Generate of squares and then take the first half elements and the other half elements
// and add them and square them, check if it is equals to the square
// he left side of a 8 digit number is given by 12345678 / 10 ^ (8 / 2)
// and the right side is given by 12345678 % (8 / 2).

#include<cmath>
#include<cstdio>
#include<iomanip>
#include<iostream>
#include<vector>
 
using namespace std;
 
int N;
vector<int> squares;
 
int prep() {
    for(int i = 0; i < 10000; i++)
        squares.push_back(i * i);
}
 
int main() {
    prep();
    while(scanf("%d", &N) == 1) {
        for(int i = 0; i < squares.size(); i++) {
            if(squares[i] >= (int) pow(10, N)) break;
            if(pow(squares[i] % (int) pow(10, N / 2) + squares[i] / (int) pow(10, N / 2), 2) == squares[i])
                cout << setw(N) << setfill('0') << squares[i] << endl;
        }   
    }
}
*/
