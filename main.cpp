#include <iostream>
#include <vector>
#include <cstdlib> // Для использования функции rand()

std::vector<std::vector<int>> createRandomMatrix(int k, int l) {
    std::vector<std::vector<int>> matrix(k, std::vector<int>(l));
    // Seed the random number generator
    std::srand(static_cast<unsigned int>(time(nullptr)));

    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < l; ++j) {
            // Generate random numbers in the range from 1 to 100
            matrix[i][j] = std::rand() % 100 + 1;
        }
    }
    return matrix;
}




int main() {

    const int rows = 10; // Number of rows
    const int cols = 10; // Number of columns

    std::vector<std::vector<int>> matrix = createRandomMatrix(rows, cols);

    // Print the matrix
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    int total_sum1 = 0;
    // Сумма по строкам
    std::vector<int> row_sum(rows, 0);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            row_sum[i] += matrix[i][j];
            total_sum1 += matrix[i][j];
        }
    }

    int total_sum2 = 0;
    // Сумма по столбцам
    std::vector<int> col_sum(cols, 0);
    for (int j = 0; j < cols; ++j) {
        for (int i = 0; i < rows; ++i) {
            col_sum[j] += matrix[i][j];
            total_sum2 += matrix[i][j];
        }
    }


    // Вывод результатов
    std::cout << "Сумма по строкам:\n";
    for (int i = 0; i < rows; ++i) {
        std::cout << "Строка " << i+1 << ": " << row_sum[i] << std::endl;
    }
    std::cout << "\nОбщая сумма всех элементов по строкам: " << total_sum1 << std::endl;


    std::cout << "\nСумма по столбцам:\n";
    for (int j = 0; j < cols; ++j) {
        std::cout << "Столбец " << j+1 << ": " << col_sum[j] << std::endl;
    }
    std::cout << "\nОбщая сумма всех элементов по столбцам: " << total_sum2 << std::endl;
    
    return 0;
}
