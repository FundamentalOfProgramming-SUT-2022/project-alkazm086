#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>


    char loc2[100];

    //int length = str_length(str);
    int str_length(char str[]) {
        int count;
        for (count = 0; str[count] != '\0'; ++count);

        return count;
    }



    void infun(){

        char s_g , tmploc , op_file[5];
        int i = 0;
        FILE *file;
        scanf("%s" , op_file);
        getchar();//for space
        scanf("%c" , &s_g);// / OR "
        //printf("\n * %s * %c \n", op_file, s_g );
        if(s_g == '"'){
            getchar();//for frist /
        }

        while(1){
            scanf("%c" , &tmploc);
            if(tmploc == '/'){//for each dir
                mkdir(loc2);
                loc2[i] = '/';
                i++;
            }
            else if(tmploc == '\n'){//for end
                loc2[i] = '\0';
                break;//To not scan more
            }
            else if(tmploc == '"');//for ignore "
            else{//for tmploc-->loc2;
                    loc2[i]=tmploc;
                i++;
            }
        }
        return;
    }



    void creatfile(){
        char s_g , loc[100], tmploc , op_file[5];
        int i = 0;
        FILE *file;
        scanf("%s" , op_file);
        getchar();//for space
        scanf("%c" , &s_g);// / OR "
        //printf("\n * %s * %c \n", op_file, s_g );
        if(s_g == '"'){
            getchar();//for frist /
        }

        while(1){
            scanf("%c" , &tmploc);
            if(tmploc == '/'){//for each dir
                mkdir(loc);
                loc[i] = '/';
                i++;
            }
            else if(tmploc == '\n'){//for end
                loc[i] = '\0';
                break;//To not scan more
            }
            else if(tmploc == '"');//for ignore "
            else{//for tmploc-->loc;
                    loc[i]=tmploc;
                i++;
            }
        }

        if( (file = fopen(loc , "r") != NULL) ){
            printf("This file already exists!\n");
        }
        else{
            FILE *ptr = fopen(loc , "w");
            fclose(ptr);
            printf("The file was created.\n");
        }
        return;
    }


    void insertstr(){
        char cmd_insert[100];
        int w=0;
        infun();
        //printf("%s\n", loc2);
        for(int i=0;i<str_length(loc2);i++){
            if( (loc2[i]== '-')&&(loc2[i+1]== 's')&&(loc2[i+2]== 't')&&(loc2[i+3]== 'r') ){
                loc2[i-1]= '\0';
                //printf("Hello");
                //printf("%d\n", i);
                w=i;
                break;
            }
        }
        //printf("%s\n", loc2);
        for(int j=0;j<(str_length(loc2)-w-5);j++){
            cmd_insert[j]=loc2[w+1];
        }

        printf("%s\n", cmd_insert);

        return;
    }


    int main(){

        char cmd[100];
        char last;

        while(1){

            scanf("%s" , cmd);
            last = getchar(); // space OR \n

            if(strcmp(cmd , "creatfile") == 0){creatfile();}
            else if(strcmp(cmd , "insertstr") == 0){insertstr();}
            else if(strcmp(cmd , "exit") == 0){break;}
            else{
                if(last == '\n') printf("invalid command!\n");
            }

        }

    return 0;
    }
