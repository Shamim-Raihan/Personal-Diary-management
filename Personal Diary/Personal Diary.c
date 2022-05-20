#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<ctype.h>
FILE *pagedate;
FILE *pagesub;
FILE *pagestory;
FILE *position;
FILE *frem;
int pos=0,po=1,npos=1;
void new_page(int b)
{
    pos++;
    const int buf_size = 20;
    char buf[buf_size];
    int ret = snprintf(buf, buf_size, "date_%d.txt", b);
    pagedate = fopen(buf, "w");
    int date;
    printf("Enter Date:");
    scanf("%d",&date);
    fprintf(pagedate,"%d",date);
    fclose(pagedate);

    ret = snprintf(buf, buf_size, "sub_%d.txt", b);
    pagesub = fopen(buf, "w");
    char sub[20];
    printf("Enter Subject:");
    scanf("%s",&sub);
    fprintf(pagesub,"%s",sub);
    fclose(pagesub);

    ret = snprintf(buf, buf_size, "story_%d.txt", b);
    pagestory = fopen(buf, "w");
    char story[200];
    printf("Enter Story:");
    scanf("%s",&story);
    fprintf(pagesub,"%s",story);
    fclose(pagestory);
    position=fopen("posit.txt","w");
    fprintf(position,"%d",pos);
    fclose(position);
    system("cls");

}
void addstory(int a)
{

    int pc;
    printf("Enter Page No:");
    scanf("%d",&pc);
    const int buf_size = 20;
    char buf[buf_size];
    for (int i = 0; i < a; i++)
    {
        if(i==pc-1)
        {
            int ret = snprintf(buf, buf_size, "story_%d.txt", i);
            pagestory = fopen(buf, "a");
            char story[200];
            printf("Start writing Here:");
            scanf("%s",&story);
            fprintf(pagestory,"%s",story);
        }
        fclose(pagestory);
    }
    system("cls");
}
void wnew_page(int tpos)
{
    while(1)
    {
        int echo;
        printf("1:continue\n2:Exit To Main Menu\n");
        scanf("%d",&echo);
        if(echo==1)
        {
            int a;
            printf("Enter Page Number :");
            scanf("%d",&a);
            const int buf_size = 20;
            char buf[buf_size];
            for (int i = 0; i <= tpos; i++)
            {
                if(i==a-1)
                {
                    int chop;
                    printf("1:Edit Subject\n2:Edit Story\n");
                    scanf("%d",&chop);
                    if(chop==1)
                    {
                        int ret = snprintf(buf, buf_size, "sub_%d.txt", i);
                        pagesub = fopen(buf, "w");
                        char sub[10];
                        scanf("%s",&sub);
                        fprintf(pagesub,"%s",sub);
                        fclose(pagesub);
                    }
                    else if(chop==2)
                    {
                        int ret = snprintf(buf, buf_size, "story_%d.txt", i);
                        pagestory = fopen(buf, "w");
                        char story[200];
                        scanf("%s",&story);
                        fprintf(pagestory,"%s",story);
                        fclose(pagestory);
                    }
                }
                //else
                //  printf("Page Not Found!\n");
            }
        }
        else if(echo==2)
            break;
        else
            printf("Wrong Input\n");
    }
    system("cls");
}
void showall_sub(int tpos)
{
    printf("\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\ MAIN INDEX \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
    const int buf_size = 20;
    char buf[buf_size];
    for (int i = 0; i < tpos; i++)
    {
        int ret = snprintf(buf, buf_size, "sub_%d.txt", i);
        pagesub = fopen(buf, "r");
        char sub[20];
        fscanf(pagesub,"%s",&sub);
        if(pagesub==NULL)
            printf("\t\t\t\t\t  -------!You Deleted This Page!-------\n");
        else
        {
            printf("\t\t\t\t\t-----------------------------------------\n");
            printf("\t\t\t\t\tPage: %d \t  \tSubject:  %s\n",i+1,sub);
        }
        fclose(pagesub);
    }
}
void searcg_page(int a)
{
    printf("***********************************************************************************************************\n");
    loaderSRP();
    system("cls");
    system("color 9");
    int d,chds;
    char subj[10];
    const int buf_size = 20;
    char buf[buf_size];
    printf("1:Search by Page\t2:Search by Subject\n3:Exit\n");
    while(1)
    {
        scanf("%d",&chds);
        if(chds==1)
        {
            printf("Enter Page No:\n");
            scanf("%d",&d);
            for (int i = 0; i < a; i++)
            {
                if(i==d-1)
                {
                    int ret = snprintf(buf, buf_size, "story_%d.txt", i);
                    pagestory = fopen(buf, "r");
                    char story[200];
                    fgets(story,200,pagestory);

                    ret = snprintf(buf, buf_size, "sub_%d.txt", i);
                    pagesub = fopen(buf, "r");
                    char sub[20];
                    fscanf(pagesub,"%s",&sub);

                    ret = snprintf(buf, buf_size, "date_%d.txt", i);
                    pagedate = fopen(buf, "r");
                    int date;
                    fscanf(pagedate,"%d",&date);
                    if(pagedate==NULL && pagesub==NULL && pagestory==NULL)
                        printf("----------------------------------------.......!YOU DELETED EVERYTHING FROM THIS PAGE......---------------------------\n");
                    else if(pagedate==NULL && pagesub==NULL)
                        printf("------------------------------------- .......!YOU DELETED DATE & SUBJECT FROM THIS PAGE......-------------------------\n");
                    else if(pagedate==NULL && pagestory==NULL)
                        printf("------------------------------------- .......!YOU DELETED DATE & STORY FROM THIS PAGE......---------------------------\n");
                    else if(pagesub==NULL && pagestory==NULL)
                        printf("------------------------------------ .......!YOU DELETED SUBJECT & STORY FROM THIS PAGE......-------------------------\n");
                    printf("----------------------------------------------------------------------------------------------------------------------\n");
                    printf("                                                     Date:%d/11/2019              \n",date);
                    printf("----------------------------------------------------------------------------------------------------------------------\n");
                    printf("-\n");
                    printf("----------------------------------------------------------------------------------------------------------------------\n");
                    printf("-                                                    Sub:%s                                          \n",sub);
                    printf("----------------------------------------------------------------------------------------------------------------------\n");
                    printf("-\n");
                    printf("- Full Story:%s\n",story);
                    printf("-\n");
                    printf("-\n");
                    printf("-\n");
                    printf("-\n");
                    printf("-\n");
                    printf("-\n");
                    printf("----------------------------------------------------------------------------------------------------------------------\n");
                }
            }
            fclose(pagestory);
            fclose(pagesub);
            fclose(pagedate);
        }

        else if(chds==2)
        {
            printf("Enter Subject Name: \n");
            scanf("%s",&subj);
            for (int i = 0; i < a; i++)
            {
                int ret = snprintf(buf, buf_size, "story_%d.txt", i);
                pagestory = fopen(buf, "r");
                char story[200];
                fgets(story,200,pagestory);
                fclose(pagestory);

                ret = snprintf(buf, buf_size, "sub_%d.txt", i);
                pagesub = fopen(buf, "r");
                char sub[20];
                fscanf(pagesub,"%s",&sub);
                int chks=strcmp(subj,sub);
                if(chks==1)
                {
                    printf("%s\n",story);
                    break;
                }
            }
            fclose(pagesub);
        }

        else if(chds==3)
            break;
        else
            printf("Wrong Keyword\n");
    }
    system("cls");
}

void loaderSRP()
{
    int i;
    system("cls");
    printf("\nLoading Pages...");
    for(i=0; i<50; i++)
    {
        Sleep(20);
        printf("%c",219);
    }
}

void delsub(int a,int sel)
{
    const int buf_size = 20;
    char buf[buf_size];
    for (int i = 0; i < a; i++)
    {
        int ret = snprintf(buf, buf_size, "sub_%d.txt", i);
        if(i==sel-1)
        {
            remove(buf);
        }
        fclose(pagesub);
    }

}
void deldate(int a,int sel)
{
    const int buf_size = 20;
    char buf[buf_size];
    for (int i = 0; i < a; i++)
    {
        int ret = snprintf(buf, buf_size, "date_%d.txt", i);
        if(i==sel-1)
        {
            remove(buf);
        }
        fclose(pagesub);
    }


}
void delstory(int a,int sel)
{
    const int buf_size = 20;
    char buf[buf_size];
    for (int i = 0; i < a; i++)
    {
        int ret = snprintf(buf, buf_size, "story_%d.txt", i);
        if(i==sel-1)
        {
            remove(buf);
        }
        fclose(pagesub);
    }

}

void graph(int a)
{
    while(1)
    {
        loaderG();
        system("cls");
        printf("\n\nSuccessfully Graph Opened\n\n");
        system("color 9");
        printf("\n\nGRAPH\n");
        const int buf_size = 20;
        char buf[buf_size];
        int i,ar[200],max,min,pag,pagn;
        for (i = 0; i < a; i++)
        {
            int ret = snprintf(buf, buf_size, "story_%d.txt", i);
            pagestory = fopen(buf, "r");
            char story[200];
            fgets(story,200,pagestory);
            int len=strlen(story);
            ar[i]=len;
            for(int j=0; j<len; j++)
            {
                printf("%c",219);
            }
            printf("-Page:%d\n\n",i+1);
            fclose(pagestory);
        }
        max=ar[0];
        min=ar[0];
        for ( i = 0; i < a; i++)
        {
            if(max<ar[i])
            {
                max=ar[i];
                pag=i;
            }
            else if(max==ar[i])
            {
                max=ar[i];
                pag=i;
            }
            if(min>ar[i])
            {
                min=ar[i];
                pagn=i;
            }

        }
        int ret = snprintf(buf, buf_size, "date_%d.txt", pag);
        pagedate = fopen(buf, "r");
        int date;
        fscanf(pagedate,"%d",&date);
        printf("You Wrote Most In: %d/11/2019\n",date);
        fclose(pagedate);

        ret = snprintf(buf, buf_size, "date_%d.txt", pagn);
        pagedate = fopen(buf, "r");
        int date2;
        fscanf(pagedate,"%d",&date2);
        printf("You Wrote Least In: %d/11/2019\n",date2);
        fclose(pagedate);
        printf("Biggest Story In Page:%d\n",pag+1);
        printf("Smalest Story In Page:%d\n",pagn+1);
        printf("\t\tClick 1 to Exit to Main Menu :  ");
        int click;
        scanf("%d",&click);
        if(click==1)
            break;
        else
            printf("Worng click\n");
    }
    system("cls");

}

void specialpagecre()
{
    loaderSC();
    system("cls");
    printf("\n\nWrite A Hidden Page\n\n");
    system("color 9");
    int crep;
    printf("Enter A Page No As Your Wish:");
    scanf("%d",&crep);
    int b=crep;
    const int buf_size = 20;
    char buf[buf_size];
    int ret = snprintf(buf, buf_size, "dat_%d.txt", b);
    pagedate = fopen(buf, "w");
    int dat;
    printf("Enter Date:");
    scanf("%d",&dat);
    fprintf(pagedate,"%d",dat);
    fclose(pagedate);

    ret = snprintf(buf, buf_size, "su_%d.txt", b);
    pagesub = fopen(buf, "w");
    char su[20];
    printf("Enter Subject:");
    scanf("%s",&su);
    fprintf(pagesub,"%s",su);
    fclose(pagesub);

    ret = snprintf(buf, buf_size, "stor_%d.txt", b);
    pagestory = fopen(buf, "w");
    char stor[200];
    printf("Enter Story:");
    scanf("%s",&stor);
    fprintf(pagestory,"%s",stor);
    fclose(pagestory);
}
void showspepages()
{
    loaderSP();
    system("cls");
    printf("\n\n-----Remember Page Number-----\n\n");
    system("color 9");
    int chosp;
    printf("Enter Page No:");
    scanf("%d",&chosp);
    const int buf_size = 20;
    char buf[buf_size];
    for (int i = 0; i < 100; i++)
    {
        int ret = snprintf(buf, buf_size, "su_%d.txt", i);
        pagesub = fopen(buf, "r");
        char su[20];
        fscanf(pagesub,"%s",&su);

        ret = snprintf(buf, buf_size, "stor_%d.txt", i);
        pagestory = fopen(buf, "r");
        char stor[200];
        fgets(stor,200,pagestory);

        ret = snprintf(buf, buf_size, "dat_%d.txt", i);
        pagedate = fopen(buf, "r");
        int dat;
        fscanf(pagedate,"%d",&dat);
        if(chosp==i)
        {
            printf("----------------------------------------------------------------------------------------------------------------------\n");
            printf("                                                     Date:%d/11/2019              \n",dat);
            printf("----------------------------------------------------------------------------------------------------------------------\n");
            printf("-\n");
            printf("----------------------------------------------------------------------------------------------------------------------\n");
            printf("-                                                    Sub:%s                                          \n",su);
            printf("----------------------------------------------------------------------------------------------------------------------\n");
            printf("-\n");
            printf("- Full Story:%s\n",stor);
            printf("-\n");
            printf("-\n");
            printf("-\n");
            printf("-\n");
            printf("-\n");
            printf("-\n");
            printf("----------------------------------------------------------------------------------------------------------------------\n");
        }
    }
    fclose(pagesub);
    fclose(pagestory);
    fclose(pagedate);

}



void menu()
{
    loaderM();
    system("cls");
    printf("\n\nMain Menu Opened\n\n");
    system("color 9");
    int tpos;
    position=fopen("posit.txt","r");
    fscanf(position,"%d",&pos);
    tpos=pos;

    printf("                                                                                                      There is %d pages\n",tpos);

    int cho;

    while(1)
    {
        showall_sub(tpos);
        printf("--------------------------------------------------------------------------------------------------------------------\n");
        printf("1:Start Writing Todays Note\n2:Edit Info\n3:Search Page Info\n4:Delet\n");
        printf("5:Show Graph\n6:Add Story In Previous Page\n7:Special Pages\n8:Change Pass or G-mail\n");
        printf("9:Log Info\n10:Exit\n");
        printf("Enter your choice :  ");
        scanf("%d",&cho);
        if(cho==1)
            new_page(tpos);
        else if(cho==2)
            wnew_page(tpos);
        else if(cho==3)
            searcg_page(tpos);
        else if(cho==4)
        {
            while(1)
            {
                int del,sel;
                printf("1:Delete Full Page\n2:Delete a item\n3:Exit\n");
                scanf("%d",&del);
                if(del==1)
                {
                    printf("Enter Page Number:");
                    scanf("%d",&sel);
                    delsub(tpos,sel);
                    deldate(tpos,sel);
                    delstory(tpos,sel);
                    printf("Page %d Deleted\n",sel);
                }
                else if(del==2)
                {
                    int spd;
                    printf("1:Delete Date\t2:Delete sub\t3:Delete Story\n4:Exit\n");
                    while(1)
                    {
                        scanf("%d",&spd);
                        if(spd==1)
                        {
                            delsub(tpos,sel);
                        }
                        else if(spd==2)
                        {
                            deldate(tpos,sel);
                        }
                        else if(spd==3)
                        {
                            delstory(tpos,sel);
                        }
                        else if(spd==4)
                            break;
                        else
                            printf("Wrong\n");
                    }
                }
                else if(del==3)
                    break;
            }
        }
        else if(cho==5)
            graph(tpos);
        else if(cho==6)
            addstory(tpos);
        else if(cho==7)
        {
            int chopa;
            while(1)
            {
                printf("1:Create Page as your wish\n2:Show Special Index\n3:Exit\n");
                scanf("%d",&chopa);
                if(chopa==1)
                    specialpagecre();
                else if(chopa==2)
                    showspepages();
                else if(chopa==3)
                    break;
                else
                    printf("Wrong Keyword\n");
            }
            system("cls");
        }
        else if(cho==8)
        {
            FILE *file;
            char ch[100];
            char pass[50];
            file = fopen("file 3.text","w");
            printf("\t\tEnter New E-mail :  ");
            scanf("%s",&ch);
            printf("\t\tEnter New password :  ");
            scanf("%s",&pass);
            fprintf(file,"%s \n%s",ch,pass);
            printf("\t\tPassword And g-mail changed successfully\n");
            system("cls");
            fclose(file);

        }
        else if(cho==9)
        {
            while(1)
            {
                int lch;
                printf("1:Remember Me\n2:Forget me\n3:Exit\n");
                scanf("%d",&lch);
                if(lch==1)
                    remembr();
                else if(lch==2)
                    forget();
                else if(lch==3)
                    break;
                else
                    printf("Wrong Keyword\n");
            }
            system("cls");
        }
        else if(cho==10)
            break;
        else
            printf("Wrong Keyword\n");
    }
    system("cls");

}


void sign_up()
{
    char ch[100];
    char pass[50];

    FILE *file;
    file = fopen("file 3.text","w");
    printf("\t\tEnter your E-mail :  ");
    scanf("%s",&ch);
    printf("\t\tEnter your password :  ");
    scanf("%s",&pass);
    fprintf(file,"%s \n%s",ch,pass);
    printf("\t\tSign up successfully\n");
    system("cls");
    fclose(file);
    menu();
}
void forget()
{
    int rem=0;
    frem=fopen("rm.txt","w");
    fprintf(frem,"%d",rem);
}

void remembr()
{
    int rem=2;
    frem=fopen("rm.txt","w");
    fprintf(frem,"%d",rem);
}

void login()
{
    FILE *file;
    file = fopen("file 3.text","r");
    char cha[100];
    char ch[50];
    char pass[50];
    printf("\t\tEnter your E-mail :  ");
    scanf("%s",&ch);

    char a[50];
    printf("\t\tEnter your password :  ");
    scanf("%s",&a);
    fscanf(file,"%s",&cha);
    fscanf(file,"%s",&pass);
    if(strcmp(cha,ch)==0 && strcmp(a,pass)==0)
    {
        printf("\t\tLogin successfully\n");
    }
    else
    {
        while(1)
        {
            system("cls");
            printf("\t\tincorrect username or password....\n");

            FILE *file;
            char newc[50];
            char newch[50];
            file = fopen("file 3.text","r");
            fscanf(file,"%s",&newc);
            fscanf(file,"%s",&newch);

            char d[50];
            char c[50];
            printf("\t\tEnter your E-mail :  ");
            scanf("%s",&d);

            printf("\t\tEnter your password :  ");
            scanf("%s",&c);
            if(strcmp(d,newc)==0 && strcmp(c,newch)==0)
            {
                printf("\t\tLogin successfully\n");
                break;
            }


            else
            {
                continue;
            }
        }
        system("cls");

    }
    fclose(file);

    menu();

}

void loaderSC()
{
    int i;
    system("cls");
    printf("\nWait...");
    for(i=0; i<50; i++)
    {
        Sleep(20);
        printf("%c",219);
    }
}


void loaderG()
{
    int i;
    system("cls");
    printf("\nLoading Graph...");
    for(i=0; i<50; i++)
    {
        Sleep(20);
        printf("%c",219);
    }
}


void loaderSP()
{
    int i;
    system("cls");
    printf("\nSpecial pages Loading...");
    for(i=0; i<50; i++)
    {
        Sleep(20);
        printf("%c",219);
    }
}


void loaderM()
{
    int i;
    system("cls");
    printf("\nOpening Main Menu...");
    for(i=0; i<50; i++)
    {
        Sleep(20);
        printf("%c",219);
    }
}

void loader()
{
    int i;
    system("cls");
    printf("\nOpening Diary...");
    for(i=0; i<50; i++)
    {
        Sleep(80);
        printf("%c",219);
    }
}

main()
{

    loader();
    system("cls");

    printf("************************************************************************\n");
    printf("* * ***** * **          ** * ***** * **         **         ** ******* **\n");
    printf("* ** *** ** ** *********** ** *** ** ** ******* ** ******* *** ***** ***\n");
    printf("* *** * *** ** *********** *** * *** ** ******* ** ****** ***** *** ****\n");
    printf("* **** **** **          ** **** **** ** ******* **       ******** ******\n");
    printf("* ********* ** *********** ********* ** ******* ** **** ********* ******\n");
    printf("* ********* ** *********** ********* ** ******* ** ****** ******* ******\n");
    printf("* ********* **          ** ********* **         ** ******* ****** ******\n");
    printf("************************************************************************\n");
    printf("\nCreate A Life!\n");

    printf("\n\nDiary Opened\n\n");



    frem=fopen("rm.txt","r");
    int rim;
    fscanf(frem,"%d",&rim);
    if(rim==2)
    {
        menu();
        system("cls");



    }



    else
    {


        while(1)
        {
            printf("\t\t1. Sign Up\n\t\t2. Login\n\t\t3. Close\n");
            int test;
            printf("\t\tEnter your choice :  ");
            scanf("%d",&test);
            system("cls");
            if(test==1)
            {
                sign_up();
            }
            else if(test==2)
            {
                login();
            }
            else if(test==3)
                break;
            else
            {
                printf("\t\tInvalid choice.....\n");

            }
        }
        system("cls");
    }
}




