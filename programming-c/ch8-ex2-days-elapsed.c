// Program to return the days elapsed between two dates as an integer

#include <stdio.h>

struct date
{
  int month;
  int day;
  int year;
};

int convertYear (int year, int month)
{
  int convertedYear;

  if ( month <= 2 )
  {
    convertedYear = year - 1;
  }
  else
  {
    convertedYear = year;
  }

  return convertedYear;
}

int convertMonth (int month)
{
  int convertedMonth;

  if ( month <= 2 )
  {
    convertedMonth = month + 13;
  }
  else
  {
    convertedMonth = month + 1;
  }

  return convertedMonth;
}

int convertToInt (struct date dateToConvert)
{
  return (1461 * convertYear (dateToConvert.year, dateToConvert.month)) / 4
          + (153 * convertMonth (dateToConvert.month)) / 5
          + dateToConvert.day;
}

int findDifference (struct date date1, struct date date2)
{
  int date1AsInt = convertToInt(date1);
  int date2AsInt = convertToInt(date2);

  return date2AsInt - date1AsInt;
}

int main (void)
{
  struct date date1, date2;
  int elapsedDays = 0;

  printf ("Please enter the first date (mm dd yyyy): ");
  scanf ("%i%i%i", &date1.month, &date1.day, &date1.year);
  printf ("Thanks.\nI have that the first date is %i/%i/%i.\n\n", date1.month, date1.day, date1.year);

  printf ("Please enter the second date (mm dd yyyy): ");
  scanf ("%i%i%i", &date2.month, &date2.day, &date2.year);
  printf ("Thanks.\nI have that the second date is %i/%i/%i.\n\n", date2.month, date2.day, date2.year);

  elapsedDays = findDifference(date1, date2);

  printf ("\n%i days have elapsed between those dates. Thank you.\n", elapsedDays);

  return 0;
}
