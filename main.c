#include "main.h"
 
int main() {
    int x;
    printf("Choose an option:\n"); // MAIN MENU Options
    printf("Press 1 for admin access\n");
    printf("Press 2 for tutor access\n");
    printf("Press 3 for student access\n"); 
    scanf("%d",&x);
    if(x==1){                                   //Admin options
            const char* username = "admin";
            const char* password = "APU";
            char user_input[100];
            printf("Enter Username: \n");
            scanf("%s",user_input); 
            user_input[strcspn(user_input, "\n")]='\0'; 
            if (strcmp(user_input, username) == 0) {
                printf("Enter User Password: \n");
                scanf("%s",user_input);
                user_input[strcspn(user_input, "\n")]='\0';
                if (strcmp(user_input, password) == 0) {
                    //printf("password matched");
                    printf("\nPress 1 for tutor registration: ");
                    printf("\nPress 2 for student registration: ");
                    printf("\nPress 3 for session registration: ");
                    printf("\nPress 4 for student_session registration:");
                    printf("\nPress 5 To see student_session details:\n");
                    int a;
                    scanf("%d", &a);
                    FILE* fptr;
                    FILE* fptr1;
                    FILE* fptr2;
                    FILE* fptr3;
                    FILE* fptr4;
                    switch (a) {
                    case 1:
                        fptr = fopen("tutor.txt", "a+");   //inside sub-option 1
                        char tutor[100];
                        printf("Enter tutor user code: \n");
                        scanf("%s", &tutor);
                        fprintf(fptr, "%s\n", tutor);
                        printf("Enter tutor name: \n");
                        scanf("%s", &tutor);
                        fprintf(fptr, "%s\n", tutor);
                        printf("Enter tutor course\n");
                        scanf("%s", &tutor);
                        fprintf(fptr, "%s\n", tutor);
                        printf("Enter tutor password: \n");
                        scanf("%s", &tutor);
                        fprintf(fptr, "%s\n", tutor);
                        fclose(fptr);
                        break;
                    case 2:
                        fptr1=fopen("student.txt","a+");  //inside sub-option 2
                        char student[100];
                        printf("Enter TP number: \n");
                        scanf("%s", &student);
                        fprintf(fptr1, "%s\n", student);
        
                        printf("Enter student password: \n");
                        scanf("%s", &student);
                        fprintf(fptr1, "%s\n", student);
        
                        printf("Enter student name: \n");
                        scanf("%s", &student);
                        fprintf(fptr1, "%s\n", student);
        
                        fclose(fptr1);
                        break;
                    case 3:
                        fptr2=fopen("session.txt","a+");   //inside sub-option 3
                        char session[350];
                        printf("Enter session code:\n ");
                        scanf("%s", &session);
                        fprintf(fptr2, "%s\n", session);
                        printf("Enter session name:\n");
                        scanf("%s", &session);
                        fprintf(fptr2, "%s\n", session);
                        printf("Enter session time:\n");
                        scanf("%s", &session);
                        fprintf(fptr2, "%s\n", session);
                        printf("Enter session location: \n");
                        scanf("%s", &session);
                        fprintf(fptr2, "%s\n", session);
                        printf("Enter session date:\n");
                        scanf("%s", &session);
                        fprintf(fptr2, "%s\n", session);
                        printf("Enter Tutor code:\n");
                        scanf("%s", &session);
                        fprintf(fptr2, "%s\n", session);
        
                        fclose(fptr2);
                        break;
                    case 4:
                        fptr3=fopen("student_session.txt","a+");  //inside sub-option 4
                        char student_session[350];
                        printf("Enter TP Number:\n");
                        scanf("%s", &student_session);
                        fprintf(fptr3, "%s\n", student_session);
                        printf("Enter session code:\n");
                        scanf("%s", &student_session);
                        fprintf(fptr3, "%s\n", student_session);
                        
                        fclose(fptr3);
                        break;
                    case 5:
                        fptr4=fopen("student_session.txt","r");   //inside sub-option 5
                        char line[500];
                        //printf("\nEnter User Code:");
                        char SID[500];
                        char SSID[500];
                        printf("%-20s %-20s %-20s %s\n", "Student Name", "Session ID", "Tutor Name", "Location");
                        printf("---------------------------------------------------------------------------------------\n");
                        while(fgets(line,sizeof(line),fptr4)){
                            line[strcspn(line, "\n")] = '\0';
                            //printf("%s",line);
                            strcpy(SID,line);
                            fgets(line,sizeof(line),fptr4);
                            line[strcspn(line, "\n")] = '\0';
                            strcpy(SSID,line);
                            //printf("%s\n",SID);
                            //printf("%s",SSID);
                            char sname[500];
                            fptr1=fopen("student.txt","r");
                            while(fgets(line,sizeof(line),fptr1)){
                            line[strcspn(line, "\n")] = '\0';
                            //printf("%s",line);
                            if(strcmp(line,SID)==0){
                                //printf("%s",line);
                                fgets(line,sizeof(line),fptr1);
                                fgets(line,sizeof(line),fptr1);
                                line[strcspn(line, "\n")] = '\0';
                                strcpy(sname,line);
                                }
                            }
                            fptr2=fopen("session.txt","r");
                            char tutorid[500];
                            char location[500];
                            while(fgets(line,sizeof(line),fptr2)){
                                line[strcspn(line, "\n")] = '\0';
                                //printf("%s",line);
                                if(strcmp(line,SSID)==0){
                                //printf("%s ",SSID);
                                fgets(line,sizeof(line),fptr2);
                                fgets(line,sizeof(line),fptr2);
                                fgets(line,sizeof(line),fptr2);
                                line[strcspn(line, "\n")] = '\0';
                                strcpy(location,line);
                                //printf("%s ",line);
                                fgets(line,sizeof(line),fptr2);
                                fgets(line,sizeof(line),fptr2);
                                line[strcspn(line, "\n")] = '\0';
                                strcpy(tutorid,line);
                                //printf("%s ",line);
                                //printf("%s ",tutorid);
                                //printf("%s ",location);
                                }
                            }
                            fptr3=fopen("tutor.txt","r");
                            char t_name[500];
                            while(fgets(line,sizeof(line),fptr3)){
                                line[strcspn(line, "\n")] = '\0';
                                //printf("%s",line);
                                if(strcmp(line,tutorid)==0){
                                fgets(line,sizeof(line),fptr3);
                                line[strcspn(line, "\n")] = '\0';
                                strcpy(t_name,line);
                                }
                            } 
                            printf("%-20s %-20s %-20s %s\n", sname, SSID, t_name, location); 
                            // printf("%s ",sname);
                            // printf("%s ",SSID);
                            // printf("%s ",t_name);
                            // printf("%s \n",location);
                        }
                        fclose(fptr4);
                        fclose(fptr1);
                        fclose(fptr2);
                        fclose(fptr3);
                        break;    
                    default:
                        printf("Invalid Input!\n");
                    }
                }
            }
    }
    else if(x==2){     //menu for tutors
        FILE* fptr4;
        FILE* fptr1;
        char tid[500];
        char tpass[500];
        char line[500];
        printf("Enter Tutor ID: \n");
        scanf("%s",tid);
        tid[strcspn(tid, "\n")]='\0';
        printf("Enter Tutor Password: \n");
        scanf("%s",tpass);
        tpass[strcspn(tpass, "\n")]='\0';
        fptr4=fopen("tutor.txt","r");
        while(fgets(line,sizeof(line),fptr4)){
                        line[strcspn(line, "\n")] = '\0';
                        //printf("%s",line);
                        if(strcmp(line,tid)==0){         //matching username and password for authentication
                            //printf("%s",line);
                            fgets(line,sizeof(line),fptr4);
                            fgets(line,sizeof(line),fptr4);
                            fgets(line,sizeof(line),fptr4);
                            line[strcspn(line, "\n")] = '\0';
                            if(strcmp(line,tpass)==0){
                                int m;
                                char line1[500];
                                char line2[500];
                                char line3[500];
                                char line4[500];
                                char line5[500];
                                char line6[500];
                                printf("Press 1 to see sessions assigned to you:\n");   //session table menu
                                scanf("%d",&m);
                                if(m==1){
                                    fptr1=fopen("session.txt","r");
                                    int counter=0;
                                    printf("%-20s %-30s %-10s %-20s %-20s\n", "Session Code", "Session Name", "Time", "Location", "Day");
                                    printf("-----------------------------------------------------------------------------------------\n");
                                    while(fgets(line1,sizeof(line1),fptr1)){
                                        line1[strcspn(line1, "\n")] = '\0';
                                        //printf("%s ",line1);  
                                        fgets(line2,sizeof(line2),fptr1);
                                        line2[strcspn(line2, "\n")] = '\0';
                                        fgets(line3,sizeof(line3),fptr1);
                                        line3[strcspn(line3, "\n")] = '\0';
                                        fgets(line4,sizeof(line4),fptr1);
                                        line4[strcspn(line4, "\n")] = '\0';
                                        fgets(line5,sizeof(line5),fptr1);
                                        line5[strcspn(line5, "\n")] = '\0';
                                        fgets(line6,sizeof(line6),fptr1);
                                        line6[strcspn(line6, "\n")] = '\0';
                                        //printf("%s\n",line2);
                                        if(strcmp(line6,tid)==0 && strcmp(line1,"")!=0){
                                           counter=counter+1;
                                           printf("%-20s %-30s %-10s %-20s %-20s\n", line1, line2, line3, line4,line5);  
                                        }
                                        // if(strcmp(line,TP_Number)==0){
                                        //     //printf("%s",line);
                                        //     fgets(line,sizeof(line),fptr4);
                                        //     printf("%s",line);
                                        //     fgets(line,sizeof(line),fptr4);
                                        //     printf("%s",line);
                                        // }
                                    }
                                    if(counter==0){
                                        printf("No Sessions assigned yet!\n");
                                    }
                                    fclose(fptr1);
                                }
                                else{
                                    printf("Invalid Input!");
                                }
                            }
                            else{
                                printf("Wrong Credentials! \n");
                                fclose(fptr4);
                                break;
                            }
                        }
                    }

    }
    else if(x==3){
        FILE* fptrx;
        FILE* fptr4;
        FILE* fptr2;
        FILE* fptr3;
        FILE* fptr1;
        char sid[500];
        char spass[500];
        char linex[500];
        printf("Enter Student TP: \n");
        scanf("%s",sid);
        sid[strcspn(sid, "\n")]='\0';
        printf("Enter Student Password: \n");
        scanf("%s",spass);
        spass[strcspn(spass, "\n")]='\0';
        fptrx=fopen("student.txt","r");
        while(fgets(linex,sizeof(linex),fptrx)){
                        linex[strcspn(linex, "\n")] = '\0';
                        //printf("%s",line);
                        if(strcmp(linex,sid)==0){
                            //printf("%s",line);
                            fgets(linex,sizeof(linex),fptrx);
                            linex[strcspn(linex, "\n")] = '\0';
                            if(strcmp(linex,spass)==0){       //login Authentication
                                //printf("Entered password is correct. Inside student now!\n");
                                printf("Enter 1 to see sessions:\nEnter 2 to enroll in a session:\n");
                                int g;
                                scanf("%d",&g);
                                if(g==1){
                                    fptr4=fopen("student_session.txt","r");
                                    char line[500];
                                    //printf("\nEnter User Code:");
                                    char SSID[500];
                                    printf("%-20s %-20s %-20s %s\n", "Student Name", "Session ID", "Tutor Name", "Location");
                                    printf("---------------------------------------------------------------------------------------\n");
                                    while(fgets(line,sizeof(line),fptr4)){       //table creation matching
                                        line[strcspn(line, "\n")] = '\0';
                                        //printf("%s",line);
                                        if(strcmp(sid,line)==0){
                                            fgets(line,sizeof(line),fptr4);
                                            line[strcspn(line, "\n")] = '\0';
                                            strcpy(SSID,line);
                                            //printf("%s\n",SID);
                                            //printf("%s",SSID);
                                            char sname[500];
                                            fptr1=fopen("student.txt","r");
                                            while(fgets(line,sizeof(line),fptr1)){
                                            line[strcspn(line, "\n")] = '\0';
                                            //printf("%s",line);
                                            if(strcmp(line,sid)==0){
                                                //printf("%s",line);
                                                fgets(line,sizeof(line),fptr1);
                                                fgets(line,sizeof(line),fptr1);
                                                line[strcspn(line, "\n")] = '\0';
                                                strcpy(sname,line);
                                                }
                                            }
                                            fptr2=fopen("session.txt","r");
                                            char tutorid[500];
                                            char location[500];
                                            while(fgets(line,sizeof(line),fptr2)){
                                                line[strcspn(line, "\n")] = '\0';
                                                //printf("%s",line);
                                                if(strcmp(line,SSID)==0){
                                                //printf("%s ",SSID);
                                                fgets(line,sizeof(line),fptr2);
                                                fgets(line,sizeof(line),fptr2);
                                                fgets(line,sizeof(line),fptr2);
                                                line[strcspn(line, "\n")] = '\0';
                                                strcpy(location,line);
                                                //printf("%s ",line);
                                                fgets(line,sizeof(line),fptr2);
                                                fgets(line,sizeof(line),fptr2);
                                                line[strcspn(line, "\n")] = '\0';
                                                strcpy(tutorid,line);
                                                //printf("%s ",line);
                                                //printf("%s ",tutorid);
                                                //printf("%s ",location);
                                                }
                                            }
                                            fptr3=fopen("tutor.txt","r");
                                            char t_name[500];
                                            while(fgets(line,sizeof(line),fptr3)){
                                                line[strcspn(line, "\n")] = '\0';
                                                //printf("%s",line);
                                                if(strcmp(line,tutorid)==0){
                                                fgets(line,sizeof(line),fptr3);
                                                line[strcspn(line, "\n")] = '\0';
                                                strcpy(t_name,line);
                                                }
                                            } 
                                            printf("%-20s %-20s %-20s %s\n", sname, SSID, t_name, location); 
                                        }
                                    }
                                    fclose(fptr4);
                                    fclose(fptr1);
                                    fclose(fptr2);
                                }
                                else if(g==2){    //self enrollment for student
                                    fptr3=fopen("student_session.txt","a+");
                                    char student_session[350];
                                    if (fptr3 != NULL) {
                                        if (ftell(fptr3) != 0) {  // Check if the file is not empty
                                            fprintf(fptr3, "\n");  // Add a newline before writing the session code
                                        }
                                        fprintf(fptr3, "%s\n", sid);
                                        printf("Enter session code:\n");
                                        scanf("%s", student_session);
                                        fprintf(fptr3, "%s\n", student_session);
                                        printf("Successfully Enrolled!\n");
                                    }
                                    
                                    fclose(fptr3);
                                    break;
                                }
                                else{
                                    printf("Wrong Input!\n");
                                }
                            }
                            else{
                                printf("Wrong Credentials! \n");
                                break;
                            }
                        }
        }
        fclose(fptrx);
    }
    else{
        printf("Wrong Input. System terminating..........\n");
    }
    return 0;
}