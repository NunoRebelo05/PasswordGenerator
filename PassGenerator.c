#include "stdio.h"
#include "stdlib.h"
#include "assert.h"
#include "time.h"
#include "string.h"


void GeraPass(int passlenght, int mode){
    
    int ran;
    char *password;
    int charsLenght = 11;
    password = calloc(sizeof(char),passlenght);
    char chars[92];

    srand(time(NULL));  

    if(mode == 1){
        char chars92[] = " !#$&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[^_`abcdefghijklmnopqrstuvwxyz{|}~\0";
        charsLenght = 92;
        strcpy(chars,chars92);
    }else if(mode == 2){
        char chars64[] = " 0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz\0";
        charsLenght = 64;
        strcpy(chars,chars64);
    }else {
        char chars11[] = "1234567890\0";
        charsLenght = 11;
        strcpy(chars,chars11);
    }

    for(int i = 0; i < passlenght ;i++){
        
        ran = (rand()%charsLenght);// so it's on the arrey range
        //printf(" %d ,-> %c \n",ran ,chars[ran] );
        password[i] = chars[ran];
    }
    
    for(int i = 0; i < passlenght; i++)
        printf("%c",password[i]);

    free(password);
    
}

void GerapassController(){
    int option;
    int passlenght = 16;
    printf("Welcome to PassGen\nPlease select one of the options:\n1 --------- Normal Password\n2 --------- No Special Characters Password\n3 --------- Only Numbers Password\n");

    assert(scanf("%d",&option));

    printf("Please writh down the number of caracters wanted:\n");

    assert(scanf("%d",&passlenght));

    if(option == 1){

        GeraPass(passlenght,1);
        printf("\n");
    }else if(option == 2){

        GeraPass(passlenght,2);
        printf("\n");
    }else if(option == 3){

        GeraPass(passlenght,3);
        printf("\n");
    }else{
        printf("Please select a valid option!");
    }

}


int main(){

    GerapassController();
    
    return 0;
}
