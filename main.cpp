#include <iostream>
#include <cstdlib>
#include <chrono>

const int MAX_ROWS = 1000;
const int MAX_COLS = 1000;


void createRandomMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = std::rand() % 100 + 1;
        }
    }
}


void calculateRowSum(const int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    auto row_start = std::chrono::high_resolution_clock::now();

    int row_total_sum = 0;
    for (int i = 0; i < rows; ++i) {
        int row_sum = 0;
        for (int j = 0; j < cols; ++j) {
            row_sum += matrix[i][j];
            row_total_sum += matrix[i][j];
        }
        //std::cout << "Сумма элементов в строке " << i+1 << ": " << row_sum << std::endl;
    }

    auto row_end = std::chrono::high_resolution_clock::now();
    auto row_duration = std::chrono::duration_cast<std::chrono::milliseconds>(row_end - row_start);
    std::cout <<"Сумма по строкам длительность: " << row_duration.count() << std::endl;

    std::cout << "\n Общая сумма всех элементов по строкам: " << row_total_sum << std::endl;
}


void calculateColSum(const int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    auto col_start = std::chrono::high_resolution_clock::now();

    int col_total_sum = 0;
    for (int j = 0; j < cols; ++j) {
        int col_sum = 0;
        for (int i = 0; i < rows; ++i) {
            col_sum += matrix[i][j];
            col_total_sum += matrix[i][j];
        }
        //std::cout << "Сумма элементов в столбце " << j+1 << ": " << col_sum << std::endl;
    }

    auto col_end = std::chrono::high_resolution_clock::now();
    auto col_duration = std::chrono::duration_cast<std::chrono::milliseconds>(col_end - col_start);
    std::cout <<"Сумма по столбцам длительность: " << col_duration.count() << std::endl;

    std::cout << "\n Общая сумма всех элементов по столбцам: " << col_total_sum << std::endl;
}

int main() {

    const int rows = 1000; 
    const int cols = 1000; 

    int matrix[MAX_ROWS][MAX_COLS];

    createRandomMatrix(matrix, rows, cols);

    calculateRowSum(matrix, rows, cols);
    calculateColSum(matrix, rows, cols);

    return 0;
}
