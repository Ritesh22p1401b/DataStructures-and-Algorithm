#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;

    // Inserting elements
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Stack after pushes (Top to Bottom): ";
    stack<int> temp = s;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    // Removing (popping) element
    s.pop(); // removes 30

    cout << "Stack after one pop (Top to Bottom): ";
    temp = s;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    return 0;
}
