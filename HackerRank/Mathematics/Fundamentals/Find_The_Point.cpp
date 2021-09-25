#include <bits/stdc++.h>
#define ANGLE (double)180.0

using namespace std;

// Cool way to calculate PI
const double PI = acos(-1.0);
// degrees to radians
const double radians = ANGLE * (PI / 180.0);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int cases;
    cin >> cases;

    while (cases--) {
        double px, py, qx, qy;
        cin >> px >> py >> qx >> qy;

        // Rotates about origin
        double px_rotated = (px - qx) * cos(radians) - (py - qy) * sin(radians);
        double py_rotated = (py - qy) * cos(radians) + (px - qx) * sin(radians);

        // Translate back to q point
        px_rotated += qx, py_rotated += qy;
        cout << (int)round(px_rotated) << " " << (int)round(py_rotated) << '\n';
    }
    cout.flush();
    return 0;
}
