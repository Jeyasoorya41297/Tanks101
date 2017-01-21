#include "tanks.h"
#include<time.h>
main_program
{   unsigned int sval;
    time_t t;
    sval=(unsigned)time(&t);
    srand(sval);
    initCanvas("Tanks101",1366,768);
    int choice;
    first:
    choice=page1();
    if(choice==0||choice==4)
    {   endFrame();
        goto first;
    }
   else if(choice==1)
   {
	singleplayer();
	goto first;
   }
    else if(choice==2||choice==3)
    {
    	gameplay3(choice);
	endFrame();
	goto first;
    }
}
