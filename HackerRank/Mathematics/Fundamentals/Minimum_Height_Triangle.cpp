#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int base, area;
    cin>>base>>area;
    int height = ceil((area<<1)/(double)base);
    cout<<height<<"\n"; 
    return 0;
}
