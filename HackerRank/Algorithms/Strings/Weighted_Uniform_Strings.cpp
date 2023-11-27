#include <bits/stdc++.h>

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

int weights[(int)1e7+10];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string str;
    int query, n;
    cin >> str >> n;
    memset(weights, 0, sizeof(weights));
    for (int i = 0, j; i < str.length();) {
        int sum = 0;
        for (j = i; j < str.length(); ++j) {
            if (str[i] == str[j]) {
                sum += (int)((str[i]-'a') + 1);
                ++weights[sum];
            } else {
                break;
            }
        }
        i = j;
    }

    while (n-- && cin >> query) {
        if (weights[query]) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}
