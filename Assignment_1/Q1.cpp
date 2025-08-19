#include <iostream>
using namespace std;

int arr[100]; 
int n = 0;    
void create() {
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void display() {
    if (n == 0) {
        cout << "Array is empty.\n";
        return;
    }
    cout << "Array elements: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insert() {
    if (n >= 100) {
        cout << "Array is full.\n";
        return;
    }
    int pos, val;
    cout << "Enter position to insert (1 to " << n + 1 << "): ";
    cin >> pos;
    cout << "Enter value to insert: ";
    cin >> val;

    if (pos < 1 || pos > n + 1) {
        cout << "Invalid position.\n";
        return;
    }
    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = val;
    n++;
    cout << "Element inserted.\n";
}

void del() {
    if (n == 0) {
        cout << "Array is empty.\n";
        return;
    }
    int pos;
    cout << "Enter position to delete (1 to " << n << "): ";
    cin >> pos;

    if (pos < 1 || pos > n) {
        cout << "Invalid position.\n";
        return;
    }
    for (int i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
    cout << "Element deleted.\n";
}

void linearSearch() {
    if (n == 0) {
        cout << "Array is empty.\n";
        return;
    }
    int key, found = 0;
    cout << "Enter element to search: ";
    cin >> key;

    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Element found at position " << i + 1 << ".\n";
            found = 1;
            break;
        }
    }
    if (!found) {
        cout << "Element not found.\n";
    }
}

int main() {
    int choice;
    do {
        cout << "1. CREATE\n2. DISPLAY\n3. INSERT\n4. DELETE\n5. LINEAR SEARCH\n6. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: insert(); break;
            case 4: del(); break;
            case 5: linearSearch(); break;
            case 6: break;
            default: cout << "Invalid\n";
        }
    } 
    while (choice != 6);
}
