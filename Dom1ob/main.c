#include <stdio.h>

#define MAX_BR_EL 1000

void swap(unsigned int* a, unsigned int* b)
{
    unsigned int tmp = *a;
    *a = *b;
    *b = tmp;
}
int part(unsigned int in[], int low, int high)
{
    unsigned int pivot = in[high];
    int i = low-1;
    for(int j = low; j < high; ++j)
    {
        if(in[j] <= pivot)
        {
            i++;
            swap(&in[i], &in[j]);          
        }
    }
    i++;
    swap(&in[i], &in[high]);
    return i;
}

void sort(unsigned int in[], int low, int high)
{
    if(low < high)
    {
        int p = part(in, low, high);
        
        sort(in, low, p-1);
        sort(in, p+1, high);
    }

}


void prvi()
{
    //Input
    int len;
    unsigned int array[MAX_BR_EL];
    scanf("%d", &len);
    for(int i = 0; i < len; ++i)
    {
        int tmp;;
        scanf("%d", &tmp);
        if(tmp < 0)
        {
            printf("Bad input");
            return;
        }
        else
        {
            array[i] = (unsigned int) tmp;
        }
    }

    //Sort
    sort(array, 0, len-1);
    for(int i = 0; i < len; ++i)
    {
        printf("%u ", array[i]);
    }
    printf("\n");
    //
    for(int i = 0; i < len; ++i)
    {
        unsigned int init = array[i];
        int occ = 1;
        while(array[++i] == init) occ++;
        i--;
        if(occ == 1) printf("%d ", init);
    }
}



int main(void)
{
   prvi();
   return 0; 
}


// TODO aa
