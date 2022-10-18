#include<stdio.h>
#include <stdlib.h>
// Viết chương trình nhập vào các số ngẫu nhiên rồi lưu vào mảng arr
//Nhấn 1: Sắp xếp theo thứ tự từ bé đến lớn
//Nhấn 2: Sắp xếp theo thứ tự từ lớn đến bé
//Nhấn 3: Tìm số lớn nhất
//Nhấn 4: Thoát chương trình

struct TypeArr
{
    int *arr; // Lưu địa chỉ đầu tiên của mảng
    int size; // Lưu kích thước mảng
};

void NhapThongTin(struct TypeArr *value)
{
    
    printf("\n Nhap chieu dai cua mang:");
    scanf("%d", &(value->size));

    value->arr = (int*) malloc (value->size * sizeof(int)); // Cấp phát động
    for (int i=0; i < value->size; i++)
    {
        printf("Nhap gia tri tai arr[%d]: ",i);
        scanf("%d", &(value->arr[i]));
    }
}

void BeDenLon (struct TypeArr *value)
{
    for (int i =0; i < value->size ; i++)
    {
        for (int j = i+1; j < value->size; j++)
        {
            if (value->arr[i] > value->arr[j])
            {
                int ex = value->arr[i];
                value->arr[i] = value->arr[j];
                value->arr[j] = ex;
            }
        }
    }
}
void LonDenBe (struct TypeArr *value)
{
     for (int i =0; i < value->size - 1; i++)
    {
        for (int j = i+1; j < value->size; j++)
        {
            if (value->arr[i] < value->arr[j])
            {
                int ex = value->arr[i];
                value->arr[i] = value->arr[j];
                value->arr[j] = ex;
            }
        }
    }
}
void SoLonNhat (struct TypeArr value)
{
    int max = -9999;
    for (int i =0; i < value.size; i++ )
    {
        if (value.arr[i] > max)
        {
            max = value.arr[i];
        }
    }
    printf("Gia tri lon nhat cua mang la: %d", max);
}
int main()
{
    struct TypeArr test;
    NhapThongTin(&test);

    for (int i=0; i < test.size; i++)
    {
        printf("ptr[%d]: %d\n", i,  test.arr[i]);
    }

    
    printf("Nhan 1: Sap xep tu be den lon \n");
    printf("Nhan 2: Sap xep tu lon den be \n");
    printf("Nhan 3: In ra so lon nhat cua mang \n");
    printf("Nhan 4: Thoat chuong trinh\n");
    int luachon;
    printf("Nhap lua chon cua ban: ");
    scanf("%d", &luachon);

    switch(luachon)
    {
        case 1:
        {
            BeDenLon(&test);
            printf("Mang sap xep tu be den lon la:\n");
            for (int i=0; i < test.size; i++)
            {
                printf(" %d", *(test. arr + i));
            }
            break;
        }

        case 2:
        {
            LonDenBe(&test);
            printf("Mang sap xep tu lon den be la:\n");
             for (int i=0; i < test.size; i++)
            {
                printf(" %d", test.arr[i]);
            }
            break;
        }

        case 3:
        {
            SoLonNhat(test);
            break;
        }
        case 4:
        {
            printf("Thoat chuong trinh");
            break;
        }
        default:
            printf("Nhap lua chon khong dung ");
    }
    return 0;
}
