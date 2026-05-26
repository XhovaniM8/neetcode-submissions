class DynamicArray {
public:
    explicit DynamicArray(int capacity)
        : size_(0), capacity_(capacity), data_(new int[capacity]) {}

    ~DynamicArray() { delete[] data_; }

    int get(int i) const { return data_[i]; }

    void set(int i, int n) { data_[i] = n; }

    void pushback(int n) {
        if (size_ == capacity_) resize();
        data_[size_++] = n;
    }

    int popback() { return data_[--size_]; }  // assume non-empty

    void resize() {
        capacity_ *= 2;
        int* newData = new int[capacity_];
        for (int k = 0; k < size_; ++k) newData[k] = data_[k];
        delete[] data_;
        data_ = newData;
    }

    int getSize() const { return size_; }
    int getCapacity() const { return capacity_; }

private:
    int* data_;
    int  size_;
    int  capacity_;
};
