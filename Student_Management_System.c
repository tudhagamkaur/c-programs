/******************************************************************************
                        STUDENT MANAGEMENT SYSTEM

Project Name : Student Management System
Language     : C
Platform     : Microsoft Visual Studio
Developed By : Tudhagam Kaur
Course       : C Programming

******************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define MAX 100
#define PASSWORD_LENGTH 20
typedef struct 
{
   char studentid[15];
   int rollno;
   char name[40];
   int age;
   char gender[10];
   char course[30];
   float physics;
   float chemistry;
   float mathematics;
   float total;
   float percentage;
   float cgpa;
   float attendance;
   char grade;
}student;
student students[MAX];
int count=0;
char password[PASSWORD_LENGTH]="admin123";
//function prototypes
void login();
void menu();
void addstudent();
void displaystudents();
void searchstudent();
void updatestudent();
void deletestudent();
void sortstudents();
void statistics();
void savedata();
void loadData();
void backupdata();
void restoredata();
void exportReport();
void changepassword();
void generatestudentid(int index);
float calculatepercentage(float p,float c,float m);
float calculateCGPA(float percentage);
char calculategrade(float percentage);
void pausescreen();
void clearscreen();
void title();
int searchrollnumber(int roll);
void rankstudents();
void attendancereport();
//main function
int main()
{
    login();
    menu();
    return 0;
}
//menu function
void menu()
{
    int choice;
    loadData();
    do
    {
        title();
        printf("\n============================================");
        printf("\n        STUDENT MANAGEMENT SYSTEM");
        printf("\n============================================");
        printf("\n1. Add Student");
        printf("\n2. Display Students");
        printf("\n3. Search Student");
        printf("\n4. Update Student");
        printf("\n5. Delete Student");
        printf("\n6. Sort Students");
        printf("\n7. Statistics");
        printf("\n8. Attendance Report");
        printf("\n9. Save Data");
        printf("\n10. Backup Database");
        printf("\n11. Restore Database");
        printf("\n12. Export Report");
        printf("\n13. Change Password");
        printf("\n14. Exit");
        printf("\n\nEnter Choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            addstudent();
            break;
        case 2:
            displaystudents();
            break;
        case 3:
            searchstudent();
            break;
        case 4:
            updatestudent();
            break;
             case 5:
            deletestudent();
            break;
        case 6:
            sortstudents();
            break;
        case 7:
            statistics();
            break;
        case 8:
            attendancereport();
            break;
        case 9:
            savedata();
            break;
        case 10:
            backupdata();
            break;
        case 11:
            restoredata();
            break;
        case 12:
            exportReport();
            break;
        case 13:
            changepassword();
            break;
        case 14:
            savedata();
            printf("\n\n...Saved Successfully...");
            printf("\nThank You!\n");
            break;
        default:
            printf("\nInvalid Choice.");
        }
        pausescreen();
    }while(choice!=14);
}
//utility functions
void clearscreen()
{
    system("cls");
}
void pausescreen()
{
    printf("\n\nPress Enter to Continue...");
    getchar();
    getchar();
}
void title()
{
    time_t t;
    time(&t);
    clearscreen();
    printf("\n%s",ctime(&t));
}
//login function
void login()
{
    char pass[20];
    int attempt = 3;
    while(attempt > 0)
    {
        clearscreen();
        printf("\n====================================");
        printf("\n         LOGIN SYSTEM");
        printf("\n====================================");
        printf("\nEnter Password : ");
        scanf("%s", pass);
        if(strcmp(pass, password) == 0)
        {
            printf("\n\nLogin Successful!\n");
            return;
        }
        else
        {
            attempt--;
            printf("\nWrong Password!");
            if(attempt > 0)
            {
                printf("\nAttempts Left : %d", attempt);
            }
        }
    }
    printf("\n\nToo many incorrect attempts.");
    printf("\nProgram Terminated!!");
    exit(0);
}
void changepassword()
{
    char oldpass[20];
    char newpass[20];
    printf("\nEnter Old Password:");
    scanf("%s",oldpass);
    if(strcmp(oldpass,password)==0)
    {
    printf("\nEnter New Password : ");
        scanf("%s", newpass);

        strcpy(password, newpass);

        printf("\nPassword Changed Successfully.");
    }
    else
    {
        printf("\nIncorrect Old Password.");
    }
}
void generatestudentid(int index)
{
    sprintf(students[index].studentid,"STU%03d", index + 1);
}
float calculatepercentage(float p, float c, float m)
{
    float total;
    total = p + c + m;
    return total / 3.0;
}
float calculateCGPA(float percentage)
{
    return percentage / 9.5;
}
char calculategrade(float percentage)
{
    if(percentage >= 90)
        return 'A';
    else if(percentage >= 80)
        return 'B';
    else if(percentage >= 70)
        return 'C';
    else if(percentage >= 60)
        return 'D';
    else if(percentage >= 40)
        return 'E';
    else
        return 'F';
}
int searchrollnumber(int roll)
{
    int i;
    for(i = 0; i < count; i++)
    {
        if(students[i].rollno == roll)
        {
            return i;
        }
    }
    return -1;
}
//add student
void addstudent()
{
    if(count >= MAX)
    {
        printf("\nDatabase is Full!");
        return;
    }
    printf("\n====================================");
    printf("\n        ADD NEW STUDENT");
    printf("\n====================================");
    printf("\nEnter Roll Number : ");
    scanf("%d", &students[count].rollno);
    if(searchrollnumber(students[count].rollno) != -1)
    {
        printf("\nRoll Number Already Exists!");
        return;
    }
    generatestudentid(count);
    printf("Enter Name : ");
    scanf(" %[^\n]", students[count].name);
    printf("Enter Age : ");
    scanf("%d", &students[count].age);
    printf("Enter Gender : ");
    scanf("%s", students[count].gender);
    printf("Enter Course : ");
    scanf(" %[^\n]", students[count].course);
    printf("Enter Physics Marks : ");
    scanf("%f", &students[count].physics);
    printf("Enter Chemistry Marks : ");
    scanf("%f", &students[count].chemistry);
    printf("Enter Mathematics Marks : ");
    scanf("%f", &students[count].mathematics);
    printf("Enter Attendance (%%) : ");
    scanf("%f", &students[count].attendance);
    students[count].total =
        students[count].physics +
        students[count].chemistry +
        students[count].mathematics;
    students[count].percentage =
        calculatepercentage(
            students[count].physics,
            students[count].chemistry,
            students[count].mathematics);
    students[count].cgpa =
        calculateCGPA(students[count].percentage);
    students[count].grade =
        calculategrade(students[count].percentage);
    printf("\n====================================");
    printf("\nStudent Added Successfully!");
    printf("\n\nStudent ID : %s", students[count].studentid);
    printf("\nTotal Marks : %.2f", students[count].total);
    printf("\nPercentage : %.2f", students[count].percentage);
    printf("\nCGPA : %.2f", students[count].cgpa);
    printf("\nGrade : %c", students[count].grade);
    count++;
}
//display student
void displaystudents()
{
    int i;
    if(count == 0)
    {
        printf("\nNo Student Records Found!");
        return;
    }
    printf("\n==============================================================================================================");
    printf("\n%-10s %-8s %-20s %-10s %-8s %-10s %-8s %-8s %-10s",
           "ID","Roll","Name","Course","Total","Percent","CGPA","Grade","Attendance");
    printf("\n==============================================================================================================");
    for(i = 0; i < count; i++)
    {
        printf("\n%-10s %-8d %-20s %-10s %-8.2f %-10.2f %-8.2f %-8c %-10.2f",
               students[i].studentid,
               students[i].rollno,
               students[i].name,
               students[i].course,
               students[i].total,
               students[i].percentage,
               students[i].cgpa,
               students[i].grade,
               students[i].attendance);
    }
    printf("\n==============================================================================================================");
}
//search student
void searchstudent()
{
    int roll;
    int index;
    printf("\n====================================");
    printf("\n        SEARCH STUDENT");
    printf("\n====================================");
    printf("\nEnter Roll Number : ");
    scanf("%d", &roll);
    index = searchrollnumber(roll);
    if(index == -1)
    {
        printf("\nStudent Record Not Found!");
        return;
    }
    printf("\n====================================");
    printf("\nStudent ID      : %s", students[index].studentid);
    printf("\nRoll Number     : %d", students[index].rollno);
    printf("\nName            : %s", students[index].name);
    printf("\nAge             : %d", students[index].age);
    printf("\nGender          : %s", students[index].gender);
    printf("\nCourse          : %s", students[index].course);
    printf("\nPhysics Marks   : %.2f", students[index].physics);
    printf("\nChemistry Marks : %.2f", students[index].chemistry);
    printf("\nMathematics     : %.2f", students[index].mathematics);
    printf("\nTotal Marks     : %.2f", students[index].total);
    printf("\nPercentage      : %.2f", students[index].percentage);
    printf("\nCGPA            : %.2f", students[index].cgpa);
    printf("\nGrade           : %c", students[index].grade);
    printf("\nAttendance      : %.2f%%", students[index].attendance);
    printf("\n====================================");
}
//update student
void updatestudent()
{
    int roll;
    int index;
    char choice;
    student temp;
    printf("\n====================================");
    printf("\n        UPDATE STUDENT");
    printf("\n====================================");
    printf("\nEnter Roll Number : ");
    scanf("%d", &roll);
    index = searchrollnumber(roll);
    if(index == -1)
    {
        printf("\nStudent Record Not Found!");
        return;
    }
    temp = students[index];
    printf("\nCurrent Student Details");
    printf("\n----------------------------");
    printf("\nName : %s", students[index].name);
    printf("\nAge : %d", students[index].age);
    printf("\nGender : %s", students[index].gender);
    printf("\nCourse : %s", students[index].course);
    printf("\nPhysics : %.2f", students[index].physics);
    printf("\nChemistry : %.2f", students[index].chemistry);
    printf("\nMathematics : %.2f", students[index].mathematics);
    printf("\nAttendance : %.2f%%", students[index].attendance);
    printf("\n\nEnter New Name : ");
    scanf(" %[^\n]", temp.name);
    printf("Enter New Age : ");
    scanf("%d", &temp.age);
    printf("Enter New Gender : ");
    scanf("%s", temp.gender);
    printf("Enter New Course : ");
    scanf(" %[^\n]", temp.course);
    printf("Enter New Physics Marks : ");
    scanf("%f", &temp.physics);
    printf("Enter New Chemistry Marks : ");
    scanf("%f", &temp.chemistry);
    printf("Enter New Mathematics Marks : ");
    scanf("%f", &temp.mathematics);
    printf("Enter New Attendance : ");
    scanf("%f", &temp.attendance);
    temp.total =
        temp.physics +
        temp.chemistry +
        temp.mathematics;
    temp.percentage =
        calculatepercentage(
            temp.physics,
            temp.chemistry,
            temp.mathematics);
    temp.cgpa =
        calculateCGPA(temp.percentage);
    temp.grade =
        calculategrade(temp.percentage);
    printf("\n\nSave Changes? (Y/N) : ");
    scanf(" %c", &choice);
    if(choice == 'Y' || choice == 'y')
    {
        students[index] = temp;
        printf("\nStudent Record Updated Successfully!");
    }
    else
    {
        printf("\nChanges Cancelled!");
    }
}
//delete student
void deletestudent()
{
    int roll;
    int index;
    int i;
    printf("\n====================================");
    printf("\n        DELETE STUDENT");
    printf("\n====================================");
    printf("\nEnter Roll Number : ");
    scanf("%d", &roll);
    index = searchrollnumber(roll);
    if(index == -1)
    {
        printf("\nStudent Record Not Found!");
        return;
    }
    for(i = index; i < count - 1; i++)
    {
        students[i] = students[i + 1];
    }
    count--;
    printf("\nStudent Record Deleted Successfully!");
}
//sort students
void sortstudents()
{
    int i, j;
    student temp;
    if(count == 0)
    {
        printf("\nNo Student Records Found!");
        return;
    }
    for(i = 0; i < count - 1; i++)
    {
        for(j = 0; j < count - i - 1; j++)
        {
            if(students[j].rollno > students[j + 1].rollno)
            {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    printf("\nStudents Sorted Successfully by Roll Number!");
}
//statistics
void statistics()
{
    int i;
    float highest, lowest, average = 0;
    if(count == 0)
    {
        printf("\nNo Student Records Found!");
        return;
    }
    highest = students[0].percentage;
    lowest = students[0].percentage;
    for(i = 0; i < count; i++)
    {
        if(students[i].percentage > highest)
        {
            highest = students[i].percentage;
        }
        if(students[i].percentage < lowest)
        {
            lowest = students[i].percentage;
        }
        average += students[i].percentage;
    }
    average = average / count;
    printf("\n====================================");
    printf("\n          STATISTICS");
    printf("\n====================================");
    printf("\nTotal Students      : %d", count);
    printf("\nHighest Percentage  : %.2f", highest);
    printf("\nLowest Percentage   : %.2f", lowest);
    printf("\nAverage Percentage  : %.2f", average);
    printf("\n====================================");
}
//save data
void savedata()
{
    FILE *fp;
    int i;
    fp = fopen("students.txt", "w");
    if(fp == NULL)
    {
        printf("\nError Opening File!");
        return;
    }
    fprintf(fp,"%d\n",count);
    for(i = 0; i < count; i++)
    {
        fprintf(fp,"%s\n",students[i].studentid);
        fprintf(fp,"%d\n",students[i].rollno);
        fprintf(fp,"%s\n",students[i].name);
        fprintf(fp,"%d\n",students[i].age);
        fprintf(fp,"%s\n",students[i].gender);
        fprintf(fp,"%s\n",students[i].course);
        fprintf(fp,"%.2f\n",students[i].physics);
        fprintf(fp,"%.2f\n",students[i].chemistry);
        fprintf(fp,"%.2f\n",students[i].mathematics);
        fprintf(fp,"%.2f\n",students[i].total);
        fprintf(fp,"%.2f\n",students[i].percentage);
        fprintf(fp,"%.2f\n",students[i].cgpa);
        fprintf(fp,"%.2f\n",students[i].attendance);
        fprintf(fp,"%c\n",students[i].grade);
    }
    fclose(fp);
    printf("\nData Saved Successfully!");
}
//load data
void loadData()
{
    FILE *fp;
    int i;
    fp = fopen("students.txt","r");
    if(fp == NULL)
    {
        return;
    }
    fscanf(fp,"%d",&count);
    for(i=0;i<count;i++)
    {
        fscanf(fp,"%s",students[i].studentid);
        fscanf(fp,"%d",&students[i].rollno);
        fscanf(fp," %[^\n]",students[i].name);
        fscanf(fp,"%d",&students[i].age);
        fscanf(fp,"%s",students[i].gender);
        fscanf(fp," %[^\n]",students[i].course);
        fscanf(fp,"%f",&students[i].physics);
        fscanf(fp,"%f",&students[i].chemistry);
        fscanf(fp,"%f",&students[i].mathematics);
        fscanf(fp,"%f",&students[i].total);
        fscanf(fp,"%f",&students[i].percentage);
        fscanf(fp,"%f",&students[i].cgpa);
        fscanf(fp,"%f",&students[i].attendance);
        fscanf(fp," %c",&students[i].grade);
    }
    fclose(fp);
}
//back up
void backupdata()
{
    FILE *source, *backup;
    char ch;
    source = fopen("students.txt", "r");
    if(source == NULL)
    {
        printf("\nNo Data Available to Backup!");
        return;
    }
    backup = fopen("backup.txt", "w");
    while((ch = fgetc(source)) != EOF)
    {
        fputc(ch, backup);
    }
    fclose(source);
    fclose(backup);
    printf("\nBackup Created Successfully!");
}
//restore data
void restoredata()
{
    FILE *backup, *source;
    char ch;
    backup = fopen("backup.txt", "r");
    if(backup == NULL)
    {
        printf("\nBackup File Not Found!");
        return;
    }
    source = fopen("students.txt", "w");
    while((ch = fgetc(backup)) != EOF)
    {
        fputc(ch, source);
    }
    fclose(backup);
    fclose(source);
    loadData();
    printf("\nDatabase Restored Successfully!");
}
//attendance report
void attendancereport()
{
    int i;
    if(count == 0)
    {
        printf("\nNo Student Records Found!");
        return;
    }
    printf("\n==============================================================");
    printf("\n%-10s %-20s %-15s","Roll No","Name","Attendance");
    printf("\n==============================================================");
    for(i = 0; i < count; i++)
    {
        printf("\n%-10d %-20s %-10.2f%%",
               students[i].rollno,
               students[i].name,
               students[i].attendance);
    }
    printf("\n==============================================================");
}
//export report
void exportReport()
{
    FILE *fp;
    int i;
    fp = fopen("Student_Report.txt","w");
    if(fp == NULL)
    {
        printf("\nUnable to Create Report!");
        return;
    }
    fprintf(fp,"===============================================\n");
    fprintf(fp,"      STUDENT MANAGEMENT SYSTEM REPORT\n");
    fprintf(fp,"===============================================\n\n");
    fprintf(fp,"Total Students : %d\n\n",count);
    for(i = 0; i < count; i++)
    {
        fprintf(fp,"Student %d\n",i+1);
        fprintf(fp,"-------------------------------------------\n");
        fprintf(fp,"Student ID : %s\n",students[i].studentid);
        fprintf(fp,"Roll Number : %d\n",students[i].rollno);
        fprintf(fp,"Name : %s\n",students[i].name);
        fprintf(fp,"Age : %d\n",students[i].age);
        fprintf(fp,"Gender : %s\n",students[i].gender);
        fprintf(fp,"Course : %s\n",students[i].course);
        fprintf(fp,"Physics : %.2f\n",students[i].physics);
        fprintf(fp,"Chemistry : %.2f\n",students[i].chemistry);
        fprintf(fp,"Mathematics : %.2f\n",students[i].mathematics);
        fprintf(fp,"Total : %.2f\n",students[i].total);
        fprintf(fp,"Percentage : %.2f\n",students[i].percentage);
        fprintf(fp,"CGPA : %.2f\n",students[i].cgpa);
        fprintf(fp,"Grade : %c\n",students[i].grade);
        fprintf(fp,"Attendance : %.2f%%\n",students[i].attendance);
        fprintf(fp,"\n");
    }
    fclose(fp);
    printf("\nReport Exported Successfully!");
}