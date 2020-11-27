#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<dos.h>
/** define the structure **/
typedef struct {
    char fullName[50];
    int age;
    float salary;
} Employee;
/** function declaration: prototypes ***/
void addEmployee();
void displayAllEmployeeList();
void searchEmployeeByName();
void editEmployeeByName();
void deleteEmployeeByName();
FILE* openFile();
/**************************************/
int main()
{
    /** Declare necessary variables ************/
    int option;
    /*******Show the Menu *****************/
MENU:
    system ( "cls" );
    printf ( "\n1. Add Employee Record\n" );
    printf ( "\n2. View Employee Record\n" );
    printf ( "\n3. Edit Employee Record\n" );
    printf ( "\n4. Search Employee Record\n" );
    printf ( "\n5. Delete Employee Record\n" );
    printf ( "\n6. Exit\n" );
    printf ( "\nEnter your choice: \t" );
    /*******Read the option********************/
    scanf ( "%d", &option );
    
    switch ( option ) {
    case 1:
        addEmployee();
        break;
        
    case 2:
        displayAllEmployeeList();
        break;
        
    case 3:
        editEmployeeByName();
        break;
        
    case 4:
        searchEmployeeByName();
        break;
        
    case 5:
        deleteEmployeeByName();
        break;
        
    case 6:
        exit ( -1 );
        break;
        
    default:
        printf ( "\nWrong choice" );
        break;
    }
    
    getch();
    goto MENU;
    getch();
    return 0;
}
/**** function definitions **************/
FILE* openFile()  ///returning a pointer from a function
{
    FILE *fptr;
    /**
        see if the file is already present or not
        ->if it is already present open it in
        "r+b": read and write within the file
        ->Do not use "a+b" mode because you won't be able to modify earlier records
        ->Otherwise, open the file in
        "w+b": a new file is created if not found
        for reading and writing by removing all the previous contents in it.
    **/
    fptr = fopen ( "emp.bin", "r+b" );
    
    if ( fptr == NULL ) {
        printf ( "\n File not found .....trying to create one" );
        fptr = fopen ( "emp.bin", "w+b" );
        
        if ( fptr == NULL ) {
            printf ( "\n File not found .....trying to create one failed too..." );
            return NULL;
        }
        
        else {
            //printf("\n File  not found .....trying to create a new one passed...");
            return fptr;
        }
    }
    
    else {
//printf("\n File  found .....did not try to create a new one");
        return fptr;
    }
}///open file ends
void addEmployee()
{
    system ( "cls" ); ///to clear the screen
    Employee e;
    FILE *fptr = openFile();///call the function to open the file
    
    if ( fptr == NULL )
        exit ( -1 );
        
///read the details of an employee
    printf ( "\n Enter the name: " );
    fflush ( stdin );
    gets ( e.fullName );
    printf ( "\nEnter the age: " );
    scanf ( "%d", &e.age );
    printf ( "\nEnter the salary: " );
    scanf ( "%f", &e.salary );
///take the file pointer after the last record i.e to the end of the file
///or else you will end up over writing the earlier records.
    fseek ( fptr, 0, 2 );
    
/// Write the content to the disk
    if ( fwrite ( &e, sizeof ( e ), 1, fptr ) == 1 )
        printf ( "\nWriting to disk...Done..Press any key to continue.." );
        
    fclose ( fptr );
}
/**** to display all the details of each employee *****/
void displayAllEmployeeList()
{
///clear the screen
    system ( "cls" );
    Employee e;
    int hasRecord = 0;
///open the file
    FILE *fptr = openFile();
    
    if ( fptr == NULL )
        exit ( -1 );
        
    printf ( "\nName\t\tAge\tSalary" );
    printf ( "\n***********************************************\n" );
    
    while ( fread ( &e, sizeof ( e ), 1, fptr ) == 1 ) {
        hasRecord = 1;
        printf ( "%s\t%d\t%.3f\n", e.fullName, e.age, e.salary );
        printf ( "_____________________________________________\n" );
    }
    
    if ( hasRecord == 0 )
        printf ( "\nThere are no records..Press any key to continue." );
        
///close the file
    fclose ( fptr );
}///function ends
/** function to edit the employee salary details ***/
void editEmployeeByName()
{
///clear the screen
    system ( "cls" );
    Employee e;
    char searchName[50];
    int recordNo = 0, isFound = 0;
    FILE *fptr = openFile();
    
    if ( fptr == NULL ) {
        printf ( "\nSorry, the modification failed..." );
        exit ( -1 );
    }
    
    printf ( "\nEnter the name of the employee:\t" );
    fflush ( stdin );
    gets ( searchName );
    
    while ( fread ( &e, sizeof ( e ), 1, fptr ) == 1 ) {
        ///case sensitive search
        if ( strcmp ( searchName, e.fullName ) == 0 ) {
            isFound = 1;
///the same logic can be used to change the age and full name as well
            printf ( "\nEnter the new salary: " );
            scanf ( "%f", &e.salary );
///take the file pointer to the record that needs to be modified
            fseek ( fptr, sizeof ( e ) *recordNo, 0 );
            
            if ( fwrite ( &e, sizeof ( e ), 1, fptr ) == 1 ) {
                ///take file pointer to the next record
                fseek ( fptr, sizeof ( e ) * ( recordNo + 1 ), 0 );
            }
        }
        
        recordNo++;
    }
    
    if ( isFound == 1 )
        printf ( "\nData modified successfully..Press any key to continue" );
        
    else
        printf ( "\nNo match found..Press any key to continue" );
        
    fclose ( fptr );
}///function ends
void deleteEmployeeByName()
{
///clear the screen
    system ( "cls" );
    Employee e;
    FILE *fptr, *fptr2;
    int isDeleted = 0;
    char searchName[50];
    fptr = openFile();
    fptr2 = fopen ( "tmp.bin", "w+b" );
    
    if ( fptr2 == NULL || fptr == NULL ) {
        printf ( "\n Sorry file could not be opened..." );
        exit ( -1 );
    }
    
    printf ( "\nEnter the name of the employee:\t" );
    fflush ( stdin );
    gets ( searchName );
    
    while ( fread ( &e, sizeof ( e ), 1, fptr ) == 1 ) {
        ///case insensitive search
        if ( strcasecmp ( e.fullName, searchName ) != 0 ) {
            fwrite ( &e, sizeof ( e ), 1, fptr2 );
            printf ( "\nWriting....to temporary file...done!!!" );
        }
    }
    
///close the files
    if ( fclose ( fptr ) == 0 )
        printf ( "\nOriginal file closed..." );
        
    if ( fclose ( fptr2 ) == 0 )
        printf ( "\nTemporary file closed..." );
        
///remove the original file
    if ( remove ( "emp.bin" ) == 0 ) {
        ///success
        printf ( "\nOriginal file removed..." );
    }
    
    else
        printf ( "\nOriginal file could not be removed..." );
        
///rename the tmp file
    if ( rename ( "tmp.bin", "emp.bin" ) == 0 ) {
        ///success
        printf ( "\nTemporary file renamed...Press any key to continue" );
    }
    
    else
        printf ( "\nTemporary file could not be renamed..." );
}///function ends
/** Function to search Employee By Name **/
void searchEmployeeByName()
{
    ///clear the screen
    system ( "cls" );
    Employee e;
    char searchName[50];
    int  isFound = 0;
    FILE *fptr = openFile();
    
    if ( fptr == NULL ) {
        printf ( "\nSorry, the data file could not be opened..." );
        exit ( -1 );
    }
    
    printf ( "\nEnter the name of the employee :\t" );
    fflush ( stdin );
    gets ( searchName );
    printf ( "\nName\t\tAge\tSalary" );
    printf ( "\n***********************************************\n" );
    
    while ( fread ( &e, sizeof ( e ), 1, fptr ) == 1 ) {
        ///to compare the string in case insensitive format
        if ( strcasecmp ( e.fullName, searchName ) == 0 ) {
            isFound = 1;
            printf ( "%s\t%d\t\t%.3f\n", e.fullName, e.age, e.salary );
            printf ( "_____________________________________________" );
        }
    }
    
    if ( isFound == 0 )
        printf ( "\nSorry...the record not found... try checking your spelling..\nPress any key to continue " );
        
    fclose ( fptr );
}///function ends
