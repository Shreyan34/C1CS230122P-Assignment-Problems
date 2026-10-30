// Program 23
// Write a program in C to accept the total number of students as ‘n’ and the current date. Input the date of birth of each student to calculate their age in terms of years, months and days using structures.

#include <stdio.h>
#include <stdlib.h>

struct Date {
    int day;
    int month;
    int year;
};

struct Student {
    int roll;
    struct Date dob;
    int years, months, days;   /* calculated age */
};

int is_leap(int y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int days_in_month(int m, int y) {
    static const int dim[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (m == 2 && is_leap(y))
        return 29;
    return dim[m - 1];
}

int is_valid_date(struct Date d) {
    if (d.year < 1 || d.month < 1 || d.month > 12)
        return 0;
    return d.day >= 1 && d.day <= days_in_month(d.month, d.year);
}

/* returns 1 if a is later than b */
int is_after(struct Date a, struct Date b) {
    if (a.year != b.year)   return a.year > b.year;
    if (a.month != b.month) return a.month > b.month;
    return a.day > b.day;
}

void calculate_age(struct Student *s, struct Date cur) {
    int y = cur.year  - s->dob.year;
    int m = cur.month - s->dob.month;
    int d = cur.day   - s->dob.day;

    if (d < 0) {
        /* borrow the length of the month before the current month */
        int pm = cur.month - 1;
        int py = cur.year;
        if (pm == 0) {
            pm = 12;
            py--;
        }
        d += days_in_month(pm, py);
        m--;
    }
    if (m < 0) {
        m += 12;
        y--;
    }
    s->years = y;
    s->months = m;
    s->days = d;
}

struct Date read_date(const char *prompt) {
    struct Date d;
    while (1) {
        printf("%s (dd mm yyyy): ", prompt);
        if (scanf("%d %d %d", &d.day, &d.month, &d.year) != 3) {
            printf("Invalid input. Please enter numbers only.\n");
            while (getchar() != '\n');   /* discard bad input */
            continue;
        }
        if (is_valid_date(d))
            return d;
        printf("That is not a valid date. Try again.\n");
    }
}

int main(void) {
    int n, i;
    printf("Enter the total number of students: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of students.\n");
        return 1;
    }

    struct Date current = read_date("Enter the current date");

    struct Student *students = malloc(n * sizeof(struct Student));
    if (students == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        students[i].roll = i + 1;
        while (1) {
            char label[40];
            snprintf(label, sizeof label, "Enter DOB of student %d", i + 1);
            students[i].dob = read_date(label);
            if (!is_after(students[i].dob, current))
                break;
            printf("Date of birth cannot be after the current date.\n");
        }
        calculate_age(&students[i], current);
    }

    printf("\n%-8s %-12s %-6s %-7s %-5s\n", "Student", "DOB", "Years", "Months", "Days");
    printf("-------------------------------------------\n");
    for (i = 0; i < n; i++) {
        printf("%-8d %02d/%02d/%04d   %-6d %-7d %-5d\n",
               students[i].roll,
               students[i].dob.day, students[i].dob.month, students[i].dob.year,
               students[i].years, students[i].months, students[i].days);
    }

    free(students);
    return 0;
}
