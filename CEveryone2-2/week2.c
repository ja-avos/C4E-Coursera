/*
    Assignment for week 2. Option 1. Dates.
    Juan Avelino
    2023/04/19
*/
#include <stdio.h>

typedef enum month { 
    jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec 
    } month;

typedef struct date { 
    month month; 
    int day;
    } date;

/*
    Returns the number of days according to the month
*/
int daysInMonth(month m) {
    if (m == feb)
        return 28;
    else if (m == apr || m == jun || m == sep || m == nov)
        return 30;
    else
        return 31;
}

/*
    Returns the next day of the date.
    If the date is the last day of the month, it returns the first day of the next month.
*/
date nextDay(date d) {
    if (d.day == daysInMonth(d.month)) {
        d.day = 1;
        d.month = (d.month + 1) % 12;
    } else
        d.day++;

    return d;
}

/*
    Prints the date in the format "Month day"
*/
void printDate(date d) {
    switch (d.month) // Print the month based on the enumeration
    {
    case jan:
        printf("January ");
        break;
    case feb:
        printf("February ");
        break;
    case mar:
        printf("March ");
        break;
    case apr:
        printf("April ");
        break;
    case may:
        printf("May ");
        break;
    case jun:
        printf("June ");
        break;
    case jul:
        printf("July ");
        break;
    case aug:
        printf("August ");
        break;
    case sep:
        printf("September ");
        break;
    case oct:
        printf("October ");
        break;
    case nov:
        printf("November ");
        break;
    case dec:
        printf("December ");
        break;
    default:
        break;
    }
    printf("%d\n", d.day); // Print the day and a new line
}

/*
    Main function
    Reads a date from the user, prints the original date, and the next day.
    The test dates like January 1, February 28, March 14, October 31 and December 31 can be
    used with the inputs 1/1, 2/28, 3/14, 10/31 and 12/31 respectively.
*/
int main(void) {
    date d;

    printf("Enter a date (mm/dd): ");
    scanf("%d/%d", &d.month, &d.day);

    d.month--; // The month is decremented because the enumeration starts at 0.

    printf("Original date: ");
    printDate(d);

    printf("Next day: ");
    printDate(nextDay(d));
}