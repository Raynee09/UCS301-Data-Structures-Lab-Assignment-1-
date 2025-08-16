#include <iostream>
#include <algorithm> 
using namespace std;

void removeDuplicates(int arr[], int& size) {
    if (size == 0) { 
        cout << "Array is empty!" << endl;
        return;
    }
    if (size == 1) { 
        cout << "No duplicates to remove!" << endl;
        return;
    }
    sort(arr, arr + size); 
    int writeIndex = 1;
    for (int i = 1; i < size; i++) { 
        if (arr[i] != arr[writeIndex - 1]) { 
            arr[writeIndex] = arr[i]; 
            writeIndex++;
        }
    }
    size = writeIndex; 
    cout << "Duplicates removed successfully!" << endl;
}

void display(int arr[], int size) {
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

int main() {
    int arr[100]; 
    int size; 
    cout << "Enter the size of the array (max 100): ";
    cin >> size;
    if (size > 100 || size <= 0) { 
        cout << "Invalid size! Size should be between 1 and 100." << endl;
        return 1;
    }
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

     cout << "Original array: ";
    display(arr, size);

    removeDuplicates(arr, size);

    cout << "Array after removing duplicates: ";
    display(arr, size);

    return 0; 
}
