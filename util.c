#include <stdio.h>
#include<string.h>
#include<stdbool.h>
#include "struct.h"

#define MAXCHAR 1000
#define CSVPATH "../data.csv"

int input(struct employee *emp1)
{
    FILE* fp = fopen(CSVPATH, "a+");
    if (!fp) {
        printf("Can't open file\n");
        return 1;
    }
    printf("\nEnter Id\n");
    scanf("%d", &emp1->id);
    fflush(stdin);
    printf("\nEnter Name\n");
    scanf("%s", &emp1->name);
    fflush(stdin);
    printf("\nEnter birth date\n");

    printf("Enter date (DD/MM/YYYY format): ");
//    scanf("%d/%d/%d",&emp1->Date.day,&emp1->Date.month,&emp1->Date.year);

    printf("Enter date \n");
    scanf("%d",&emp1->Date.day);
    fflush(stdin);
    printf("Enter month \n");
    scanf("%d",&emp1->Date.month);
    fflush(stdin);
    printf("Enter year \n");
    scanf("%d",&emp1->Date.year);
    fflush(stdin);
//    printf("%d", emp1->Date.year);
    //check year
    if(emp1->Date.year>=1900 && emp1->Date.year<=9999)
    {
        //check month
        if(emp1->Date.month>=1 && emp1->Date.month<=12)
        {
            //check days
            if((emp1->Date.day>=1 && emp1->Date.day<=31) && (emp1->Date.month==1 || emp1->Date.month==3 || emp1->Date.month==5 || emp1->Date.month==7 || emp1->Date.month==8 || emp1->Date.month==10 || emp1->Date.month==12))
                printf("Date is valid.\n");
            else if((emp1->Date.day>=1 && emp1->Date.day<=30) && (emp1->Date.month==4 || emp1->Date.month==6 || emp1->Date.month==9 || emp1->Date.month==11))
                printf("Date is valid.\n");
            else if((emp1->Date.day>=1 && emp1->Date.day<=28) && (emp1->Date.month==2))
                printf("Date is valid.\n");
            else if(emp1->Date.day==29 && emp1->Date.month==2 && (emp1->Date.year % 400==0 ||(emp1->Date.year %4==0 && emp1->Date.year %100!=0)))
                printf("Date is valid.\n");
            else
                printf("Day is invalid.\n");
        }
        else
        {
            printf("Month is not valid.\n");
        }
    }
    else
    {
        printf("Year is not valid.\n");
    }

    printf("\nEnter Position\n");
    scanf("%d", &emp1->position);
    fflush(stdin);
    printf("\nEnter Salary\n");
    scanf("%d", &emp1->salary);
    fflush(stdin);
    // id, name, date, month, year, position, salary
    // int, char, int, int, int   , int, int
    fprintf(fp, "%d,%s,%d,%d,%d,%d,%d\n", emp1->id,
            emp1->name, emp1->Date.day, emp1->Date.month, emp1->Date.year, emp1->position, emp1->salary);
    fflush(stdin);

    printf("\nNew employee added to record");

    fclose(fp);
    return 0;
}

int show_data(){
    FILE *fp;
    char row[MAXCHAR];
    char *token;
    char *array[7];
    fp = fopen(CSVPATH,"r");
    while (feof(fp) != true)
    {
        fgets(row, MAXCHAR, fp);
        token = strtok(row, ",");
        int i = 0;
        while(token != NULL) {
            array[i++] = token;
            token = strtok(NULL, ",");
        }
        printf("id %s\n", array[0]);
        printf("name %s\n",array[1]);
        printf("birth date %s/%s/%s\n", array[2],array[3], array[4]);
        printf("position %s\n", array[5]);
        printf("salary %s\n",array[6]);
        printf("========\n");
    }
    fclose(fp);
    return 0;
}

bool searchID(char* array[], int id){
    printf("\n asdsd %s \n", array);
    printf("\n %d", (100 == id));
//    if ( (int) *array[0]-48 == (int) id) {
    if ( 200 == id) {
        printf("\n====== FOUND ====== \n");
        printf("id %c\n", *(array)[0]);
        printf("name %s\n", array[1]);
        printf("birth date %s/%s/%s\n", array[2],array[3], array[4]);
        printf("position %s\n", array[5]);
        printf("salary %s\n", array[6]);
        printf("======      ====== \n");
        return true;
    } else {
        return false;
    }

}

bool searchPosition(char *array[], int id){
    printf("\n %d \n",(int) *array[0]-48 );
    if ( (int) *array[5]-48 == (int) id) {
        printf("\n====== FOUND ====== \n");
        printf("id %c\n", *array[0]);
        printf("name %s\n", array[1]);
        printf("birth date %s/%s/%s\n", array[2],array[3], array[4]);
        printf("position %s\n", array[5]);
        printf("salary %s\n", array[6]);
        printf("======      ====== \n");
        return true;
    } else {
        return false;
    }
}

int findById(int id, int search_by){
    FILE *fp;
    char row[MAXCHAR];
    char *token;
    char *array[7];
    fp = fopen(CSVPATH,"r");
    while (feof(fp) != true)
    {
        fgets(row, MAXCHAR, fp);
        token = strtok(row, ",");
        int i = 0;
        while(token != NULL) {
            array[i++] = token;
            token = strtok(NULL, ",");
        }

//        printf("id %s\n", array[0]);
//        printf("name %s\n", array[1]);
//        printf("birth date %s/%s/%s\n", array[2],array[3], array[4]);
//        printf("position %s\n", array[5]);
//        printf("salary %s\n", array[6]);
//        printf("%s \n", array[0]);
        //https://interviewsansar.com/char-to-int-c-program/
        int is_ok = false;
        switch (search_by)
            {
            case 1:
                is_ok = searchID(array, id);
                if (is_ok){
                    fclose(fp);
                    return 0;
                }
                break;
            case 2:
                is_ok = searchPosition(array, id);
                    if (is_ok) {
                        fclose(fp);
                        return 0;
                    }
                break;
            default:
                break;
        }
    }
    printf("not found");
    fclose(fp);
    return 0;
}





int findByPosition(int position){
    FILE *fp;
    char row[MAXCHAR];
    char *token;
    char *array[7];
    int i = 0;

    fp = fopen(CSVPATH,"r");

    while (feof(fp) != true)
    {
        fgets(row, MAXCHAR, fp);
        token = strtok(row, ",");
        while(token != NULL) {
            array[i++] = token;
            token = strtok(NULL, ",");
        }
//        for (i = 0; i < 7; ++i)
//            printf("%s\n", array[i]);
        if (array[5] == position){
            printf("id %s\n", array[0]);
            printf("name %s\n", array[1]);
            printf("birth date %s/%s/%s\n", array[2],array[3], array[4]);
            printf("position %s\n", array[5]);
            printf("salary %s\n", array[6]);
            return 0;
        }
    }
    fclose(fp);
    return 1;
}

int findByYear(int year){
    FILE *fp;
    char row[MAXCHAR];
    char *token;
    char *array[7];
    int i = 0;

    fp = fopen(CSVPATH,"r");

    while (feof(fp) != true)
    {
        fgets(row, MAXCHAR, fp);
        token = strtok(row, ",");
        while(token != NULL) {
            array[i++] = token;
            token = strtok(NULL, ",");
        }
//        for (i = 0; i < 7; ++i)
//            printf("%s\n", array[i]);
        if (array[4] == year){
            printf("id %s\n", array[0]);
            printf("name %s\n", array[1]);
            printf("birth date %s/%s/%s\n", array[2],array[3], array[4]);
            printf("position %s\n", array[5]);
            printf("salary %s\n", array[6]);
            return 0;
        }
    }
    fclose(fp);
    return 1;
}

int findBySalary(int salary){
    FILE *fp;
    char row[MAXCHAR];
    char *token;
    char *array[7];
    int i = 0;

    fp = fopen(CSVPATH,"r");

    while (feof(fp) != true)
    {
        fgets(row, MAXCHAR, fp);
        token = strtok(row, ",");
        while(token != NULL) {
            array[i++] = token;
            token = strtok(NULL, ",");
        }
        if (array[6] == salary){
            printf("id %s\n", array[0]);
            printf("name %s\n", array[1]);
            printf("birth date %s/%s/%s\n", array[2],array[3], array[4]);
            printf("position %s\n", array[5]);
            printf("salary %s\n", array[6]);
            return 0;
        }
    }
    fclose(fp);
    return 1;
}