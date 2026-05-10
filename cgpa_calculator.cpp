#include <iostream>
#include <iomanip>
#include <windows.h>
#include <limits> 

using namespace std;

int main() {
    SetConsoleOutputCP(65001);
    // ---- WELCOME SCREEN ----
    cout << "=======================================" << endl;
    cout << "      CodeAlpha Internship (Task 1)    " << endl;
    cout << "            CGPA CALCULATOR            " << endl;
    cout << "=======================================" << endl;
    cout << endl; // blank line
    
    // ---- Grade reference table -----
    cout << "--- Grade Point Reference ---" << endl;
    cout << "A  = 4.0 | B+ = 3.5 | B = 3.0" << endl;
    cout << "C+ = 2.5 | C  = 2.0 | D = 1.0" << endl;
    cout << "F  = 0.0" << endl;
    cout << "-------------------------------"<< endl;
    cout << endl; // blank line

    // ---- Get number of courses ----
    int numberOfCourses;
    do {
        cout << "How many courses do you take? ";
        cin >> numberOfCourses;

        if (cin.fail()) {
            // reboot and flush if letters are typed
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid! Please enter numbers only." << endl;
        }
        else if (numberOfCourses <= 0) {
            cout << "❌ Invalid! Must be at least 1 course." << endl;
        }
    } while (cin.fail() || numberOfCourses <= 0);
    cout << "✅ Accepted!" << endl;
    cout << endl;

    
    // Course array
    int course[numberOfCourses];
    // Grade array
    double courseGrade[numberOfCourses];

    // Total weighted points
    double totalWeightedPoints = 0;
    // Total credit hours
    int totalCreditHours = 0;
    // CGPA
    double cgpa;
    
    // ---- Loop through each course ----
    for (int i = 0; i < numberOfCourses; i++) {
        
        double gradePoints;
        int creditHours;

        cout << "---- Course " << i + 1<< " ---- " << endl;
        // validate grade points
        do {
            cout << "Enter grade points (0.0 - 4.0): ";
            cin >> gradePoints;

            if (cin.fail()) {
                // reboot and flush if letters are typed
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid! Please enter numbers only." << endl;
            }
            else if (gradePoints < 0.0 || gradePoints > 4.0) {
                cout << "❌ Invalid! Grade must be between 0.0 and 4.0." << endl;
            }

        } while (cin.fail() || gradePoints < 0.0 || gradePoints > 4.0);
        cout << "✅ Accepted!" << endl;
        
        // validate credit hours
        do {
            cout << "Enter credit hours (1 - 6): ";
            cin >> creditHours;
            
            if (cin.fail()) {
                // reboot and flush if letters are typed
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid! Please enter numbers only." << endl;
            }
            else if (creditHours < 1 || creditHours > 6) {
                cout << "❌ Invalid! Credit hours must be between 1 and 6." << endl;
            }
            
        } while (cin.fail() || creditHours < 1 || creditHours > 6);
        cout << "✅ Accepted!" << endl;
        cout << endl;

        // store course and course Grades in arrays
        course[i] = i + 1;
        courseGrade[i] = gradePoints;

        // Update total weighted points and total credit hours
        totalWeightedPoints += (gradePoints * creditHours);
        totalCreditHours += creditHours;
    }

    // ---- CGPA Calculation ----
    cgpa = totalWeightedPoints / totalCreditHours;

    // ---- Results ----
    cout << "===========================================" << endl;
    cout << "               RESULTS                     " << endl;
    cout << "===========================================" << endl;
    cout << "       Course       |         Grade        " << endl;
    cout << "-------------------------------------------" << endl;
    for (int i = 0; i < numberOfCourses; i++) {
        cout << " Course " << course[i] << "         :          " << courseGrade[i] << endl;
    }
    cout << "===========================================" << endl;
    cout << "Total Credit Hours : " << totalCreditHours << endl;
    cout << "===========================================" << endl;
    cout << "Your CGPA          : " << fixed << setprecision(2) << cgpa << endl;
    cout << "===========================================" << endl;
    cout << "===========================================" << endl;
    cout << "     Thank you for using CGPA Calc!       " << endl;
    cout << "===========================================" << endl;

    return 0;
}