class MinHeap {
private:
  std::vector<int> heap;

  void bubbleUp(int index) {
    while (index > 0) {
      int parent = (index - 1) / 2;
      if (heap[index] < heap[parent]) {
        std::swap(heap[index], heap[parent]);
        index = parent;
      } else {
        break;
      }
    }
  }

  void bubbleDown(int index) {
    int n = heap.size();
    while (true) {
      int smallest = index;
      int left = 2 * index + 1;
      int right = 2 * index + 2;

      if (left < n && heap[left] < heap[smallest]) {
        smallest = left;
      }

      if (right < n && heap[right] < heap[smallest]) {
        smallest = right;
      }

      if (smallest != index) {
        std::swap(heap[index], heap[smallest]);
        index = smallest;
      } else {
        break;
      }
    }
  }

public:
  MinHeap() {}

  void push(int val) {
    heap.push_back(val);
    bubbleUp(heap.size() - 1);
  }

  int pop() {
    if (heap.empty())
      return -1;

    int root = heap[0];
    heap[0] = heap.back();
    heap.pop_back();

    if (!heap.empty()) {
      bubbleDown(0);
    }
    return root;
  }

  int top() { return heap.empty() ? -1 : heap[0]; }

  void heapify(const std::vector<int> &arr) {
    heap = arr;
    for (int i = (heap.size() / 2) - 1; i >= 0; i--) {
      bubbleDown(i);
    }
  }
};