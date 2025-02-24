#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void bubbleSort(vector<int>& v) {

    int n = v.size();

    for (int i = 0; i < n - 1; i++) {

        for (int j = 0; j < n - i - 1; j++) {
          
            if (v[j] < v[j + 1])
                swap(v[j+1], v[j]);
        }
    }
}

int main()
{
    vector<int> arr = {5, 1, 4, 2, 8,10, 12, 14, 16, 18, 20 };
    bubbleSort(arr);
    for (int i = 0; i < 10; i++) {
    
        cout << arr[i] << " ";
    }
    return 0;
}
