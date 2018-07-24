#include <stdio.h>
#include <math.h>
#include <string.h>

void findprimes(int, int);

int main()
{
    int src1, src2;
    printf("Input the starting integer (0-2,147,483,647): ");
    scanf("%d", &src1);
    printf("Input the ending integer (0-2,147,483,647): ");
    scanf("%d", &src2);
    if ((src1<0 || src1>2147483647)||(src2<0 || src2>2147483647)||(src1>src2))
    {
        printf("I appreciate your sense of humor. Bye!");
        return 0;
    }
    findprimes(src1, src2);
    return 0;
}
void findprimes(int x, int y)
{
    int testee=0, counter=0;
    char filename[30];
    FILE * outputFile;
    sprintf(filename, "prime_%d-\%d.txt", x, y);
    outputFile = fopen(filename, "w");
    fprintf(outputFile, "Prime Numbers from %d to %d:\n", x, y);
    for (testee=x; testee<=y; testee++)
    {
        int max = (int)sqrt(testee)+1;
        int i;
        int factor = 0;
        for (i=2; i<=max; i++)
        {
            if (testee % i == 0)
            {
                factor++;
            }
        }
        if (factor == 0 || testee ==2)
        {
            printf("Found prime number: %d\n", testee );
            fprintf(outputFile, "Found prime number: %d\n", testee );
            counter++;
        }
    }
    printf("#Primes Found in Range: %d\n", counter);
    fprintf(outputFile, "#Primes Found in Range: %d\n", counter);
    fclose(outputFile);
}
