#include <iostream>
#include <algorithm>

#define MAX_N 250005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> pii;

pii ar[MAX_N];

bool cmp(pii a, pii b) {
    return ((a.f.f * 1.0 / a.f.s * 1.0) > (b.f.f * 1.0 / b.f.s * 1.0));
}

int N;

int main() {
    cin >> N;
    
    for (int i = 0; i < N; i ++) {
        cin >> ar[i].f.f >> ar[i].f.s;
        ar[i].s = i;
    }
    
    sort(ar, ar + N, cmp);
    
    cout << ar[0].f.s + ar[1].f.s + ar[2].f.s << endl;
    
    cout << ar[0].s + 1 << endl;
    cout << ar[1].s + 1 << endl;
    cout << ar[2].s + 1 << endl;
    
    return (0);
}