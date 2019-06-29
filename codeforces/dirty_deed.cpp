#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

#define MAX_N 300005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> pii;

int N;

bool cmp1(pii a, pii b) {
    bool posA = (a.f.s > b.f.f);
    bool posB = (b.f.s > a.f.f);
    
    if (posA && posB)
        return (a.f.s < b.f.s);
    if (posA)
        return (true);
    
    return (false);
}

bool cmp2(pii a, pii b) {
    bool posA = (a.f.s < b.f.f);
    bool posB = (b.f.s < a.f.f);
    
    if (posA && posB)
        return (a.f.s > b.f.s);
    if (posA)
        return (true);
    
    return (false);
}

int main() {
    cin >> N;
    
    vector<pii> v1;
    vector<pii> v2;
    
    int a, b;
    for (int i = 0; i < N; i ++) {
        cin >> a >> b;    
    
        if (a < b)
            v1.push_back(pii(ii(a, b), (i + 1)));
        else
            v2.push_back(pii(ii(a, b), (i + 1)));
    }
    
    sort(v1.begin(), v1.end(), cmp1);
    sort(v2.begin(), v2.end(), cmp2);
    
    int pos1 = min((int)v1.size(), 1);
    int pos2 = min((int)v2.size(), 1);
    
    for (int i = 1; i < v1.size(); i ++) {
        if (v1[i - 1].f.s <= v1[i].f.f) {
            pos1 = i;
            break;
        }
        
        if (i == v1.size() - 1)
            pos1 = v1.size();
    }
    
    for (int i = 1; i < v2.size(); i ++) {
        if (v2[i - 1].f.s >= v2[i].f.f) {
            pos2 = i;
            break;
        }
        
        if (i == v2.size() - 1)
            pos2 = v2.size();
    }
    
    if (pos1 > pos2) {
        cout << pos1 << endl;
        
        for (int i = 0; i < pos1; i ++)
            cout << v1[i].s << " ";
        
        cout << endl;
    }
    
    else {
        cout << pos2 << endl;
        
        for (int i = 0; i < pos2; i ++)
            cout << v2[i].s << " ";
        
        cout << endl;
    }
    
    return (0);
}