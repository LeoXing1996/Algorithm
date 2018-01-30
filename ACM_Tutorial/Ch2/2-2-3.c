#include<stdio.h>
#include<string.h>

int N=6;
char ch[] = "ACDBCB";
void solution();

int main(){
    solution();
    return 0;
}

void solution(){
    int s = 0;
    int e = strlen(ch)-1;
    //int left = 0;
    while(s<e){
        if(ch[s]==ch[e]){
            int i=s;
            int j=e;
            while(ch[i]==ch[j]){++i; --j;}
            if(ch[i]>ch[j]){
                putchar(ch[e--]);
            }else{
                putchar(ch[s++]);
            }
        } else if(ch[s]>ch[e]){
            putchar(ch[e--]);
        } else{
            putchar(ch[s++]);
        }
    }
    putchar(ch[s]);
}
