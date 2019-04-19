#include <iostream>

using namespace std;

int main() {
    int x1, y1, x2, y2;
    int x3, y3, x4, y4;
    
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
    
    int a = max(x1, x3);
    int b = min(x2, x4);
    int c = max(y1, y3);
    int d = min(y2, y4);
    
    cout << (b - a) << " " << (d - c) << endl;
    
    int diff_x = max(max(x1, x2), max(x3, x4)) - min(min(x1, x2), min(x3, x4));
    int diff_y = max(max(y1, y2), max(y3, y4)) - min(min(y1, y2), min(y3, y4));
    
    if ((b - a) <= 0 || (d - c) <= 0) {
        cout << (x2 - x1) * (y2 - y1) << endl;
        return (0);
    }
    
    if ((b - a) >= (diff_x) && (d - c) >= (diff_y)) {
        cout << 0 << endl;
        return (0);
    }
    
    if ((b - a) <= (diff_x) && (d - c) >= (diff_y)) {
        cout << (x2 - x1) * (d - c) << endl;
        return (0);
    }

    if ((b - a) >= (diff_x) && (d - c) <= (diff_y)) {
        cout << (b - a) * (y2 - y1) << endl;
        return (0);
    }
    
    if ((b - a) <= (diff_x) && (d - c) <= (diff_y) {
        cout << (x2 - x1) * (y2 - y1) << endl;
        return (0);
    }
}