#include <iostream>
#include <vector>
using namespace std;

class SegmentTree{
public:
	SegmentTree(int tam):tam(tam){
		vec.assign(4*tam,0);
		local.push_back(0);
	}
	void build(int p,int l,int r){
		if(l==r){
			vec[p]=local[l];
		}else{
			build(p<<1,l,(l+r)/2);
			build((p<<1)+1,(l+r)/2+1,r);
			vec[p]=vec[p<<1]+vec[(p<<1)+1];
		}
	}
	long suma(int p,int l,int r, int i, int j){
		if(i>r || j<l) return -1;
		if(l>=i && r<=j) return vec[p];

		long p1=suma(p<<1,l,(r+l)/2,i,j);
		long p2=suma((p<<1)+1,(r+l)/2+1,r,i,j);
		if(p1==-1) return p2;
		if(p2==-1) return p1;

		return p1+p2;
	}
	long suma(int i, int j){
		return suma(1,0,local.size()-1,i,j);
	}
	void actualizar(int p, int l, int r, int ver, int val){
		if(l>r || ver>r || ver<l) return;
		if(l==r){
			vec[p]=val;
			return;
		}
		actualizar(p<<1,l,(l+r)/2,ver,val);
		actualizar((p<<1)+1,(l+r)/2+1,r,ver,val);
		vec[p]=vec[p<<1]+vec[(p<<1)+1];
	}
	void actualizar(int i, int j){
		actualizar(1,0,local.size()-1,i,j);
	}
	void inicia(int val){
		local.push_back(val);
	}
private:
	vector<int> vec,local;
	int tam;
};
int main(){
	int c=0,caso=0;
	while(cin>>c && c){
		if(caso>=1) cout<<endl;
		SegmentTree fen(c);
		int var=0;
		for(int x=1; x<=c; x++){
			cin>>var;
			fen.inicia(var);
		}
		fen.build(1,0,c);
		string cadena="";
		int i=0,j=0;
		cout<<"Case "<<++caso<<":"<<endl;
		while(cin>>cadena &&cadena!="END"){
			cin>>i>>j;
			if(cadena=="M"){
				cout<<fen.suma(i,j)<<endl;
			}else{
				fen.actualizar(i,j);
			}
		}
	}
	return 0;
}
