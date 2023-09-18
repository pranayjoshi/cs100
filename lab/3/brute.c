#include <stdio.h>

int main(void) {
    int x1, y1, res1;
    int x2, y2, res2;
    scanf("%d %d %d", &x1,&y1,&res1);
    scanf("%d %d %d", &x2,&y2,&res2);
    int s = 0;
    for (int i = -10; i <=10; i ++){
        
        for (int j = -10; j <=10; j ++){
            if ((i * x1) + (j*y1) == res1  && (i * x2) + (j*y2) == res2){
                printf("x = %d, y = %d",i,j);
                s = 1;
                break;
            }
        }
        if (s == 1){
            break;
        }
    }
    if (s == 0){
        printf("There is no solution");
    }

   return 0;
}
