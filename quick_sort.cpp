#include <iostream>
using namespace std;

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

// function to print the array
void printArray(int arr[], int size) {
  int i;
  for (i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;
}

int partition(int arr[], int low, int high) {
    
  int pivot = arr[high];
  int i = (low - 1);

  for (int j = low; j < high; j++) {
    if (arr[j] <= pivot) {
      i++;
      swap(&arr[i], &arr[j]);
    }

  }
  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}

void quickSort(int arr[], int low, int high) {

  if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi -1);
        quickSort(arr, pi + 1, high);
    }

}

int main() {
  int arr[] = {8, 7, 6, 1, 0, 9};
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << "Unsorted Array: \n";
  printArray(arr, n);
  quickSort(arr, 0, n - 1);
  cout << "Sorted array in ascending order: \n";
  printArray(arr, n);

}

