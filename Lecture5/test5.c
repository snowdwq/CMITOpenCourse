#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int array[10] = {10, 9, 8, 7, 5 ,6 ,4, 1, 2, 3};
int array2[10] = {10, 9, 8, 7, 5 ,6 ,4, 1, 2, 3};
int array3[10] = {3, 4, 3, 2, 3, 2, 4, 55, 44, 34};
// int array[2] = {2, 1};

/* move previous elements down until
   insertion point reached */
// it is like when a new card comes in your hand and you put it in the right order (ascending or desending)
void shift_element(unsigned int i)
{
    int value;

    // printf("%d %d\n", array[0], array[1]);
    /* guard against going outside the array */
    for(value = array[i]; i && (array[i-1] > value); i--)
    {
        array[i] = array[i-1]; // move element
    }

    // printf("%d\n", value);
    array[i] = value; // insert element
}

void insertion_sort(void)
{
    unsigned int i, len = sizeof(array)/sizeof(array[0]); // good tactic to have as a macro

    for(i = 1; i < len; i++)
    {
        if(array[i-1]>array[i])
        {
            shift_element(i);
        }
    }
}

void swap(int* a, int* b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

// obviously it doesn't work
// values are passed by value, so at first some local (to the function) copies are made
// then we just change the values of the copies
// when the function finishes, these local copies are deleted from the stack
/*void swap(int a, int b)
{
    int temp = b;
    b = a;
    a = temp;
}*/

void quick_sort(unsigned int left, unsigned int right)
{
    unsigned int i;
    unsigned int mid;
    int pivot;

    if(left > right)
        return; /* nothing to sort */
    /* pivot is midpoint; move to the left side */
    swap(&array2[left], &array2[(left+right)/2]);
    pivot = array2[mid=left];
    /* seperate into side < pivot (left+1 to mid)
        and side >= pivot (mid+1 to right) */
    for(i = left+1; i <= right; i++)
    {
        if(array2[i] < pivot)
        {
            swap(&array2[++mid], &array2[i]);
        }
    }

    /* restore pivot position */
    swap(&array2[left], &array2[mid]);
    /* sort two sides */
    if(mid > left)
        quick_sort(left, mid-1);
    if(mid < right)
        quick_sort(mid+1, right);
}


int* binary_search(int val)
{
    unsigned int L = 0, R = sizeof(array)/sizeof(array[0]), M;

    while(L < R)
    {
        M = (L+R-1)/2;
        if(val == array[M])
        {
            return &array[M];
        }
        else if(val < array[M])
        {
            R = M;
        }
        else // if(val > array[M])
        {
            L = M+1;
        }
    }

    return NULL;
}

void distcount(int l, int r)
{
    int i, j, cnt[56];
    int b[56];

    for(j = 0; j < 56; j++) cnt[j] = 0;
    for(i = l; i <= r; i++) cnt[array3[i]+1]++; // elements of array3 should be less than 10 ... but after the change from the algorithm of the book now it seems ok :)
    for(j = 1; j < 56; j++) cnt[j] += cnt[j-1];
    for(i = l; i <= r; i++) b[cnt[array3[i]]++] = array3[i];
    for(i = l; i <= r; i++) array3[i] = b[i-l];
}

void external_sort(int l, int r)
{

}

int main(void)
{
    insertion_sort();
    unsigned int i;

    for(i = 0; i < 10; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n");

    quick_sort(0, 9);

    for(i = 0; i < 10; i++)
    {
        printf("%d ", array2[i]);
    }

    printf("\n%d \n %p \n %p \n %p \n", *binary_search(4), binary_search(1), binary_search(4), binary_search(10));

    distcount(0, 9);

    for(i = 0; i < 10; i++)
    {
        printf("%d ", array3[i]);
    }

    // test
    return 0;
}
