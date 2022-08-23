#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<stdbool.h>

bool searchYear(char* array[], int id){
    if (id == atoi(array[4])){
        printf("\n====== FOUND ====== \n");
        printf("id %s\n", array[0]);
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

int findByYear(FILE *fp){
    int id;
    printf("Nhap Nam Sinh Nhan vien Can Tim  \n");
    scanf("%d", &id);

    fseek(fp, 0, SEEK_SET);
    char row[MAXCHAR];
    char *token;
    char *array[7];

    while (feof(fp) != true)
    {
        fgets(row, MAXCHAR, fp);
        token = strtok(row, ",");
        int i = 0;
        while(token != NULL) {
            array[i++] = token;
            token = strtok(NULL, ",");
        }
        if (searchYear(array, id)){
            return 0;
        }
    }
    printf("not found");
    return 0;
}