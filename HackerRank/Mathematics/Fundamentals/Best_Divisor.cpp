#include <bits/stdc++.h>
#define SIZE 100002

using namespace std;

vector<int> divisors;

int sumDigits(int number) {
    string strval = to_string(number);
    int sum = 0;
    for (char &c : strval) {
        sum += (int)(c - '0');
    }
    return sum;
}

int getBestDivisor() {
    int maxSum = 0;
    int bestDivisor = 1;
    for (int &val : divisors) {
        int sum = sumDigits(val);
        if (sum > maxSum) {
            maxSum = sum;
            bestDivisor = val;
        } else if (sum == maxSum) {
            bestDivisor = min(val, bestDivisor);
        }
    }
    return bestDivisor;
}

vector<int> calcDivisors(int number) {
    int limit = (int)ceil(sqrt((double)number));
    for (int i = 1; i < limit; ++i) {
        if (number % i == 0) {
            int res = number / i;
            if (res == i)
                divisors.emplace_back(i);
            if (res != i)
                divisors.emplace_back(i), divisors.emplace_back(res);
        }
    }
    return divisors;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int number;

    cin >> number;

    calcDivisors(number);
    cout << getBestDivisor() << endl;

    return 0;
}
