#include <stdio.h>
#include <limits.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>

#include "array.h"

#define K_FOR_COMB_SORT 1.24733

void inputArray_(int *const a, const size_t n) {
    for (size_t i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void outputArray_(const int *const a, const size_t n) {
    for (size_t i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void append_(int *const a, size_t *const n, const int value) {
    (*n)++;
    a[*n - 1] = value;
}

void insert_(int *const a, size_t *const n, const size_t pos,
             const int value) {
    assert(pos < *n);
    if (*n != 0) {
        size_t lowBound = (pos == 0) ? SIZE_MAX : pos;

        (*n)++;
        for (size_t i = *n; i != lowBound; i--)
            a[i] = a[i - 1];
        a[pos] = value;
    } else {
        (*n)++;
        a[pos] = value;
    }
}

void deleteByPosSaveOrder_(int *a, size_t *n, const size_t pos) {
    for (size_t i = pos + 1; i < *n; i++)
        a[i - 1] = a[i];
    (*n)--;
}

void deleteByPosUnsavedOrder_(int *a, size_t *n, size_t pos) {
    a[pos] = a[*n - 1];
    (*n)--;
}

size_t linearSearch_(const int *a, const size_t n, int x) {
    for (size_t i = 0; i < n; i++)
        if (a[i] == x)
            return i;
    return n;
}

int any_(const int *a, size_t n, int (*predicate )(int)) {
    for (size_t i = 0; i < n; i++)
        if (predicate(a[i]))
            return 1;
    return 0;
}

int all_(const int *a, size_t n, int (*predicate )(int)) {
    for (size_t i = 0; i < n; i++)
        if (!predicate(a[i]))
            return 0;
    return 1;
}

int countIf_(const int *const a, const size_t n, int (*predicate )(int)) {
    int count = 0;
    for (size_t i = 0; i < n; i++)

        count += predicate(a[i]);
    return count;
}

void deleteIf_(int *const a, size_t *const n, int (*deletePredicate )(int)) {
    size_t iRead = 0;
    while (iRead < *n && !deletePredicate(a[iRead]))
        iRead++;
    size_t iWrite = iRead;
    while (iRead < *n) {
        if (!deletePredicate(a[iRead])) {
            a[iWrite] = a[iRead];
            iWrite++;

        }
        iRead++;
    }
    *n = iWrite;
}

void forEach_(const int *source, int *dest, const size_t n, const int (*
predicate )(int)) {
    for (size_t i = 0; i < n; i++)
        dest[i] = predicate(source[i]);
}

size_t binarySearch_(const int *a, size_t n, int x) {
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int middle = left + (right - left) / 2;
        if (a[middle] < x)
            left = middle + 1;
        else if (a[middle] > x)
            right = middle - 1;
        else
            return middle;
    }
    return n;
}

size_t binarySearchMoreOrEqual_(const int *a, size_t n, int x) {
    if (a[0] >= x)
        return 0;
    size_t left = 0;
    size_t right = n;
    while (right - left > 1) {
        size_t middle = left + (right - left) / 2;
        if (a[middle] < x)
            left = middle;
        else
            right = middle;
    }
    return right;
}

int cmp_ints(const void *a, const void *b) {
    int arg1 = *(const int *) a;
    int arg2 = *(const int *) b;
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

long long max2(long long int a, long long int b) {
    return a > b ? a : b;
}

void mergeOfUniqueElement(const int *a, const size_t sizeA, const int *b, const size_t sizeB, int *c, size_t *sizeC) {
    int indexA = 0;
    int indexB = 0;
    while (indexA < sizeA && indexB < sizeB) {
        if (a[indexA] < b[indexB])
            append_(c, sizeC, a[indexA++]);
        else if (a[indexA] > b[indexB])
            append_(c, sizeC, b[indexB++]);
        else
            indexA++;
    }

    if (indexA < sizeA)
        while (indexA < sizeA)
            append_(c, sizeC, a[indexA++]);
    else
        while (indexB < sizeB)
            append_(c, sizeC, b[indexB++]);

}

bool isOrdered(const int *a, size_t n) {
    for (size_t i = 1; i < n; i++)
        if (a[i] < a[i - 1])
            return false;

    return true;
}

// algorithms of generate

void generateRandomArray(int *a, size_t n) {
    srand(time(NULL));
    for (size_t i = 0; i < n; i++)
        a[i] = rand();
}

void generateOrderedArray(int *a, size_t n) {
    for (size_t i = 0; i < n; i++)
        a[i] = i;
}

void generateOrderedBackwards(int *a, size_t n) {
    for (int i = n - 1; i >= 0; i--)
        a[i] = i;
}

// algorithms of Sorting

void bubbleSort(int *a, size_t size) {
    for (size_t i = 0; i < size - 1; i++)
        for (size_t j = size - 1; j > i; j--)
            if (a[j - 1] > a[j])
                swap(&a[j - 1], &a[j]);
}

void selectionSort(int *a, size_t n) {
    for (size_t i = 0; i < n - 1; i++) {
        size_t indexMin = i;
        for (size_t j = i; j < n; j++)
            if (a[j] < a[indexMin])
                indexMin = j;
        swap(a + i, a + indexMin);
    }
}

void insertionSort(int *a, size_t n) {
    for (int i = 1; i < n; i++) {
        int t = a[i];
        int indexRead = i - 1;
        while (indexRead > -1 && a[indexRead] > t) {
            a[indexRead + 1] = a[indexRead];
            indexRead--;
        }
        a[indexRead + 1] = t;
    }
}

void combSort(int *a, size_t n) {
    size_t s = n;
    bool swapped = true;
    while (s > 1 || swapped) {
        if (s > 1)
            s /= K_FOR_COMB_SORT;
        swapped = false;
        for (size_t i = 0, j = i + s; j < n; i++, j++) {
            if (a[i] > a[j]) {
                swap(a + i, a + j);
                swapped = true;
            }
        }
    }
}

void shellSort(int *a, int n) {
    for (int s = n / 2; s > 0; s /= 2) {
        for (int i = s; i < n; i++) {
            for (int j = i - s; j >= 0 && a[j] > a[j + s]; j -= s)
                swap(a + j, a + j + s);
        }
    }
}

void digitalSort(int *a, size_t n) {
    size_t countOfStep = sizeof(int);
    int *buf = (int *) malloc(sizeof(int) * n);
    for (size_t s = 0; s < countOfStep; s++) {
        int countOfLastEightBits[512 + 1] = {0};
        int positionOfLastEightBits[512 + 1] = {0};
        for (size_t i = 0; i < n; i++) {
            int lastEightBits = (a[i] >> (s * 8)) & ((1 << 8) - 1);
            if (a[i] >> 31)
                countOfLastEightBits[256 - lastEightBits]++;
            else
                countOfLastEightBits[256 + 1 + lastEightBits]++;
        }
        for (size_t i = 1; i < 513; i++)
            positionOfLastEightBits[i] = positionOfLastEightBits[i - 1] + countOfLastEightBits[i - 1];

        for (size_t i = 0; i < n; i++) {
            int lastEightBits = (a[i] >> (s * 8) & ((1 << 8) - 1));
            if (a[i] >> 31) {
                buf[positionOfLastEightBits[256 - lastEightBits]] = a[i];
                positionOfLastEightBits[256 - lastEightBits]++;
            } else {
                buf[positionOfLastEightBits[257 + lastEightBits]] = a[i];
                positionOfLastEightBits[257 + lastEightBits]++;
            }
        }
        memcpy(a, buf, sizeof(int) * n);
    }
    free(buf);
}
