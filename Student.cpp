#include <iostream>
#include <string>
#include <vector>
using namespace std;



struct Student {
    string name;
    vector<string> subjects;
    vector<int> marks;
};

int main() {
    Student students[5];

    students[0].name = "Alice";
    students[0].subjects = {"DS", "C++", "Java"};
    students[0].marks = {90, 85, 92};

    students[1].name = "Bob";
    students[1].subjects= {"DS", "C++", "Java"};
    students[1].marks = {30, 88, 75};

    students[2].name="charlie";
    students[2].subjects= {"DS", "C++", "Java"};
    students[2].marks={75,89,65};

        
    
    string choice;
    cout<<"enter the subject choice  DS,C++,Java"<<endl;
    cin>>choice;
    for(int i=0;i<3;i++){
        if(students[i].subjects[i]=="DS"){
            if(students[i].marks[i]>75<90){
                cout<<"fast learner"<<endl;
                cout<<students[i].name;
                continue;
            }
            if(students[i].marks[i]<75){
                cout<<"slow learner"<<endl;
                cout<<students[i].name;
            } 
        }
    }
    
    


    // for (int i = 0; i < 5; ++i) {
    //     cout << "Student Name: " << students[i].name <<endl;
    //     cout << "Subjects and Marks:" << endl;
    //     for (size_t j = 0; j < students[i].subjects.size(); ++j) {
    //         cout << "  " << students[i].subjects[j] << ": " << students[i].marks[j] << endl;
    //     }
    //     cout << endl;
    // }

    return 0;
}
