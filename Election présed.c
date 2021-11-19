//Election présedentielle 2020 sass

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void displayArr(char arr[][25], int size, int votes[], int pd){
    if(pd == 0) printf("\nList of candidates :\nID \t|\tCandidate");
    else if (pd == 1) printf("\nList of electors :\nID \t|\tCIN");
    for(int i = 0; i < size; i++){
        printf("\n%d \t|\t%s", i,arr[i]);
    }
}
int searchIndexCIN(char str[10], char arrElectors[][25], int size){
    for(int i = 0; i < size; i++){
        //rintf("char : %s | arr[%d] : %s\n", str, i, arrElectors[i]);
        if(!strcmp(str, arrElectors[i])) {
            //printf("\nComparaison result : %d", strcmp(str, arrElectors[i]));
            return i;}
    }
    return -1;
}
void populateVotes(int arrVotes[], char arrElectors[][25], char arrCandidates[][25], int sizeE, int sizeP){
    getch();
    system("cls");
    //displayArr(arrElectors, sizeE, NULL, 1);
    bool oneTimeVote[sizeE];
    int index, i =0;
    for(i ; i < sizeE; i++){oneTimeVote[i] = false;}
    i = 0;
    char str[10];
    for(i; i < sizeE ; i++){
       printf("\nEnter your CIN : ");
       scanf(" %s", str);
       index = searchIndexCIN(str, &arrElectors[0], sizeE);
       if(index == -1) {
            printf("\nCIN not found. Try again");
            i--; //in case someone enters an invalid CIN the loop repeats the process of input so we need to decrement the i
            continue;
            }
        if(oneTimeVote[index]) {
            printf("\nYou already voted. You can't vote again in first tour.");
            i--;
            continue;
        }
        displayArr(arrCandidates, sizeP, NULL, 0);
        printf("\nVote for the candidate by ID : ");
        scanf(" %d", &arrVotes[index]);
        oneTimeVote[index] = true;
        //getch();
        system("cls");
    }
}
void populateDatabase(char arr[][25], int size, int pd){
    int i=0;
    if(pd == 0){printf("\nProvide the name of candidates  : ");}
    else if (pd == 1){printf("\nProvide electors CIN  : ");}
    do {
        scanf(" %s", &arr[i]);
        i++;
    }
    while(i < size);
    displayArr(arr, size, NULL, pd);
}
void main(){
    int sizeCand;
    int sizeElec;

    do{
        printf("This is the election of 2020 for president status.\nEnter the number of candidates : (minimum 5) ");
        scanf("%d", &sizeCand);
        if(sizeCand < 2) printf("\nThe election can't be held for less than 5 president candidates.");
    } while(sizeCand < 2);

    do {
        printf("\nEnter the number of electors: "); //make it dynamic after having a working version
        scanf("%d", &sizeElec);
        if(sizeElec < 4) printf("\nThe election can't be held having only 10 electors.");
    }while (sizeElec < 4);
    //declare candidates array and electros array
    char arrCandidates[sizeCand][25];
    char arrElectors[sizeElec][25];
    int votesArr[sizeElec];
    //char** elecArr[3];

    populateDatabase(arrCandidates, sizeCand, 0);

    populateDatabase(arrElectors, sizeElec, 1);

    populateVotes(votesArr, arrElectors, arrCandidates, sizeElec, sizeCand);

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
