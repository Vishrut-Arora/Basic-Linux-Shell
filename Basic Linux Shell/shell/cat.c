#include<stdio.h>
#include <dirent.h>
#include<string.h>
#include<sys/dir.h>
#include <sys/stat.h>
#include<stdlib.h>
#include <signal.h>

int execute;
void trap(int signal){ execute = 0; }
int main()
{
    char arr[200];
    printf("Commands: cat > (file name)\ncat >> (file name)\ncat -n (filename)\ncat -E (filename)\n");
    fgets(arr,200,stdin);
    if(strstr(arr,"cat >> ") || strstr(arr,"cat > ")){
 
        char s[100]="";
        //printf("%s",&arr[7]);
        arr[strlen(arr)-1]='\0';
        int index=7;
        if(strstr(arr,"cat > ")){
            index=6;
        }
        char buff[10000];
    printf("Press ctrl+c to stop appending\n");    
for(int i=0;i<100;i++){
     FILE *fptr;
     fptr=fopen(&arr[index],"a");
        fgets(buff,sizeof(buff),stdin);
          fputs(buff,fptr);
          fclose(fptr);       
}

    }
    else if(strstr(arr,"cat -n ")){
     char buff[10000];
         FILE *fptr;
         
     arr[strlen(arr)-1]='\0';
     fptr=fopen(&arr[7],"r");       
    int c = 0;
     int count=0;

     while(c!=EOF){
         c=getc(fptr);
         ++count;
     }
     c=0;
     fclose(fptr);
         FILE *fptr2; 
         fptr2=fopen(&arr[7],"r");
         int check=0;
         int counter=1;
    while (c != EOF) 
    {  
        if(c==0){
        printf("1 %c", c);     
        }
        else if(c=='\n' &&(check!=(count-1)))
        {
            ++counter;
            printf("\n%d ",counter);
        }
        else {
        printf ("%c", c);
        } 
        c = fgetc(fptr2);
        ++check; 
    } 
    fclose(fptr2); 
    // }
    }
    else if(strstr(arr,"cat -E ")){
     FILE *fptr;
     char buff[10000];
     arr[strlen(arr)-1]='\0';
     fptr=fopen(&arr[7],"r");       
    int c = 0;
    while (c != EOF) 
    {  
        if(c=='\n' && (c)!=EOF&&(c+1)!=EOF)
        {
            printf("%s\n","$");
        }
        else {
        printf ("%c", c);
        } 
        c = fgetc(fptr); 
    } 
    fclose(fptr);        

    }
    else if(strcmp(arr,"cat -n\n")==0){
         int count=0;
         char buff[1000];
         while(1){
             ++count;
             fgets(buff,100,stdin);
             printf("\n     %d  %s",count,buff);
             //fflush(stdin);
         }
     }  
    else if(strcmp(arr,"cat -E\n")==0){
        
         char buff[1000];
         while(1){
        
             fgets(buff,100,stdin);
             printf("$%s",buff);
             //fflush(stdin);
         }
     }            
    else{
        printf("Syntax error");
        exit(0);
    }
    return 0;
}    