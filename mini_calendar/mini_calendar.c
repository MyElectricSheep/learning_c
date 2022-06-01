#include <stdio.h>
#include <stdbool.h>

bool is_leap_year(int year);
void add_days_to_date(int *mm, int *dd, int *yy, int days_left_to_add);

// A leap year has to be divisible by 4 and NOT divisible by 100
// except when the year is divisible by 400.

// Long version
// bool is_leap_year(int year)
// {
//     if (year % 4 != 0)
//     {
//         return false;
//     }
//     else
//     {
//         if (year % 100 != 0)
//         {
//             return true;
//         }
//         else
//         {
//             if (year % 400 != 0)
//             {
//                 return false;
//             }
//             else
//             {
//                 return true;
//             }
//         }
//     }
// }

// Short version
bool is_leap_year(int year)
{
    return (year % 4 == 0 && (year % 100 || year % 400 == 0));
}

// index 0 is a placeholder so indices will match the regular month numbers
// e.g.: days_in_month[12] == december
int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void add_days_to_date(int *mm, int *dd, int *yy, int days_left_to_add)
{
    int days_left_in_month;
    while (days_left_to_add > 0)
    {
        days_left_in_month = days_in_month[*mm] - *dd;
        if (*mm == 2 && is_leap_year(*yy))
        {
            days_left_in_month++;
        }
        if (days_left_to_add >= days_left_in_month)
        {
            days_left_to_add -= days_left_in_month;
            *dd = 1;
            days_left_to_add--;
            if (*mm != 12)
            {
                *mm = *mm + 1;
            }
            else
            {
                *mm = 1;
                *yy = *yy + 1;
            }
        }
        else
        {
            *dd += days_left_to_add;
            days_left_to_add = 0;
        }
    }
}

int main()
{
    // int year = 0;

    // while (year < 1800 || year > 10000)
    // {
    //     printf("Please choose a year between 1800 and 10000\n");
    //     scanf("%d", &year);
    // }

    // bool leap = is_leap_year(year);

    // printf("%s", leap ? "Leap Year" : "Not Leap Year");

    int mm, dd, yy, days_left_to_add;

    while (yy < 1800 || yy > 10000)
    {
        printf("Please choose a date (between 1800 and 10000) in the format mm dd yy\nAlso provide the number of days to add to this date.\nFor example, if you want to add 500 days to March 14, 2021,\nthe input should be entered as follows: 3 13 2021 500\n");
        scanf("%d%d%d%d", &mm, &dd, &yy, &days_left_to_add);
    }

    printf("The date you entered is:\n");
    printf("%d/%d/%d\n", mm, dd, yy);

    add_days_to_date(&mm, &dd, &yy, days_left_to_add);

    printf("The new date (with %d days added) is:\n", days_left_to_add);
    printf("%d/%d/%d\n", mm, dd, yy);
}