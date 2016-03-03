/*
Zigzag Iterator
Given two 1d vectors, implement an iterator to return their elements alternately.

For example, given two 1d vectors:

v1 = [1, 2]
v2 = [3, 4, 5, 6]
By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1, 3, 2, 4, 5, 6].

Follow up: What if you are given k 1d vectors? How well can your code be extended to such cases?
*/


class ZigzagIterator {
private:
    vector<int>::iterator be[2];
    vector<int>::iterator ed[2];
    int p;

public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        be[0] = v1.begin(); ed[0] = v1.end();
        be[1] = v2.begin(); ed[1] = v2.end();
        p = be[0] == v1.end() ? 1 : 0;
    }

    int next() {
        int ret = *be[p];
        be[p]++;    // iterator move to next        
        int pre = p;
        // for each iterator, if the next iter is null, find the avaliable iter
        do {
            p++;
            if(p >= 2) p = 0;
        } while (p != pre && be[p] == ed[p]);
        return ret;
    }

    bool hasNext() {
        return be[p] != ed[p];
    }
};

class ZigzagIterator {
public:
    ZigzagIterator(Iterator& a, Iterator& b) :_its{a,b} {
        _pointer = a.has_next() ? 0 : 1;
    }
    
    int get_next() {
        int ret = _its[_pointer].get_next();
        int old = _pointer;
        do {
            if(++_pointer >= all_size) _pointer = 0;
        } while(!_its[_pointer].has_next() && _pointer != old);
        return ret;
    }
    
    bool has_next() { return _its[_pointer].has_next(); }
private:
    Iterator _its[all_size];
    int all_size;
    int _pointer;
};

public class ZigzagIterator {
    
    Iterator<Integer> it1;
    Iterator<Integer> it2;
    int turns;

    public ZigzagIterator(List<Integer> v1, List<Integer> v2) {
        this.it1 = v1.iterator();
        this.it2 = v2.iterator();
        turns = 0;
    }

    public int next() {
        // 如果没有下一个则返回0
        if(!hasNext()){
            return 0;
        }
        turns++;
        // 如果是第奇数个，且第一个列表也有下一个元素时，返回第一个列表的下一个
        // 如果第二个列表已经没有，返回第一个列表的下一个
        if((turns % 2 == 1 && it1.hasNext()) || (!it2.hasNext())){
            return it1.next();
        // 如果是第偶数个，且第二个列表也有下一个元素时，返回第二个列表的下一个
        // 如果第一个列表已经没有，返回第二个列表的下一个
        } else if((turns % 2 == 0 && it2.hasNext()) || (!it1.hasNext())){
            return it2.next();
        }
        return 0;
    }

    public boolean hasNext() {
        return it1.hasNext() || it2.hasNext();
    }
};

public class ZigzagIterator implements Iterator<Integer> {
    
    List<Iterator<Integer>> itlist;
    int turns;

    public ZigzagIterator(List<Iterator<Integer>> list) {
        this.itlist = new LinkedList<Iterator<Integer>>();
        // 将非空迭代器加入列表
        for(Iterator<Integer> it : list){
            if(it.hasNext()){
                itlist.add(it);
            }
        }
        turns = 0;
    }

    public Integer next() {
        if(!hasNext()){
            return 0;
        }
        Integer res = 0;
        // 算出本次使用的迭代器的下标
        int pos = turns % itlist.size();
        Iterator<Integer> curr = itlist.get(pos);
        res = curr.next();
        // 如果这个迭代器用完，就将其从列表中移出
        if(!curr.hasNext()){
            itlist.remove(turns % itlist.size());
            // turns变量更新为上一个下标
            turns = pos - 1;
        }
        turns++;
        return res;
    }

    public boolean hasNext() {
        return itlist.size() > 0;
    }
};