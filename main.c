#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<stdbool.h>

//Bulk data.
int s_indexNoArr[] = {125,226,184,165,201,135,216,174,195,200};
int s_mathsArr[] =  {95,66,84,44,40,55,68,54,24,69};
int s_physicsArr[] =  {98,48,87,24,57,18,28,87,66,57};
int s_chemistryArr[] = {95,55,92,32,54,65,81,62,42,44};

//N = no of students sat for the exam.
#define N 100

//Initialize the each subject array.
int indexNoArr[N], mathsArr[N], physicsArr[N], chemistryArr[N];
//Initialize the each subject's grade array.
char mathsGradeArr[N], physicsGradeArr[N], chemistryGradeArr[N];
//Initialize the each subject's z-score array.
double mathsZScores[N], physicsZScores[N], chemistryZScores[N], studentZScores[N];

//Each grade
int mathsA = 0, physicsA = 0, chemistryA = 0;
int mathsB = 0, physicsB = 0, chemistryB = 0;
int mathsC = 0, physicsC = 0, chemistryC = 0;
int mathsS = 0, physicsS = 0, chemistryS = 0;
int mathsF = 0, physicsF = 0, chemistryF = 0;


int no_of_students = 0;

int main()
{
    loadBlukInputs();
    getNoOfStudents();
    init();

    return 0;
}
/**
*Program initialization method.
*This will show the main menu.
**/
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
            case 4:
                searchStudent();
                break;
            case 5:
                reportSubMenu();
                break;
            case 6:
                graphSubMenu();
                break;
            case 7:
                exit(0);
                break;
            default:
                init();
                break;
        }
        printf("\nDesigned and developed by Sahan Karunaratne \n");
    }
}

/**
*Main menu method.
**/
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

/**
*Reports sub menu method.
**/
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
/**
*Graphs sub menu method.
**/
int graphSubMenu(){

    int reportMenuOption;

    printf("---------------------------- \n");
    printf(" Please select graph type     \n");
    printf("---------------------------- \n");
    printf(" 1) Grade Analysis \n");
    printf(" 2) Subject Analysis \n");
    printf(" 3) Exit \n");
    printf("---------------------------- \n");
    printf(" Please enter your choice :  ");
    scanf("%d", &reportMenuOption);
    printf("---------------------------- \n");

    //validation must do later.
    switch(reportMenuOption){
        case 1:
           // printf("Here goes Grade Analysis graph \n");
            printGradeAnalysisGraph();
        break;
        case 2:
            //printf("Here goes Subject Analysis graph \n");
             printSubjectAnalysisGraph();
        break;
    }
    return reportMenuOption;
}
/**
*This method is to load some bulk data as this system isn't associated with any database.
* There records of 10 students.
**/
void loadBlukInputs(){
    for(int i=0; i < N; i++){
        if(i < 10){
            indexNoArr[i] = s_indexNoArr[i];
            mathsArr[i] = s_mathsArr[i];
            physicsArr[i] = s_physicsArr[i];
            chemistryArr[i] = s_chemistryArr[i];
        }
    }
}
/**
*This method is to calculate number of students programtically.
**/
int getNoOfStudents(){
    for(int i=0; i<N; i++){
        if(indexNoArr[i]){
            no_of_students++;
            //printf("no_of_students : %d\n",indexNoArr[i]);
        }
    }
}
/**
*This method is to add a student to index and subject arrays.
**/
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
/**
*This method is to load student records to console screen.
**/
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
/**
*This method is to search a student records.
**/
void searchStudent(){

    int index = 0;
    printf("Enter index no : ");
    scanf("%d", &index);
    int width = 12;
    bool found = false;

    calculateMathsGrades();
    calculatePhysicsGrades();
    calculateChemistryGrades();
    calculateStudentZScores();

    for(int i=0; i < N; i++){
        if(indexNoArr[i] == index){
            found = true;
            printf("\n\n");
            printf("Index No : %d\n", index);
            printf("-----------------------------------------------------------\n");
            printf("      %*s", width, "");
            printf("%*s", width, "Maths");
            printf("%*s", width, "Physics");
            printf("%*s\n", width, "Chemistry");
            printf("-----------------------------------------------------------\n\n");
            printf("Marks %*s", width, "");
            printf("%*d", width, mathsArr[i]);
            printf("%*d", width, physicsArr[i]);
            printf("%*d\n", width, chemistryArr[i]);
            printf("Grade %*s", width, "");
            printf("%*c", width, mathsGradeArr[i]);
            printf("%*c", width, physicsGradeArr[i]);
            printf("%*c\n", width, chemistryGradeArr[i]);
            printf("Z-Score : %.4f\n", studentZScores[i]);
            printf("-----------------------------------------------------------\n\n");
        }
    }
    if(found == false){
        printf("No records found for Index No %d\n\n", index);
    }
    init();
}
/**
*This method is to calculate the maths grade.
**/
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
/**
*This method is to calculate the physics grade.
**/
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
/**
*This method is to calculate the chemistry grade.
**/
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
*This method is to calculate the mean of each subject.
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
/**
*This method is to calculate the Standard Deviation of each subject.
*mean = Mean of the subject.
*subject = subject's array.
*/
double calculateStandardDeviation(double mean, int subject[]){
    double temp = 0.0, sd = 0.0;

    for (int i = 0; i < no_of_students; ++i){
        temp += pow(subject[i] - mean, 2);
    }

    sd = sqrt(temp/no_of_students);
    return sd;
}
/**
*This method is to calculate the Z-Score of each subject.
*mean = Mean of the subject.
*sd = Standard Deviation of the subject.
*marks = student's marks for the subject.
*/
double calculateZScore(double mean, double sd, int marks){
    double z_score = 0.0;
    z_score = (marks - mean)/sd;
    return z_score;
}
/**
*This method is to calculate and store Z-Score of maths.
*/
void storeMathsZScores(){
    double maths_mean = calculateMean(0);
    double mathsSD = calculateStandardDeviation(maths_mean, mathsArr);

    for(int i=0; i < no_of_students; i++){
        mathsZScores[i] = calculateZScore(maths_mean, mathsSD, mathsArr[i]);
    }
}
/**
*This method is to calculate and store Z-Score of physics.
*/
void storePhysicsZScores(){
    double physics_mean = calculateMean(1);
    double physicsSD = calculateStandardDeviation(physics_mean, physicsArr);

    for(int i=0; i < no_of_students; i++){
        physicsZScores[i] = calculateZScore(physics_mean, physicsSD, physicsArr[i]);
    }
}
/**
*This method is to calculate and store Z-Score of chemistry.
*/
void storeChemistryZScores(){
    double chemistry_mean = calculateMean(2);
    double chemistrySD = calculateStandardDeviation(chemistry_mean, chemistryArr);

    for(int i=0; i < no_of_students; i++){
        chemistryZScores[i] = calculateZScore(chemistry_mean, chemistrySD, chemistryArr[i]);
    }
}
/**
*This method is to calculate final Z-Score of each student.
*/
void calculateStudentZScores(){

    storeMathsZScores();
    storePhysicsZScores();
    storeChemistryZScores();

    for(int i=0; i<no_of_students; i++){
        studentZScores[i] = (mathsZScores[i] + physicsZScores[i] + chemistryZScores[i])/3;
    }
}
/**
*This method is to print grades to console screen.
*/
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


/**
*This method is to calculate each grade quantities for each subject.
*/
void calculateEachGradeQuantities(){
    calculateMathsGrades();
    calculatePhysicsGrades();
    calculateChemistryGrades();

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
}

/**
*This method is to print results summary to console screen.
*/
void printSummary(){

    calculateEachGradeQuantities();

    int width = 12;

    printf("\n\n");
    printf("            Advanced Level Results - Summary                     \n");
    printf("-----------------------------------------------------------\n");
    printf("%*s", width, "IndexNo");
    printf("%*s", width, "Maths");
    printf("%*s", width, "Physics");
    printf("%*s\n", width, "Chemistry");
    printf("-----------------------------------------------------------\n");

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
/**
*This method is to print grades analysis graph to console screen.
*symbol - the symbol to draw graph for each subject.
*percentage -  percentage
*/
void gradeGraphPrinter(char symbol, int percentage){
    int org_percentage = percentage; // to keep original percentage.
    printf("\n");
    if(percentage == 0)
        printf(" - %d%%", org_percentage);
    while(percentage!=0){
        printf("%c",symbol);
        percentage--;
        if(percentage == 0)
            printf(" - %d%%", org_percentage);
    }
   // printf("\n");
}
/**
*This method is to organize print grades analysis graph.
*/
void printGradeAnalysisGraph(){

    calculateEachGradeQuantities();

    printf("\n");
    printf("                  Grades Analysis Graph                    \n");
    printf("-----------------------------------------------------------\n");
    printf("  #%*s", 8, " - Maths \n");
    printf("  &%*s", 8, " - Physics \n");
    printf("  $%*s", 8, " - Chemistry \n");
    printf("-----------------------------------------------------------\n");

    //Calculate sum of each grade.
    int noOfAs = mathsA + physicsA + chemistryA;
    int noOfBs = mathsB + physicsB + chemistryB;
    int noOfCs = mathsC + physicsC + chemistryC;
    int noOfSs = mathsS + physicsS + chemistryS;
    int noOfFs = mathsF + physicsF + chemistryF;

    //calculate percentage of each grade.
    int maths_A_perc=0, physics_A_perc=0, chemistry_A_perc=0;
    int maths_B_perc=0, physics_B_perc=0, chemistry_B_perc=0;
    int maths_C_perc=0, physics_C_perc=0, chemistry_C_perc=0;
    int maths_S_perc=0, physics_S_perc=0, chemistry_S_perc=0;
    int maths_F_perc=0, physics_F_perc=0, chemistry_F_perc=0;

    maths_A_perc = (int)(((double)mathsA/(double)noOfAs)*100);
    physics_A_perc = (int)(((double)physicsA/(double)noOfAs)*100);
    chemistry_A_perc = (int)(((double)chemistryA/(double)noOfAs)*100);

    maths_B_perc = (int)(((double)mathsB/(double)noOfBs)*100);
    physics_B_perc = (int)(((double)physicsB/(double)noOfBs)*100);
    chemistry_B_perc = (int)(((double)chemistryB/(double)noOfBs)*100);

    maths_C_perc = (int)(((double)mathsC/(double)noOfCs)*100);
    physics_C_perc = (int)(((double)physicsC/(double)noOfCs)*100);
    chemistry_C_perc = (int)(((double)chemistryC/(double)noOfCs)*100);

    maths_S_perc = (int)(((double)mathsS/(double)noOfSs)*100);
    physics_S_perc = (int)(((double)physicsS/(double)noOfSs)*100);
    chemistry_S_perc = (int)(((double)chemistryS/(double)noOfSs)*100);

    maths_F_perc = (int)(((double)mathsF/(double)noOfFs)*100);
    physics_F_perc = (int)(((double)physicsF/(double)noOfFs)*100);
    chemistry_F_perc = (int)(((double)chemistryF/(double)noOfFs)*100);

    printf("\n");
    printf(" A grades \n");
    gradeGraphPrinter(35, maths_A_perc); //Maths As | ASCII 35 = #
    gradeGraphPrinter(38, physics_A_perc); //Physics As  | ASCII 38 = &
    gradeGraphPrinter(36, chemistry_A_perc); //Chemistry As  | ASCII 36 = $
    printf("\n");
    printf("\n");
    printf(" B grades \n");
    gradeGraphPrinter(35, maths_B_perc); //Maths As | ASCII 35 = #
    gradeGraphPrinter(38, physics_B_perc); //Physics As  | ASCII 38 = &
    gradeGraphPrinter(36, chemistry_B_perc); //Chemistry As  | ASCII 36 = $
    printf("\n");
    printf("\n");
    printf(" C grades \n");
    gradeGraphPrinter(35, maths_C_perc); //Maths As | ASCII 35 = #
    gradeGraphPrinter(38, physics_C_perc); //Physics As  | ASCII 38 = &
    gradeGraphPrinter(36, chemistry_C_perc); //Chemistry As  | ASCII 36 = $
    printf("\n");
    printf("\n");
    printf(" S grades \n");
    gradeGraphPrinter(35, maths_S_perc); //Maths As | ASCII 35 = #
    gradeGraphPrinter(38, physics_S_perc); //Physics As  | ASCII 38 = &
    gradeGraphPrinter(36, chemistry_S_perc); //Chemistry As  | ASCII 36 = $
    printf("\n");
    printf("\n");
    printf(" F grades \n");
    gradeGraphPrinter(35, maths_F_perc); //Maths As | ASCII 35 = #
    gradeGraphPrinter(38, physics_F_perc); //Physics As  | ASCII 38 = &
    gradeGraphPrinter(36, chemistry_F_perc); //Chemistry As  | ASCII 36 = $

    printf("\n\n\n");
    init();
}

/**
*This method is to print grades analysis graph to console screen.
*symbol - the symbol to draw graph for each subject.
*percentage -  percentage
*/
void subjectGraphPrinter(char symbol, int percentage){
    int org_percentage = percentage; // to keep original percentage.
    printf("\n");
    if(percentage == 0)
        printf(" - %d%%", org_percentage);
    while(percentage!=0){
        printf("%c",symbol);
        percentage--;
        if(percentage == 0)
            printf(" - %d%%", org_percentage);
    }
   // printf("\n");
}

/**
*This method is to organize print grades analysis graph.
*/
void printSubjectAnalysisGraph(){
    // Mean percentage calculations.
    double maths_mean = calculateMean(0);
    double physics_mean = calculateMean(1);
    double chemistry_mean = calculateMean(2);

    double mathsSD = calculateStandardDeviation(maths_mean, mathsArr);
    double physicsSD = calculateStandardDeviation(physics_mean, physicsArr);
    double chemistrySD = calculateStandardDeviation(chemistry_mean, chemistryArr);

    printf("\n");
    printf("                  Subject Analysis Graph                   \n");
    printf("-----------------------------------------------------------\n");
    printf("  #%*s", 8, " - Mean \n");
    printf("  $%*s", 8, " - Standard Deviation \n");
    printf("-----------------------------------------------------------\n");

    printf("\n");
    printf(" Maths \n");
    subjectGraphPrinter(35, (int)maths_mean); //Mean As | ASCII 35 = #
    subjectGraphPrinter(36, (int)mathsSD); //Standard Deviation As  | ASCII 36 = $
    printf("\n");
    printf("\n");
    printf(" Physics \n");
    subjectGraphPrinter(35, (int)physics_mean); //Mean As | ASCII 35 = #
    subjectGraphPrinter(36, (int)physicsSD); //Standard Deviation As  | ASCII 36 = $
    printf("\n");
    printf("\n");
    printf(" Chemistry \n");
    subjectGraphPrinter(35, (int)chemistry_mean); //Mean As | ASCII 35 = #
    subjectGraphPrinter(36, (int)chemistrySD); //Standard Deviation As  | ASCII 36 = $

    printf("\n\n\n");
    init();
}
