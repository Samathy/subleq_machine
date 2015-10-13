#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <cstring>
#include <array>

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

//    std::ifstream in("subleq.bin"); //Read in file into input buffer
//    std::string contents((std::istreambuf_iterator<char>(in)),std::istreambuf_iterator<char>()); //Create new string and read in full file into that string
//
//   printf("Read in file\n");
//
//    printf("Length of program: %d\n",contents.length());
//    char * string = new char [contents.length()+1];
//    std::strncpy(string,contents.c_str(), contents.length()+1); //Get the C string because its easier to iterate over than C++ string objects.


    char string[12] = {1,2,3,1,2,-2,64,-1,9,1,2,-1};

    //char string [36] {71, -1, 3, 68, -1, 0, 75, -1, 0, 75, -1, 0, 78, -1, 0, 31, -1, 0, 86, -1, 0, 78, -1, 0, 81, -1, 0, 75, -1, 0, 67, -1, 0, 1, 2, -1} ;

    reg1 = string[0];                 //initial set registers
    reg2 = string[1];
    reg3 = string[2];

    printf("Subleq SISC\n");
    printf("Initial registers: [1]%hhd [2]%hhd [3]%hhd \n\n", reg1,reg2,reg3);


    int tick = 0;
    while (reg1 != 0 || reg2 != 0 || reg3 != 0)  
    {

        if ((reg1 - reg2) <= 0) //If less than or equal to 0
        {

            if (reg3 == -1)     //If reg3 is -1 then exit
            {   printf("\n -1 Exit\n");
                break; 
            }


            if (reg3 == -2) //IF reg3 == -2 then just move forward one set
            {   tick = tick+3; }

            else                            //else jump to reg3 location
            {   tick = reg3; }



        }
        else if ((reg1 - reg2) > 0 && reg2 == -1)         
        {   //If register 2 = -1 then print the result of (reg1 - -2) and continue
            printf("%hhc",(reg1 -  reg2));
            tick = tick+3;
        }


        reg1 = string[tick];        //Set registers to new values
        reg2 = string[tick+1];
        reg3 = string[tick+2];



     }

}
