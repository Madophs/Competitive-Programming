#include <bits/stdc++.h>

using namespace std;

int crow[] = {-1,-1, 0, 1, 1, 1, 0,-1};
int ccol[] = { 0, 1, 1, 1, 0,-1,-1,-1};

int minasAlrededor(vector<string> &matrix, int row, int col){
	int minas = 0;
	for(int i = 0; i<8; i++){
		int fila = row + crow[i], columna = col + ccol[i];
		if(fila < 0 || fila >= matrix.size()) continue;
		if(columna < 0 || columna >= matrix.back().length()) continue;
		minas += matrix[fila][columna] == '*';
	}
	return minas;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int alto, ancho;
	string linea;
	while(cin>>ancho>>alto && (alto || ancho)){
		vector<string> matrix;
		while(alto-- && cin>>linea){
			matrix.emplace_back(linea);
		}
		int res = 0;
		for(int row = 0; row < matrix.size(); row++){
			for(int col = 0; col < ancho; col++){
				if(matrix[row][col] != '*'){
					res += (minasAlrededor(matrix, row, col) >= 6);
				}
			}
		}
		cout<<res<<"\n";
	}	
	return 0;
}
