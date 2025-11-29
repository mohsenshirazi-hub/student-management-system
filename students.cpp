#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <chrono>
using namespace std;    


int id_generator() {
    static int id = 0;
    return ++id;
}


class Student {
    private :
    int id ;
    public :
    string Name ;
    string Family ;
    string Major ;
    string Sex ;
    string Passion ;
    int year_of_graduation ;

    Student(string name , string family , string major , string sex , string passion , int year_of_graduation ){
        Name = name ;
        Family = family ; 
        Major = major ;
        Sex = sex ;
        id = id_generator() ;
        Passion = passion ;
        year_of_graduation = year_of_graduation ;
        cout << "new student added " << endl ;

    };
    void show_info(){
        cout << "the student name  " << Name << " " << Family 
        << " studying in major : " << Major
        << " with registraton ID : " << id << endl;

    }

};

int main() {
    vector<string> validMajors = {
    "CS", "Physics", "Math", "Engineering", "Biology"
    };
    vector <Student> students ;
    string name , family , major , sex , passion ;
    int year_of_graduation ;
 
    while (true){
        int option ;
        cout << "hello to student registration system " << endl ;
        cout << "----------------------------------" << endl ;
        cout << "1- Add a new student " << endl ;   
        cout << "2- show all students list" << endl ;
        cout << "3- Exit " << endl ;
        cout << "choose an option to continue " << endl ;
        cin >> option ;
        if (option == 1){
            cout << "Enter your Name " ;
            cin >> name;
            while (!all_of(name.begin(), name.end(), ::isalpha)) {
                cout << "Invalid name. Enter letters only: ";
                cin >> name;
            }
            cout << "Enter your Family name ";
            cin >> family;
            while (!all_of(family.begin(), family.end(), ::isalpha)) {
                cout << "Invalid name. Enter letters only: ";
                cin >> family;
            }
            cout << "Enter your major ";
            cin >> major;
            while (find(validMajors.begin(), validMajors.end(), major) == validMajors.end()) {
                cout << "Invalid major. Allowed majors: CS, Physics, Math, Engineering, Biology\n";
                cout << "Enter your major: ";
                cin >> major;
            }
            cout << "Enter your Sex ";
            cin >> sex;
            while (sex != "male" && sex != "female" &&
                sex != "Male" && sex != "Female"){
                cout << "Invalid sex. Please enter male or female: ";
                cin >> sex;
            }
            cout << "Enter your Passion ";
            cin >> passion ;
            char student_type ;
            cout << "Is the student a graduate student ? (y/n) " ;
            cin >> student_type ;
            if (student_type == 'y' || student_type == 'Y'){
                cout << "Enter year of graduation " ;
                cin >> year_of_graduation ;
                while (cin.fail() || year_of_graduation < 2000 || year_of_graduation > 2300) {
                    cin.clear();            
                    cin.ignore(1000, '\n');  
                    cout << "Invalid year. Enter a valid graduation year: ";
                    cin >> year_of_graduation;
                }
                Student student1 (name , family , major , sex , passion , year_of_graduation ) ;
            } 
            else {
                cout << "Enter year of ecpected graduation " ;
                cin >> year_of_graduation ;
                while (cin.fail() || year_of_graduation < 1300 || year_of_graduation > 1500) {
                    cin.clear();            
                    cin.ignore(1000, '\n');  
                    cout << "Invalid year. Enter a valid graduation year: ";
                    cin >> year_of_graduation;
                }
                Student student1 (name , family , major , sex , passion , year_of_graduation ) ; 
                students.push_back(student1) ;
                student1.show_info() ;
            }
        }
        else if (option == 2){
            cout << "students list : " << endl ;
            for (size_t i = 0; i < students.size(); i++){
                cout << "------------------------" << endl ;
                cout << "name : " << students[i].Name << " " << students[i].Family << endl ;
                cout << "major : " << students[i].Major << endl ;
                cout << "sex : " << students[i].Sex << endl ;
                cout << "graduation year : " << students[i].year_of_graduation << endl ;
                cout << "-------------------------" << endl ;
            }
        }
        else if (option == 3){
            cout << "Exiting the system. Goodbye!" << endl ;
            break ;
        }
        else {
            cout << "Invalid option. Please try again." << endl ;
            break;
        }       
    }

    return 0;
}
