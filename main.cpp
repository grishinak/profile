#include <iostream>
#include <vector>
#include <cstdlib>

std::vector<std::vector<int>> createRandomMatrix(int k, int l) {
    std::vector<std::vector<int>> matrix(k, std::vector<int>(l));
    //Разные при каждом запуске
    //std::srand(static_cast<unsigned int>(time(nullptr)));

    // Заполняем случайными числами от 1 до 100
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < l; ++j) {
            matrix[i][j] = std::rand() % 100 + 1;
        }
    }
    return matrix;
}




int main() {

    const int rows = 10000; 
    const int cols = 10000; 

    std::vector<std::vector<int>> matrix = createRandomMatrix(rows, cols);

    // Вывод элементов сгенерированной матрицы
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
    std::cout << "\n Общая сумма всех элементов по строкам: " << total_sum1 << std::endl;


    std::cout << "\n Сумма по столбцам:\n";
    for (int j = 0; j < cols; ++j) {
        std::cout << "Столбец " << j+1 << ": " << col_sum[j] << std::endl;
    }
    std::cout << "\n Общая сумма всех элементов по столбцам: " << total_sum2 << std::endl;
    
    return 0;
}
