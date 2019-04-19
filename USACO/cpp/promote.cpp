#include <iostream>

using namespace std;

int main() {
    int b1, b2, s1, s2, g1, g2, p1, p2;
    cin >> b1 >> b2 >> s1 >> s2 >> g1 >> g2 >> p1 >> p2;
    
    int diff_p = p2 - p1;
    int diff_g = g2 - g1 + diff_p;
    int diff_s = s2 - s1 + diff_g;

    cout << diff_s << endl;
    cout << diff_g << endl;
    cout << diff_p << endl;
    return (0);
}