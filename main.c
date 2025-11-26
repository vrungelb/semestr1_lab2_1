#include <stdio.h>
#include <math.h>

// Прототипы функций
void ClearInputBuffer();
double ArshinFunc(double x, int k);

// main
int main() {
    int k = 0;
    double x = 0.0;

    while (1) {
        printf("Enter k (k > 0) and x (|x| < 1): ");

        if (scanf("%d %lf", &k, &x) != 2 || k <= 0) { // scanf возвращает количество успешно считанных элементов
            printf("Invalid input!\n");
            ClearInputBuffer();
            continue;
        }

        if (fabs(x) >= 1) {
            printf("Series does not converge. |x| must be < 1.\n");
            continue;
        }

        break;
    }

    printf("asinh       : %.15f\n", log(x + sqrt(1.0 + x * x)));
    printf("Arshin series: %.15f  (N=%d)\n", ArshinFunc(x, k), k);

    return 0;
}

// Очистка входного буфера
void ClearInputBuffer() {
    int temp;
    while ((temp = getchar()) != '\n' && temp != EOF) {}
}

// Вычисление arsinh(x) по кол-ву k членов ряда
double ArshinFunc(double x, int k) {
    double s = 0.0;
    double an = x;

    for (int n = 0; n < k; ++n) {
        s += an;
        an *= -(x * x) * (2.0 * n + 1.0) * (2.0 * n + 1.0) /
              (2.0 * (n + 1.0) * (2.0 * n + 3.0));
    }

    return s;
}
