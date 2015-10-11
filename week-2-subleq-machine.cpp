#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <cstring>

/* =========================================================//
 *
 * SUBLEQ Virtual Machine
 *
 ===========================================================*/





int main(int argv, char ** argc)
{


    char reg1 = 0; //Registers
    char reg2 = 0;
    char reg3 = 0;

    std::ifstream in("subleq.bin"); //Read in file into input buffer
    std::string contents((std::istreambuf_iterator<char>(in)),std::istreambuf_iterator<char>()); //Create new string and read in full file into that string

    printf("Read in file\n");


    char * string = new char [contents.length()+1];
    std::strcpy(string,contents.c_str()); //Get the C string because its easier to iterate over than C++ string objects.

    printf("Got string\n");

    reg1 = string[0];                 //initial set registers
    reg2 = string[1];
    reg3 = string[2];

    printf("Set Registers\n");
    printf("Registers are\n: %c\n %c\n %c\n", reg1,reg2,reg3);

    int i = 2;
    while (reg1 != NULL || reg2 != NULL|| reg3 != NULL)  
    {
        printf("Registers are:\n %c\n %c\n %c\n", reg1,reg2,reg3);

        i--;

        if (((reg1-'0') - (reg2-'0')) <= 0) //If less than or equal to 0
        {
            printf("Encountered less than or equal\n");
            printf("%c - %c = %d\n", reg1,reg2,(reg1-'0') - (reg2-'0'));

            if ((reg2 - '0') == -2)         
            {   reg2 = ((reg1 - '0') - (reg2 - '0')); //set memory address
            }

            if ((reg3 - '0') == -2)
            {   reg1 = string[reg3+1];        //Set registers to new values
                reg2 = string[reg1+1];
                reg3  = string[reg2+1];
                continue;
            }

            printf("Jumping to %c\n", reg3);
            reg1  = string[(reg3-'0')];        //Set registers to new values
            reg2  = string[(reg3-'0')+1];
            reg3  = string[(reg1-'0')+3];

            printf("Registers are:\n %c\n %c\n %c\n", reg1,reg2,reg3);


            continue;                   //gogo
        }
        else if (((reg1 - '0') - (reg2 - '0')) <= 0 && (reg3 - '0') == -1)  //If result is less than or equal to 0 and jump address is -1 end program.
        {
            break;
        }
        else //Else, just move forward one
        {   reg1 = string[reg3+1];        //Set registers to new values
            reg2 = string[reg3+2];
            reg3 = string[reg1+2];
        }


     }

}
