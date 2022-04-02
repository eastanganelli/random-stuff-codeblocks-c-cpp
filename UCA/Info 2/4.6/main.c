#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numbers[] = {8, 2, 5, 1, 0},i, count = 0;
    sortingIntegers(numbers, 0, 5);
    for (i=0;i<5;i++)
        printf("%d -", numbers[i]);
        count << numbers[i] << ' ';
    return 0;
}

void sortingIntegers(int *list, int left, int size) {
    if (left == size) return;
    else{
        int smallest = smallestIndex(list, left, size);
        int c = list[smallest];
        list[smallest] = list[left];
        list[left] = c;
        sortingIntegers(list, left+1 ,size);
    }
}

int smallestIndex(int *array, int left, int size) {
    int smallest = array[left];
    int smIndex = left;
    int i;
    for (i = left+1; i < size; i++) {
        if (array[i] < smallest) {
            smallest = array[i];
            smIndex = i;
        }
    }
    return smIndex;
}
