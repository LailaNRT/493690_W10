// Tugas Struct dan Array
// Chapter 9; Programming exercise no. 2


// Laila Nur Rizqi Tasnimiyah
// 22/493690/TK/54095

#include <iostream>
#include <string>
#include <iomanip>
#include <cctype> // cek isdigit() 
using namespace std;

// jumlah maksimum murid
const int NUM_STUDENTS = 20;

struct studentType {
    string studentFName; // nama depan
    string studentLName; // nama belakang
    int testScore;       // nilai ulangan (0-100)
    char grade;          // final grade (A, B, C, D, E)
};

// memeriksa apakah nama (depan dan belakang) sudah ada di dalam array.
bool isDuplicateName(const studentType list[], int currentSize, const string& fName, const string& lName) {
    // hanya perlu memeriksa elemen hingga currentSize (yaitu, data yang sudah dimasukkan).
    for (int j = 0; j < currentSize; ++j) {
        if (list[j].studentFName == fName && list[j].studentLName == lName) {
            return true; // Duplikat ditemukan
        }
    }
    return false; // tidak ada duplikat
}

// function a: reads student data into the array
void readStudentData(studentType list[], int size) {
    // instruct user to input data on one line: FirstName LastName Score
    cout << "--- Enter Data for " << size << " Students (Format: FirstName LastName Score) ---" << endl;
    cout << "------------------------------------------------" << endl;
    for (int i = 0; i < size; ++i) {
        
        bool dataIsValid = false;
        
        // loop until a valid score and valid names are entered
        do {
            cout << "  Enter data for Student " << i + 1 << ": ";
            
            // baca nama depan, nama belakang, dan nilai ulangan
            if (!(cin >> list[i].studentFName >> list[i].studentLName >> list[i].testScore)) {
                // handle non-numeric input error for score
                cerr << "!!! Input error. Please enter with the format: FirstName LastName Score" << endl;
                cin.clear();
                cin.ignore(10000, '\n');
                continue; // restart the loop iteration for this student
            }

            // 1. cek apakah nama duplikat
            bool isDuplicate = isDuplicateName(list, i, list[i].studentFName, list[i].studentLName);
            
            // 2. cek apakah nilai ujian memiliki rentang yang benar (0-100)
            bool scoreIsValid = (list[i].testScore >= 0 && list[i].testScore <= 100);

            // 3. cek apakah nama mengandung angka
            bool nameHasDigit = false;
            
            for (char c : list[i].studentFName) {
                if (isdigit(c)) { nameHasDigit = true; break; }
            }
            if (!nameHasDigit) {
                for (char c : list[i].studentLName) {
                    if (isdigit(c)) { nameHasDigit = true; break; }
                }
            }

            // tampilkan pesan error dan set flag
            if (isDuplicate) {
                 cerr << "!!! Invalid data. This name (" << list[i].studentFName << " " << list[i].studentLName << ") has already been entered. Please re-enter the data." << endl;
            } else if (!scoreIsValid) {
                cerr << "!!! Invalid score (" << list[i].testScore << "). Score must be between 0 and 100. Please re-enter all three values." << endl;
            } else if (nameHasDigit) {
                cerr << "!!! Invalid name. Name cannot contain numbers. Please re-enter all three values." << endl;
            } else {
                // jika semua valid, set flag
                dataIsValid = true;
            }

        } while (!dataIsValid);
    }
    cout << "------------------------------------------------" << endl;
}

// function b: assigns the relevant letter grade based on test score
// 90-100 A, 80-89 B, 70-79 C, 60-69 D, <60 E
void assignGrades(studentType list[], int size) {
    for (int i = 0; i < size; ++i) {
        int score = list[i].testScore;
        if (score >= 90) {
            list[i].grade = 'A';
        } else if (score >= 80) {
            list[i].grade = 'B';
        } else if (score >= 70) {
            list[i].grade = 'C';
        } else if (score >= 60) {
            list[i].grade = 'D';
        } else {
            list[i].grade = 'E';
        }
    }
}

// function c: finds and returns the highest test score in the array
int findHighestScore(const studentType list[], int size) {
    int maxScore = 0; // initialize with the lowest possible valid score

    for (int i = 0; i < size; ++i) {
        if (list[i].testScore > maxScore) {
            maxScore = list[i].testScore;
        }
    }
    return maxScore;
}

// function d: prints the names and scores of students who achieved the highest score
void printHighestScorers(const studentType list[], int size, int highestScore) {
    
    cout << endl << "--- Students with the Highest Score ---" << endl;
    cout << left << setw(25) << "STUDENT NAME"
              << setw(10) << "SCORE" << endl;
    cout << "---------------------------------" << endl;

    for (int i = 0; i < size; ++i) {
        if (list[i].testScore == highestScore) {
            // Required format: Last Name, First Name
            cout << left << setw(25)
                      << (list[i].studentLName + ", " + list[i].studentFName);
            cout << setw(10) << list[i].testScore << endl;
        }
    }
    cout << "---------------------------------" << endl;
}

// tabel menampilkan seluruh isi struct dalam bentuk tabel
void printStudentResults(const studentType list[], int size) {
    
    cout << endl << "--- CLASS GRADE REPORT ---" << endl;
    cout << left << setw(25) << "STUDENT NAME"
              << setw(10) << "SCORE"
              << setw(10) << "GRADE" << endl;
    cout << "-------------------------------------------" << endl;

    for (int i = 0; i < size; ++i) {
        // name format: Last Name, First Name
        cout << left << setw(25)
                  << (list[i].studentLName + ", " + list[i].studentFName);
        // Score
        cout << setw(10) << list[i].testScore;
        // Grade
        cout << setw(10) << list[i].grade << endl;
    }
    cout << "-------------------------------------------" << endl;
}


int main() {
    // 1. variable declarations
    studentType classList[NUM_STUDENTS];
    int highestScore;

    // 2. function Calls 
    
    // a. read all student data (nama depan, nama belakang, nilai ulangan)
    readStudentData(classList, NUM_STUDENTS);

    // b. assign grades to all students
    assignGrades(classList, NUM_STUDENTS);

    // print all students' results
    printStudentResults(classList, NUM_STUDENTS);

    // c. find the highest test score
    highestScore = findHighestScore(classList, NUM_STUDENTS);

    // d. print the names and scores of students with the highest score
    printHighestScorers(classList, NUM_STUDENTS, highestScore);

    return 0;
}