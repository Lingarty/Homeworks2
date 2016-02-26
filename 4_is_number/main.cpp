#include <stdio.h>

bool is_number (char s[], const int size) {

    bool answer = true;

    for (int i = 0; (i < size) && (answer); i++) {
        answer = (((int)s[i] <= (int)'9') && ((int)s[i] >= (int)'0'));
    }

    return answer;
}

int char_to_int(char s[], const int size) {

    int answer = 0;

    for (int i = 0; i < size; i++) {
        answer = (answer + ((int)s[i] - (int)'0'))*10;
    }

    return answer / 10;
}

int main() {

    const int size = 2;
    char s[size];

    printf("Введите число");
    scanf("%s", s);

    bool answer = is_number (s, size);

    if (answer) {
        int num = char_to_int(s, size);
        printf ("На вход подавалось число %d", num);
    }
    else {
        printf("-1");
    }

    return 0;
}