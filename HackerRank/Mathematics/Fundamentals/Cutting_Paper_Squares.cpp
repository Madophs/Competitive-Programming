#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    uint64_t n, m;
    cin >> n >> m;

    uint64_t firstCut = n-1;
    uint64_t secondCut = n * (m-1);
    uint64_t minCuts = firstCut + secondCut;

    cout << minCuts << '\n';
    return 0;
}
