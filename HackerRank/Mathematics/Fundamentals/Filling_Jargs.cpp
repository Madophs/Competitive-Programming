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

    int n, t, a, b, k;
    uint64_t ans = 0;
    cin >> n >> t;
    while (t--) {
        cin >> a >> b >> k;
        ans += (uint64_t)((b-a) + 1) * (uint64_t)k;
    }
    cout << (ans / n) << '\n';
    return 0;
}
