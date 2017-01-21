#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include<simplecpp>

struct coordinate
{
    float x,y;
};


int page1();
int gameplay2();
void pageinst();
//void pageoptions();
int checkclick(int,int,int,int,int,int);
int whichclick(int n,int l[],coordinate p[],int ch);
int gameplay3(int);
int singleplayer();
void weapon_select(char[][20],char[][20],char[][15],int g=0 );


#endif // HEADER_H_INCLUDED
