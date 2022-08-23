#include <stdio.h>
#include <string.h>
#include "util.c"

#define MAXCHAR 1000
#define CSVPATH "../data.csv"

#include "struct.h"
#include "input.c"
#include "showData.c"
#include "findByID.c"
#include "findByPosition.c"
#include "findByYear.c"
#include "findBySalary.c"
#include "menu.c"

int main()
{
    struct employee emp;
    FILE *fp;
    fp = fopen(CSVPATH,"a+");

    if (fp == NULL)
    {
        printf("Couldn't open file\n");
        return 1;
    }
    chose:
    menu();
    int option=0;
    do{
        printf("\n Nhap Lua Chon \n");
        scanf("%d",&option);
    }while( (option < 0 ) || (option > 7));
    switch (option) {
        case 1:
            input(&emp, fp);
            goto chose;
        case 2:
            show_data(fp);
            goto chose;
        case 3:
            findById(fp);
            goto chose;
        case 4:
            findByPosition(fp);
            goto chose;
        case 5:
            findByYear(fp);
            goto chose;
        case 6:
            findBySalary(fp);
            goto chose;
    }
    fclose(fp);
    return 0;
}
