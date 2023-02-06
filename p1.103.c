#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>


    char loc2[100], clip[100];
    char alltxt[100][1000];
    int d2=0;
    int gio=0;// \"
    int gio2=0;// "
    int inter1=0;// \n
    int inter2=0;// \\n
    //int rcp=0;

    //int length = str_length(str);
    int str_length(char str[]) {
        int count;
        for (count = 0; str[count] != '\0'; ++count);

        return count;
    }


    int sum_arr(int arr[],int b){
        int sum=0;
        for(int i=1;i<b;i++){
            sum+= (arr[i]-1);
        }
        return sum;
    }



    void infun(){

        char s_g , tmploc, tloc1=' ', tloc2=' ', op_file[5];
        int i = 0;
        gio=0;
        gio2=0;
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
            else if( tmploc == '\n' ){//for end
                loc2[i] = '\0';
                break;//To not scan more
            }
            /*else if( (tmploc == 'n') && (tloc1=='\\' ) && (tloc2=='\\' ) ){
                loc2[i] = '\n';
                break;//To not scan more
            }*/
            //else if( (tmploc == '\\') && (tloc1!='\\' ) );//for ignore /* \ */
            else if( (tmploc == '"') && (tloc1=='\\' ) ){
                gio++;
                loc2[i]=tmploc;
                i++;
            }//for ignore \"
            //else if(  ){}
            else if( (tmploc == '"') ){gio2++;}//for ignore "
            else if( (tmploc == 'n') && (tloc1=='\\' ) && (tloc2=='\\' ) ){
                inter2++;
                loc2[i]=tmploc;
                i++;
            }
            else if( (tmploc == 'n') && (tloc1=='\\' ) && (tloc2!='\\' ) ){
                inter1++;
                loc2[i]=tmploc;
                i++;
            }
            else{//for tmploc-->loc2;
                    loc2[i]=tmploc;
                i++;
            }
            tloc2=tloc1;
            tloc1=tmploc;
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


    void cat(){
        infun();
        char txt;
        FILE *ptr;
        int d1=0,d2=0;
        if( (ptr = fopen(loc2 , "r") ) != NULL){
            ptr = fopen(loc2 , "r");
            while(! feof(ptr)){
                fscanf(ptr , "%c" , &txt );
                d1++;
            }
            fclose(ptr);
            ptr = fopen(loc2 , "r");
            while( (! feof(ptr)) && (d1-d2>1) ){
                fscanf(ptr , "%c" , &txt );
                printf("%c", txt);
                d2++;
            }
            //printf("%d", d1);
            printf("\n");
            fclose(ptr);
        }
        else{
            printf("No file with the given address exists!\n");
        }

        //printf("%s", loc2);

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
                //printf("%d", str_length(cmd_i) );
                //printf("%d", txtfile[14]);
                //printf("%d", charkolinter-inter);
                //printf("%d", ja);//ja=charkolinter-inter+1
                //line=inter+1
                //ch=ch-1
                fclose(ptr);
                if(p2>inter+1){printf("Out of range (line)!\n");}
                else if(p1>=chln[p2]){printf("out of range (character of line)!\n");}
                else{

                    ptr = fopen(loc2 , "w");
                    int g=0;

                    for(int r=0;r<charkolinter+str_length(cmd_i);r++){
                            //fprintf(ptr , "%c" , txtfile[r]);insertstr -file /root/1.txt -str 1234 -pos 4:5
                        g = r- ( sum_arr(chln, p2) + p1 + p2 - 1 );
                        if( (r< ( sum_arr(chln, p2) + p1 + p2 - 1 ) )){fprintf(ptr , "%c" , txtfile[r]);}
                        else if( (r>( sum_arr(chln, p2) + p1 + p2 + str_length(cmd_i) - 2 ) )  ){fprintf(ptr , "%c" , txtfile[r-str_length(cmd_i)]);}
                        else{

                            if((cmd_i[g]=='\\') && (cmd_i[g+1]=='\\') && (cmd_i[g+2]=='n') ){fprintf(ptr , "%c" , '\\');fprintf(ptr , "%c" , 'n');r+=2; }
                            else if((cmd_i[g-1]!='\\') && (cmd_i[g]=='\\') && (cmd_i[g+1]=='n') ){fprintf(ptr , "%c" , '\n');r+=1; }
                            else if((cmd_i[g]=='\\') && (cmd_i[g+1]!='n') && (cmd_i[g+2]!='n') ){fprintf(ptr , "%c" , '\\');}
                            //fprintf(ptr , "%c" , '*');
                            //else if( ( (cmd_i[g]!='\\')||(g==0) ) && (cmd_i[g+1]=='\\') && (cmd_i[g+2]=='n') ){fprintf(ptr , "%c" , '&');}
                            //else
                            //if(cmd_i[r]!='\0'){}
                            else {
                                    fprintf(ptr , "%c" , cmd_i[g]);
                            }
                            //else{}
                            //fprintf(ptr , "%c" , '*');

                        }
                        //else{}
                        //fprintf(ptr , "%c" , txtfile[r]);
                    }
                    /****************************************/
                    /*for(int r=0;r<100;r++){
                        //if( (r<)||(r>) ){fprintf(ptr , "%c" , txtfile[r]);}
                        //else if(1){}
                        //else{}
                        if((cmd_i[r]=='\\') && (cmd_i[r+1]=='\\') && (cmd_i[r+2]=='n') ){fprintf(ptr , "%c" , '\n'); r+=2; }
                        else if(cmd_i[r]!='\0'){ fprintf(ptr , "%c" , cmd_i[r]);}
                        //else if(cmd_i[r+1]!='\0' || cmd_i[r+2]!='\0'){}
                        //else{break;}

                    }*/
                    //fprintf(ptr , "%c" , '8');
                    printf("The operation was successful!\n");
                    fclose(ptr);

                }
            }
        else{
            printf("No file with the given address exists!\n");
        }

        /*if(p2>inter+1){printf("Out of range (line)!");}
        else if(p1>linechar){printf("out of range (character of line)!");}*/

        //for(int k=1;k<100;k++){printf("%c", txtfile[k]);}

        //printf("%s", cmd_i);
        //printf("%d", sum_arr(chln, 4) );

        return;
    }


    void rccp(int rcp){

        infun();
        char cmd_remove[100];
        char cmd_r[100];
        int size=0;
        int p1=0;//line
        int p2=0;//char
        int forb=0;
        char txtfile[10000];


        for(int i=0;i<100;i++)clip[i]=NULL;


        FILE *ptr;
        int w=0;
        int a = str_length(loc2);
        for(int i=0;i<str_length(loc2);i++){
            if( (loc2[i]== '-')&&(loc2[i+1]== 'p')&&(loc2[i+2]== 'o')&&(loc2[i+3]== 's') ){
                loc2[i-1]= '\0';
                w=i;
                break;
            }
        }


        for(int j=0;j<a;j++){
            cmd_remove[j]=loc2[j+w+5];
        }
        cmd_remove[a]='\0';
        int tmp_p=str_length(cmd_remove);

        if( cmd_remove[tmp_p-1]=='f' ){forb=1;}
        else{forb=-1;}
        //printf("%c\n", cmd_remove[tmp_p-1]);

        int space=0;
        int tmp2=0;
        while(space!=2){

            if(cmd_remove[tmp_p]==' '){space++;}
            if(space==2){tmp2=tmp_p;}
            tmp_p--;
        }

        //printf("%d ", tmp2+1);
        int t3 = tmp2 + 1;
        while(cmd_remove[t3]!=' '){

            size=(size*10)+(cmd_remove[t3]-48);
            //printf("%c\n", cmd_remove[t3]);
            t3++;
        }
        //printf("%d", size);

        t3=tmp2-6;
        int tedad=0;
        while(cmd_remove[t3]!=':'){

            tedad++;
            //printf("%c\n", cmd_remove[t3]);
            t3--;
        }
        t3++;
        //printf("%d\n", t3);
        //printf("%d\n", tedad-1);

        while(cmd_remove[t3]!=' '){

            p2=(p2*10)+(cmd_remove[t3]-48);
            //printf("%c\n", cmd_remove[t3]);
            t3++;
        }
        //printf("%d\n", p2);

        //t3-=tedad;
        //printf("%d\n", t3);
        tedad=0;
        while(cmd_remove[tedad]!=':'){

            //printf("%c", cmd_remove[tedad]);
            p1=(p1*10)+(cmd_remove[tedad]-48);
            //t3++;
            tedad++;
        }
        //printf("%s\n", cmd_remove);

        /******************************************/

        int inter=0;
        int chofln=0;
        int chln[100];
        int charkolinter =-1;
        int ja=0;

        if( (ptr = fopen(loc2 , "r") ) != NULL){

                ptr = fopen(loc2 , "r");
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
                fclose(ptr);


                if(p1>inter+1){printf("Out of range (line)!\n");}
                else if(p2>=chln[p1]){printf("out of range (character of line)!\n");}
                else if( (size+( sum_arr(chln, p1) + p2 + p1 - 1 )>charkolinter) && (forb>0) ){printf("out of range (size+)!\n");}
                else if( (( sum_arr(chln, p1) + p2 + p1 - 1 )-size<0) && (forb<0) ){printf("out of range (size-)!\n");}
                else{


                    ptr = fopen(loc2 , "w");
                    int g=0;
                    int tp=0;
                    int q=1;
                    char cmd_i[100];
                    int rp=0;
                    g = ( sum_arr(chln, p1) + p2 + p1 - 1 );
                    if(forb<0){g-=size;/*printf("Are\n");*/}
                    for(int r=0;r<charkolinter;r++){
                        //if(g<0){printf("The size is too long(-)!\n");q=0;break;}
                        //else if(g+size>charkolinter){printf("The size is too long(+)!\n");q=0;break;}
                        if( (r< g )){fprintf(ptr , "%c" , txtfile[r]);}
                        else if( (r>( g + size - 1 ) )  ){fprintf(ptr , "%c" , txtfile[r]);}
                        else{

                            //printf("%d", rcp);

                            if(rcp==1){//remove

                                    //printf("Hello1");
                                    tp=0;

                            }else if(rcp==3){//cut

                                //strcpy(save , badal);
                                clip[rp]=txtfile[r];
                                rp++;
                                tp=1;
                                //printf("Hello3");

                            }else if(rcp==2){//else//copy

                                fprintf(ptr , "%c" , txtfile[r]);
                                clip[rp]=txtfile[r];
                                rp++;
                                tp=1;
                                //printf("Hello2");

                            }
                                    //fprintf(ptr , "%c" , cmd_i[g]);
                                    //printf("Oops!");
                        }
                    }

                    /**************/


                    if(q)printf("The operation was successful!\n");
                    rp=0;
                    if(tp==1)printf("Your copied text is: %s\n", clip);
                    tp=0;
                    fclose(ptr);
                    /*if(q!=0){

                        ptr = fopen(loc2 , "w");
                        for(int r=0;r<charkolinter;r++){
                            fprintf(ptr , "%c" , txtfile[r]);
                            printf("%c\n", txtfile[r]);
                        fclose(ptr);
                        }
                    }*/
                    q=1;

                    }

                }

        else{
            printf("No file with the given address exists!\n");
        }

        //printf("%s\n", clip);
        rcp=0;
        return;
    }


    void crundo(){

        //infun();
        char txt;
        FILE *ptr;
        int d1=0;
        if( (ptr = fopen(loc2 , "r") ) != NULL){
            ptr = fopen(loc2 , "r");
            while(! feof(ptr)){
                fscanf(ptr , "%c" , &txt );
                alltxt[d2][d1]= txt;
                d1++;
            }
            d2++;
            fclose(ptr);

        }
        else{
            printf("No file with the given address exists!\n");
        }

        //printf("%s", loc2);

        return;

    }


    void undo(){

        infun();
        char txt;
        FILE *ptr;
        int d1=0;
        d2--;
        //d2--;
        if( (ptr = fopen(loc2 , "r") ) != NULL){
            while(alltxt[d2][d1]!='\0'){
                d1++;
            }

            ptr = fopen(loc2 , "w");
            for(int r=0;r<d1-1;r++){

                fprintf(ptr , "%c" , alltxt[d2][r]);

                    }
            //d2--;
            fclose(ptr);

        }
        else{
            printf("No file with the given address exists!\n");
        }

        //printf("%s", loc2);

        return;

    }


    int main(){

        char cmd[100];
        char last;

        while(1){

            scanf("%s" , cmd);
            last = getchar(); // space OR \n


            if(strcmp(cmd , "creatfile") == 0){creatfile();crundo();}
            else if(strcmp(cmd , "insertstr") == 0){insertstr();crundo();}
            else if(strcmp(cmd , "cat") == 0){cat();crundo();}
            else if(strcmp(cmd , "removestr") == 0){rccp(1);crundo();}
            else if(strcmp(cmd , "copystr") == 0){rccp(2);crundo();}
            else if(strcmp(cmd , "cutstr") == 0){rccp(3);crundo();}
            else if(strcmp(cmd , "undo") == 0){undo();}
            else if(strcmp(cmd , "exit") == 0){break;}
            else{
                if(last == '\n') printf("invalid command!\n");
            }

        }

    return 0;
    }
