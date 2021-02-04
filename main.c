#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int indexNoArr[] = {125,226,184,165,201};
int mathsArr[] =  {95,78,84,44,40};
int physicsArr[] =  {98,68,87,24,57};
int chemistryArr[] = {95,55,92,32,54};

char* mathsGradeArr[5], physicsGradeArr[5], chemistryGradeArr[5];
double mathsZScores[5], physicsZScores[5], chemistryZScores[5], studentZScores[5];

int no_of_students = 0;

int main()
{
    no_of_students = sizeof(indexNoArr)/sizeof(indexNoArr[0]);

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
        printf(" Thank you!.");
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
     indexNoArr[] = {125,226,184,165,201};
     mathsArr[] = {55,78,85,44,40};
     physicsArr[] = {68,68,87,24,57};
     chemistryArr[] = {95,55,92,32,54};
}*/

void calculateMathsGrades(){

    for(int i=0; i < no_of_students; i++){
        if(mathsArr[i] > 74){
            mathsGradeArr[i] = 'A';
        } else if(mathsArr[i] > 64){
            mathsGradeArr[i] = 'B';
        } else if(mathsArr[i] > 49){
            mathsGradeArr[i] = 'C';
        } else if(mathsArr[i] > 34){
            mathsGradeArr[i] = 'S';
        } else {
            mathsGradeArr[i] = 'F';
        }
    }
}

void calculatePhysicsGrades(){

    for(int i=0; i < no_of_students; i++){
        if(physicsArr[i] > 74){
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

    for(int i=0; i < no_of_students; i++){
        if(chemistryArr[i] > 74){
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
}

/**
* Maths = 0
* Physics = 1
* Chemistry = 2
*/
double calculateMean(int sub){
    int total = 0;

    for(int i = 0; i < no_of_students; i++){
        if(sub == 0){
            total = total + mathsArr[i];
        } else if(1){
            total = total + physicsArr[i];
        } else if(2) {
            total = total + chemistryArr[i];
        }
    }
    double mean = (double) total / no_of_students;
    return mean;
}

double calculateStandardDeviation(double mean, int subject[]){
    double temp = 0.0, sd = 0.0;

    for (int i = 0; i < 10; ++i){
        temp += pow(subject[i] - mean, 2);
    }

    sd = sqrt(temp/no_of_students);
    return sd;
}

double calculateZScore(double mean, double sd, int marks){
    double z_score = 0.0;
    z_score = (marks - mean)/sd;
    return z_score;
}

void storeMathsZScores(){
    double maths_mean = calculateMean(0);
    double mathsSD = calculateStandardDeviation(maths_mean, mathsArr);

    for(int i=0; i < no_of_students; i++){
        mathsZScores[i] = calculateZScore(maths_mean, mathsSD, mathsArr[i]);
    }
}

void storePhysicsZScores(){
    double physics_mean = calculateMean(0);
    double physicsSD = calculateStandardDeviation(physics_mean, physicsArr);

    for(int i=0; i < no_of_students; i++){
        physicsZScores[i] = calculateZScore(physics_mean, physicsSD, physicsArr[i]);
    }
}

void storeChemistryZScores(){
    double chemistry_mean = calculateMean(0);
    double chemistrySD = calculateStandardDeviation(chemistry_mean, chemistryArr);

    for(int i=0; i < no_of_students; i++){
        chemistryZScores[i] = calculateZScore(chemistry_mean, chemistrySD, chemistryArr[i]);
    }
}

void calculateStudentZScores(){

    storeMathsZScores();
    storePhysicsZScores();
    storeChemistryZScores();

    for(int i=0; i<no_of_students; i++){
        studentZScores[i] = (mathsZScores[i] + physicsZScores[i] + chemistryZScores[i])/3;
    }
}

void printGrades(){

    calculateMathsGrades();
    calculatePhysicsGrades();
    calculateChemistryGrades();

    calculateStudentZScores();

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

    for(int i=0; i < no_of_students; i++){
        printf("%*d", width, indexNoArr[i]);
        printf("%*c", width, mathsGradeArr[i]);
        printf("%*c", width, physicsGradeArr[i]);
        printf("%*c", width, chemistryGradeArr[i]);
        printf("%*.4f\n", width, studentZScores[i]);
    }

    printf("-----------------------------------------------------------------\n");
    printf("No of students : %d----------------------------------------------\n", no_of_students);
}


/*
    double maths_mean = calculateMean(0);
    double physics_mean = calculateMean(1);
    double chemistry_mean = calculateMean(2);

    double mathsSD = calculateStandardDeviation(maths_mean, mathsArr);
    double physicsSD = calculateStandardDeviation(physics_mean, physicsArr);
    double chemistrySD = calculateStandardDeviation(chemistry_mean, chemistryArr);
*/
