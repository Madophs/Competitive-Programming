#include "edx-io.hpp"
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
	int matrix[3][3];
	for(int row = 0; row<3 ; row++){
		for(int col = 0; col<3; col++){
			io>>matrix[row][col];
		}
	}
	double maximum = 0.0;
	for(int x=0; x<3; x++){
		for(int y=0; y<3; y++){
			if(y==x)continue;
			for(int z=0; z<3; z++){
				if(z==x || z==y)continue;
				int a = pow(matrix[0][x],2), b = pow(matrix[1][y],2),c = pow(matrix[2][z],2);
				maximum = max(maximum,(double)sqrt(a+b+c));
			}
		}
	}
	io<<maximum<<"\n";
	return 0;
}