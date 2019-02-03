#ifdef JUDGE
	#include <fstream>
	using namespace std;
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#else
	#include <iostream>
	using namespace std;
#endif

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int arr[4];
	for(int x=0; x<4 && cin>>arr[x]; x++);
	if(arr[3] <=2){
		cout<<arr[arr[3]]<<'\n';
	}else{
		int cont = 2,ans = 0;
		while(cont < arr[3]){
			ans = arr[2]+arr[1]-arr[0];
			arr[0] = arr[1];
			arr[1] = arr[2];
			arr[2] = ans;
			++cont;
		}
		cout<<ans<<'\n';
	}
	return 0;
}