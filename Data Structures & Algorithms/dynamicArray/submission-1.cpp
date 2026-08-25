class DynamicArray {
private: 
    int size;
    int cap;
    int* p;
public:

    DynamicArray(int capacity) {
        if(capacity < 1){
            return;
        }
        this->cap = capacity;
        this->p = new int[cap] {};
        this->size = 0;
    }

    int get(int i) {
        return p[i];
    }

    void set(int i, int n) {
        p[i] = n;
    }

    void pushback(int n) {
        if (size == cap) {
            resize();
        }
        p[size] = n;
        size++;
    }

    int popback() {
        size--;
        return p[size];
    }

    void resize() {
        cap *= 2;
        int* newArr = new int[cap] {};
        for(int i=0; i<size; i++){
            newArr[i] = p[i];
        }
        delete[] p;
        p = newArr;
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return cap;
    }
};
