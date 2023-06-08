#include <iostream>
using namespace std;

class ShellSort {
public:
    int n;
    int A[100];
    int i;

    void accept();
    void sort();
    void display();
};

void ShellSort::accept() {
    cout << "Enter the number of students: ";
    cin >> n;

    for (i = 0; i < n; i++) {
        cout << "Enter the marks of student " << i + 1 << ": ";
        cin >> A[i];
        cout << " ";
    }
}

void ShellSort::display() {
    cout << "You entered the following data:\n\t";
    for (i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

void ShellSort::sort() {
    for (int interval = n / 2; interval > 0; interval /= 2) {
        for (int i = interval; i < n; i += 1) {
            int temp = A[i];
            int j;
            for (j = i; j >= interval && A[j - interval] > temp; j -= interval) {
                A[j] = A[j - interval];
            }
            A[j] = temp;
        }
        
        cout << "Pass " << ":-\t";
        for (int i = 0; i < n; ++i) {
            cout << A[i] << "\t";
        }
        cout << "\n\n";
    }
}

int main() {
    ShellSort b;
    int choice;
    char ch;
    do {
        cout << "\n\t    Enter the choice";
        cout << "\n\t 1. Insert an element";
        cout << "\n\t 2. Display the elements";
        cout << "\n\t 3. Shell sort";
        cout << "\n\t 4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                b.accept();
                break;
            case 2:
                b.display();
                break;
            case 3:
                b.sort();
                b.display();
                break;
			case 4:
				cout <<"Exiting...";
				break;
            default:
                cout << "Unknown choice";
        }
    } while (choice != 4);

    return 0;
}

