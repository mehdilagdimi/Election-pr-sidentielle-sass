//Election présedentielle 2020 sass

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void displayArr(char arr[][1], int size, int votes ){
    printf("\nList of candidates :\n");
    for(int i = 0; i < size; i++){
                printf("%s \n", arr[i]);
        printf("\n");
    }
}
void populateDatabase(char arr[][1], int size, int pp){
    int i=0;
    if(pp == 0){printf("\nProvide the name of candidates  : ");}
    else if (pp == 1){printf("\nProvide electors CIN  : ")}
    do {
        scanf(" %s", &arr[i]);
        i++;
    }
    while(i < size);
    displayArr(arr, size, 0);
}
void main(){
    int size;
    printf("This is the election of 2020 for president status.\nEnter the number of candidates : (minimum 5) ");
    scanf("%d", &size);
    char arrCandidates[size][1];
    //char** elecArr[3];
    populateDatabase(arrCandidates, size);

    /*printf("\nAdresse of arr %d", &arr);
    elecArr[0] = &arr[0];
    printf("\nAdresse of elecArr %d", elecArr[0]);
    printf("\nAdress of first element in arr %d", &arr[0]);
    printf("\nAdress of first element in elecArr %d", elecArr[0]);
    printf("\nValue of first element in elecArr %s", elecArr[0][1]);
    printf("\n First array inside tableau %p,  and second %s", elecArr);
    */
    //printf("\Test first element of array : %s", arr[1]);

}
