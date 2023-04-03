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

int countGemstones(vector<string> &rocks) {
    int letters[26];
    bool visitedRocks[26];
    memset(letters, 0, sizeof(letters));

    for (string &rock : rocks) {
        memset(visitedRocks, false, sizeof(visitedRocks));
        for (char &c : rock) {
            if (!visitedRocks[c - 'a']) {
                ++letters[c - 'a'];
                visitedRocks[c - 'a'] = true;
            }
        }
    }

    int gemstones = 0, numberOfRocks = rocks.size();
    for (int i = 0; i < 26; ++i) {
        if (letters[i] == numberOfRocks) {
            ++gemstones;
        }
    }
    return gemstones;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<string> rocks(n);
    for (;n--; cin >> rocks[n]);
    cout << countGemstones(rocks) << '\n';
    return 0;
}
