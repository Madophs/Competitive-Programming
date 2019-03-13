#include <bits/stdc++.h>

using namespace std;

int letterValue(char c){
	if(c == 'B' || c == 'F' || c == 'P' || c=='V'){
		return 1;
	}else if(c =='C' || c =='G' || c =='J' || c =='K' || c =='Q' || c =='S' || c =='X' || c =='Z'){
		return 2;
	}else if(c == 'D' || c == 'T'){
		return 3;
	}else if(c == 'L'){
		return 4;
	}else if(c == 'M' || c == 'N'){
		return 5;
	}else if(c == 'R'){
		return 6;
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string word,ans;
	int aux;
	while(cin>>word){
		ans = "";
		aux = -1;
		for(auto it = word.begin(); it!=word.end(); it++){
			int temp = letterValue(*it);
			if(!temp){
				aux = temp;
				continue;
			}
			if(temp == aux) continue;
			ans+=to_string(temp);
			aux = temp;
		}
		cout<<ans<<"\n";
	}
	return 0;
}