#include <iostream>
using namespace std;

void heapify(int arr[], int size, int index) {
    int largest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < size && arr[leftChild] > arr[largest])
        largest = leftChild;

    if (rightChild < size && arr[rightChild] > arr[largest])
        largest = rightChild;

    if (largest != index) {
        swap(arr[index], arr[largest]);
        heapify(arr, size, largest);
    }
}

void maxHeap(int arr[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(arr, size, i);
}

int main() {
    int arr[50], n;
    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    maxHeap(arr, n);

    cout << "Max Heap: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
