#include<stdio.h>

#include<conio.h>

#include<string.h>

#include<stdio.h>

#include<windows.h>

#include<time.h>

#define size 200
int main() {
  system("color 0a");
  int Login;
  time_t t;
  time( & t);
  printf("Login Date: %s", ctime( & t));
  printf("\n\n\t\t\t\t\t***********************************\n");

  printf("\t\t\t\t\t*PASSWORD PROTECTED PERSONAL Login*\n");

  printf("\t\t\t\t\t***********************************");

  printf("\n\n\t\t\t\t\t\tSYSTEM LOGIN\n\n\t\t\t\t\t\tCreate User[1]\n\n\t\t\t\t\t\tLogin User[2]\n\n>> ");
  scanf("%d", & Login);

  switch (Login) {
  case 1:

    Adduser();
    break;
  case 2:
    Userlogin();
    break;
  default:
    printf("Please Choose proper Option,Press key to try Again");
    break;
  }
  return 0;

}
int Adduser()

{
  system("cls");
  system("color 0a");
  char User[50];
  char password[20];
  int i;
  int pool;
  time_t t;
  time( & t);
  printf("Login Date: %s", ctime( & t));
  printf("\n\n\t\t\t\t\t***********************************\n");

  printf("\t\t\t\t\t\t*Let's create New User*\n");

  printf("\t\t\t\t\t***********************************\n\n");
  printf("\tEnter Username: ");
  scanf("%s", & User);
  if (User) {
    printf("\tEnter New Password: ");
    int p = 0;
    do {
      password[p] = getch();
      if (password[p] != '\r') {
        printf("*");
      }
      p++;
    } while (password[p - 1] != '\r');
    password[p - 1] = '\0';
    getch();
    system("cls");
    system("cls");
    printf("\tconfirmation Password");
    printf("..");
    Sleep(500);
    printf("...");
    Sleep(200);
    printf("..");
    Sleep(200);
    system("Cls");
    printf("\n");
    printf("\t Congratulation %s User Created Successfully!!");
    Sleep(1000);
    system("cls");
    printf("\n\n\t\t\t\t\t***********************************\n");

    printf("\t\t\t\t\t\t*Please Select Option*\n");

    printf("\t\t\t\t\t***********************************\n\n");
    printf("\n\n\t\t\tMAIN MENU:");

    printf("\n\n\tADD RECORD\t[1]");

    printf("\n\tEDIT RECORD\t[2]");

    printf("\n\tDELET RECORD\t[3]");

    printf("\n\tAMC CALCULATOR\t[4]");

    printf("\n\tSYSTEM LOGOUT\t[5]");

    printf("\n\n\tENTER YOUR CHOICE:");

    scanf("%d", & pool);

    switch (pool) {
    case 1:
      Addrecord();
      break;

    case 2:
      ReadRecord();
      break;
    case 3:
      DeleteRecord();
      break;
    case 4:
      AmcCalulator();
      break;
    case 5:
      systemlogout();
      break;
    default:
      printf("please try Once");
      break;
    }

  }
};
int Userlogin()

{
  system("cls");
  system("Color 0a");
  char key[20] = ("****");
  char User[20];
  char password[50];
  int pool;
  printf("\n\n\t\t\t\t\t***********************************\n");

  printf("\t\t\t\t\t*PASSWORD PROTECTED PERSONAL Login*\n");

  printf("\t\t\t\t\t***********************************\n\n");
  printf("\tEnter UserName: ");
  scanf("%s", & User);
  if (User); {

    if (key) {
      printf("\tEnter Password: ");
      int p = 0;
      do {
        password[p] = getch();
        if (password[p] != '\r') {
          printf("*");
        }
        p++;
      } while (password[p - 1] != '\r');
      password[p - 1] = '\0';
      system("cls");
      printf("\n");
      printf("verifying your account");
      Sleep(100);
      printf(".");
      Sleep(100);
      printf("..");
      Sleep(500);
      printf("...\n");
      Sleep(100);
      system("cls");
      printf("Login Success\n\n");
      Sleep(500);
      system("Cls");
      printf("Login User %s", & User);
      Sleep(500);
      system("cls");
      printf("\n\n\t\t\t\t\t***********************************\n");

      printf("\t\t\t\t\t\t*Please Select Option*\n");

      printf("\t\t\t\t\t***********************************\n\n");

      printf("\n\n\t\tMAIN MENU:");

      printf("\n\n\tADD RECORD\t[1]");

      printf("\n\tEDIT RECORD\t[2]");

      printf("\n\tDELET RECORD\t[3]");

      printf("\n\tAMC CALCULATOR\t[4]");

      printf("\n\tSYSTEM LOGOUT\t[5]");

      printf("\n\n\tENTER YOUR CHOICE:");

      scanf("%d", & pool);

      switch (pool) {
      case 1:
        Addrecord();
        break;

      case 2:
        ReadRecord();
        break;
      case 3:
        DeleteRecord();
        break;
      case 4:
        AmcCalulator();
        break;
      case 5:
        systemlogout();
        break;
      default:
        printf("please try Once");
        break;
      }
    }
  }
};

int Addrecord() {
  system("cls");
  char Name[200];
  int Number;
  char Address[100];
  FILE * fptr;
  printf("\n\n\t\t\t\t*****************************\n");

  printf("\t\t\t\t::*Add Client Information*::\n");

  printf("\t\t\t\t*****************************\n\n");

  fptr = fopen("E:\\Biraj.txt", "w");

  if (fptr == NULL) {
    printf("Please Enter Proper Data");
    exit(1);
  }

  printf("\tEnter Name: ");
  scanf("%s", & Name);
  fprintf(fptr, "%s", Name);
  fclose(fptr);

  printf("\n\tEnter Contact: ");
  scanf("%d", & Number);
  fprintf(fptr, "%d", Number);
  fclose(fptr);

  printf("\n\tClient Address: ");
  scanf("%s", & Address);
  fprintf(fptr, "%s", Address);
  fclose(fptr);
  Sleep(100);
  system("cls");
  printf("\tSaving Infprmation.");
  Sleep(200);
  printf("..");
  Sleep(200);
  printf("..");
  Sleep(2000);
  printf("..\n");
  system("cls");
  int Redirect;
  printf("\n\tPress Any key For Main Menu\n>>");
  scanf("%d", & Redirect);
  if (Redirect) {

    Recall();
  }
  getch();
};
int ReadRecord() {
  int Redirect;
  system("color 0a");
  system("cls");
  char Name[200];
  int Number;
  char Address[100];
  FILE * fptr;
  printf("\n\n\t\t\t\t***********************************\n");

  printf("\t\t\t\t\t::*Client Document*::\n");

  printf("\t\t\t\t***********************************\n\n");

  if ((fptr = fopen("E:\\CrmData.txt", "r")) == NULL) {
    printf("\nError! opening file");
  }
  fscanf(fptr, "%s", & Name);
  printf("\tClient Name:%s", Name);
  fclose(fptr);

  fscanf(fptr, "%d", & Number);
  printf("\n\tClient Contact: %d", Name);
  fclose(fptr);

  fscanf(fptr, "%s", & Name);
  printf("\n\tClient Address: %s", Name);
  fclose(fptr);
  getch();

  printf("\nPress Any key For Main Menu\n>>");
  scanf("%d", & Redirect);
  if (Redirect) {

    Recall();

  }

}
int DeleteRecord()

{
  system("cls");
  system("Color 0a");
  char key[20];
  char User[20];
  char password[50];
  time_t t;
  time( & t);
  printf("Login Date: %s", ctime( & t));
  printf("\n\n\t\t\t\t\t***********************************\n");

  printf("\t\t\t\t\t*Enter Client Name for Update Record's*\n");
  printf("\t\t\t\t\t***********************************\n\n");
  printf("\tPlease Login After Deleting Record\n\n");
  printf("\tEnter UserName: ");
  scanf("%s", & User);
  if (User); {

    if (key) {

      printf("\tEnter Password: ");
      int p = 0;
      do {
        password[p] = getch();
        if (password[p] != '\r') {
          printf("*");
        }
        p++;
      } while (password[p - 1] != '\r');
      password[p - 1] = '\0';
      system("cls");
      printf("\n");
      printf("Checking User Data: ");
      Sleep(100);
      printf(".");
      Sleep(100);
      printf("..");
      Sleep(500);
      printf("...\n");
      Sleep(100);
      system("cls");
      printf(" %s User Data Found in System \n\n");
      Sleep(1000);
      system("Cls");
      printf("System logging out Due to Security Reason.");
      Sleep(500);
      printf("..");
      Sleep(500);
      system("exit");

    }
  }
};
void AmcCalulator() {
  system("cls");
  int Redirect;
  float value1, value2, P, T, R, Vat, Net, result;
  system("cls");
  printf("\n\n\t\t\t\t\t***********************************\n");
  printf("\t\t\t\t\t\t*Amc Record*\n");
  printf("\t\t\t\t\t***********************************\n\n");
  printf("\n\n\t\t\tCalculate Amc:");

  printf("\n\nSales Amount: ");
  scanf("%f", & P);
  printf("Time: ");
  scanf("%f", & T);
  printf("Rate: ");
  scanf("%f", & R);
  result = (P * T * R / 365);
  printf("\nAmc:%f", result);
  printf("Press Any key to logout:\n>");
  scanf("%d", Redirect);
  if (Redirect)
    Recall();
};
void systemlogout() {
  char A;
  time_t t;
  time( & t);
  printf("Login Date: %s", ctime( & t));
  printf("For Logout Press[Y]\n\n>>");
  scanf("%c", & A);
  if (A == 'Y') {
    system("exit");

  } else {

    Recall();
  }

};
int Recall() {
  int pool;
  system("cls");
  printf("\n\n\t\t\t\t\t***********************************\n");
  printf("\t\t\t\t\t\t*Please Select Option*\n");
  printf("\t\t\t\t\t***********************************\n\n");
  printf("\n\n\t\t\tMAIN MENU:");

  printf("\n\n\tADD RECORD\t[1]");

  printf("\n\tEDIT RECORD\t[2]");

  printf("\n\tDELET RECORD\t[3]");

  printf("\n\tAMC CALCULATOR\t[4]");

  printf("\n\tSYSTEM LOGOUT\t[5]");

  printf("\n\n\tENTER YOUR CHOICE:");

  scanf("%d", & pool);

  switch (pool) {
  case 1:
    Addrecord();
    break;

  case 2:
    ReadRecord();
    break;
  case 3:
    DeleteRecord();
    break;
  case 4:
    AmcCalulator();
    break;
  case 5:
    systemlogout();
    break;
  default:
    printf("please try Once");
    break;
  }

};
