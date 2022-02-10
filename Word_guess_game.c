#include<stdio.h>
#include<string.h>
//#include<ctime>
#include<conio.h>
#include<windows.h>
#include<dos.h>
char word[100];
void get_caf_file(int rand){
    //printf("random =%d\n",rand);
    FILE *ptr;
    ptr=fopen("C:\\Users\\HP\\OneDrive\\Attachments\\mohimmmmm.txt","r");
    int i=1;
    while(i<rand){
        fscanf(ptr,"%s",word);
        i++;
    }
    //printf("func=%s  ",word);
    fclose(ptr);
}



void clrscr(){
    system("@cls||clear");
}
int main()
{

    ///initialize array with different word
    char s[25][20]= {"apple","ball","elegant","dragon","elephant","fruit","gorgeous","house","internet","mosque","canteen","stairs","balloon","tree","chair","table","facebook","dustbin","love","poetry","beauty","car","burger","digital","star"};

    play:
    printf("REMEMBER THE WORDS WITHIN 5 SECONDS\n\n");
    int a;
     int y,n;
    for ( a = 0; a<25; a++){
    printf("%s\n", s[a]);
    }
     for(n=0;n<100013;n++){
                for(y=0;y<10000;y++){

                }
            }

//delay(5000);
    clrscr();
    srand(time(NULL));
    printf("CHOOSE LEVEL \n1. EASY\n2. MEDIUM\n3. HARD\n");
    int level;
    scanf("%d",&level);
    getchar();
    int gridlimit;
    if(level==1)
    {
        gridlimit=10;
    }
    else if(level==2)
    {
        gridlimit=15;
    }
    else if(level==3)
    {
        gridlimit=20;
    }
    int h,k=0;
    for(h=0;h<10;h++){
    int c;
    ///declare 2d array of haracters for puzzle box
    char m[gridlimit][gridlimit];
    ///initialize each index with an alphabet with rand() function
    ///rand function generates random numbers but we need alphabet...so will give some condition
    int i,j;
    for ( i=0; i<gridlimit; i++)
    {
        for(j=0; j<gridlimit; j++)
        {
                m[i][j]=( rand() % 26 )+ 'a';
        }
    }
    ///randomly choose a position from puzzle word and set the string there vertically or horizntally
    ///if length of word is odd==horizontal else vertical
    //int p=rand()%25; ///generated an index between 1 and 10. Change this if u change the no of words
    int row,col;
    char l[100];

    get_caf_file(rand()%25);
    //printf("%s",word);

    for(i =0; i<strlen(word);i++){
        l[i] = word[i];
    }
   l[i] = '\0';
   //printf("asd=%s",l);

    //int len=strlen(l); ***THIS LINE USED TO CHECK WHETHER THE WORD LENGTH IS EVEN OR ODD. IF ODD, PUT HORIZONTALLY, IF EVEN, VERTICALLY
    //Now replacing this with a  random number generator so that horizontal and vertical will not depend on word length
    int len = rand() % 2;
    if(len%2!=0)
    {
        row=rand()%gridlimit;
        col=rand()%3;
        for(c=0; word[c]!='\0'; c++,col++)
        {
            m[row][col]=word[c];
        }
    }
    else
    {
        col=rand()%gridlimit;
        row=rand()%3;
        for(c=0; word[c]!='\0'; c++,row++)
        {
            m[row][col]=word[c];
        }
    }
    //delay(2000);

    ///print the puzzle box
    printf("\n\t");

    for ( i=0; i<gridlimit; i++)
    {
        for(j=0; j<gridlimit; j++)
        {
            printf("%c ",m[i][j]);

        }
        printf("\n\t");
    }
    printf("Enter the word you guess the word should be of %d length : ",strlen(word) ); ///prob
    char guess[100];

    int chance = 3;
    guessing:
    gets(guess);

    //printf("////%s\n",guess);
    if(strcmp(guess, word) == 0){
        printf("\aYOU WON\n");
        for(n=0;n<100000;n++){
                for(y=0;y<10000;y++){

                }
            }
        k++;

    }
    else
    {
        if(chance == 3){
            printf("Wrong answer! Try again\n");
            chance--;
            goto guessing;
        }else if(chance == 2){
            printf("Wrong again! Try harder\n");
            chance--;
            goto guessing;
        }else if(chance == 1){

            printf("Last chance\n");
            chance--;
            goto guessing;
        }else if(chance == 0){

            printf("FAILED!!!!\n");
            //delay(2000);
            clrscr();
           // printf(" ***   ***  *   * *****   ");       printf(" ***  *   * ***** ***** \n");
           // printf("*   * *   * ** ** *       ");       printf("*   * *   * *     *   * \n");
            //printf("*  ** ***** * * * ***     ");       printf("*   * *   * ***   ***** \n");
           // printf("*   * *   * *   * *       ");       printf("*   *  * *  *     *  *  \n");
           // printf(" ***  *   * *   * *****   ");       printf(" ***    *   ***** *   * \n\n\n");
//delay(1500);

            printf("THE ANSWER IS %s",word);
            for(n=0;n<100000;n++){
                for(y=0;y<10000;y++){

                }
            }

        }

    }
    clrscr();
    }
    printf("Your total score is: %d\n",k);
    printf("\n\nPlay again??? Y/N:  ");
    char ch = getchar();
    if(ch == 'Y' || ch == 'y'){
    clrscr();
        goto play;
    }
      //clrscr();
    else if(ch == 'N' || ch == 'n') return 0;

}

