
void add_entry(void)
{
    FILE *fp;
    fp = fopen("bloodgroup.txt", "a");
    printf("\t\t\t Name: ");
    fflush(stdin);
    gets(entry.name);

    fflush(stdin);
        printf("\t\t\t Blood Group: ");
    gets(entry.blood_group);

    fflush(stdin);
        printf("\t\t\t Batch: ");
    gets(entry.batch);

    fflush(stdin);
        printf("\t\t\t Phone: ");
    gets(entry.phone);

    fflush(stdin);
        printf("\t\t\t Email: ");
    gets(entry.email);

    fwrite(&entry, sizeof(entry), 1, fp);

    fclose(fp);
    menu();
}

void list(void)
{
    system("CLS");
    fflush(stdin);
    printf("\n\n\t\t\t\t All lists\n\t\t===============================================\n");
    FILE *fp;
    fp=fopen("bloodgroup.txt","r");

    for(int i=0; i<100; i++)
    {
        while(fread(&entry,sizeof(entry),1,fp)==1)
        {
            printf("\n\t\t\tName:%s \n\t\t\tBlood group:%s \n\t\t\tBatch:%s\n\t\t\tphone:%s\n\t\t\tEmail:%s\n",entry.name,entry.blood_group,entry.batch,entry.phone,entry.email);
            printf("\t\t============================================\n");
        }

    }
    menu();
}

void search(void)
{
    system("CLS");
    int fd;
    char bloodgroup[10];
    FILE *fp;
            fd=0;
            printf("\n\t\t\t\tSEARCH\n\t\t===========================================\n");
            fflush(stdin);
            printf("\t\t\tEnter any blood group: ");
            gets(search);
            int length=strlen(search);
            fp=fopen("bloodgroup.txt","r");

            system("CLS");
            printf("\n\t\t\tSEARCH result for %s\n\t\t=====================================",search);
            while(fread(&entry,sizeof(entry),1,fp)==1)
            {
                for(int i=0; i<=length; i++)
                {
                    bloodgroup[i]=entry.blood_group[i];
                    bloodgroup[length]='\0';
                }
                if(strcmp(bloodgroup,search)==0)
                {
                    printf("\n\t\t\tName:%s \n\t\t\tBlood group:%s \n\t\t\tBatch:%d\n\t\t\tphone:%d\n\t\t\tEmail:%s\n",entry.name,entry.blood_group,entry.batch,entry.phone,entry.email);
                    printf("\t\t============================================\n");
                    fd++;

                }

            }
            if(fd==0)
            {
                printf("no match\n");
            }
            else
            {
                printf("%d match\n",fd);
            }
            menu();
}

void aboutus(void)
{
    system("CLS");
        printf("\n\n\t\tABOUT US\n\t===========================================================");
        printf("\n\t\tName:Arif Ahmed Khan\n\t\tID:2231100642\n\t\tSECTION:9\n");
        printf("\n\n\t\t\tThis is a Blood Group Management Project\n\t===========================================================");
    menu();
}

void print_error(void)
{
    printf("\n\t\t\tError: Invalid option!\n");
}
