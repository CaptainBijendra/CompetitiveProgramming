#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>

using namespace std;

string str1, str2;

int N;

int main() {
    cin >> N;
    cin >> str1 >> str2;

    int clowns = 0;
    int actor = 0;
    int both = 0;
    int neither = 0;

    for (int i = 0; i < str1.size(); i ++) {
        if (str1[i] == '1') {
            clowns += (str2[i] == '0');
            both += (str2[i] == '1');
        }

        else if (str2[i] == '1') {
            actor += (str1[i] == '0');
            both += (str1[i] == '1');
        }

        else
            neither ++;
    }

    int only_clowns = -1, only_both, only_neither, only_actor;

    bool flag = false;

    for (int i = 0; i <= clowns; i ++) { //How many clowns only are we taking
        for (int j = 0; j <= both; j ++) { //How many both actor and clown are we taking
            if (i + j > N / 2)
                break;

            int tot = (i + j);
            int actors_used = tot - (both - j);

            if (actors_used < 0)
                continue;
            if (actors_used > actor)
                continue;

            int non_clown = N / 2 - (i + j);
            int remaining_actors = (actor - actors_used);
            int remaining_clowns = (clowns - i);
            
            if (remaining_clowns < 0 || remaining_actors < 0)
                continue;
            if (remaining_actors + neither < non_clown)
                continue;
            if (remaining_actors > non_clown)
                continue;

            neither -= (non_clown - remaining_actors);

            only_neither = (non_clown) - remaining_actors;
            only_actor = remaining_actors;

            if (only_neither < 0 || only_actor < 0)
                continue;

            remaining_actors = 0;

            if (neither < 0)
                continue;
            if (remaining_clowns + neither < non_clown)
                continue;

            only_clowns = i;
            only_both = j;
            flag = true;
            break;
        }
        
        if (flag)
            break;
    }

    if (only_clowns == -1) {
        cout << "-1" << endl;
        return (0);
    }

    for (int i = 0; i < N; i ++) {
        if (str1[i] == '1' && str2[i] == '1' && only_both > 0) {
            cout << (i + 1) << " ";
            only_both --;
        }

        if (str1[i] == '1' && str2[i] == '0' && only_clowns > 0) {
            cout << (i + 1) << " ";
            only_clowns --;
        }

        if (str1[i] == '0' && str2[i] == '1' && only_actor > 0) {
            cout << (i + 1) << " ";
            only_actor --;
        }

        if (str1[i] == '0' && str2[i] == '0' && only_neither > 0) {
            cout << (i + 1) << " ";
            only_neither --;
        }
    }

    cout << endl;
    return (0);
}