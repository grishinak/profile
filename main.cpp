#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>

std::vector<std::vector<int>> createRandomMatrix(int k, int l) {
    std::vector<std::vector<int>> matrix(k, std::vector<int>(l));
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < l; ++j) {
            matrix[i][j] = std::rand() % 100 + 1;
        }
    }
    return matrix;
}


void calculateRowSum(const std::vector<std::vector<int>>& matrix, int rows, int cols) {
auto row_start = std::chrono::high_resolution_clock::now();

    int row_total_sum = 0;
    std::vector<int> row_sum(rows, 0);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            row_sum[i] += matrix[i][j];
            row_total_sum += matrix[i][j];
        }
    }

auto row_end = std::chrono::high_resolution_clock::now();
auto row_duration = std::chrono::duration_cast<std::chrono::milliseconds>(row_end - row_start);
std::cout <<"Сумма по строкам. длительность: " << row_duration.count() << std::endl;

    std::cout << "\n Общая сумма всех элементов по строкам: " << row_total_sum << std::endl;
}



void calculateColSum(const std::vector<std::vector<int>>& matrix, int rows, int cols) {
auto col_start = std::chrono::high_resolution_clock::now();

    int col_total_sum = 0;
    std::vector<int> col_sum(cols, 0);
    for (int j = 0; j < cols; ++j) {
        for (int i = 0; i < rows; ++i) {
            col_sum[j] += matrix[i][j];
            col_total_sum += matrix[i][j];
        }
    }

auto col_end = std::chrono::high_resolution_clock::now();
auto col_duration = std::chrono::duration_cast<std::chrono::milliseconds>(col_end - col_start);
std::cout <<"Сумма по столбцам. длительность: " << col_duration.count() << std::endl;

    std::cout << "\n Общая сумма всех элементов по столбцам: " << col_total_sum << std::endl;
}



int main() {
    
    const int rows = 1000; 
    const int cols = 1000; 

    std::vector<std::vector<int>> matrix = createRandomMatrix(rows, cols);

    calculateRowSum(matrix, rows, cols);
    calculateColSum(matrix, rows, cols);

    return 0;
}
