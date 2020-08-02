#include <stdio.h>
    
void showbits( unsigned int x )
{
    
    
    /* for (int i = (sizeof(int) * 8) - 1; i >= 0; i--)
    {
        z=i;
       putchar(x & (1u << i) ? '1' : '0');
    }
    printf("\n"); */
    // printf("i = %d \n", (1u<<z));
}

void getEndian() {
    unsigned int i = 1;  
    char *c = (char*)&i;  
    if (*c)  
        printf("Little endian");  
    else
        printf("Big endian");  
    // return 0;
}

int main( void )
{
    int j = 0xfffffffe;
    printf("%d in binary \t\t ", j);
    /* assume we have a function that prints a binary string when given 
       a decimal integer 
    */
    // showbits(j);
    int z = j ;

    // getEndian();

    /* the loop for right shift operation */
    // for (int m = 0; m <= 5; m++)
    // {
    //     int n = j >> m;
    //     printf("%d right shift %d gives ", j, m);
    //     showbits(n);
    // }
    return 0;
}