#include <iostream>
using namespace std;

//завдання 1
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(int month, int year) {
    switch (month) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        return 31;
    case 4: case 6: case 9: case 11:
        return 30;
    case 2:
        return isLeapYear(year) ? 29 : 28;
    default:
        return 0;
    }
}

int daysFromStartOfYear(int day, int month, int year) {
    int totalDays = 0;
    for (int i = 1; i < month; i++) {
        totalDays += daysInMonth(i, year);
    }
    totalDays += day;
    return totalDays;
}

int daysBetweenDates(int day1, int month1, int year1, int day2, int month2, int year2) {
    int days1 = daysFromStartOfYear(day1, month1, year1);
    int days2 = daysFromStartOfYear(day2, month2, year2);

    if (year1 == year2) {
        return (days2 - days1);
    }

    int daysInYear1 = isLeapYear(year1) ? 366 : 365;
    int totalDays = (daysInYear1 - days1) + days2;

    for (int i = year1 + 1; i < year2; i++) {
        totalDays += isLeapYear(i) ? 366 : 365;
    }

    return totalDays;
}


//завдання 2
double calculateAverage(int arr[], int size) {
    if (size == 0) {
        cout << "The array is empty!" << endl;
    }

    int sum = 0;

    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    return static_cast<double>(sum) / size;
}

int main() {
    int day1, month1, year1;
    int day2, month2, year2;

    cout << "Enter the first date (day, month, year):";
    cin >> day1 >> month1 >> year1;

    cout << "Enter the second date (day, month, year): ";
    cin >> day2 >> month2 >> year2;

    int difference = daysBetweenDates(day1, month1, year1, day2, month2, year2);

    cout << "The difference between the dates is " << difference << " days." << endl;


    int size;

    cout << "Enter the number of array elements: ";
    cin >> size;

    int arr[size];

    cout << "Enter the elements of the array:";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    double average = calculateAverage(arr, size);

    cout << "Arithmetic average of array elements: " << average << endl;
}
