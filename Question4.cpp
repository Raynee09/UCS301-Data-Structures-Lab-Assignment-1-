#include <iostream>  
#include <vector>  
using namespace std; 

void reverseArray(int arr[], int size) {
    int start = 0;              
    int end = size - 1;         
    while (start < end) {       
        
        int temp = arr[start];  
        arr[start] = arr[end];  
        arr[end] = temp;        
        start++;                
        end--;                  
    }
}

vector<vector<int>> transposeMatrix(const vector<vector<int>>& matrix, int rows, int cols) {
  
    vector<vector<int>> transpose(cols, vector<int>(rows, 0)); 
    for (int i = 0; i < rows; i++) {  
        for (int j = 0; j < cols; j++) { 
            transpose[j][i] = matrix[i][j]; 
        }
    }
    return transpose; 
}

vector<vector<int>> multiplyMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B, int m, int n, int p) {
    
    vector<vector<int>> result(m, vector<int>(p, 0)); 
    for (int i = 0; i < m; i++) {      
        for (int j = 0; j < p; j++) { 
            for (int k = 0; k < n; k++) { 
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return result; 
}


void printMatrix(const vector<vector<int>>& matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) { 
        for (int j = 0; j < cols; j++) { 
            cout << matrix[i][j] << " "; 
        }
        cout << endl; 
    }
}


void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";       
    }
    cout << endl;
}

int main() {
    cout << "Reversing an array:" << endl; 
    int arr[] = {1, 2, 3, 4, 5};          
    int size = 5;                          
    cout << "Original array: ";            
    printArray(arr, size);              
    reverseArray(arr, size);
    cout << "Reversed array: ";           
    printArray(arr, size);              
    cout << endl;                     

    cout << "Matrix Transpose:" << endl;  
    vector<vector<int>> matrix = {     
        {1, 2, 3},
        {4, 5, 6}
    };
    int rows = 2;                         
    int cols = 3;                        
    cout << "Original matrix:" << endl;    
    printMatrix(matrix, rows, cols);       
    vector<vector<int>> trans = transposeMatrix(matrix, rows, cols); 
    cout << "Transpose matrix:" << endl;   
    printMatrix(trans, cols, rows);        
    cout << endl;                     

    cout << "Matrix Multiplication:" << endl; 
    vector<vector<int>> A = {                
        {1, 2, 3},
        {4, 5, 6}
    };
    vector<vector<int>> B = {                 
        {7, 8},
        {9, 10},
        {11, 12}
    };
    int m = 2;
    int n = 3;  
    int p = 2;  
    cout << "Matrix A:" << endl;              
    printMatrix(A, m, n);                    
    cout << "Matrix B:" << endl;
    printMatrix(B, n, p);                     
    vector<vector<int>> product = multiplyMatrices(A, B, m, n, p);
    cout << "Product (A * B):" << endl;    
    printMatrix(product, m, p);             
    
    return 0;
}
