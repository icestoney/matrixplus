# s21_matrix_oop

Этот проект представляет собой реализацию библиотеки для работы с матрицами на языке C++ с использованием объектно-ориентированного подхода (ООП). Библиотека предоставляет набор операций для работы с матрицами, включая базовые арифметические операции, преобразования матриц, а также более сложные вычисления, такие как нахождение определителя и обратной матрицы.

## Содержание

1. [Введение](#введение)
2. [Функциональность](#функциональность)
3. [Установка](#установка)
4. [Использование](#использование)
5. [Тестирование](#тестирование)
6. [Вклад в проект](#вклад-в-проект)
7. [Лицензия](#лицензия)

## Введение

Данный проект является реализацией библиотеки для работы с матрицами, написанной на языке C++ с использованием объектно-ориентированного подхода. Библиотека предоставляет класс `S21Matrix`, который позволяет выполнять различные операции над матрицами, такие как сложение, вычитание, умножение, транспонирование, вычисление определителя и обратной матрицы.

## Функциональность

Библиотека поддерживает следующие операции над матрицами:

- **Сложение матриц**: `SumMatrix(const S21Matrix& other)`
- **Вычитание матриц**: `SubMatrix(const S21Matrix& other)`
- **Умножение матрицы на число**: `MulNumber(const double num)`
- **Умножение матриц**: `MulMatrix(const S21Matrix& other)`
- **Транспонирование матрицы**: `Transpose()`
- **Вычисление матрицы алгебраических дополнений**: `CalcComplements()`
- **Вычисление определителя матрицы**: `Determinant()`
- **Вычисление обратной матрицы**: `InverseMatrix()`

Также реализованы перегруженные операторы для удобства работы с матрицами:

- **Сложение**: `+`
- **Вычитание**: `-`
- **Умножение**: `*`
- **Сравнение на равенство**: `==`
- **Присваивание**: `=`
- **Сложение с присваиванием**: `+=`
- **Вычитание с присваиванием**: `-=`
- **Умножение с присваиванием**: `*=`
- **Индексация**: `(int i, int j)`

## Установка

Для использования библиотеки необходимо склонировать репозиторий и собрать проект с помощью `Makefile`.

1. Клонируйте репозиторий:
   ```bash
   git clone https://github.com/ваш-username/s21_matrix_oop.git
   cd s21_matrix_oop
   ```

2. Соберите библиотеку и тесты:
   ```bash
   make all
   ```

3. Для запуска тестов выполните:
   ```bash
   make test
   ```

4. Для очистки проекта:
   ```bash
   make clean
   ```

## Использование

Пример использования библиотеки:

```cpp
#include "s21_matrix_oop.h"

int main() {
    S21Matrix matrix1(3, 3);
    S21Matrix matrix2(3, 3);

    // Заполнение матриц значениями
    matrix1(0, 0) = 1;
    matrix1(0, 1) = 2;
    matrix1(0, 2) = 3;
    matrix1(1, 0) = 4;
    matrix1(1, 1) = 5;
    matrix1(1, 2) = 6;
    matrix1(2, 0) = 7;
    matrix1(2, 1) = 8;
    matrix1(2, 2) = 9;

    matrix2(0, 0) = 9;
    matrix2(0, 1) = 8;
    matrix2(0, 2) = 7;
    matrix2(1, 0) = 6;
    matrix2(1, 1) = 5;
    matrix2(1, 2) = 4;
    matrix2(2, 0) = 3;
    matrix2(2, 1) = 2;
    matrix2(2, 2) = 1;

    // Сложение матриц
    S21Matrix result = matrix1 + matrix2;

    // Вывод результата
    result.PrintMatrix();

    return 0;
}
```

## Тестирование

- Unit-тесты написаны с использованием библиотеки `GTest`.
- Покрытие каждой функции — не менее 80%.
- Для запуска тестов: `make test`.
- Для генерации HTML-отчета о покрытии: `make gcov_report`.

## Требования к коду

- Код написан на языке C++ стандарта C++17.
- Используется компилятор gcc.
- Код соответствует стилю Google Style.
- Библиотека оформлена как статическая библиотека `s21_matrix_oop.a` с заголовочным файлом `s21_matrix_oop.h`.
- Подготовлено полное покрытие unit-тестами с использованием библиотеки `GTest`.

Тесты покрывают все основные функции и операции, реализованные в библиотеке.

## Лицензия

Этот проект распространяется под лицензией MIT. Подробнее см. в файле [LICENSE](LICENSE).

---

Проект разработан в рамках учебного задания.
