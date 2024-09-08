#include <stdio.h>

int main() {
    printf("请输入9个整数，以回车键结尾：\n" );
    int z[9];
    int i;
    for (i = 0; i < 9; i++) {
        scanf("%d",&z[i]);
    }
    int j;
    int k;
    for (j=0;j<8;j++){
        for(k=0;k<8-j;k++){
            if(z[k]>z[k+1]){
                int xiao=z[k+1];
                z[k+1]=z[k];
                z[k]=xiao;
            }
        }

    }
    printf("排序后的整数从小到大依次为：");
    for (int q=0; q<9; q++){
        printf("%d\n",z[q]);
    }
    return 0;
}