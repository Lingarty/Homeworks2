#include <stdio.h>
#include <math.h>

bool is_prime_number (int a) {

    bool is_right = true;

    for (int i = 2; (i <= sqrt(a)) && (is_right); i++) {
        if (a%i == 0 ) {
            is_right = false;
        }
    }

    return is_right;
}

int main() {
    printf("Введите число");
    int a;
    scanf("%d", &a);

    bool is_prime = is_prime_number(a);

    if (is_prime) {
        printf ("Вы ввели простое число");
    }
    else {
        printf("Вы ввели непростое число");
    }

    return 0;
}