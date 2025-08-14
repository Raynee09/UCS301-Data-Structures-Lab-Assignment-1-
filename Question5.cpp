#include <iostream>
#include <vector>

void rowSums(const std::vector<std::vector<int>>& matrix) {
    int rows = matrix.size();
    if (rows == 0) {
        std::cout << "Matrix is empty!\n";
        return;
    }
    
    for (int i = 0; i < rows; ++i) {
        int sum = 0;
        for (int j = 0; j < matrix[i].size(); ++j) {
            sum += matrix[i][j];
        }
        std::cout << "Sum of row " << i + 1 << ": " << sum << "\n";
    }
}


void columnSums(const std::vector<std::vector<int>>& matrix) {
    int rows = matrix.size();
    if (rows == 0) {
        std::cout << "Matrix is empty!\n";
        return;
    }
    int cols = matrix[0].size();
    
    for (int j = 0; j < cols; ++j) {
        int sum = 0;
        for (int i = 0; i < rows; ++i) {
            sum += matrix[i][j];
        }
        std::cout << "Sum of column " << j + 1 << ": " << sum << "\n";
    }
}
void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }
}

int main() {
    
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    std::cout << "Matrix:\n";
    printMatrix(matrix);
    
    std::cout << "\nRow Sums:\n";
    rowSums(matrix);
    
    std::cout << "\nColumn Sums:\n";
    columnSums(matrix);
    
    return 0;
}