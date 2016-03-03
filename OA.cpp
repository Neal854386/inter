
/*
 1. Leetcode 的 Valid Parentheses 包括'<' 和 '>'。所以请仔细读题。
 Solution: stack.
 Time Complexity O(n)
 Space Complexity O(n)
 */

#include <bits/stdc++.h>
using namespace std;

bool isValid(string &s) {
    stack<char> stk;
    
    int n = s.length();
    for (int i = 0; i < n; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[' || s[i] == '<') {
            stk.push(s[i]);
        } else {
            if (stk.empty() || abs(stk.top() - s[i]) > 2) {
                return false;
            }
            stk.pop();
        }
    }
    
    return stk.empty();
}

int main() {
    string input;
    cin >> input;
    
    isValid(input) ? cout << "true" :
                     cout << "false";
    cout << endl;
}

/*
 2. BST PreOrder to PostOrder，给你一个BST的PreOrder，让你输出PostOrder。
 	如果做过leetcode的 PreOrder + InOrder 构建Tree 和 PostOrder + InOrder 构建Tree的那两题，这题就不难做。
 Solution: stack.
 Time Complexity O(n)
 Space Complexity O(n)
 */
/*
Sol 1) sort preOrder array, you can get inOrder

Sol 2)no need to sort, just use preOrder, 
for the current val in array, you can use a loop to find all the smaller val next to him, 
which consists of a left subtree, the rest of the val in array should be the right subtree.
*/
#include <bits/stdc++.h>
using namespace std;

void printPost(vector<long> &pre, int l, int r) {
    if (l > r) {
        return;
    }
        
    if (l == r) {
        cout << pre[r] << endl;
        return;
    }
    
    int root = pre[l];
    int right = l + 1;
    
    while (right <= r && pre[right] < root) {
        right++;
    }
    
    printPost(pre, l + 1, right - 1);
    printPost(pre, right, r);
    cout << root << endl;
}

int main() {
    vector<long> pre;
    
    long l;
    while (cin >> l) {
        pre.push_back(l);
    }
    
    printPost(pre, 0, pre.size() - 1);
}

/*
3. Leetcode 的 Permutation Sequence input是64bit的，因为题目告诉你20的阶乘是64bit，
所以要定义long long。和leetcode稍微不一样的地方，就是从0开始的, 
n此处不是0到9，是0到20，另外k此处不是1-based，是0-based
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> getPermutation(int n, long long k) {  
    if (n == 1) {
        return vector<int>(1, 0);
    }
    
    vector<int> nums;
    for (int i = 0;i < n;i++)
        nums.push_back(i);
    
    long long factorial[n];
    factorial[0] = 1LL;
    factorial[1] = 1LL;
    
    for (int i = 2; i < n;i++)
        factorial[i] = factorial[i-1] * i;
    
    vector<int> ret;
    
    int N = n;
    for (int i = 0;i < N;i++) {
        long long f = factorial[n - 1];
        int d = nums[k / f];
        k %= f;
        ret.push_back(d);
        nums.erase(find(nums.begin(), nums.end(), d));
        n--;
    }
    
    return ret;
}

int main(int argc, char *argv[]) {
    int n;
    long long m;
    cin >> m >> n;
    
    for (auto &i : getPermutation(n, m)) cout << i << " ";
}

/*
4. Knight's Adventure：一个Chess Board，你要把一个Knight从给定起点跳到给点重点，
棋盘上有一些blocked square不能走，求最短步数。Warning：最后三个test case非常大，长宽都是10000+，大数据测试。
*/

#include <bits/stdc++.h>
using namespace std;

struct state {
    int x, y, step;
    state(int x, int y, int step): x(x), y(y), step(step) {}
};

int m, n;
int start_x, start_y;
int end_x, end_y;
bool visited[1001][1001];
vector<vector<int>> dir;

bool bound(int x, int y) {
    return x >= 0 && x < m && y >= 0 && y < n;
}

int bfs() {
    queue<state> Q;
    Q.push(state(start_x, start_y, 0));
    visited[start_x][start_y] = true;
    
    while (!Q.empty()) {
        auto &cur = Q.front();
        Q.pop();
        
        if (cur.x == end_x && cur.y == end_y) {
            return cur.step;
        }
        
        for (int i = 0; i < 8; i++) {
            int next_x = cur.x + dir[i][0];
            int next_y = cur.y + dir[i][1];
            
            if (bound(next_x, next_y) && !visited[next_x][next_y]) {
                visited[next_x][next_y] = true;
                Q.push(state(next_x, next_y, cur.step + 1));
            }
        }
    }
    
    return -1;
}

void init() {
    dir = {
        {2,1}, {2,-1}, {1,2}, {1,-2},
        {-2,1}, {-2,-1}, {-1,2}, {-1,-2}
    };
    
    cin >> m >> n;
    cin >> start_x >> start_y;
    cin >> end_x >> end_y;
    
    int block;
    cin >> block;
    
    int block_x, block_y;
    while (block--) {
        cin >> block_x >> block_y;
        visited[block_x][block_y] = true;
    }
}

int main() {
    init();
    cout << bfs() << endl;
}