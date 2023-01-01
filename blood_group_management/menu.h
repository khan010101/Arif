
void menu(void)
{
    printf("\n\n\t\t   ======WELCOME TO BLOOD GROUP MANAGEMENT======\n");
    printf("\n\n\t\t\t*********************************\n\t\t\t*\t\t\t\t*\n\t\t\t*\t     Main Menu      \t*\n\t\t\t*\t\t\t\t*\n\t\t\t*********************************\n\t\t\t*\t\t\t\t*");
    printf("\n\t\t\t*\t  [1]All list\t\t*\n");
    printf("\t\t\t*\t  [2] Add entry\t\t*\n");
    printf("\t\t\t*\t  [3]Search\t\t*\n");
    printf("\t\t\t*\t  [4]About Us\t\t*\n");
    printf("\t\t\t*\t  [5]Exit\t\t*\n\t\t\t*\t\t\t\t*\n");
    printf("\t\t\t*********************************\n\n");
    printf("\t\t\t\tChoice Any Number: ");

    int choice;
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        list();
        break;
    case 2:
        add_entry();
    case 3:
        search();
        break;
    case 4:
        aboutus();
        break;
    case 5:
        printf("\n\t\t\tThank you for using us..\n");
        exit(0);
    default:
        print_error();
        break;
    }
}
