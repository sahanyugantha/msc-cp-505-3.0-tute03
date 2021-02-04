#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Bulk data.
int s_indexNoArr[] = {125,226,184,165,201};
int s_mathsArr[] =  {95,78,84,44,40};
int s_physicsArr[] =  {98,68,87,24,57};
int s_chemistryArr[] = {95,55,92,32,54};

//N = no of students sat for the exam.
#define N 100

int indexNoArr[N], mathsArr[N], physicsArr[N], chemistryArr[N];
char* mathsGradeArr[N], physicsGradeArr[N], chemistryGradeArr[N];
double mathsZScores[N], physicsZScores[N], chemistryZScores[N], studentZScores[N];

int no_of_students = 0;

int main()
{
    loadBlukInputs();
    getNoOfStudents();
    init();

    return 0;
}

void init(){
    int menuOption = showMainMenu();
    if(menuOption<1 || menuOption>7 ){
        printf(" Please enter valid option no  \n");
        init();
    } else {
        switch (menuOption){
            case 1:
                addStudent();
                break;
            case 3:
                loadRecords();
                break;
            case 5:
                reportSubMenu();
                break;
            default:
                init();
                break;
        }
        printf("\nDesigned and developed by Sahan Karunaratne \n");
    }
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
            //printf("Here goes Subject summary \n");
            printSummary();
        break;
    }
    return reportMenuOption;
}

void loadBlukInputs(){
    for(int i=0; i < N; i++){
        if(i < 5){
            indexNoArr[i] = s_indexNoArr[i];
            mathsArr[i] = s_mathsArr[i];
            physicsArr[i] = s_physicsArr[i];
            chemistryArr[i] = s_chemistryArr[i];
        }
    }
}

int getNoOfStudents(){
    for(int i=0; i<N; i++){
        if(indexNoArr[i]){
            no_of_students++;
            //printf("no_of_students : %d\n",indexNoArr[i]);
        }
    }
}

void addStudent(){
    int index = 0, maths = 0, physics = 0, chemistry = 0;
    int array_index = no_of_students;

    printf("Enter Index No : ");
    scanf("%d", &index);
    printf("Enter Maths marks : ");
    scanf("%d", &maths);
    printf("Enter Physics marks : ");
    scanf("%d", &physics);
    printf("Enter Chemistry marks : ");
    scanf("%d", &chemistry);

    indexNoArr[array_index] = index;
    mathsArr[array_index] = maths;
    physicsArr[array_index] = physics;
    chemistryArr[array_index] = chemistry;

   // printf("Old No of std %d\n", no_of_students);
    no_of_students = no_of_students +1;
    //printf("New No of std %d\n", no_of_students);

    //printf("maths %d\n", maths);
   // printf("physics %d\n", physics);
   // printf("Chemistry %d\n", chemistry);
    init();
}

void loadRecords(){
    int width = 12;

    printf("\n\n");
    printf("            Advanced Level Marks                           \n");
    printf("-----------------------------------------------------------\n");
    printf("%*s", width, "IndexNo");
    printf("%*s", width, "Maths");
    printf("%*s", width, "Physics");
    printf("%*s\n", width, "Chemistry");
    printf("-----------------------------------------------------------\n");
    for(int i=0; i < no_of_students; i++){
        printf("%*d", width, indexNoArr[i]);
        printf("%*d", width, mathsArr[i]);
        printf("%*d", width, physicsArr[i]);
        printf("%*d\n", width, chemistryArr[i]);
    }
    printf("-----------------------------------------------------------\n\n");
    printf("No of students : %d\n", no_of_students);
    printf("-----------------------------------------------------------\n\n");
    init();
}


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

    for (int i = 0; i < no_of_students; ++i){
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
    double physics_mean = calculateMean(1);
    double physicsSD = calculateStandardDeviation(physics_mean, physicsArr);

    for(int i=0; i < no_of_students; i++){
        physicsZScores[i] = calculateZScore(physics_mean, physicsSD, physicsArr[i]);
    }
}

void storeChemistryZScores(){
    double chemistry_mean = calculateMean(2);
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

    init();
}

void printSummary(){

    calculateMathsGrades();
    calculatePhysicsGrades();
    calculateChemistryGrades();

    int width = 12;

    printf("\n\n");
    printf("            Advanced Level Results - Summary                     \n");
    printf("-----------------------------------------------------------\n");
    printf("%*s", width, "IndexNo");
    printf("%*s", width, "Maths");
    printf("%*s", width, "Physics");
    printf("%*s\n", width, "Chemistry");
    printf("-----------------------------------------------------------\n");


    int mathsA = 0, physicsA = 0, chemistryA = 0;
    int mathsB = 0, physicsB = 0, chemistryB = 0;
    int mathsC = 0, physicsC = 0, chemistryC = 0;
    int mathsS = 0, physicsS = 0, chemistryS = 0;
    int mathsF = 0, physicsF = 0, chemistryF = 0;


    //grades summary
     for(int i=0; i < no_of_students; i++){
        //printf("Maths A --> %c\n", mathsGradeArr[i]);
        switch((char)mathsGradeArr[i]){
            case 'A':  mathsA++; break;
            case 'B':  mathsB++; break;
            case 'C':  mathsC++; break;
            case 'S':  mathsS++; break;
            case 'F':  mathsF++; break;
        }

        switch((char)physicsGradeArr[i]){
            case 'A':  physicsA++; break;
            case 'B':  physicsB++; break;
            case 'C':  physicsC++; break;
            case 'S':  physicsS++; break;
            case 'F':  physicsF++; break;
        }

        switch((char)chemistryGradeArr[i]){
            case 'A':  chemistryA++; break;
            case 'B':  chemistryB++; break;
            case 'C':  chemistryC++; break;
            case 'S':  chemistryS++; break;
            case 'F':  chemistryF++; break;
        }
     }

    double maths_mean = calculateMean(0);
    double mathsSD = calculateStandardDeviation(maths_mean, mathsArr);
    double physics_mean = calculateMean(1);
    double physicsSD = calculateStandardDeviation(physics_mean, physicsArr);
    double chemistry_mean = calculateMean(2);
    double chemistrySD = calculateStandardDeviation(chemistry_mean, chemistryArr);

    printf("%*s", width, "A");
    printf("%*d", width, mathsA);
    printf("%*d", width, physicsA);
    printf("%*d\n", width, chemistryA);
    printf("%*s", width, "B");
    printf("%*d", width, mathsB);
    printf("%*d", width, physicsB);
    printf("%*d\n", width, chemistryB);
    printf("%*s", width, "C");
    printf("%*d", width, mathsC);
    printf("%*d", width, physicsC);
    printf("%*d\n", width, chemistryC);
    printf("%*s", width, "S");
    printf("%*d", width, mathsS);
    printf("%*d", width, physicsS);
    printf("%*d\n", width, chemistryS);
    printf("%*s", width, "F");
    printf("%*d", width, mathsF);
    printf("%*d", width, physicsF);
    printf("%*d\n", width, chemistryF);
    printf("%*s", width, "Mean");
    printf("%*.2f", width, maths_mean);
    printf("%*.2f", width, physics_mean);
    printf("%*.2f\n", width, chemistry_mean);
    printf("%*s", width, "Stan Dev");
    printf("%*.2f", width, mathsSD);
    printf("%*.2f", width, physicsSD);
    printf("%*.2f\n", width, chemistrySD);

    printf("-----------------------------------------------------------\n\n");
    init();
}
