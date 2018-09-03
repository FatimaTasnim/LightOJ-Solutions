#include<bits/stdc++.h>
using namespace std;
char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}

int main()
{
    int c,k=1;
    char str[101],str1[101];
    scanf("%d",&c);
    while(c--){
        scanf("%s",str);
        strcpy(str1,str);
        strrev(str1);
        if(strcmp(str,str1)==0)printf("Case %d: Yes\n",k++);
        else printf("Case %d: No\n",k++);
    }
}
