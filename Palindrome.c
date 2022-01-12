#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int ispalindrome(char str[])
{
	int i,j,n;
	n=strlen(str);
	
	//for(i=0,j=n-1;str[i]!=0,j>=0;i++,j--)
	for(i=0,j=n-1;i<=(n/2),j>=(n/2);i++,j--)
	{
		if(str[i]!=str[j])
			return 1;
	}
	return 0;
}

int main()
{
    char str[25];
    int ans;
    printf("\nEnter the String: ");
    gets(str);

    ans=ispalindrome(str);
    if(ans==0)
        printf("\n%s is Palindrome!!!",str);
    else
        printf("\n%s is Not Palindrome!!!",str);
}
