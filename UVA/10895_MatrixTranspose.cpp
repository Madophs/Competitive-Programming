#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
using namespace std;

int main(){
	string dimensiones="";
	getline(cin,dimensiones);
	while(dimensiones.length()>0){
		int rows=std::atoi((dimensiones.substr(0,dimensiones.find(' ')).c_str()));
		int col =std::atoi((dimensiones.substr(dimensiones.find(' ')+1,string::npos).c_str()));
		int mat[rows][col];
		memset(mat, 0, sizeof(mat[0][0]) * rows * col);
		for(int x=0; x<rows; x++){
			int aRow=0;
			cin>>aRow;
			if(aRow==0){
				cin.get();
			}else{
				int temp[col];
				memset(temp,0,sizeof(temp));
				int c=0;
				for(c=0;c<aRow; c++) cin>>temp[c];
				for(c=0;c<aRow; c++){
					cin>>mat[x][temp[c]-1];
				}
			}
		}
		cout<<col<<" "<<rows<<endl;
		for(int x=0; x<col; x++){
			int num=0;
			vector<int> vec,val;
			for(int y=0; y<rows; y++){
				if(mat[y][x]!=0){
					++num;
					vec.push_back(y+1);
					val.push_back(mat[y][x]);
				}
			}
			cout<<num;
			for(int y=0; y<vec.size(); y++){
				cout<<" "<<vec[y];
			}
			cout<<endl;
			for(int y=0; y<val.size(); y++){
				cout<<val[y]<<(y+1==val.size()?"": " ");
			}
			cout<<endl;
		}
		cin.ignore();
		getline(cin,dimensiones);
	}
	return 0;
}
