#include <iostream>
#include <time.h>

using namespace std;

/// Task 1
void printArray(const int size, const double *arr) {
    for (int i = 0; i < size; ++i) cout << arr[i] << " ";
    cout << "\n";
}

/// Task 2
void invertArray(const int size, int *arr) {
    cout << "before invert: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
        arr[i] = !arr[i];
    }
    cout << endl;
    cout << "after invert:  ";
    for (int j = 0; j < size; ++j) {
        cout << arr[j] << " ";
    }
}

/// Task 3
void initArray(const int size, int *arr) {
    arr[size];
    for (int i = 0, j = 1; i < size; j += 3, ++i) {
        arr[i] = j;
        cout << j << " ";
    }
}

/// Task 4

void rightShift(const int size, int *arr) {
    int temp = arr[size - 1];
    for (int i = size - 1; i > 0; i--) arr[i] = arr[i - 1];
    arr[0] = temp;
}

void leftShift(const int size, int *arr) {
    int temp = arr[0];
    for (int i = 0; i < size - 1; i++) arr[i] = arr[i + 1];
    arr[size - 1] = temp;
}

void shiftArray(const int size, int *arr, int n) {

    if (n < 0) {
        for (int i = 0; i > n; --i) leftShift(size, arr);
    } else {
        for (int i = 0; i < n; ++i) rightShift(size, arr);
    }

    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
}

/// Task 5
bool checkBalance(const int size, const int *arr) { // {1, 2, 3, 4, 10};
    int left_sum = arr[0], right_sum = 0;

    for(int i = 1; i < size ; ++i)
    {
        right_sum = 0;

        for (int j = i; j < size; ++j) right_sum += arr[j];

        if(left_sum == right_sum) return true;

        left_sum += arr[i];
    }
    return false;
}

int main() {
    const int SIZE = 50;
    srand(time(0));
    /// Task 1
    {
        double arr[SIZE];
        for (double &i : arr) i = rand() % 1000;
        printArray(SIZE, arr);
    }

    /// Task 2
    {
        int arr[SIZE];
        for (int &i: arr) i = rand() % 2;
        invertArray(SIZE, arr);
    }


    /// Task 3
    {
        const int SIZE_ARR_TASK_3 = 8;
        int arr[SIZE_ARR_TASK_3];
        initArray(SIZE_ARR_TASK_3, arr);
    }

    /// Task 4
    {
        const int SIZE_ARR_TASK_4 = 9;
        int arr[SIZE_ARR_TASK_4] = {1, 2, 3, 4, 5, 6, 7, 8, 9,};
        int n = 2;
        shiftArray(SIZE_ARR_TASK_4, arr, n);

    }
    /// Task 5
    {
        const int SIZE_ARR_TASK_5 = 5;
        int arr[SIZE_ARR_TASK_5] = {1, 2, 3, 4, 10};
        cout << checkBalance(SIZE_ARR_TASK_5, arr);
    }

    return 0;
}
