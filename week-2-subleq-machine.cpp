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

//    printf("Read in file\n");


    char * string = new char [contents.length()+1];
    std::strcpy(string,contents.c_str()); //Get the C string because its easier to iterate over than C++ string objects.


    reg1 = string[0];                 //initial set registers
    reg2 = string[1];
    reg3 = string[2];

    printf("Set Registers\n");
    printf("Registers are\n: %hhd\n %hhd\n %hhd\n\n\n", reg1,reg2,reg3);

    int i = 2;
    int tick = 0;
   // while (reg1 != NULL || reg2 != NULL|| reg3 != NULL)  
    while(i>0) 
    {


        i--;
        if ((reg1 - reg2) <= 0) //If less than or equal to 0
        {
            if (reg3 == -1)         
            {   printf("Encountered -1: Exit condition\n");
                break; //set memory address
            }

            

            else if (reg3 == -2)
            {   reg1 = string[reg3+1];        //Set registers to new values
                reg2 = string[reg1+1];
                reg3  = string[reg2+1];
                continue;
            }

            if (reg3 == -2) //IF reg3 == -2 then just move forward one.
            {
                reg1  = string[tick+1];        //Set registers to new values
                reg2  = string[tick+2];
                reg3  = string[tick+3];
            }
            else                            //else jump to reg3 location
            {
                reg1  = string[reg3];        //Set registers to new values
                reg2  = string[reg3+1];
                reg3  = string[reg1+3];
            }


            
            continue;                   //gogo
        }
        else if (reg2 == -1)         
        {   //If register 2 = -1 then print the result of (reg1 - -2) and continue
            printf("%c",(reg1 -  reg2));
            reg1 = string[tick+1];        //Set registers to new values
            reg2 = string[tick+2];
            reg3 = string[tick+3];
        }
        else //Else, just move forward one
        {   reg1 = string[tick+1];        //Set registers to new values
            reg2 = string[tick+2];
            reg3 = string[tick+3];
        }

        tick++;

     }

}
