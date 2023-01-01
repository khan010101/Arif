
void signup(void)
{
    system("CLS");
    FILE *fp;
    fp=fopen("user_pass.txt","w");
    printf("\n\t\t\t\tREGISTRATION\n\t\t==============================================\n");
    printf("\n\t\t\tFirst Name:");
    fflush(stdin);
    gets(entry.firstname);
    printf("\n\t\t\tLast Name:");
    gets(entry.lastname);
    printf("\n\t\t\tUser Name:");
    gets(entry.username);
    printf("\n\t\t\tPassword:");
    gets(entry.password);

    if (strlen(entry.username) == 0 || strlen(entry.password) == 0)
    {
        printf("\t\t\tError: Username or Password can NOT be blank..\n\n");
        system("CLS");
        login();
    }

    fwrite(&entry,sizeof(entry),1,fp);
    fclose(fp);
    printf("\n\t\tRegistration Successfully.....\n");
    system("CLS");
    login();
}

void login()
{
    system("cls");

    printf("\t\t\tTo sign up, keep the username and password blank..\n\n");

    int choise,i;

    char password[30];
    char username[30],ch;
    fflush(stdin);
    FILE *fp;
    fp=fopen("user_pass.txt","r");
    printf("\n\t\t\tENTER YOUR USERNAME AND PASSWORD\n\t    ==========================================================\n");

    printf("\n\t\t\tUser Name: ");
    gets(username);

    printf("\n\t\t\tPassword: ");
    gets(password);

    if (strlen(username) == 0 && strlen(password) == 0)
    {
            signup();
            return;
    }

    while(fread(&entry,sizeof(entry),1,fp))
    {

        if(strcmp(username,entry.username)==0 && strcmp(password,entry.password)==0)
        {
            system("CLS");
            printf("\n\n\n\t\t\tSuccesful login....\n");
            printf("\n\t\t\tPress any key to continue....");
            getch();
            system("CLS");
        }

        else
        {
            printf("\n\t\tYour Username Or Password Is Incorrect\n\t\tPlease Enter correct Username and Password\n\n\n\n");
            login();
        }
    }

    fclose(fp);

}
