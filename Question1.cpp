#include <iostream>
#include <unordered_set>
using namespace std;

int arr[100]; 
int size = 0; 


void create() {
    cout << "Enter the size of the array (max 100): ";
    cin >> size;
    if (size > 100 || size <= 0) { 
        cout << "Invalid size! Size should be between 1 and 100." << endl;
        size = 0;
        return;
    }
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) { 
        cin >> arr[i]; 
    }
    cout << "Array created successfully!" << endl;
}


void display() {
    if (size == 0) { 
        cout << "Array is empty!" << endl;
        return;
    }
    cout << "Array elements are: ";
    for (int i = 0; i < size; i++) { 
        cout << arr[i] << " ";
    }
    cout << endl;
}


void insert() {
    int pos, value;
    cout << "Enter the position (0-based index) to insert: ";
    cin >> pos; 
    if (pos < 0 || pos > size || size >= 100) { 
        cout << "Invalid position or array is full!" << endl;
        return;
    }
    cout << "Enter the value to insert: ";
    cin >> value;
    for (int i = size; i > pos; i--) { 
        arr[i] = arr[i - 1];
    }
    arr[pos] = value; 
    size++;
    cout << "Element inserted successfully!" << endl;
}

void deleteElement() {
    int pos;
    cout << "Enter the position (0-based index) to delete: ";
    cin >> pos; 
    if (pos < 0 || pos >= size) {
        cout << "Invalid position!" << endl;
        return;
    }
    for (int i = pos; i < size - 1; i++) { 
        arr[i] = arr[i + 1];
    }
    size--; 
    cout << "Element deleted successfully!" << endl;
}


void linearSearch() {
    int value;
    cout << "Enter the value to search: ";
    cin >> value; 
    for (int i = 0; i < size; i++) { 
        if (arr[i] == value) {
            cout << "Element " << value << " found at index " << i << endl;
            return;
        }
    }
    cout << "Element " << value << " not found in the array!" << endl;
}


void removeDuplicates() {
    if (size == 0) { 
        cout << "Array is empty!" << endl;
        return;
    }
    unordered_set<int> seen; 
    int writeIndex = 0; 
    for (int i = 0; i < size; i++) { 
        if (seen.find(arr[i]) == seen.end()) { 
            seen.insert(arr[i]); 
            arr[writeIndex] = arr[i]; 
            writeIndex++; 
        }
    }
    size = writeIndex; 
    cout << "Duplicates removed successfully!" << endl;
}

int main() {
    int choice;
    do { 
        cout << "\n------MENU------\n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. REMOVE DUPLICATES\n";
        cout << "7. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice; 

        switch (choice) { 
            case 1:
                create();
                break;
            case 2:
                display(); 
                break;
            case 3:
                insert(); 
                break;
            case 4:
                deleteElement(); 
                break;
            case 5:
                linearSearch(); 
                break;
            case 6:
                removeDuplicates();
                break;
            case 7:
                cout << "Exiting program!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 7); 
    return 0; 
}
