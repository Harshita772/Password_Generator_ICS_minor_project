#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

int strength(char *password, int len){

    // initialize all values to zero
    int num=0;
    int lower=0;
    int upper=0;
    int charac=0;
    int nota=0;

    int count[5];
    // to check the number of characters of each category entered by the user
    for(int i=0; i<len; i++)
    {
        if(password[i]>='0' && password[i]<='9')
        {
            num++;
        }
        else if(password[i]>='A' && password[i]<='Z')
        {
            upper++;
        }
        else if(password[i]>='a' && password[i]<='z')
        {
            lower++;
        }
        else if (password[i]=='-' || password[i]=='#' || password[i]=='+' || password[i]=='?' || password[i]=='@' || password[i]==')' || password[i]=='!' || password[i]=='=' 
                || password[i]=='$' || password[i]=='(' || password[i]=='*' || password[i]=='|' || password[i]=='&' || password[i]=='_' || password[i]=='~' || password[i]=='`'
                || password[i]=='.' || password[i]=='/' || password[i]==':'|| password[i]==';' || password[i]==',')
        {
            charac++;
        }
        else{
            nota++;
        }
    }

    count[0]=num;
    count[1]=upper;
    count[2]=lower;
    count[3]=charac;

    int type=0;

    for(int i=0; i<4; i++)
    {
        if(count[i]!=0)
        {
            type++;
        }
        
    }
    
    // calculating strength of password
    if(nota!=0){
        return -1;
    }

    else if(type==1){
        return 40;
    }
    else if(type==2){
        return 55;
    }
    else if(type==3){
        return 70;
    }
    else if(charac==1 && upper>=1){
        return 80;
    }
    int more_than_one_num=(num>=2);
    int more_than_one_lower = (lower >= 2); 
    int more_than_one_upper = (upper >= 2);
    int more_than_one_char = (charac >= 2);
    if(more_than_one_char && more_than_one_lower && more_than_one_num && more_than_one_upper)
        return 100;
    else 
        return 95;
}

// To swap the characters 
void swap(char *a,char *b){
    char temp=*a;
    *a=*b;
    *b=temp;
}

void create_password(int len){
    //arrays for different sets of characters
    char number[]="0123456789";
    char lower[]="abcdefghijklmnopqrstuvwxyz";
    char upper[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char charac[]="!@#?-+=*|&_~`.()$/,;:";

    char password[len];
    int x=0;
    for (int i=0; i<6; i++)
    {
        password[x++]=number[rand()%10];
        password[x++]=lower[rand()%26];
        password[x++]=upper[rand()%26];
        password[x++]=charac[rand()%21];
    }

    // to arrange array
    for (int i=len-1; i>0; i--)
    {
        int a=rand()%(i+1);
        swap(&password[i],&password[a]);
    }
    
    printf("\n Suggested 100%% strong password: ");
    for(int i=0;i<len;i++)
    {
        printf("%c",password[i]);
    }
    printf("\n\n");

}

int main()
{
    system("cls");                   // to clear the screen each time the program is run
    char user_password[100];
    printf("Hi! Welcome to random password generator.\n");
    printf("\n This program will calculate the strength of your password, and also suggest a randomly generated 100%% strength password.");
    
    //labelled as repeat
    repeat:
    printf("\n The entered password should not contain the following characters:");
    printf("\n '%%','\\','{','}','[',']','^'");
    printf("\n The password should contain at least more than 4 characters.");  
    printf("\n Enter your password: "); 
    scanf("%s",user_password);

    if(strlen(user_password)<4)
    {
        printf("\n The password should be at least 4 characters long.\n\n");
        goto repeat;   //go to starting point
    }

    int choice;
    //labelled as menu
    menu:
    printf("1) Calculate strength of given password.\n");
    printf("2) Suggest a 100%% strong password.\n");
    printf("3) Exit the program.\n");
    
    printf("Enter your choice:");
    scanf("%d",&choice);

    if (choice==1)
    {
        int final_strength;
        final_strength=strength(user_password,strlen(user_password));

        if(final_strength != -1) 
        {    printf("\n Strength of your password is: %d%%\n\n", final_strength);
             goto menu;    //go to staring point
        }
        else 
        {
            printf("\n Invalid password.\n\n");
            goto repeat;    //go to starting point
        }

        if(final_strength == 100) 
        {    
            printf("\n Great! Your password is 100%% strong.\n\n");
            goto menu;      //go to main 'menu'
        }
    }
    if (choice==2)
    {
        int final_strength;
        final_strength=strength(user_password,strlen(user_password));
        if(final_strength!=100)
        {
            srand((unsigned int)(time(NULL))); 
            create_password(strlen(user_password));
            goto menu;    //go to main 'menu'
        }
        else{
            printf("Your password is already strong enough.\n");
        }
    }
    if (choice==3)
    {
        printf("Program terminated successfully!");
        exit(0);
    }
    else{
        printf("Please enter a number between 1-3\n\n");
        goto menu;
    }
    printf("\n");
    return 0; 
}
