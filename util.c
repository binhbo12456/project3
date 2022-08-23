//#include <stdio.h>
//#include<string.h>
//#include<stdbool.h>
//#include "struct.h"
//
//#define MAXCHAR 1000
//#define CSVPATH "../data.csv"
//
//
//
//
//
//
//bool searchPosition(char *array[], int id){
//    printf("\n %d \n",(int) *array[0]-48 );
//    if ( (int) *array[5]-48 == (int) id) {
//        printf("\n====== FOUND ====== \n");
//        printf("id %c\n", *array[0]);
//        printf("name %s\n", array[1]);
//        printf("birth date %s/%s/%s\n", array[2],array[3], array[4]);
//        printf("position %s\n", array[5]);
//        printf("salary %s\n", array[6]);
//        printf("======      ====== \n");
//        return true;
//    } else {
//        return false;
//    }
//}
//
//
//int findByPosition(int position){
//    FILE *fp;
//    char row[MAXCHAR];
//    char *token;
//    char *array[7];
//    int i = 0;
//
//    fp = fopen(CSVPATH,"r");
//
//    while (feof(fp) != true)
//    {
//        fgets(row, MAXCHAR, fp);
//        token = strtok(row, ",");
//        while(token != NULL) {
//            array[i++] = token;
//            token = strtok(NULL, ",");
//        }
////        for (i = 0; i < 7; ++i)
////            printf("%s\n", array[i]);
//        if (array[5] == position){
//            printf("id %s\n", array[0]);
//            printf("name %s\n", array[1]);
//            printf("birth date %s/%s/%s\n", array[2],array[3], array[4]);
//            printf("position %s\n", array[5]);
//            printf("salary %s\n", array[6]);
//            return 0;
//        }
//    }
//    fclose(fp);
//    return 1;
//}
//
//int findByYear(int year){
//    FILE *fp;
//    char row[MAXCHAR];
//    char *token;
//    char *array[7];
//    int i = 0;
//
//    fp = fopen(CSVPATH,"r");
//
//    while (feof(fp) != true)
//    {
//        fgets(row, MAXCHAR, fp);
//        token = strtok(row, ",");
//        while(token != NULL) {
//            array[i++] = token;
//            token = strtok(NULL, ",");
//        }
////        for (i = 0; i < 7; ++i)
////            printf("%s\n", array[i]);
//        if (array[4] == year){
//            printf("id %s\n", array[0]);
//            printf("name %s\n", array[1]);
//            printf("birth date %s/%s/%s\n", array[2],array[3], array[4]);
//            printf("position %s\n", array[5]);
//            printf("salary %s\n", array[6]);
//            return 0;
//        }
//    }
//    fclose(fp);
//    return 1;
//}
//
//int findBySalary(int salary){
//    FILE *fp;
//    char row[MAXCHAR];
//    char *token;
//    char *array[7];
//    int i = 0;
//
//    fp = fopen(CSVPATH,"r");
//
//    while (feof(fp) != true)
//    {
//        fgets(row, MAXCHAR, fp);
//        token = strtok(row, ",");
//        while(token != NULL) {
//            array[i++] = token;
//            token = strtok(NULL, ",");
//        }
//        if (array[6] == salary){
//            printf("id %s\n", array[0]);
//            printf("name %s\n", array[1]);
//            printf("birth date %s/%s/%s\n", array[2],array[3], array[4]);
//            printf("position %s\n", array[5]);
//            printf("salary %s\n", array[6]);
//            return 0;
//        }
//    }
//    fclose(fp);
//    return 1;
//}