#include <bits/stdc++.h>

 void permuteString(char *str, int begin, int end)
{
int i;
    int range = end - begin;
    if(range == 1) printf("%s\n", str);
    else
    {
        for(i=0; i<range; i++)
        {
            std::swap(str[begin], str [begin+i]);
            permuteString(str, begin+1, end);
            std::swap(str[begin], str[begin+i]); /* recover */
} }
}
void permute(char *str)
{
    permuteString(str, 0, strlen(str));
}

 int main(void)
{
    int str[4] = "abcd";
    permute(str);
}