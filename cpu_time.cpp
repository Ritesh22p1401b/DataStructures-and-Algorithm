#include <bits/stdc++.h>

using namespace std;


int main() {

    int num;
    cout<<"enter the number";cin>>num;

    clock_t start_time = clock(); 

    // long long sum = 0;
    for (int i = 0; i < num; ++i) {
        // sum += i;
    }
    clock_t end_time = clock(); 

    
    double cpu_time_seconds = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    cout<<cpu_time_seconds<<endl;
    
    return 0;
}

