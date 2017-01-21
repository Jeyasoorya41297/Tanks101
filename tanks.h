#ifndef TANKS_H_INCLUDED
#define TANKS_H_INCLUDED
#include"header.h"



class tank{
 public:
      Rectangle r1,r2,r3;
      Circle c1,c2;
      int pts,nofw;
      coordinate cr1,cr2,cr3,cc1,cc2,cr3end;//change
      float angle;
      long double power;
      char weaponlist[20][20];
      char selwpn[20];
      char color[100],p_name[100];
      tank(float r1x1,float r1y1,float r2x1,float r2y1,float r3x1,float r3y1,float c1x1,float c1y1,float c2x1,float c2y1,char* colr,char* nam,char p[20][20],int k);
      void movetank(char ch);
      void angselect();

};
void background(coordinate bgr[]);
void tank_color(char colr[],char name[]);
coordinate projectile(tank &,tank&,int[],int);
coordinate distantprojectile(tank&,tank&,int[],int);
void blast(coordinate,int);
void weaponselplay(tank &t);
#endif // TANKS_H_INCLUDED
