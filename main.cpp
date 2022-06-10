// amir abu shanab
//208586214
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int N = 20;
int numofcan = 0;
typedef struct recommender {

    char FName[20];
    char Lname[20];
    char Email[20];

} Recommender;


typedef struct developer {
    char FName[20];
    char Lname[20];
    char Degg[20];
    struct developer *Dp1;
    struct developer *Dp2;
    struct recommender *Rp1;
    struct recommender *Rp2;
} Developer;

void fun1(Developer *cani[]);// print candidates function

void fun2(Developer *emplo[]);//print workers function

void fun3(Developer *cani[], Developer *emplo[]);// add candidates function

void fun4(Developer *cani[], Developer *emplo[]);//hire candidate function



int main() {
    int x;

    Developer *employees[20], *candidates[20];// we start by making sure we dont have any junk files in the memory
    for (int i = 0; i < 20; i++) {
        employees[i] = NULL;
        candidates[i] = NULL;
    }

    while (1) {// infinite while loop
        printf("Welcome, what do you want to do?\n"
               "1. Print candidates.\n"
               "2. Print workers.\n"
               "3. Insert new Candidate.\n"
               "4. Hire candidate.\n"
               "5. Exit.\n");
        scanf("%d", &x);
        if (x == 1)
            fun1(candidates);// if the user presses 1 it calls the first function
        else if (x == 2)
            fun2(employees);// if the user presses 2 it calls the second  function
        else if (x == 3)
            fun3(candidates, employees);// if the user presses 3 it calls the third function
        else if (x == 4)
            fun4(candidates, employees);// if the user presses 5 it calls the forth function
        else if (x == 5)
            break;// if the user presses 5 it stops the program

        else {
            printf("No such task restart the program\n");// anything other it says that no such task
            return 0;
        }
    }
    for (int i = 0; i < 20; i++) {// to free up the arrays after were done using them.
        free(candidates[i]->Rp2);
        free(candidates[i]->Rp1);
        free(candidates[i]);
        free(employees[i]);
    }
    return 0;
}

void fun1(struct developer *cani[]) {//1. Print candidates
    int count = 0;
    for (int i = 0; i < 20; ++i) {
        if (cani[i] != NULL) {// looks in candidates array and checks if there is candidates there.
            count++;// to keep track of how many candidates we have.
            printf("Candidate number : %d \n", count);
            printf("    Name : %s \n", cani[i]->FName);
            printf("    Family : %s \n", cani[i]->Lname);
            printf("    Degree : %s \n", cani[i]->Degg);

            if (cani[i]->Dp1 != NULL) {// if the candidate has recommenders from the company it prints them
                printf("Recommended by :-\n    name : %s \n", cani[i]->Dp1->FName);
                printf("    Last name : %s \n", cani[i]->Dp1->Lname);
                printf("    From the Company\n");
            }
            if (cani[i]->Dp2 != NULL) {// if the candidate has recommenders from the company it prints them
                printf("Also recommended by :-\n    Name : %s\n", cani[i]->Dp2->FName);
                printf("    Last name : %s\n", cani[i]->Dp2->Lname);
                printf("    Recommender is from the Company\n");
            }
            if (cani[i]->Rp1 != NULL) {// if the candidate has recommenders from outside the company it prints them
                printf("Recommended by :-\n    Name : %s\n", cani[i]->Rp1->FName);
                printf("    Last name : %s\n", cani[i]->Rp1->Lname);
                printf("    Email address : %s\n", cani[i]->Rp1->Email);
                printf("    Recommender is not from the company\n");
            }
            if (cani[i]->Rp2 != NULL) {// if the candidate has recommenders from outside the company it prints them
                printf("Also recommended by :- \n    Name : %s\n", cani[i]->Rp2->FName);
                printf("    Last name : %s\n", cani[i]->Rp2->Lname);
                printf("    Email address : %s\n", cani[i]->Rp2->Email);
                printf("    Recommender is not from the company\n");

            }
            printf("--------------------------------------------------\n");
        }
        if (numofcan == 0) {// if the candidates array is empty it tells us that there are no candidates available
            printf("No candidates currently available.\n");
            printf("--------------------------------------------------\n");
            break;
        }
    }
}

void fun2(Developer *emplo[]) {// a function to print all the workers in the employees array
    int count = 0;
    for (int i = 0; i < 20; ++i) {
        if (emplo[i] != NULL) {
            count++;// to keep track of how many workers we have
            printf("Worker number : %d \n", count);
            printf("     First name : %s\n", emplo[i]->FName);
            printf("     Last name : %s\n", emplo[i]->Lname);
            printf("----------------------------------------\n");
        }
    }
    if(count == 0){
        printf("No workers currently available.\n");
        printf("--------------------------------------\n");
    }
}

void fun3(Developer *cani[], Developer *emplo[]) {
    int x = -1;
    int y = 2;
    char answerF[20];
    char answerS[20];
    char answerE[20];
    for (int i = 0; i < 20; i++) {
        if (cani[i] == NULL) {//checks in the candidates array if there are any available it will go to the next step
            cani[i] = (Developer *) malloc(1 * sizeof(Developer));// making a size for the array using malloc
            printf("Enter First name :-\n");// taking info about the candidate from the user
            scanf("%s", cani[i]->FName);
            printf("Enter Last name\n");
            scanf("%s", cani[i]->Lname);
            printf("Enter Degree\n");
            scanf("%s", cani[i]->Degg);
            numofcan++;
            printf("Does this candidate have recommenders from outside the company ?(press 1)\nif not (press 2)\n");
            scanf("%d", &x);
            //Filling a recommender from outside the company
            if(x == 1){// ouside recommender
                strcpy(answerF, "");
                strcpy(answerS, "");
                strcpy(answerE, "");
                printf("Enter the first recommender's full name and email\n");// taking info about the recommenders from the user
                cani[i]->Rp1=(Recommender *) malloc(sizeof(Recommender)*1);
                scanf("%s",answerF);
                scanf("%s",answerS);
                scanf("%s",answerE);
                strcpy(cani[i]->Rp1->FName,answerF);
                strcpy(cani[i]->Rp1->Lname,answerS);
                strcpy(cani[i]->Rp1->Email,answerE);
                printf("Is there another recommender from outside the company?(press 1)\nif not (press 2)\n");
                scanf("%d",&x);
                if(x==1){// another outside recommender
                    cani[i]->Rp2=(Recommender *) malloc(sizeof(Recommender)*1);
                    printf("Enter second recommender's full name and email\n");// taking info about the recommender from the user
                    scanf("%s",answerF);
                    scanf("%s",answerS);
                    scanf("%s",answerE);
                    strcpy(cani[i]->Rp2->FName,answerF);
                    strcpy(cani[i]->Rp2->Lname,answerS);
                    strcpy(cani[i]->Rp2->Email,answerE);
                }

                x=y;

            }
            //skip
            if(x==2){//inside recommender

                printf("Does this candidate have recommenders from inside the company?(press 1)\nIf not (press 2)\n");// taking info from the user about the recommender
                scanf("%d", &x);
                if(x == 1){
                    strcpy(answerF, "");
                    strcpy(answerS, "");
                    strcpy(answerE, "");
                    printf("Enter the recommenders full name.\n");
                    scanf("%s",answerF);
                    scanf("%s",answerS);
                    int error=-1;
                    for(int j=0;j<N;j++){
                        if(emplo[j]!=NULL && ((strcmp(emplo[j]->FName,answerF)==0)&&(strcmp(emplo[j]->Lname,answerS)==0))){
                            cani[i]->Dp1=emplo[j];
                            error=1;
                            break;
                        }
                    }
                    if(error==-1){// if the recommender is not from the company
                        printf("This employee does exist\n");
                    }
                    printf(("Does this candidate have another recommender from inside the company?(press 1)\nIf not (press 2)\n"));
                    scanf("%d",&x);
                    if(x==1){
                        strcpy(answerF, "");
                        strcpy(answerS, "");
                        strcpy(answerE, "");
                        printf("Enter the recommenders full name.\n");
                        scanf("%s",answerF);
                        scanf("%s",answerS);
                        error=-1;
                        for(int j=0;j<N;j++){
                            if(emplo[j]!=NULL && ((strcmp(emplo[j]->FName,answerF)==0)&&(strcmp(emplo[j]->Lname,answerS)==0))){
                                cani[i]->Dp2=emplo[j];
                                error=1;
                                break;
                            }
                        }
                        if(error==-1){// if the recommender is not from the company
                            printf("This employee does not exist!\n");
                        }
                    }
                }
            }
            break;
        }
    }
}



void fun4(Developer *cani[], Developer *emplo[]) {// a function to hire a candidate.
    char answerF[20];
    char answerS[20];
    char First[20];
    char Second[20];
    char degree[20];
    int y = 0;
    printf("Enter the name of the candidate that you want to recruit: \n");
    scanf("%s", answerF);
    scanf("%s", answerS);
    for (int k = 0; k < 20; k++) {// checking if the information that the user put in are in the candidates array.
        if (cani[k]!=NULL && (strcmp(cani[k]->FName, answerF) == 0) && (strcmp(cani[k]->Lname, answerS) == 0)) {
            y = 1;
            strcpy(First, cani[k]->FName);
            strcpy(Second, cani[k]->Lname);
            strcpy(degree, cani[k]->Degg);
            free(cani[k]->Rp1);
            free(cani[k]->Rp2);
            cani[k]->Dp1 = NULL;
            cani[k]->Dp2 = NULL;
            free(cani[k]);
            cani[k] = NULL;
            break;
        }
    }
    if(y==0){// if the candidate is not in the candidates array
        printf("the candidate does not exist\n");
    }
    else {// if it is it will add the candidate to the employees array.
        for (int i = 0; i < 20; i++) {
            if (emplo[i] == NULL) {
                emplo[i] = (Developer *) malloc(1 * sizeof(Developer));
                strcpy(emplo[i]->FName, First);
                strcpy(emplo[i]->Lname, Second);
                strcpy(emplo[i]->Degg, degree);
                printf("The candidate %s %s has started working in the company :)\n", First, Second);
                printf("-----------------------------------------------------------------\n");
                break;
            }
        }
    }
}

