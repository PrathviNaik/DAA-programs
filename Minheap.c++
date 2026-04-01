#include <iostream>
using namespace std;

class MinHeap {
    int arr[100];
    int size;

public:
    MinHeap() {
        size = 0;
    }

    // Insert element
    void insert(int val) {
        size++;
        int index = size;
        arr[index] = val;

        // Heapify up
        while (index > 1) {
            int parent = index / 2;

            if (arr[parent] > arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            } else {
                return;
            }
        }
    }

    // Delete root (minimum element)
    void deleteRoot() {
        if (size == 0) {
            cout << "Heap is empty\n";
            return;
        }

        arr[1] = arr[size];
        size--;

        // Heapify down
        int i = 1;
        while (i <= size) {
            int left = 2 * i;
            int right = 2 * i + 1;
            int smallest = i;

            if (left <= size && arr[left] < arr[smallest])
                smallest = left;

            if (right <= size && arr[right] < arr[smallest])
                smallest = right;

            if (smallest != i) {
                swap(arr[i], arr[smallest]);
                i = smallest;
            } else {
                return;
            }
        }
    }

    // Print heap
    void print() {
        for (int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MinHeap h;

    h.insert(50);
    h.insert(30);
    h.insert(40);
    h.insert(10);
    h.insert(5);

    cout << "Heap: ";
    h.print();

    h.deleteRoot();

    cout << "After deletion: ";
    h.print();

    return 0;
}