 #include <bits/stdc++.h>

using namespace std;

vector<int> contruction(string &str){
	vector<int> z(str.length());
	int l = 0, r = 0, k = 0;
	for(int i = 1; i<str.size(); i++){
		if(i > r){
			l = r = i;
			while(r < str.size() && str[r-l] == str[r])++r;
			z[i] = r-l;
			--r;
		}else{
			k = i - l;
			if(z[k] < r-i+1){
				z[i] = z[k];
			}else{
				l = i;
				while(r < str.size() && str[r-l] == str[r])++r;
				z[i] = r-l;
				--r;
			}
		}
	}
	return z;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	string str;
	ostream_iterator<char> cout_str(cout," ");
	ostream_iterator<int> cout_vec(cout," ");
	cin>>t;
	while(t-- && cin>>str){
		vector<int> pattern = contruction(str);
		copy(str.begin(), str.end(),cout_str);
		cout<<endl;
		copy(pattern.begin(), pattern.end(),cout_vec);
		cout<<'\n'<<setw(50)<<setfill('_');
		cout<<'\n';
	}
	return 0;
}