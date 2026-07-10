class DynamicArray {
private:
    int* arr;
    int _size;
    int _capacity;
public:
    DynamicArray(int capacity) : _capacity(capacity), _size(0) {
        arr = (int*)malloc(capacity * sizeof(int));;
    }

    int get(int i) {
        return arr[i];
    }

    void set(int i, int n) {
        arr[i] = n;
    }

    void pushback(int n) {
        if(_size >= _capacity) resize();

        arr[_size++] = n;
    }

    int popback() {
        return arr[--_size];
    }

    void resize() {
        int new_cap = _capacity * 2;
        int* new_arr = (int*)malloc(new_cap * sizeof(int));
        for(int i{}; i < _size; ++i) {
            new_arr[i] = std::move(arr[i]);
        }
        arr = new_arr;
        _capacity = new_cap;
    }

    int getSize() {
        return _size;
    }

    int getCapacity() {
        return _capacity;
    }
};
