#ifndef COMPLEXITYOFALGORITHMS_ARRAY_H
#define COMPLEXITYOFALGORITHMS_ARRAY_H

// ввод массива data размера n
void inputArray_(int *a, size_t n);

// вывод массива data размера n
void outputArray_(const int *a, size_t n);

// возвращает значение первого вхождения элемента x
// в массиве a размера n при его наличии, иначе - n
size_t linearSearch_(const int *a, const size_t n, int x);

// возвращает позицию вхождения элемента x
// в отсортированном массиве a размера n при его наличии, иначе - n
size_t binarySearch_(const int *a, const size_t n, int x);

// возвращает позицию первого элемента равного или большего x
// в отсортированном массиве a размера n
// при отсутствии такого элемента возвращает n
size_t binarySearchMoreOrEqual_(const int *a, const size_t n, int x);

// вставка элемента со значением value
// в массив data размера n на позицию pos
void insert_(int *a, size_t *n, size_t pos, int value);

// добавление элемента value в конец массива data размера n
void append_(int *a, size_t *n, int value);

// удаление из массива data размера n элемента на позиции pos
// с сохранением порядка оставшихся элементов
void deleteByPosSaveOrder_(int *a, size_t *n, size_t pos);

// удаление из массива data размера n элемента на позиции pos
// без сохранения порядка оставшихся элементов
// размер массива data уменьшается на единицу
void deleteByPosUnsavedOrder_(int *a, size_t *n, size_t pos);

// возвращает значение ’истина’ если все элементы
// массива data размера n соответствует функции-предикату predicate
// иначе - ’ложь’
int all_(const int *a, size_t n, int (*predicate )(int));

// возвращает значение ’истина’ если хотя бы один элемент
// массива data размера n соответствует функции-предикату predicate
// иначе - ’ложь’
int any_(const int *a, size_t n, int (*predicate )(int));

// применяет функцию predicate ко всем элементам массива source
// размера n и сохраняет результат в массиве dest размера n
void forEach_(const int *source, int *dest, size_t n, const int (*
predicate )(int));

// возвращает количество элементов массива data размера n
// удовлетворяющих функции-предикату predicate
int countIf_(const int *a, size_t n, int (*predicate )(int));

// удаляет из массива data размера n все элементы, удовлетворяющие
// функции-предикату deletePredicate, записывает в n новый размер
// массива
void deleteIf_(int *a, size_t *n, int (*deletePredicate )(int));

// возвращает -1, если первый аргумент меньше второго аргумента,
// 1, если первый аргумент больше второго и 0, если аргументы равны
int cmp_ints(const void *a, const void *b);

// меняет значения по адресам a и b
void swap(int *a, int *b);

long long max2(long long int a, long long int b);

// изменяет массив c размера sizeC, производя объединение массива a размера sizeA с массива b размера sizeB
void mergeOfUniqueElement(const int *a, const size_t sizeA, const int *b, const size_t sizeB, int *c, size_t *sizeC);

// возвращает true, если массив a размера n упорядочен, иначе - false
bool isOrdered(const int *a, size_t n);

// algorithms of Sorting

void generateRandomArray(int *a, size_t n);

void generateOrderedArray(int *a, size_t n);

void generateOrderedBackwards(int *a, size_t n);

// algorithms of generate

void bubbleSort ( int *a, size_t size );

void selectionSort(int *a, size_t n);

void insertionSort(int *a, size_t n);

#endif