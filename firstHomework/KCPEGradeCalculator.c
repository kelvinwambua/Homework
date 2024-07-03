#include <stdio.h>

double compute();
double input();
double get_mean(double math, double eng, double kisw, double sci, double ssr);
char* get_grade(double mean);
void show(double mean, char *grade);

int main() {
    int count, number;
    printf("\nHow many students do you want to enter their Math, English, Kiswahili, SSRE, Science: ");
    scanf("%d", &number);
    for (count = 0; count < number; count++) {
        compute();
    }
    getchar();
    getchar();
    return 0;
}

double compute() {
    double math, eng, kisw, sci, ssr, mean;
    char* grade;
    printf("\nEnter the marks for Math: ");
    math = input();
    printf("\nEnter the marks for English: ");
    eng = input();
    printf("\nEnter the marks for Kiswahili: ");
    kisw = input();
    printf("\nEnter the marks for Science: ");
    sci = input();
    printf("\nEnter the marks for Social Studies and Religious Education: ");
    ssr = input();
    mean = get_mean(math, eng, kisw, sci, ssr);
    grade = get_grade(mean);
    show(mean, grade);
    return 0;
}

double input() {
    double mark;
    scanf("%lf", &mark);
    while (mark < 0 || mark > 100) {
        printf("\nInvalid mark. Please enter a mark between 0 and 100\n");
        scanf("%lf", &mark);
    }
    return mark;
}

double get_mean(double math, double eng, double kisw, double sci, double ssr) {
    return (math + eng + kisw + sci + ssr) / 5;
}

char* get_grade(double mean) {
    if (mean >= 80 && mean <= 100) {
        return "A";
    } else if (mean >= 75 && mean < 80) {
        return "A-";
    } else if (mean >= 70 && mean < 75) {
        return "B+";
    } else if (mean >= 65 && mean < 70) {
        return "B";
    } else if (mean >= 60 && mean < 65) {
        return "B-";
    } else if (mean >= 55 && mean < 60) {
        return "C+";
    } else if (mean >= 50 && mean < 55) {
        return "C";
    } else if (mean >= 45 && mean < 50) {
        return "C-";
    } else if (mean >= 40 && mean < 45) {
        return "D+";
    } else if (mean >= 35 && mean < 40) {
        return "D";
    } else if (mean >= 30 && mean < 35) {
        return "D-";
    } else {
        return "E";
    }
}

void show(double mean, char* grade) {
    printf("\nThe mean score is %.3lf and the grade is %s\n", mean, grade);
}