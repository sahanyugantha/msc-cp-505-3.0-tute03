#include <stdio.h>
#include <stdlib.h>

//int menuOption;

//int indexNoArr[];
//int mathsArr[], physicsArr[], chemistryArr[];
int indexNoArr[] = {125,226,184,165,201};
int mathsArr[] = {55,78,84,44,40};
int physicsArr[] = {68,68,87,24,57};
int chemistryArr[] = {95,55,92,32,54};

char mathsGradeArr[], physicsGradeArr[], chemistryGradeArr[];

int main()
{
    int menuOption = showMainMenu();
    if(menuOption<1 || menuOption>7 ){
        printf(" Please enter valid option no  \n");
        main();
    } else {
        switch (menuOption){
            case 5:
                reportSubMenu();
                break;
            default:
                main();
                break;
        }
        printf(" Yeah!  \n");
    }

    return 0;
}

int showMainMenu(){
    int mainMenuOption;

    printf("---------------------------- \n");
    printf(" Please select an option     \n");
    printf("---------------------------- \n");
    printf(" 1) Add Student \n");
    printf(" 2) Save records \n");
    printf(" 3) Load records \n");
    printf(" 4) Search student \n");
    printf(" 5) Print reports \n");
    printf(" 6) Print graphs \n");
    printf(" 7) Exit \n");
    printf("---------------------------- \n");
    printf(" Please enter your choice :  ");
    scanf("%d", &mainMenuOption);
    printf("---------------------------- \n");

    //printf("Number : %d", mainMenuOption);
    return mainMenuOption;
}

int reportSubMenu(){

   int reportMenuOption;

    printf("---------------------------- \n");
    printf(" Please select report type     \n");
    printf("---------------------------- \n");
    printf(" 1) Print result sheet \n");
    printf(" 2) Print subject summary \n");
    printf(" 3) Exit \n");
    printf("---------------------------- \n");
    printf(" Please enter your choice :  ");
    scanf("%d", &reportMenuOption);
    printf("---------------------------- \n");

    //validation must do later.
    switch(reportMenuOption){
        case 1:
            //printf("Here goes Result sheet \n");
            printGrades();
        break;
        case 2:
            printf("Here goes Subject summary \n");
        break;
    }


    return reportMenuOption;
}

/*void loadInputs(){
     int indexNoArr[] = {125,226,184,165,201};
     mathsArr[] = {55,78,85,44,40};
     physicsArr[] = {68,68,87,24,57};
     chemistryArr[] = {95,55,92,32,54};
}*/

void calculateGrades(int maths[]){

    for(int i=0; i < sizeof(maths); i++){
        if(maths[i] > 75){
            mathsGradeArr[i] = 'A';
        } else if(maths[i] > 64){
            mathsGradeArr[i] = 'B';
        } else if(maths[i] > 49){
            mathsGradeArr[i] = 'C';
        } else if(maths[i] > 34){
            mathsGradeArr[i] = 'S';
        } else {
            mathsGradeArr[i] = 'F';
        }
    }
}
/*
void calculatePhysicsGrades(){

    for(int i=0; i < sizeof(physicsArr); i++){
        if(physicsArr[i] > 75){
            physicsGradeArr[i] = 'A';
        } else if(physicsArr[i] > 64){
            physicsGradeArr[i] = 'B';
        } else if(physicsArr[i] > 49){
            physicsGradeArr[i] = 'C';
        } else if(physicsArr[i] > 34){
            physicsGradeArr[i] = 'S';
        } else {
            physicsGradeArr[i] = 'F';
        }
    }
}

void calculateChemistryGrades(){

    for(int i=0; i < sizeof(chemistryArr); i++){
        if(chemistryArr[i] > 75){
            chemistryGradeArr[i] = 'A';
        } else if(chemistryArr[i] > 64){
            chemistryGradeArr[i] = 'B';
        } else if(chemistryArr[i] > 49){
            chemistryGradeArr[i] = 'C';
        } else if(chemistryArr[i] > 34){
            chemistryGradeArr[i] = 'S';
        } else {
            chemistryGradeArr[i] = 'F';
        }
    }
}*/

/**
* Maths = 0
* Physics = 1
* Chemistry = 2
*/
double calculateMean(int sub){

    int total = 0;
    int no_of_std = sizeof(indexNoArr);

    for(int i = 0; i < no_of_std; i++){
        if(sub == 0){
            total = total + mathsArr[i];
        } else if(1){
            total = total + physicsArr[i];
        } else if(2) {
            total = total + chemistryArr[i];
        }
    }

    double mean = (double) total / no_of_std;

    return mean;

}

void printGrades(){

    calculateGrades(mathsArr);
//    calculatePhysicsGrades();
 //   calculateChemistryGrades();

    int width = 12;


    printf("\n\n");
    printf("                     Advanced Level Results                      \n");
    printf("-----------------------------------------------------------------\n");
    printf("%*s", width, "IndexNo");
    printf("%*s", width, "Maths");
    printf("%*s", width, "Physics");
    printf("%*s", width, "Chemistry");
    printf("%*s\n", width, "Z-Score");
    printf("-----------------------------------------------------------------\n");

    for(int i=0; i < 5; i++){
        printf("%*d", width,  indexNoArr[i]);
        printf("%*c", width,  mathsGradeArr[i]);
        //printf("%*c", width,  physicsGradeArr[i]);
        //printf("%*c", width,  chemistryGradeArr[i]);
        printf("%*s\n", width,  "0.0000");
    }

     printf("-----------------------------------------------------------------\n");

     double m_m = calculateMean(0);
     printf("Maths Mean =  %1f", m_m);
}
