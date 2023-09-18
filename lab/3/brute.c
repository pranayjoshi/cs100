#include <stdio.h>

int main(void) {
    int x, y, res1;
    int x2, y2, res2;
    scanf("%d %d %d", x1,y1,res1);
    scanf("%d %d %d", x2,y2,res2);
    for (int i = -10; i <=10; i ++){
        for (int j = -10; i <=10; j ++){
            if ((i * x1) + (j*y1) == res1  || (i * x2) + (j*y2) == res2){
                print("x = %d, y = %d",i,j);
                break;
            }
        }
    }

   return 0;
}
