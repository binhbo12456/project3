#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<stdbool.h>

bool searchID(char* array[], int id){
    if (id == atoi(array[0])){
        printf("\n====== FOUND ====== \n");
        printf("id %d\n", id);
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

int findById(FILE *fp){
    fseek(fp, 0, SEEK_SET);

    int id;
    printf("Nhap ID Nhan vien Can Tim  \n");
    scanf("%d", &id);

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
        if (searchID(array, id)){
            return 0;
        }
    }
    printf("not found");
    return 0;
}