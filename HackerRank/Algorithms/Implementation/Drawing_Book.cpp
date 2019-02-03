#include <bits/stdc++.h>

using namespace std;

int pagesTurned(int &book, int &page){
	int beginning=page/2, end=abs((book/2)-beginning);
	return beginning<end?beginning:end;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int bookPages, page;
	cin>>bookPages>>page;
	cout<<pagesTurned(bookPages,page)<<endl;
	return 0;
}