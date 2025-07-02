#include <fstream>
#include <iostream>
using namespace std;


int main() {
    ofstream outFile("output.txt"); 

    if (outFile.is_open()) { 
        outFile << "This is a line of text." <<endl;
        outFile << "Another line of text." <<endl;
        outFile.close(); 
        cout << "Data written to output.txt" <<endl;
    } else {
        std::cerr << "Error opening file!" <<endl;
    }
    return 0;
}
