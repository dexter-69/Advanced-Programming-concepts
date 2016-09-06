#include <stdio.h>
#include <string.h>


int is_anagram(char *s1, char *s2)
{
    int A1[256]={0}, A2[256]={0};
    
    int i, j;
    for(i=0; s1[i]!='\0'; i++)
        A1[s1[i]]++;

    for(i=0; s2[i]!='\0'; i++)
        A2[s2[i]]++;
    
    for(i=0; i<256; i++)
    {
        if(A1[i]!=A2[i])
            return 0;
    }
    
    return 1;
}


int main()
{
    int N;
    scanf("%d", &N);
    char s[N][100];
    int i, j;
   
    for(i=0; i<N; i++)
        scanf("%s", s[i]);

    for(i=0; i<N; i++)
        printf("%s ", s[i]);

    printf("\n\nANAGRAMS:\n");

    for(i=0; i<N; i++)
    {
        puts(s[i]);
        for(j=i+1; j<N; j++)
        {
            if(s[j][0]!=0 && is_anagram(s[i], s[j]))
            {
                puts(s[j]);
                s[j][0]=0;
            }
        }
        
//        printf("\n");
    }
    
    return 0;
}
