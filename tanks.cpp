#include "tanks.h"
#include "getch.h"
 tank::tank(float r1x1,float r1y1,float r2x1,float r2y1,float r3x1,float r3y1,float c1x1,float c1y1,float c2x1,float c2y1,char* colr,char* nam,char p[20][20],int k):r1(r1x1,r1y1,20,10),r2(r2x1,r2y1,35,10),r3(r3x1,r3y1,20,3),c1(c1x1,c1y1,5),c2(c2x1,c2y1,5){
   cr1.x=r1x1;cr1.y=r1y1;cr2.x=r2x1;cr2.y=r2y1;cr3.x=r3x1;cr3.y=r3y1;cc1.x=c1x1;cc1.y=c1y1;cc2.x=c2x1;cc2.y=c2y1;//change
   strcpy(p_name,nam);
   strcpy(color,colr);
   r3.setColor(COLOR(color));
   r1.setFill(true);
   r1.setColor(COLOR(color));
   r2.setFill(true);
   r2.setColor(COLOR(color));
   pts=0;
   power=0;
   angle=0;
   int i=0;
   while(i<k){
     strcpy(weaponlist[i],p[i]);
     i++;
   }
   strcpy(selwpn,weaponlist[0]);
   nofw=k;
  }
  void tank::movetank(char ch){

    if(ch=='f') {
        cr1.x+=20;cr2.x+=20;cr3.x+=20;cc1.x+=20;cc2.x+=20;cr3end.x+=20;//change
      repeat(2){
       beginFrame();
       r1.move(10,0);
       r2.move(10,0);
       r3.move(10,0);
       c1.move(10,0);
       c2.move(10,0);
       endFrame();
       wait(1);
       }
    }

   else
   {
       cr1.x-=20;cr2.x-=20;cr3.x-=20;cc1.x-=20;cc2.x-=20;cr3end.x-=20;//change

       beginFrame();
       repeat(2)
       {


       r1.move(-10,0);
       r2.move(-10,0);
       r3.move(-10,0);
       c1.move(-10,0);
       c2.move(-10,0);
       endFrame();
       wait(1);

       }
   }

  }
 void tank::angselect(){
     //float xc=r3x-10*cos(-r3.getOrientation()),yc=r3y+10*sin(-r3.getOrientation());//change
     float a1;
     int m=getClick();
      float x1=m/65536,y1=m%65536;
      a1=arccosine((x1-cr3end.x)/sqrt((x1-cr3end.x)*(x1-cr3end.x)+(cr3end.y-y1)*(cr3end.y-y1)));
      if(y1>cr3end.y){
       a1*=-1;
      }
      cr3.x=cr3end.x+10*cosine(a1);cr3.y=cr3end.y-10*sine(a1);//change
      r3.reset(cr3.x,cr3.y,20,3);//change
      r3.left(a1);
      angle=a1;
 }
 void tank_color(char colr[],char name[])
 {     int m;//used at the end




       Text t(1366/2-300,100,"ENTER PLAYER NAME(Max 10 characters)(press space after completion)        :");
       t.setColor(COLOR("red"));
       char c[2];
       c[1]='\0';
       c[0]='\0';
       Text t1;
       int i=0;
       c[0]=getche();
       while(c[0]!=' ')
       {
        name[i]=c[0];
        name[i+1]='\0';
         t1.reset(1366/2-300+textWidth("ENTER PLAYER NAME(Max 10 characters)(press space after completion)        :")/2+10+i*1.0/2*textWidth("a"),100,name);


        i++;
        c[0]=getche();
       }
       beginFrame();
       coordinate p[]={{483,250},{583,250},{683,250},{783,250},{883,250}};
       int l[]={50,50,50,50};
       char col[][10]={"red","yellow","black","green","blue"};

       Rectangle r1(p[0].x,p[0].y,50,50);
       r1.setFill(true);
       r1.setColor(COLOR(col[0]));

       Rectangle r2(p[1].x,p[1].y,50,50);
       r2.setFill(true);
       r2.setColor(COLOR(col[1]));
       Rectangle r3(p[2].x,p[2].y,50,50);
       r3.setFill(true);
       r3.setColor(COLOR(col[2]));
       Rectangle r4(p[3].x,p[3].y,50,50);
       r4.setFill(true);
       r4.setColor(COLOR(col[3]));

       Rectangle r5(p[4].x,p[4].y,50,50);
       r5.setFill(true);
       r5.setColor(COLOR(col[4]));

        endFrame();
        m=whichclick(5,l,p,1);
        strcpy(colr,col[m-1]);
beginFrame();



 }
