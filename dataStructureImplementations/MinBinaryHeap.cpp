#include <iostream>

using namespace std;

void swap(int* x, int* y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

class MinHeap
{
  int* harr;
  int node_count;
  int heap_size;
public:
  MinHeap(int size);

  void Heapify(int r);

  void insertKey(int k);
  void deleteKey(int k);
  void decreaseKey(int i, int d);
  int getMin() { return harr[0]; }
  int extractMin();

  int parent(int i) { return i > 0 ? (i - 1) / 2 : i; }
  int left(int i) { return 2 * i + 1; }
  int right(int i) { return 2 * i + 2; }


};

MinHeap::MinHeap(int size)
{
  heap_size = size;
  node_count = 0;
  harr = new int[size];
}
void MinHeap::insertKey(int key) {
  if (heap_size == node_count) {
    cout << "Overflow" << endl;
    return;
  }
  int i = node_count;
  harr[node_count] = key;
  heap_size++;
  while (i != 0 && key < harr[parent(i)]) { swap(&harr[parent(i)], &harr[i]); i = parent(i); }
}

void MinHeap::Heapify(int i) {
  int smallest = i;
  int l = left(i);
  if (l < node_count && harr[l] < harr[i]) smallest = l;
  int r = right(i);
  if (r < node_count && harr[r] < smallest) smallest = r;

  if (smallest != i) {
    swap(&harr[i], &harr[smallest]);
    Heapify(smallest);
  }
}

int MinHeap::extractMin() {
  if (node_count < 0) return -1;
  if (node_count == 1) {
    node_count--;
    return harr[0];
  }

  int min = harr[0];
  harr[0] = harr[node_count - 1];
  node_count--;
  Heapify(0);

  return min;
}

void MinHeap::deleteKey(int i) {
  harr[i] = INT_MIN;
  extractMin();
}

void MinHeap::decreaseKey(int i, int d) {
  harr[i] -= d;
  while (i != 0 && harr[parent(i)] > harr[i]) { swap(&harr[i], &harr[parent(i)]); i = parent(i); }
}


int main() {
  MinHeap h(11);
  h.insertKey(3);
  h.insertKey(2);
  h.deleteKey(1);
  h.insertKey(15);
  h.insertKey(5);
  h.insertKey(4);
  h.insertKey(45);
  cout << h.extractMin() << " ";
  cout << h.getMin() << " ";
  h.decreaseKey(2, 1);
  cout << h.getMin();
  return 0;
}

//        1
//    2          3
// 4    5      6    7
//8 9 10 11 12 13 