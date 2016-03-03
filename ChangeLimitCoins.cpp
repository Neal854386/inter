#include <bits/stdc++.h>
using namespace std;

// To execute C++, please define "int main()"

/*
There are unlimited numbers of 1c, 5c, 25c, 50c
pick 50 coins to have 1 dollar
print out 3 solutions, each of which has 50 coins.
*/
vector<int> c = {1, 5, 25, 50};
int target = 100;
int num = 40;
vector<pair<int, int>> p;

void changeCoins(int id, int n, int v) {
    if (id == c.size()) {
        if (n == num and v == target) {
            for (auto x : p)
                printf("%d,%d ", x.first, x.second);
            puts("");
        }
        
        return;
    }
    
    int k = c[id];
    int l = 1;
    while (v + k <= target and n+l <= num) {
        p.push_back(make_pair(l, c[id]));
        changeCoins(id + 1, n + l, v + k);
        p.pop_back();
        
        k += c[id];
        l++;
    }
    changeCoins(id+1, n, v);
}

int main() {
    changeCoins(0, 0, 0);
    return 0;
}
