#include <unistd.h>
#include <string.h>
#include <stdio.h>

void add_char(char str[], char new_char) {
    int i;

    i = strlen(str);

    str[i] = new_char;
    str[i + 1] = '\0';
}

void copy_string(char from[], char to[]) {
    int i = 0;
    while (from[i] != '\0')
    {
        to[i] = from[i];
        i++;
    }
    to[i] = '\0';
}

// int islast(char pre[], char total[]) {
//     if (strlen(pre) == strlen(total) - 1) {
//         int i = 0;
//         int count = 0;
//         while(pre[i] != '\0'){
//             if (pre[i] == total[i]) {
//                 count++;
//             }
//             i++;
//         }
//         if (i == count) {
//             return 1;
//         }
//     }
//     return 0;
// }

void inter(int n, char c, char head[], char total[]) {
    if (n == 1) {
        while(c <= '9'){
            write(1, head, strlen(head));
            write(1, &c, 1);
            // if (islast(head, total) && c == '9') {
            //     /* code */
            // } else {

            write(1, ", ", 2);
            // }
            
            c++;
        }
    }
    else {
        while(c <= '9'){
            char dummy[20] = "";
            char tem;

            copy_string(head, dummy);

            tem = c + 1;
            add_char(dummy, c);

            inter(n-1, tem, dummy, total);
            c++;
        }
    }
    
}

void ft_print_combn(int n)
{
    char head[20] = "";

    char maxn[20];
    char tem = '9';

    while(n >= 0){
        maxn[n - 1] = tem;
        tem--;
        n--;
    }
    

    inter(n, '0', head, maxn);
}

int main() {
    ft_print_combn(3);

    return 0;
}