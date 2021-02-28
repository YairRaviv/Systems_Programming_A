#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE 256
#define WORD 30

int similar(char *str1,char *str2);
void case_A(char text[],char word[]);
void case_B(char text[],char word[]);


    void case_A(char text[],char word[])
    {
       char *sep =NULL;
       sep=strtok(text, "\n");
       while(sep!=NULL)
       {
           char tmp[strlen(sep)];
           strcpy(tmp,sep);
           if(strstr(tmp,word)!=NULL)
           {
               printf("%s\n",tmp);
           }
           sep= strtok(NULL, "\n");
       }
    }

    void case_B(char text[],char word[])
    {
       char *sep =NULL;
       sep=strtok(text, "\n \t");
       while(sep!=NULL)
       {
           char tmp[strlen(sep)];
           strcpy(tmp,sep);
           int flag=similar(tmp,word);
          if(flag)
          {
              printf("%s\n",tmp);
          }
           sep=strtok(NULL, "\n \t");
       }
       
    }
        
        int similar(char *str1,char *str2)
    {
        

        if(strlen(str1)-strlen(str2)!=0&&strlen(str1)-strlen(str2)!=1&&strlen(str1)-strlen(str2)!=2)return 0;
         if(strlen(str1)-strlen(str2)==2)
          {
              if(str1[strlen(str1)-1]!='\t'&&str1[strlen(str1)-1]!='\n'&&str1[strlen(str1)-1]!=' '&&str1[strlen(str1)-1]!=' '&&str1[strlen(str1)-1]!='\r')return 0;
          }
        if(strlen(str1)==strlen(str2))
        {
            if(str1[strlen(str1)-1]=='\t'||str1[strlen(str1)-1]=='\n'||str1[strlen(str1)-1]==' '||str1[strlen(str1)-1]==' '||str1[strlen(str1)-1]=='\r')return 0;
        }


           int flag;
           if(str1[strlen(str1)-1]!='\t'&&str1[strlen(str1)-1]!='\n'&&str1[strlen(str1)-1]!=' '&&str1[strlen(str1)-1]!=' '&&str1[strlen(str1)-1]!='\r')flag=2;
           else flag=3;
           int c1=0;
           int c2=0;
           while(c1<strlen(str1)&&c2<strlen(str2))
           {
               if(flag==0)return 0;
               if(str1[c1]==str2[c2])
               {
                   c1++;
                   c2++;
               }
               else
               {
                   flag--;
                c1++;
                   
               }
           }
          
               if(flag>0)return 1;
           
           
        
        
        return 0;
    }


int main()
{
    char word[30];
    for(int i=0;i<30;i++)
    {
       char tmp;
       scanf("%c",&tmp);
       if(tmp==' '||tmp=='\t')
       {
           break;
       }
       else
       {
           word[i]=tmp;
           tmp='\0';
       }
       
    }
    char operation;
    scanf("%c",&operation);
    char b;
    scanf("%c",&b);
    scanf("%c",&b);
   
    char text[64000];
    for(int i=0;i<64000;i++)
    {
        char tmp;
        scanf("%c",&tmp);
        text[i]=tmp;
        tmp='\0';
    }

    switch (operation)
    {
        case 'a':
        {
           case_A(text,word);
           break;
        }
        case 'b':
        {
            case_B(text,word);
            break;
        }
         default:
         {
             printf("error");
             break;
         }
    }

    return 0;
    
    



}

