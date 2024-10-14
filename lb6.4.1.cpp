#include <iostream>
#include <iomanip>
#include <cmath>    
#include <vector>
#include <algorithm> 

using namespace std;


double* createArray(int n) {
    double* arr = new double[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }
    return arr;
}


void printArrayRecursive(const double* arr, int n, int index = 0) {
    if (index == 0) {
        cout << "Array: ";
    }
    if (index < n) {
        cout << setw(8) << arr[index];  
        printArrayRecursive(arr, n, index + 1);
    }
    else {
        cout << endl;
    }
}


int countNegativeRecursive(const double* arr, int n, int index = 0) {
    if (index == n) {
        return 0;
    }
    return (arr[index] < 0 ? 1 : 0) + countNegativeRecursive(arr, n, index + 1);
}


int findMinAbsIndexRecursive(const double* arr, int n, int index = 0, int minIndex = 0) {
    if (index == n) {
        return minIndex;
    }
    if (abs(arr[index]) < abs(arr[minIndex])) {
        minIndex = index;
    }
    return findMinAbsIndexRecursive(arr, n, index + 1, minIndex);
}


double sumAfterMinAbsRecursive(const double* arr, int minIndex, int n, int index = 0) {
    if (index <= minIndex) {
        return 0;
    }
    if (index == n) {
        return 0;
    }
    return abs(arr[index]) + sumAfterMinAbsRecursive(arr, minIndex, n, index + 1);
}


void replaceNegativesWithSquaresRecursive(double* arr, int n, int index = 0) {
    if (index == n) {
        return;
    }
    if (arr[index] < 0) {
        arr[index] = arr[index] * arr[index];  
    }
    replaceNegativesWithSquaresRecursive(arr, n, index + 1);
}


void collectNegativeElementsRecursive(const double* arr, vector<double>& negatives, int n, int index = 0) {
    if (index == n) {
        return;
    }
    if (arr[index] < 0) {
        negatives.push_back(arr[index]);
    }
    collectNegativeElementsRecursive(arr, negatives, n, index + 1);
}


void sortNegativesRecursive(double* arr, int n) {
    vector<double> negatives;
    collectNegativeElementsRecursive(arr, negatives, n);  

    sort(negatives.begin(), negatives.end());  

    
    for (int i = 0, negIndex = 0; i < n; i++) {
        if (arr[i] < 0) {
            arr[i] = negatives[negIndex++];
        }
    }
}


int main() {
    int n;
    cout << "size : ";
    cin >> n;

    
    double* arr = createArray(n);

   
    printArrayRecursive(arr, n);

    
    int negativeCount = countNegativeRecursive(arr, n);
    cout << "negative elements: " << negativeCount << endl;

    
    int minAbsIndex = findMinAbsIndexRecursive(arr, n);
    cout << "Min: " << arr[minAbsIndex] << " at index: " << minAbsIndex << endl;

   
    double sumAfterMinAbs = sumAfterMinAbsRecursive(arr, minAbsIndex, n);
    cout << "Sum : " << sumAfterMinAbs << endl;

    
    replaceNegativesWithSquaresRecursive(arr, n);

    
    sortNegativesRecursive(arr, n);

   
    printArrayRecursive(arr, n);

    
    delete[] arr;

    return 0;
}
