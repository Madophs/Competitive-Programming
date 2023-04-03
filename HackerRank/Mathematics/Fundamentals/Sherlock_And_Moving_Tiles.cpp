#include <bits/stdc++.h>
#include <cmath>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(10);
    double len, s1, s2, area;
    cin >> len >> s1 >> s2;
    int q;
    cin >> q;
    double squareHypo = hypot(len, len);
    while (q--) {
        cin >> area;
        double sideLen = sqrt(area);
        double hypo = hypot(sideLen, sideLen);
        double diff = fabs(squareHypo - hypo);
        double speedDiff = fabs(s1-s2);
        double ans = diff / speedDiff;
        cout << ans << '\n';
    }
    return 0;
}
