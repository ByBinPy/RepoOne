#include <iostream>
void quickSort(int *array,int left,int right)
{   int i = left;
    int j = right;
    int pivot = array[(left+right)/2];
    while (i<=j)
    {
        while(array[i]<pivot)
        {
            i++;
        }
        while(array[j]>pivot)
        {
            j--;
        }
        if (i<=j)
        {
            int buff = array[i];
            array[i] = array[j];
            array[j] = buff;
            i++;
            if (j>0)
            {
                j--;
            }
        }
    }
    if (left < j)
    {
        quickSort(array,left,j);
    }
    if (right>i)
    {
        quickSort(array,i,right);
    }
}
int main() {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    int a[n*m];
    int *weight_plot = a;
    for (int i = 0; i < m * n; i++) {
        scanf("%d", &weight_plot[i]);
    }
    int number;
    int b[number];
    int *weight_person = b;
    scanf("%d", &number);
    for (int i = 0; i < number; i++) {
        scanf("%d", &weight_person[i]);
    }
    quickSort(weight_plot, 0, m * n);
    quickSort(weight_person, 0, number);
    int counter = 0;
    int iter_plot = 1;int iter_pers = 1;int check = 0;

    while (check < m*n)
    {
        check++;
        if (weight_plot[iter_plot] >= weight_person[iter_pers])
        {
            counter += 1;
            iter_plot++;
            iter_pers++;
        } else
        {
            iter_plot++;
        }
    }
    printf("%d", counter);

    return 0;
}
/*/
    5 3
    5 11 19
    21 16 33
    26 48 9
    3 13 23
    20 37 12
    10
    35 23 19 40 8 2 11 28 13 10
    /*/
/*/
Plot--> 3 5 9 11 12 13 16 19 20 21 23 26 33 37 48
Person --> 2 8 10 11 13 19 23 28 35 40
/*/