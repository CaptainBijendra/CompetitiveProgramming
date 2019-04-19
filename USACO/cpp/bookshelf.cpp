#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int best = 20000005;

void x(int n, vector<int> a, int height){
	if(n <= 0){
		return;
	}

	vector<int> b(25);
	
	for(int i = 0; i < n; i++){
		int k = 0;
	    int sum = 0;
		
		for (int j = 0; j < n; j ++) {
			if(j != i){
				sum += a[j];
				b[k] = a[j];
				k++;
			}
		}
		
		if (sum - height < best && sum - height >= 0){
			best = sum - height;
		}
		
		x(n - 1, b, height);
	}
}

int main(){
	int n, height;
	cin >> n >> height;
    
    vector<int> a;
    
    int element;
    int sum = 0;
    
	for(int i = 0; i < n; i++){
		cin >> element;
		a.push_back(element);
	
	    sum += element;
	}
	
	sort(a.begin(), a.end());
	
	if (sum - height >= 0)
	    best = sum - height;
	
	x(n, a, height);
	cout << best << endl;
}