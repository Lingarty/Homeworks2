#include <stdio.h>
#include <stdlib.h>

void create_array(int array[], const int size) {

    for (int i = 0; i < size; i++) {
        array[i] = rand()%50;
    }
}

void bubble_sort(int a[], const int size) {
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < i; j++)
        {
            int v;
            if(a[i] < a[j])
            {
                v = a[i];
                a[i] = a[j];
                a[j] = v;
            }
        }
    }
}

void show_array(int a[], const int size) {
    for (int i = 0; i < size; i++) {
        printf ("%d ", a[i]);
    }
    printf("\n");
}

int main() {

    const int size = 10;
    int array[size];

    create_array(array, size);
    show_array(array, size);
    bubble_sort(array, size);
    show_array(array, size);

    return 0;
}