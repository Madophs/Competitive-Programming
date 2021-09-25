#include <bits/stdc++.h>

using namespace std;

int main()
{
    unsigned long long r, c;
    cin >> r >> c;

    c = ((c - 1) * 2) + (r % 2ull == 0);

    unsigned long long res = (static_cast<unsigned long long>(ceil(r / (double)2.0)) - 1ull) * 10ull + c;
    cout << res << endl;
    return 0;
}

