# CMatrix

В рамках данного проекта была реализована библиотека `matrix.h` для обработки числовых матриц на языке программирования `C` с использованием структурного подхода. Для простой сборки проекта был создан `Makefile`. Также все функции были покрыты модульными тестами, написанными с использованием `check.h`.

## Содержание

1. [Установка](#установка)
2. [Структура matrix_t](#структура-matrix_t)
3. [Операции над матрицами](#операции-над-матрицами)

### Установка
Для установки проекта подребуются следующие утилиты:
- `gcc`
- `make`

Для компиляции библиотеки переходим в `src/` и запускаем сборку командой `make s21_matrix.a`. Чтобы использовать тесты выполняем `make test`. Также с помощью `make gcov_report` иожем получить отчет о покрытии кода тестами.

### Структура matrix_t  

```c
typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;
```

- `double **matrix` - матрица в которой хранятся вещественные числа
- `int rows` - количество строк
- `int columns` - количество колонок 

### Операции над матрицами

Все операции (кроме сравнения матриц) возвращают код:

- 0 - OK
- 1 - Ошибка, некорректная матрица
- 2 - Ошибка вычисления

| Название             | Функция                                                             | 
| ---------------------|---------------------------------------------------------------------|
| Создание             | int s21_create_matrix(int rows, int columns, matrix_t *result)      |
| Очистка              | void s21_remove_matrix(matrix_t *A)                                 |
| Сравнение            | int s21_eq_matrix(matrix_t *A, matrix_t *B)                         | 
| Сложение             | int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result)      |
| Вычитание            | int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result)      |
| Умножение на число   | int s21_mult_number(matrix_t *A, double number, matrix_t *result)   |
| Умножение матриц     | int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result)     |
| Транспонирование     | int s21_transpose(matrix_t *A, matrix_t *result)                    |
| Матрица алг. доп.    | int s21_calc_complements(matrix_t *A, matrix_t *result)             |
| Определитель         | int s21_determinant(matrix_t *A, double *result)                    |
| Обратная матрица     | int s21_inverse_matrix(matrix_t *A, matrix_t *result)               |