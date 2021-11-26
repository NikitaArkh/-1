#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float func(float x) {
    return sqrt(x + 1);
}

void leftRectangels(float a, float b, int n, float e) {
    float sum = 0, h, i1, i2;
    h = (b - a) / n;
    for (float i = a; i <= b - h; i += h)
        sum += func(i);
    sum *= h;
    i1 = sum;
    printf("The method of rectangles = %f\n", i1);

}

void finCountInterval(float a, float b, int n, float e) {
    float sum = 0, h, i1, i2;
    h = (b - a) / n;
    do {
        for (float i = a; i <= b; i += h)
            sum += func(i);
        sum *= h;
        i1 = sum;
        n += 2;
        sum = 0;
        for (float i = a; i < b; i += h)
            sum += func(i);
        sum *= h;
        i2 = sum;
    } while (fabs(i1 - i2) >= e);
    printf("The method of rectangles = %f\nNumber of intervals %i\n", i2, n);
}

void rightRectangles(float a, float b, int n, float e) {
    float sum = 0, h, i1, i2;
    h = (b - a) / n;
    for (float i = a + h; i <= b; i += h)
        sum += func(i);
    sum *= h;
    i1 = sum;
    printf("The method of rectangles = %f\n", i1);
    do {
        h = (b - a) / n;
        for (float i = a; i <= b; i += h)
            sum += func(i);
        sum *= h;
        i1 = sum;
        n += 2;
        sum = 0;
        h = (b - a) / n;
        for (float i = a; i < b; i += h)
            sum += func(i);
        sum *= h;
        i2 = sum;
    } while (fabs(i1 - i2) >= e);
    printf("The method of rectangles = %f\nNumber of intervals %i\n", i2, n);
}

void Trapezoidal(float a, float b, int n, float e) {
    float sum = 0, h, i1, i2, y = 0;
    h = (b - a) / n;
    y += func(a) + func(b);
    for (int i = 1; i < n; i++)
        y += 2 * (func(a + h * i));
    i1 = ((b - a) / (2 * n) * y);
   printf("Trapezoidal method = %f\n", i1);
    do {
        y = 0;
        h = (b - a) / n;
        y += func(a) + func(b);
        for (int i = 1; i < n; i++)
            y += 2 * (func(a + h * i));
        i1 = ((b - a) / (2 * n) * y);

        n += 2;
        y = 0;

        h = (b - a) / n;
        y += func(a) + func(b);
        for (int i = 1; i < n; i++)
            y += 2 * (func(a + h * i));
        i2 = ((b - a) / (2 * n) * y);
    } while (fabs(i1 - i2) >= e);
    printf("Trapezoidal method = %f\nNumber of intervals %i\n", i2, n);
}

void Simpson(float a, float b, int n, float e) {
    float i2 = e + 1, i1 = 0;
    float h, sum2 = 0, sum4 = 0, sum = 0;
    h = (b - a) / (2 * n);
    for (int i = 1; i <= 2 * n - 1; i += 2) {
        sum4 += func(a + h * i);
        sum2 += func(a + h * (i + 1));
    }
    sum = func(a) + 4 * sum4 + 2 * sum2 - func(b);
    i2 = i1;
    i1 = (h / 3) * sum;
for (; (n <= 4) || (fabs(i1 - i2) > e); n += 2) {
        sum2 = 0, sum4 = 0, sum = 0;
        h = (b - a) / (2 * n);
        for (int i = 1; i <= 2 * n - 1; i += 2) {
            sum4 += func(a + h * i);
            sum2 += func(a + h * (i + 1));
        }
        sum = func(a) + 4 * sum4 + 2 * sum2 - func(b);
        i2 = i1;
        i1 = (h / 3) * sum;

    }
    printf("Simpson method = %f\nNumber of intervals %i\n", i1, n);
}




int main() {
    int n, method;
    float a, b, e;
for(;;){
    printf("Choice method:\n 1-Right Rectangles\n 2-left Rectangles\n 3-Trapezoidal\n 4-Simpson \n");
    scanf_s("%d", &method);
    printf("Enter data:\nLimit a: ");
    scanf_s("%f", &a);
    printf("Limit b: ");
    scanf_s("%f", &b);
    printf("Number of intervals n: ");
    scanf_s("%d", &n);

    switch (method) {
    case 1:
        rightRectangles(a, b, n, e);
break;
    case 2:
        leftRectangels(a, b, n, e);
break;
    case 3:
        Trapezoidal(a, b, n, e);
break;
    case 4:Simpson(a, b, n, e);
break;
    }
}
}