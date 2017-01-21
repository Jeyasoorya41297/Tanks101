#include "tanks.h"
#include "weapons.h"
coordinate projectile(tank &t, tank & t1, int col[],int size)
{
 coordinate c1={2*t.cr3.x-t.cr3end.x,2*t.cr3.y-t.cr3end.y};//change
 Circle c(c1.x,c1.y,size);
 c.setColor(COLOR(col[0],col[1],col[2]));
 c.setFill(1);
 long double vx=0.065*t.power*cosine(t.angle),vy=0.065*t.power*sine(t.angle);
 coordinate c2;

 while(true)
 {
     c.move(vx,-vy);
     c2.x=c.getX(); c2.y=c.getY();
     if(c2.x<0||c2.x>1366)
      {
          coordinate c={0,0};
          return c;
      }

     else if(exacthit(c2,t1)||exacthit(c2,t)||c2.y+size>575)//change
     {



          return c2;                              //in checkclick the 20,35 and 10 are width and height of the tank's rectangle respectively

     }
     vy-=(9.8*0.065*0.065);
 }
}
void blast(coordinate c, int size)
{
  float siz=3;
  Circle c1(c.x,c.y,siz);
  c1.setColor(COLOR(226,88,34));
      c1.setFill(1);
  while(siz<size)
  {
      c1.scale(1.1);
      siz=siz*1.1;

  }
}
coordinate distantprojectile(tank &t,tank &t1, int col[], int size)
{
    coordinate c1={2*t.cr3.x-t.cr3end.x,2*t.cr3.y-t.cr3end.y};//change
 Circle c(c1.x,c1.y,size);
 c.setColor(COLOR(col[0],col[1],col[2]));
 c.setFill(1);
 long double vx=0.065*t.power*cosine(t.angle),vy=0.065*t.power*sine(t.angle);


 while(true)
 {
     c.move(vx,-vy);
     c1.x=c.getX(); c1.y=c.getY();
     if(c1.x<0||c1.x>1366)
        { coordinate c={0,0};
          return c;
        }

     else if(vy<0&&c1.y>475)//change

        return c1;                              //in checkclick the 20,35 and 10 are width and height of the tank's rectangle respectively


    vy-=(9.8*0.065*0.065);
 }
}
