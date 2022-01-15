#include <bits/stdc++.h>
#include <bits/stdint-uintn.h>

using namespace std;

const uint64_t MOD = 1000000007ULL;

uint64_t applyRule(uint64_t a, uint64_t b, char opt)
{
    switch (opt) {
        case '*':
            return ((a % MOD) * (b % MOD)) % MOD;
        case '+':
            return ((a % MOD) + (b % MOD)) % MOD;
        default:
            return ((a % MOD) - (b % MOD)) % MOD;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    uint64_t n;
    cin >> t;
    while (t--) {
        cin >> n;
        uint64_t sumDigits = applyRule(applyRule(n-1ULL, n+1ULL, '*'), 1ULL, '+') % MOD;
        cout << sumDigits << endl;
    }
    return 0;
}
