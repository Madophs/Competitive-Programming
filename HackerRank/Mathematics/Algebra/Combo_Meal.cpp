#include <bits/stdc++.h>

using namespace std;

int profit(int &burger, int &soda, int &combo)
{
    int burgerRealPrice = combo - soda;
    return burger - burgerRealPrice;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int orders, burger, soda, combo;

    cin >> orders;
    while (orders--) {
        cin >> burger >> soda >> combo;
        cout << profit(burger, soda, combo) << '\n';
    }

    return 0;
}
