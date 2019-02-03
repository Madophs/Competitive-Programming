#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int dim, leftDiagonal=0, rightDiagonal=0,var;
	cin>>dim;
	for(int x=0; x<dim; x++){
		for(int y=0; y<dim; y++){
			cin>>var;
			if(x==y)leftDiagonal+=var;
			if(x+y == dim-1)rightDiagonal+=var;
		}
	}
	cout<<abs(leftDiagonal-rightDiagonal)<<endl;
	return 0;
}