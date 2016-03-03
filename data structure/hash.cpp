#include <iostream>

using namespace std;

class HashTable {
public:
    HashTable(int Length) {
        Element = new int[Length];
        for(int i = 0; i < Length; i++) {
            Element[i] = INT_MIN;
        }
        this->Length = Length;
        Count = 0;
    }
    
    ~HashTable() {
        delete[] Element;
    }
    
    // Hash function
    int Hash(int Data) {
        return Data % Length;
    }
    
    // reHash function
    int ReHash(int Index, int Count) {
        return (Index + Count) % Length;
    }
    
    // search
    bool SerachHash(int Data, int &Index) {
        int temp_count = 0;
        Index = Hash(Data);
		if (Element[Index] == INT_MIN) {
			return false;
		}
		
        while (temp_count <= Count && Element[Index] != Data) {
            Index = ReHash(Index, temp_count++);
        }
 
        return Data == Element[Index] ? true : false;
    }
    
    bool SerachHash(int Data) {
        int Index = 0;
        return SerachHash(Data, Index);
    }
    
    // insert data
    bool InsertHash(int Data) {
        int Index = 0;
        if (Count < Length && !SerachHash(Data, Index)) {
            Element[Index] = Data;
            Count++;
            return true;
        } else {
        	return false;
		}
		
		return true;
    }
    
    // set length
    void SetLength(int Length) {
        delete[] Element;
        Element = new int[Length];
        for(int i = 0;i < Length;i++) {
            Element[i] = -1;
        }
        this->Length = Length;
    }
    
    // delete element
    void Remove(int Data) {
        int Index = SerachHash(Data);
        if(Index != -1)
        {
            Element[Index] = -1;
            Count--;
        }
    }
    
    void Print() {
        for(int i = 0; i < Length; i++) {
            if (Element[i] != INT_MIN) {
                cout << Element[i] << " ";
            }
            
        }
    }
protected:
    int* Element = nullptr;           // Hash表
    int Length = 0;               // Hash表大小
    int Count = 0;                // Hash表当前大小
};



int main() {
    HashTable H(10);
    int Array[6] = {49,38,65,97,13,49};
    
    for (int i = 0; i < 6; i++) {
        H.InsertHash(Array[i]);
    }

    H.Print();
    return 1;
}