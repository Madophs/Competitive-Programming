#include <bits/stdc++.h>
#include <limits>
#include <tuple>

using namespace std;

#ifdef __MDS_DEBUG__
template <typename Arg, typename... Args>
void mds_debug(std::ostream& out, Arg&& arg, Args&&... args)
{
    stringstream ss(forward<Arg>(arg));
    vector<string> varnames;
    for (string var; getline(ss, var, ','); varnames.push_back(var)) {
        if (var.at(0) == ' ') var.erase(0, 1);
    }
    using expander = int[];
    uint32_t index = 0;
    (void)expander{0, (void(out << (index ? ", " : "Debug: ") << varnames[index++] << " = " << std::forward<Args>(args)), 0)...};
    out << std::endl;
}
#define debug(...) mds_debug(cerr, #__VA_ARGS__, __VA_ARGS__);
#else
#define debug(...)
#endif

/******************    START_CODING   ******************/

inline int countChars(uint64_t number) {
    if (!number) return 1;
    return (int)log10(number) + 1;
}

void isBeautiful(string &number) {
    if (number.at(0) == '0') {
        cout << "NO\n";
        return;
    }
    uint64_t firstBeautifulNumber = 0;
    bool beautiful = false;
    for (int cutLength = 1; cutLength <= (int)(number.size() / 2) && !beautiful; ++cutLength) {
        bool beautifulTmp = true, remainingChars = true;
        int nextCutLength = cutLength;
        for (int i = 0; i <= (int)number.size() - (nextCutLength << 1) && beautifulTmp;) {
            int64_t value = atoll(number.substr(i, nextCutLength).c_str());
            int prevCutLength = nextCutLength;

            if (!i) {
                firstBeautifulNumber = value;
            }

            if (countChars(value) != countChars(value + 1LL)) {
                ++nextCutLength;
            }

            int64_t nextValue = atoll(number.substr(i + prevCutLength, nextCutLength).c_str());
            if ((nextValue - value) != 1LL) {
                beautifulTmp = false;
            }

            if (number.at(i) == '0' || number.at(i + prevCutLength) == '0') beautifulTmp = false;

            remainingChars = ((int)number.size() - (i + prevCutLength + nextCutLength)) != 0;
            i += prevCutLength;
        }
        beautiful = beautifulTmp && !remainingChars;
    }

    if (beautiful) {
        cout << "YES " << firstBeautifulNumber << '\n';
    } else {
        cout << "NO\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    string number;
    cin >> t;
    while (t-- && cin >> number) {
        isBeautiful(number);
    }
    return 0;
}
