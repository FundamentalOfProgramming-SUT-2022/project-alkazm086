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
            else if(tmploc == ' '){//for end
                char t[100];
                scanf("%s", t);
                if(strcmp(t , "-str") == 0){loc2[i] = '\0'; insertstr();break;}
                else {
                    for(int j=0;j<str_length(t);j++){
                        loc2[i+j]=t[j];
                    }
                }
                //break;//To not scan more
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


    insertstr(){

        //infun();
        printf("%s", loc2);

    }


    int main(){

        char cmd[100];
        char last;

        while(1){

            scanf("%s" , cmd);
            last = getchar(); // space OR \n

            if(strcmp(cmd , "creatfile") == 0){creatfile();}
            else if(strcmp(cmd , "insertstr") == 0){infun();}
            else if(strcmp(cmd , "exit") == 0){break;}
            else{
                if(last == '\n') printf("invalid command!\n");
            }

        }

    return 0;
    }
