#include <bits/stdc++.h>

using namespace std;

#ifdef __MDS_DEBUG__
template <typename Arg, typename... Args>
void __mds_debug(std::ostream& out, Arg&& arg, Args&&... args)
{
    stringstream ss(forward<Arg>(arg));
    vector<string> varnames;
    for (string var; getline(ss, var, ','); varnames.push_back(var)) {
        if (var.at(0) == ' ') var.erase(0, 1);
    }
    int index = 0;
    using expander = int[];
    (void)expander{0, (void(out << varnames[index++] << " = " << std::forward<Args>(args) << ", "), 0)...};
    out << std::endl;
}
#define debug(...) __mds_debug(cout, #__VA_ARGS__, __VA_ARGS__);
#else
#define debug(...)
#endif

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int a, b, t;
    cin >> t;
    while (cin >> a >> b && t--) {
        int ans = (a * b) / pow(gcd(a, b), 2);
        cout << ans << endl;
        debug(a, b)
    }
    return 0;
}
