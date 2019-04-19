#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>

#define INF 2000000009
#define MAX_N 5005
#define f first
#define s second

using namespace std;

int ar[MAX_N];
int N;

int main() {
    ifstream fin ("cbarn.in");
    ofstream fout ("cbarn.out");
    
    fin >> N;
    
    for (int i = 0; i < N; i ++)
        fin >> ar[i];
    
    //Maximum cost, which we calculate by simulating the procedure 
    //starting at every possible index in 'ar'
    int max_cost = 0;
    
    for (int i = 0; i < N; i ++) {
        int cur_cows = 0; //How many cows are we currently moving to another location
        int cost = 0; //What is the total of the entire procedure
        
        for (int j = 0; j < N; j ++) {
            cur_cows = max(0, cur_cows + ar[j] - 1); //We add to cur_cows the number of cows at a certain index in the array 'ar'
            cost += (cur_cows * cur_cows); //We add the square of the number of cows we are holding at the moment, because this is 
                                           //the number of spaces that a cow in line has to travel before reaching their destination
        }
        
        //If the cost of simulating the process at this index is greater than our current best cost, 
        //then we should update the max_cost variable
        max_cost = max(max_cost, cost);
        
        //By rotating the array, we can treat the simulation as if it was linear
        //instead of it being circular
        rotate(ar, ar + 1, ar + N);
    }
    
    fout << max_cost << endl;
    return (0);
}