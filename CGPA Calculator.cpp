#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    const int MAX_COURSES = 100;
    string courseNames[MAX_COURSES];
    float grades[MAX_COURSES];
    int creditHours[MAX_COURSES];
    int numCourses;

    cout << "Enter number of courses: ";
    cin >> numCourses;

    if (numCourses <= 0 || numCourses > MAX_COURSES) {
        cout << "Invalid number of courses. Please enter between 1 and " << MAX_COURSES << ".\n";
        return 1;
    }

    float totalGradePoints = 0.0;
    int totalCredits = 0;

    for (int i = 0; i < numCourses; ++i) {
        cout << "\nEnter details for course " << i + 1 << ":\n";

        cout << "Course name: ";
        cin >> ws; // clears input buffer
        getline(cin, courseNames[i]);

        cout << "Grade (e.g. 3.5): ";
        cin >> grades[i];

        cout << "Credit hours: ";
        cin >> creditHours[i];

        totalGradePoints += grades[i] * creditHours[i];
        totalCredits += creditHours[i];
    }

    float cgpa = (totalCredits > 0) ? totalGradePoints / totalCredits : 0.0;

    // Display results
    cout << "\n--- Course Grades Summary ---\n";
    cout << left << setw(25) << "Course"
         << setw(15) << "Grade"
         << setw(15) << "Credit Hours" << endl;

    for (int i = 0; i < numCourses; ++i) {
        cout << left << setw(25) << courseNames[i]
             << setw(15) << fixed << setprecision(2) << grades[i]
             << setw(15) << creditHours[i] << endl;
    }

    cout << "\nFinal CGPA: " << fixed << setprecision(2) << cgpa << endl;

    return 0;
}
