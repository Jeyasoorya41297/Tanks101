#include "header.h"
int checkclick(int a,int b,int x0,int y0,int l,int h)
{
    if((a>=x0-l/2&&a<=x0+l/2)&&(b>=y0-h/2&&b<=y0+h/2))
        return 1;
    else
        return 0;
}
int whichclick(int n,int l[],coordinate p[],int ch)
{  int h;
    if(!ch)
    h=textHeight()+6;
   else  h=50;
   first:
   int c=getClick();
   int a=c/65536;
   int b=c%65536;
  for(int i=0;i<n;i++)
    if(checkclick(a,b,p[i].x,p[i].y,l[i],h))
        return i+1;
  goto first;
}
