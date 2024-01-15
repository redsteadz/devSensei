#include <iostream>

#include <iostream>
using namespace std;

int partition(int a[], int l, int r) {
  int mid = l + (r - l) / 2;
  int pivot = a[mid];
  swap(a[mid], a[r]);
  int i = l;
  for (int j = l; j < r; j++){
    if (pivot > a[j]){
      swap(a[i], a[j]);
      i++;
    }
  }
  swap(a[i], a[r]);
  return i;
}

int quickSelect(int a[], int l, int r, int k) {
  while (l < r) {
    int p = partition(a, l, r);
    if (p == k) return a[p];
    if (p > k) r = p - 1;
    else l = p + 1;
  }
  return a[l];
}

int main (int argc, char *argv[]) {
  int a[] = {10, 7, 8, 9, 1, 5};
  // partition(a, 0, 5);
  cout << quickSelect(a, 0, 5, 0) << endl;
  for (auto n : a) {
    cout << n << " ";
  }

  return 0;
}
