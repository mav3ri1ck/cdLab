#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PRODUCTIONS 10
#define MAX_FOLLOW_SET 10

int n, m = 0, p, i = 0, j = 0;
char a[MAX_PRODUCTIONS][10], followResult[MAX_FOLLOW_SET];

void follow(char c);
void first(char c);
void addToFollowResult(char c);

int main()
{
    int choice;
    char c, ch;

    printf("Enter the number of productions: ");
    scanf("%d", &n);

    printf("Enter %d productions\nProductions with multiple terms should be given as separate productions\n", n);
    for (i = 0; i < n; i++)
        scanf("%s%c", a[i], &ch);

    do
    {
        m = 0;
        printf("Find FOLLOW of --> ");
        scanf(" %c", &c);
        follow(c);
        printf("FOLLOW(%c) = { ", c);
        for (i = 0; i < m; i++)
            printf("%c ", followResult[i]);
        printf("}\n");

        printf("Do you want to continue (Press 1 to continue)? ");
        scanf("%d%c", &choice, &ch);

    } while (choice == 1);

    return 0;
}

void follow(char c)
{
    if (a[0][0] == c) {
        addToFollowResult('$');
    }

    for (i = 0; i < n; i++)
    {
        for (j = 2; j < strlen(a[i]); j++)
        {
            if (a[i][j] == c)
            {
                if (a[i][j + 1] != '\0')
                    first(a[i][j + 1]);

                if (a[i][j + 1] == '\0' && c != a[i][0])
                    follow(a[i][0]);
            }
        }
    }
}

void first(char c)
{
    int k;

    if (!(isupper(c)))
    {
        addToFollowResult(c);
    }
    for (k = 0; k < n; k++)
    {
        if (a[k][0] == c)
        {
            if (islower(a[k][3]))
                addToFollowResult(a[k][3]);
            else
                first(a[k][3]);
        }
    }
}

void addToFollowResult(char c)
{
    int i;
    for (i = 0; i <= m; i++)
    {
        if (followResult[i] == c)
            return;
    }

    followResult[m++] = c;
}
