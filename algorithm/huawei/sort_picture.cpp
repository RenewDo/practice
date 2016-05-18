#include<stdio.h>  
int main()  
{  
    char str[1024];  
    int i = 0;  
    char ch;  
    while((ch = getchar()) != EOF)  
    {  
        str[i] = ch;  
        ++i;  
    }  
    int n = i, flag = 0;  
    for(i=0; i<n; i++)  
    {  
        flag = 0;  
        for(int j=n-1; j>i;j--)  
        {  
            if(str[j] < str[j-1])  
            {  
                ch = str[j];  
                str[j] = str[j-1];  
                str[j-1] = ch;  
                flag =  1;  
            }          
        }  
        if(flag == 0)  
                break;   
    }   
    for(i=0; i<n; i++)  
    printf("%c", str[i]);  
    return 0;  
}  
