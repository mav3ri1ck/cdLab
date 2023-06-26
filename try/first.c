#include<stdio.h>
#include<ctype.h>


int main()
{
    int i,n,j,k;
    char str[10][10],f;

    printf("enter the number of productions\n");
    scanf("%d",&n);

    printf("enter grammar\n");


    for(i=0;i<n;i++)
        scanf("%s",&str[i]);
    
    for(i=0;i<n;i++)
    {
        f = str[i][0];

        int temp=i;

        if(isupper(str[i][3]))
        {
            repeat:
            for(k=0;k<n;k++)
            {
                if(str[k][0]==str[i][3])
                {
                    if(isupper(str[k][3]))
                    {
                        i = k;
                        goto repeat;
                    }
                    else
                    {
                        printf("First(%c)=%c\n",f,str[k][3]);
                    }
                }
            }
        }
        else
        {
            printf("First(%c)=%c\n",f,str[i][3]);
        }
        i=temp;
    }
}