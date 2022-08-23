#include <stdio.h>
#include<string.h>
#include<stdbool.h>

void show_data(FILE *fp){
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
        printf("id %s\n", array[0]);
        printf("name %s\n",array[1]);
        printf("birth date %s/%s/%s\n", array[2],array[3], array[4]);
        printf("position %s\n", array[5]);
        printf("salary %s\n",array[6]);
        printf("========\n");
    }
}
