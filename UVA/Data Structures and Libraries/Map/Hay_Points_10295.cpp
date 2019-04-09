#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	unordered_map<string,int> dic;
	int m, n, salary;
	string word, line;
	long long ans = 0;
	cin>>m>>n;
	while(m-- && cin>>word>>salary) dic[word] = salary;
	cin.ignore();
	while(n--){
		ans = 0;
		while(getline(cin,line) && line!="."){
			stringstream ss(line);
			while(ss>>word){
				if(dic.find(word) != dic.end()) ans += (long long) dic.find(word)->second;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}