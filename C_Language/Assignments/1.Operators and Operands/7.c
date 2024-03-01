/*Write a program to find out the difference in days between any two dates. It must work
regardless of the year, month and day. Consider Leap years while calculating the difference.*/

#include <stdio.h>

// Function to check if a year is a leap year
int is_leap_year(int year) {
  if (year % 4 == 0) {
    if (year % 100 == 0) {
      if (year % 400 == 0) {
        return 1;
      } else {
        return 0;
      }
    } else {
      return 1;
    }
  } else {
    return 0;
  }
}

// Function to calculate the number of days in a month
int days_in_month(int month, int year) {
  switch (month) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      return 31;
    case 4:
    case 6:
    case 9:
    case 11:
      return 30;
    case 2:
      if (is_leap_year(year)) {
        return 29;
      } else {
        return 28;
      }
    default:
      return -1;
  }
}

// Function to calculate the difference in days between two dates
int date_difference(int day1, int month1, int year1, int day2, int month2, int year2) {
  // Calculate the number of days in each date
  int days1 = day1 + (month1 - 1) * days_in_month(month1, year1) + year1 * 365;
  int days2 = day2 + (month2 - 1) * days_in_month(month2, year2) + year2 * 365;

  // Calculate the difference in days
  int difference = days2 - days1;

  return difference;
}

int main() {
  // Get the two dates from the user
  int day1, month1, year1, day2, month2, year2;
  printf("Enter the first date (day month year): ");
  scanf("%d %d %d", &day1, &month1, &year1);
  printf("Enter the second date (day month year): ");
  scanf("%d %d %d", &day2, &month2, &year2);

  // Calculate the difference in days
  int difference = date_difference(day1, month1, year1, day2, month2, year2);

  // Print the difference in days
  printf("The difference in days between the two dates is %d days.\n", difference);

  return 0;
}