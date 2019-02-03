#include "edx-io.hpp"
#include <algorithm>
#include <cmath>
#include <vector>


using namespace std;

int main(){
	int a,b,c;
	io>>a>>b>>c;
	io<<(a+b+c)/6.0<<"\n";
	return 0;
}