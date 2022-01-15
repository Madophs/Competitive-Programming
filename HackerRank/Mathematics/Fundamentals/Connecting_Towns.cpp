#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    const uint64_t MODULO = 1234567;
    int t, numTowns, routes;

    cin >> t;

    while (t--) {
        cin >> numTowns;
        --numTowns;
        uint64_t res = 1;
        for (int i = 0; i < numTowns; ++i) {
            cin >> routes;
            res = ((res % MODULO) * (routes % MODULO)) % MODULO;
        }

        cout << res << '\n';
    }
    return 0;
}
