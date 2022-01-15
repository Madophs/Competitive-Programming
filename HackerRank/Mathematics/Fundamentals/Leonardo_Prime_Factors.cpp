#include <bits/stdc++.h>
#define MAX_VALUE 1000000000000000001
#define LIMIT 1000

using namespace std;
bitset<LIMIT> sieve;
vector<pair<uint64_t, uint64_t>> primes;

void buildSieve()
{
    sieve.set();
    uint64_t jump = 2;
    uint64_t multi = 1;
    for (uint64_t i = 2; i < MAX_VALUE; ++i) {
        if (sieve.test(i)) {
            jump = i;
            multi *= (uint64_t) i;
            primes.push_back(make_pair(multi, primes.size() + 1));

            if (primes.back().first > MAX_VALUE)
                return;

            for (uint64_t j = i; j < LIMIT; j += jump) {
                sieve.reset(j);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // Precalculate the prime factors
    buildSieve();

    int c;
    uint64_t val;
    cin >> c;

    for (int i = 0; i < c; ++i) {
        cin >> val;
        if (val == 1) {
            cout << 0 << '\n';
            continue;
        }
        for (int j = 0; j < primes.size(); ++j) {
            if (primes[j].first > val) {
                cout << primes[j-1].second << '\n';
                break;
            }
        }
    }

    return 0;
}
