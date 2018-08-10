#include <stdio.h>
#include <conio.h>

typedef struct point{
        float x;
        float y;
}Point2D;


int main()
{
    int so_nguyen = 9;
    int *con_tro_so_nguyen = (int *)malloc(sizeof(int));
    float *con_tro_so_thuc = (float *)malloc(sizeof(float));
    char *con_tro_ky_tu = (char *)malloc(sizeof(char));
    
    
    printf("Dia cho con tro so nguyen %ld \n",con_tro_so_nguyen);
    printf("Dia cho con tro so thuc %ld \n",con_tro_so_thuc);
    printf("Dia cho con tro ky tu %ld \n",con_tro_ky_tu);
    *con_tro_so_nguyen = 503;
    *con_tro_so_thuc = 3.1416;
    *con_tro_ky_tu = 'A';
    
    printf("Noi dung con tro so nguyen %d \n",*con_tro_so_nguyen);
    printf("Noi dung con tro so nguyen %5.4f \n",*con_tro_so_thuc);
    printf("Noi dung con tro so nguyen %c \n",*con_tro_ky_tu);
    
    
    
    //Point2D a;
//    Point2D *con_tro_a;
    
    
    //printf("\n Dia chi %ld ",con_tro_so_nguyen);
//    *con_tro_so_nguyen = so_nguyen + 4;
//    printf("\n gia tri tro boi dia chi %d ",*con_tro_so_nguyen);
//    printf("\n Dia chi cua bien nguyen %ld ",&so_nguyen);
//    a.x = 0.5;
//    a.y = 0.5;
//    printf("\n Toa do cua a la (%4.2f,%4.2f) ",a.x,a.y);
//    con_tro_a->x = -0.25;
//    con_tro_a->y = -0.5;
//    printf("\n Toa do cua con tro a la (%4.2f,%4.2f) ",con_tro_a->x,con_tro_a->y);
//    printf("\n Dia chi con tro point 2d %ld ",con_tro_a);
    
    //con_tro_so_nguyen = (char *)malloc(1024*sizeof(char));
    //con_tro_a = (Point2D *)malloc(1024*sizeof(Point2D));
    
    //free(con_tro_so_nguyen);
    //free(con_tro_a);
    
    
    getch();
    return 0;
}
