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
    int index = 0;
    out << "Debug: ";
    for (auto param: {args...}) {
        if (index) out << ", ";
        out << varnames[index++] << " = " << param;
    }
    out << std::endl;
}
#define debug(...) mds_debug(cerr, #__VA_ARGS__, __VA_ARGS__);
#else
#define debug(...)
#endif

/******************    START_CODING   ******************/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t, n, k;
    for (cin >> t; t-- && cin >> n >> k;) {
        int index;
        if (k < (n / 2)) {
            index = (k * 2) + 1;
        } else {
            int relativePos = n - k - 1;
            index = relativePos * 2;
        }
        cout << index << '\n';
    }

    return 0;
}
