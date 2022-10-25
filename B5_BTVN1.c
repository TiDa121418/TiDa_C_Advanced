#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Cho 1 cái thùng nó chứa ngẫu nhiên số tất màu đỏ, màu xanh, màu vàng. 
// Đếm xem có bao nhiêu đôi mỗi loại và tổng số đôi của cả 3 loại.

typedef enum
{   
    TAT_DO,         // VD: 6 đỏ => 3 đôi đỏ
    TAT_VANG,       //     7 vàng => 3 đôi vàng             => Tổng 10 đôi cả 3 loại
    TAT_XANH        //     9 xanh => 4 đôi xanh
}TAT;

typedef struct 
{
    TAT *ptr;
    int size;
}Box;

void NhapThongTin (Box *value)
{
    
    printf("Nhap chieu dai cua mang: ");
    scanf("%d", &(value->size));
    value->ptr = (TAT*) malloc (value->size * sizeof(TAT)); // Cấp phát động
    int i = 0;
    do{
        char a[10];
        printf("\nNhap loai vo thu %d: ",i);
        scanf("%s",a);
        if( strcmp(a,"TAT_DO") == 0)
        {
            value->ptr[i] = TAT_DO;
            i++;
        }
        else if(strcmp(a,"TAT_VANG") == 0)
        {
            value->ptr[i] = TAT_VANG;
            i++;
        }
        else if(strcmp(a,"TAT_XANH") == 0)
        {
            value->ptr[i] = TAT_XANH;
            i++;
        }
        else
        {
            printf("\nBan nhap khong hop le");
        }
        
    }while(i < value->size);
}

void LietKe(Box *A){
    int sl1=0,sl2=0,sl3=0;
    for(int i = 0; i< A->size;i++){
        if(A->ptr[i] == 0){
            sl1++;
        }else if(A->ptr[i] == 1){
            sl2++;
        }else if(A->ptr[i] == 2){
            sl3++;
        }
    }
    printf("\nCo %d cap tat cung mau do",sl1/2);
    printf("\nCo %d cap tat cung mau vang",sl2/2);
    printf("\nCo %d cap tat cung mau xanh",sl3/2);
}

int main()
{
    Box test;
    NhapThongTin(&test);
    LietKe(&test);
}