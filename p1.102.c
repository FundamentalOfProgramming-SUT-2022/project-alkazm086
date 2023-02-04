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
        char cmd_i[100];
        int p1=0;
        int p2=0;
        int w=0;
        char txtfile[10000];
        //char txtfile[10000];
        infun();
        //printf("%s\n", loc2);
        int a= str_length(loc2);
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
        //int k=0;
        for(int j=0;j<a;j++){
            cmd_insert[j]=loc2[j+w+5];
        }
        cmd_insert[a]='\0';
        int tmp_p=str_length(cmd_insert);
        //printf("%d\n", tmp_p);
        while(cmd_insert[tmp_p-1]!=':'){
            tmp_p --;
        }
            //insertstr -file /root/3.txt -str Salam -pos 54:19
            //printf("%d", tmp_p-1);//13
            tmp_p--;
            //printf("%d", tmp_p);
            //printf("%d", str_length(cmd_insert));//16
            int num=tmp_p;
            int todot=num;
            //printf("%d", num);//13
            while(num!=str_length(cmd_insert)-1 ){p1=(p1*10)+(cmd_insert[num+1]-48);num++;}
                //printf("%d", (cmd_insert[num]-48) );num++;}

        tmp_p=str_length(cmd_insert);//16
        while(cmd_insert[tmp_p-1]!=' '){
            tmp_p --;
        }
            //printf("%d", tmp_p);
            //printf("%c", cmd_insert[tmp_p+1]);
            num=tmp_p;
            while(num!=todot ){p2=(p2*10)+(cmd_insert[num]-48);num++;}

        //printf("%s\n", cmd_insert);
        //printf("%d\n", p1);//character
        //printf("%d\n", p2);//line


        for(int i=0;i<str_length(cmd_insert);i++){cmd_i[i]=cmd_insert[i];}
        int w_i=0;
        for(int i=0;i<str_length(cmd_insert);i++){
            if( (cmd_insert[i]== '-')&&(cmd_insert[i+1]== 'p')&&(cmd_insert[i+2]== 'o')&&(cmd_insert[i+3]== 's') ){
                cmd_i[i-1]= '\0';
                //printf("Hello");
                //printf("%d\n", i);
                w_i=i;
                break;
            }
        }

        for(int i=w_i;i<100;i++){cmd_i[i]='\0';}

        //printf("%s\n", cmd_i);



        /******************************************/

        FILE *ptr;
        int ja=0;
        int inter=0;
        int chofln=0;
        int chln[100];
        int charkolinter =-1;
            if( (ptr = fopen(loc2 , "r") ) != NULL){
                ptr = fopen(loc2 , "r");
                //printf("Hello");
                while(! feof(ptr)){

                    fscanf(ptr , "%c" , &txtfile[ja] );

                    chofln++;
                    charkolinter++;

                    if(txtfile[ja] == '\n'){
                        inter ++;
                        chln[inter]=chofln;
                        chofln=0;
                    }
                    ja++;
                }
                if(chofln!=0)chln[inter+1]=chofln;
                //printf("%d", charkolinter-inter);
                //printf("%d", ja);//ja=charkolinter-inter+1
                //line=inter+1
                //ch=ch-1
                fclose(ptr);
                if(p2>inter+1){printf("Out of range (line)!\n");}
                else if(p1>=chln[p2]){printf("out of range (character of line)!\n");}
                else{

                    ptr = fopen(loc2 , "w");
                    for(int r=0;r<charkolinter;r++){
                        //if( (r<)||(r>) ){fprintf(ptr , "%c" , txtfile[r]);}
                        //else if(1){}
                        //else{}
                        fprintf(ptr , "%c" , txtfile[r]);
                    }
                    /****************************************/
                    for(int r=0;r<100;r++){
                        //if( (r<)||(r>) ){fprintf(ptr , "%c" , txtfile[r]);}
                        //else if(1){}
                        //else{}
                        if(cmd_i[r]!='\0'){ fprintf(ptr , "%c" , cmd_i[r]);}
                        //else if(cmd_i[r+1]!='\0' || cmd_i[r+2]!='\0'){}
                        //else{break;}

                    }
                    //fprintf(ptr , "%c" , '8');

                    fclose(ptr);

                }
            }
        else{
            printf("No file with the given address exists!\n");
        }

        //printf("%d", chln[ 11 ]);
        /*if(p2>inter+1){printf("Out of range (line)!");}
        else if(p1>linechar){printf("out of range (character of line)!");}*/

        //for(int k=1;k<100;k++){printf("%c", txtfile[k]);}

        //printf("%d", inter);

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
