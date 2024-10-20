/******************************************************************************
# Author:           Kyle Noyes & Tyler Leonard
# Assignment:       Dicussion #3 (CS161B)
# Date:             October 10, 2024
# Description:      This program will take na array of numbers from the user
#                   and prompt to check if a section of the array is in order
#                   from least to greatest.
# Input:            int arr[index]
#                   int n
#                   int start
#                   int end
# Output:           string "yes" / "no"
# Sources:          Discussion 3 specifications
#******************************************************************************/

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Number of integers: ";
    cin >> n;

    if (n > 20) {
        cout << "List exceeds maximum allowed size of 20." << endl;
        return 1;
    }

    int arr[20];
    cout << "Enter the values: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int start, end;
    cout << "Enter start and end index: ";
    cin >> start >> end;

    if (start < 0 || end >= n || start > end) {
        cout << "Invalid indices." << endl;
        return 1;
    }

    bool sorted = true;
    for (int i = start; i < end; i++) {
        if (arr[i] > arr[i + 1]) {
            sorted = false;
            break;
        }
    }

    if (sorted) {
        cout << "yes" << endl;
    }
    else {
        cout << "no" << endl;
    }

    return 0;
}