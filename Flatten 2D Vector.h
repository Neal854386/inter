/*
251. Flatten 2D Vector
Difficulty: Medium

Implement an iterator to flatten a 2d vector.

For example,
Given 2d vector =

[
  [1,2],
  [3],
  [4,5,6]
]
By calling next repeatedly until hasNext returns false, 
the order of elements returned by next should be: [1,2,3,4,5,6].

*/

class Vector2D {
private:
    vector<int> vecs, vece;
    int p, n;
public:
    Vector2D(vector<vector<int>> &vec2d) {
        n = vec2d.size();
        for (auto &v : vec2d) {
            vecs.push_back(v.begin());
            vece.push_back(v.end());
        }
        p = 0;
        while (p < n && vecs[p] == vece[p])
            p++;
    }

    int next() {
        int ret = *vecs[p];
        vecs[p]++;
        while (p < n && vecs[p] == vece[p])
            p++;
        return ret;
    }

    bool hasNext() {
        if (p == n)
            return false;
        return vecs[p] != vece[p];
    }
};

class Vector2D {
    private:
        vector<vector<int>>::iterator currStart;
        vector<vector<int>>::iterator currEnd;
        vector<int>::iterator start;
        vector<int>::iterator end;

    public:
        Vector2D(vector<vector<int>>& vec2d) {
            currStart = vec2d.begin();
            currEnd = vec2d.end();
            start = end;
        }

        int next() {
            int result = *start;
            start++;
            return result;
        }

        bool hasNext() {
            while(currStart != currEnd && start == end) {
                start = (*currStart).begin();
                end = (*currStart).end();
                ++currStart;
            }
            return start != end;
        }
};
