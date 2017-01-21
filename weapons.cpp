#include"tanks.h"
#include "weapons.h"
#include<time.h>
const int n=20;

void weapon_select(char p1[][20],char p2[][20],char name[][15],int g){

    beginFrame();
    char wpns[n][20]={"Single Shot","Triple Shot","Jackhammer","Acid Rain","Sniper","Canon ball","Pineapple","Lightning Strike","Zapper","Tracer","Skipper","Homing Missile","Boomerang","Spider","Big Shot","Tommy Gun","Chain Reaction","Bazooka","Phaser","Mystery Bomb"};
    coordinate c[21];
    int l[21];
    Text T(1366/2,50,"Weapons");
    Text t1(1366/2-400,150,name[0]);
    Text t2(1366/2+400,150,name[1]);
    int lh=textHeight()+6;
    int i=0,k=0;
    Text t[n];
    Rectangle r[n];
    Text trandom(1366/2,225+20*lh+25,"Random");
    Rectangle trand(1366/2,225+20*lh+25,100,lh);

    for(;k<n;k++)
    {
        c[k].x=1366/2;
        c[k].y=225+i;
        l[k]=100;
        t[k].reset(c[k].x,c[k].y,wpns[k]);
        r[k].reset(c[k].x,c[k].y,l[k],lh);
        i+=lh;
    }
    c[20].x=1366/2;
    c[20].y=225+20*lh+25;
    l[20]=100;
    k=0;i=0;
    int k1=0;
    int m=0,m1=0;
    endFrame();
    repeat(n/2){
        player1:
	if(m==21||m1==21)
	{m=rand()%20;
	m1=21;}
	else
        m=whichclick(n+1,l,c,0);
	if(m==21)
	goto player1;
       if(strcmp(wpns[m-1],"\0")!=0){
            strcpy(p1[k],wpns[m-1]);
            strcpy(wpns[m-1],"\0");
            r[m-1].reset(1366/2-400,225+i,100,lh);
            t[m-1].reset(1366/2-400,225+i,p1[k]);
            k++;
       }
       else goto player1;
      player2:
	{if(g==0)

	{if(m==21||m1==21)
        {m=1+rand()%20;
         m1=21;}
         else
            m=whichclick(n+1,l,c,0);
       if(m==21)
        goto player2;
	 }
        else
            m=1+rand()%20;
        }
       if(strcmp(wpns[m-1],"\0")!=0){
            strcpy(p2[k1],wpns[m-1]);
            strcpy(wpns[m-1],"\0");
            r[m-1].reset(1366/2+400,225+i,100,lh);
            t[m-1].reset(1366/2+400,225+i,p2[k1]);
            k1++;
       i+=lh;
       }
       else goto player2;


    }
beginFrame();
}
void weaponselplay(tank &t)
{

    coordinate c[20];
    int l[20];
    int lh=textHeight()+6;
    int i=0,k=0;

    Text t1[20];
    Rectangle r[20];

    beginFrame();
    for(;k<t.nofw;k++){
       c[k].x=1366/2;
       c[k].y=100+i;
       l[k]=100;
       t1[k].reset(c[k].x,c[k].y,t.weaponlist[k]);
       r[k].reset(c[k].x,c[k].y,l[k],lh);

       i+=lh;

    }

    endFrame();
    int  m=whichclick(t.nofw,l,c,0);
    strcpy(t.selwpn,t.weaponlist[m-1]);
    k=0;
    /*repeat(t.nofw)
    {
        ti[k].reset(0,0,"");
        ri[k].reset(0,0,0,0);
        k++;
    }*/

beginFrame();
}
int exacthit(coordinate c,tank &t)
{
    if(checkclick(c.x,c.y,t.cr1.x,t.cr1.y,20,10)||checkclick(c.x,c.y,t.cr2.x,t.cr2.y+5,35,20))
        return 1;
    else
        return 0;
}
void points(tank &t,tank &t1,coordinate c,int wpn)
{
    float maxpts[]={60,10,40,30,30,20,100,0,0,0,0,20,0,0,20};
    float radius[]={30,18,20,30,15,10,60,0,0,0,0,20,0,0,15};
    if(exacthit(c,t1))
        t.pts+=maxpts[wpn];
    else if(c.x<t1.cr2.x&&((t1.cr2.x-35/2)-c.x)<radius[wpn])
        t.pts+=maxpts[wpn]-((t1.cr2.x-35/2)-c.x)*maxpts[wpn]/radius[wpn];
    else if(c.x>t1.cr2.x&&(c.x-(t1.cr2.x+35/2)<radius[wpn]))
        t.pts+=maxpts[wpn]-(c.x-(t1.cr2.x+35/2))*maxpts[wpn]/radius[wpn];
    if(exacthit(c,t))
        t.pts-=maxpts[wpn];
    else if(c.x<t.cr2.x&&((t.cr2.x-35/2)-c.x)<radius[wpn])
        t.pts-=maxpts[wpn]-((t.cr2.x-35/2)-c.x)*maxpts[wpn]/radius[wpn];
    else if(c.x>t.cr2.x&&(c.x-(t.cr2.x+35/2)<radius[wpn]))
        t.pts-=maxpts[wpn]-(c.x-(t.cr2.x+35/2))*maxpts[wpn]/radius[wpn];

}
void firea(tank &t,tank &t1)
{   char wpns[n][20]={"Single Shot","Triple Shot","Jackhammer","Acid Rain","Sniper","Canon ball","Pineapple","Lightning Strike","Zapper","Tracer","Skipper","Homing Missile","Boomerang","Spider","Big Shot","Tommy Gun","Chain Reaction","Bazooka","Phaser","Mystery Bomb"};
    int i;
    for(i=0;i<n;i++)
    if(strcmp(t.selwpn,wpns[i])==0)
        break;
    checkagain:
    switch(i)
    {
        case 0:singleshot(t,t1);
               break;
        case 1:tripleshot(t,t1);
               break;
        case 2:jackhammer(t,t1);
               break;
        case 3:acidrain(t,t1);
               break;
        case 4:sniper(t,t1);
               break;
        case 5:canonball(t,t1);
               break;
        case 6:pineapple(t,t1);
               break;
        case 7:lightningstrike(t,t1);
               break;
        case 8:Zapper(t,t1);
               break;
        case 9:tracer(t,t1);
               break;
        case 10:skipper(t,t1);
                break;
        case 11:homingmissile(t,t1);
                break;
        case 12:boomerang(t,t1);
                break;
        case 13:spider(t,t1);
                break;
        case 14:bigshot(t,t1);
                break;
        case 15:TommyGun(t,t1);
                break;
        case 16:chainrxn(t,t1);
                break;
        case 17:bazooka(t,t1);
                break;
        case 18:phaser(t,t1);
                break;
        case 19:i=mysterybomb(t,t1);
                goto checkagain;
                break;
    }

}
void singleshot(tank &t,tank &t1)
{
    coordinate c;
    int projcol[3]={64,64,64};
    c=projectile(t,t1,projcol,4);
    blast(c,30);
    points(t,t1,c,0);
}

void jackhammer(tank &t,tank&t1)
{
    coordinate c;
    int projcol[3]={105,105,105};
    c=projectile(t,t1,projcol,5);
    blast(c,18);
    points(t,t1,c,1);
    {
        Circle c1;
        c1.setFill(1);
        c1.setColor(COLOR(105,105,105));
        float vertpower=10*sqrt(25/2*1.5);
        float vy=0.065*vertpower;
        for(int i=0;i<4;i++)
        {
            c1.reset(c.x,c.y,4-i);
            c1.move(0,-vy);
            while(c1.getY()<c.y)
            {
                vy-=9.8*0.065*0.065;
                c1.move(0,-vy);
            }
            vy=0.065*vertpower;
            blast(c,18);
            points(t,t1,c,1);
        }
    }
}
void sniper(tank &t,tank &t1)
{   coordinate c;
    int projcol[]={0,0,0};
    c=projectile(t,t1,projcol,2);
    if(exacthit(c,t1))
        t.pts+=100;
    if(exacthit(c,t))
        t.pts-=100;
}
void acidrain(tank &t,tank &t1)
{   coordinate c;
    int projcol[]={0,255,0};
    c=projectile(t,t1,projcol,3);
    Circle c1(c.x,c.y,3);
    c1.setFill(1);
    c1.setColor(COLOR(0,255,0));
    float vertpower=10*sqrt(25.0/2*1.5);
    float vy=0.065*vertpower;
    while(c1.getY()>c.y-30)
    {
        vy-=9.8*0.065*0.065;
        c1.move(0,-vy);
        wait(0.001);
    }
    beginFrame();

    Circle cloud[3];
    Line l[10];
    double v=35;
    int i=40,j=-12,k=0;
    repeat(3){
    cloud[k].reset(c1.getX()+j,c1.getY()-v*sine(i),15);
    j+=12;
    i+=50;
    cloud[k].setFill(1);
    cloud[k].setColor(COLOR(224,224,224));

    k++;
    }
    i=0;
    k=0;
    float m=0;
    repeat(10){
    l[i].reset(cloud[0].getX()+m,cloud[k].getY(),cloud[0].getX()+m,cloud[k].getY()+5);
    l[i].setColor(COLOR(0,255,0));
    m+=2.4;
    i++;
    k=(k+1)%3;
    }
    c1.setColor(COLOR(255,255,255));
    endFrame();

    repeat(20){
    i=1;k=0;

    repeat(5){
    l[i].move(0,5);
    coordinate li={l[i].getX(),l[i].getY()};

    if(exacthit(li,t1))
    {
        t.pts+=10;
        l[i].reset(0,0,0,0);

    }
    else if(exacthit(li,t))
    {

        t.pts-=10;
        l[i].reset(0,0,0,0);
    }
    else if(li.y+2.5>=575)
    {

        l[i].reset(0,0,0,0);
    }
    i+=2;
    }
    repeat(5){

    l[k].move(0,5);
    coordinate li={l[k].getX(),l[k].getY()};

    if(exacthit(li,t1))
    {
        t.pts+=10;
        l[k].reset(0,0,0,0);
    }
    else if(exacthit(li,t))
    {

        t.pts-=10;
        l[k].reset(0,0,0,0);
    }
    else if(li.y+2.5>=575)
    {
        l[k].reset(0,0,0,0);
    }
    k+=2;
    }

    }

}
void canonball(tank& t,tank& t1)
{
    Circle c2[15];
    int projcol[]={0,0,0};
    coordinate c=projectile(t,t1,projcol,5);
    Circle c1(c.x,c.y,5);
    c1.setFill(1);
    c1.setColor(COLOR(0,0,0));

    if(exacthit(c,t1))
        t.pts+=100;
    else if(exacthit(c,t))
        t.pts-=100;
    else if(t.angle>-90&&t.angle<90)
    {

        repeat(5)
        {
            c1.move(5,0);
            wait(0.001);
        }
        c.x=c1.getX();
        c.y=c1.getY();
        if(exacthit(c,t1))
            t.pts+=100;
        else if(exacthit(c,t))
            t.pts-=100;
    }
    else if((t.angle>90&&t.angle<180)||(t.angle<-90&&t.angle>-180))
            {

            repeat(5)
            {
                c1.move(-5,0);
                wait(0.001);
            }
            c.x=c1.getX();
            c.y=c1.getY();
            if(exacthit(c,t1))
            t.pts+=100;
        else if(exacthit(c,t))
            t.pts-=100;


            }

    c1.reset(0,0,0);
    int j=0;float r=0;
    int i=0;
    repeat(5)
    {i=0;
    beginFrame();
    repeat(15){
    c2[i].reset(c.x+r*cosine(j),c.y+r*sine(j),2);
     c2[i].setFill(1);
     c2[i].setColor(COLOR(249,241,17));
    j+=24;
    i++;
    }
    endFrame();
    r+=1.5;
    }
}
void Zapper(tank& t,tank& t1)
{   coordinate c1={2*t.cr3.x-t.cr3end.x,2*t.cr3.y-t.cr3end.y};//change
 Circle c(c1.x,c1.y,2);
 c.setColor(COLOR(255,255,0));
 c.setFill(1);
 long double vx=0.065*t.power*cosine(t.angle),vy=0.065*t.power*sine(t.angle);
 coordinate c2;
  while(true)
 {
     c.move(vx,-vy);
     c2.x=c.getX(); c2.y=c.getY();
     if(c2.x<-30||c2.x>1396)
        break;
     if(sqrt(pow(c2.x-t1.cr2.x,2)+pow(c2.y-t1.cr2.y,2))<30)
    {
        Line l(c2.x,c2.y,t1.cr2.x,t1.cr2.y);
        int j=0;
        repeat(4)
        {l.setColor(COLOR(255,255,j));
         j+=50;
         wait(0.1);
        }
        t.pts+=40;
    break;
    }
    else if(c2.y+2>575)
    {
        blast(c2,20);
        points(t,t1,c2,11);
        break;
    }
vy-=(9.8*0.065*0.065);
}
}
void TommyGun(tank& t,tank& t1)
{   int projcol[]={51,0,102};

    float iangle=t.angle;
    coordinate c;

    repeat(6)
    {   t.angle=iangle-2+rand()%5;
        c=projectile(t,t1,projcol,2);
        blast(c,15);
        points(t,t1,c,14);
    }



}

void chainrxn(tank& t,tank &t1)
{
    int projcol[]={243,20,20};
    coordinate c=projectile(t,t1,projcol,2),c1;
    c1.x=c.x;c1.y=c.y;
    double size=25,i=5;
    blast(c,size);
    points(t,t1,c,15);
    int j=0;
    size=25/1.5;
    float rad=size,max=30;
    repeat(6)
    {   if(j%2==0)
        c1.x=c.x+i;
        else
        {
            c1.x=c.x-i;
            i+=5;
            size=size/1.5;
            rad=size;
            max/=2;
        }
        blast(c1,size);


        if(exacthit(c1,t1))
        t.pts+=max;
    else if(c1.x<t1.cr2.x&&((t1.cr2.x-35/2)-c1.x)<rad)
        t.pts+=max-((t1.cr2.x-35/2)-c1.x)*max/rad;
    else if(c1.x>t1.cr2.x&&(c1.x-(t1.cr2.x+35/2)<rad))
        t.pts+=max-(c1.x-(t1.cr2.x+35/2))*max/rad;
    if(exacthit(c1,t))
        t.pts-=max;
    else if(c1.x<t.cr2.x&&((t.cr2.x-35/2)-c1.x)<rad)
        t.pts-=max-((t.cr2.x-35/2)-c1.x)*max/rad;
    else if(c1.x>t.cr2.x&&(c1.x-(t.cr2.x+35/2)<rad))
        t.pts-=max-(c1.x-(t.cr2.x+35/2))*max/rad;
    j++;
    }

}

void bazooka(tank& t,tank& t1)
{
    Circle c1(t.cr3.x,t.cr3.y,4);
    c1.setFill(1);
    c1.setColor(COLOR(64,64,64));
    double vx=0.065*t.power*cosine(t.angle),vy=0.065*t.power*sine(t.angle);
    while(true)
    {
        c1.move(vx,-vy);
        coordinate c={c1.getX(),c1.getY()};
        if(exacthit(c,t1))
        {
           t.pts+=200;blast(c,3);
           break;
        }
        else if(exacthit(c,t))
        {
            t.pts-=200;blast(c,3);
            break;
        }
        else if(c.y+3>575||c.y<0)
                break;
        else if(c.x>1366||c.x<0)
                break;


    }
}
void phaser(tank& t,tank& t1)
{
    repeat(3)
    {
        Line l(2*t.cr3.x-t.cr3end.x,2*t.cr3.y-t.cr3end.y,t1.cr2.x,t1.cr2.y);
        l.setColor(COLOR(204,204,0));
        wait(0.1);
        t.pts+=40;
    }
}
void tracer(tank& t,tank& t1)
{
    int projcol[]={0,0,0},i=-10,k=0;
    Text t2[5];
    float iangle=t.angle;
    t.angle=t.angle-10;

        repeat(5)
    {
        coordinate c=projectile(t,t1,projcol,2);
        t2[k].reset(c.x,c.y,i);
        i+=5;
        k++;
        t.angle+=5;
    }
t.angle=iangle;
wait(2);
}
void pineapple(tank &t,tank &t1)
{
    coordinate c;
    int countblast=0;
    int projcol[]={105,105,105};
    c=distantprojectile(t,t1,projcol,5);
    if(c.x!=0||c.y!=0)
    {int nop=12;
    Circle p[12];
    for(int i=0;i<nop;i++)
    {
        p[i].reset(c.x,c.y,2);
        p[i].setColor(COLOR(0,255,0));
        p[i].setFill(1);
    }
    long double vx[12],vy[12];
    for(int i=0;i<nop;i++)
    {
        vx[i]=0.065*32*cosine(30*i);
        vy[i]=0.065*32*sine(30*i);
    }
    coordinate c1[12];
    int stop[12];
    for(int i=0;i<nop;i++)
        stop[i]=0;
    while(countblast<12)
    {
        for(int i=0;i<nop;i++)
        {       if(stop[i]==1)
                    continue;
                c1[i].x=p[i].getX();c1[i].y=p[i].getY();
                p[i].move(vx[i],-vy[i]);
                if(c1[i].x<0||c1[i].x>1366)
                   {stop[i]=1;countblast++;}
                else if(exacthit(c1[i],t)||exacthit(c1[i],t1)||c1[i].y>575)
                {
                    p[i].hide();
                    blast(c1[i],10);
                    points(t,t1,c1[i],5);
                    stop[i]=1;
                    countblast++;

                }
                vy[i]-=0.065*0.065*9.8;

        }
    }
    }

}
void lightningstrike(tank &t, tank &t1)
{
    coordinate c;
    int projcol[]={105,105,105};
    c=projectile(t,t1,projcol,4);
    Rectangle r1(c.x,c.y,3,0);
    r1.setFill(1);
    for(int i=1;i<25;i++)
    {
        r1.reset(c.x,c.y-0.1*i,3,i*0.2);
    }
    wait(0.2);
    Line l[8];
    coordinate p[5];
    p[0].x=c.x+3.0/10*c.y*tangent(20);
    p[0].y=0;
    p[1].x=c.x-3.0/10*c.y*tangent(20);
    p[1].y=3.0/10*c.y;
    p[2].x=c.x+3.0/10*c.y*tangent(20);
    p[2].y=6.0/10*c.y;
    p[3].x=c.x+3.0/10*c.y*tangent(20)-2.0/10*tangent(30)*c.y;
    p[3].y=c.y-2.0/10*c.y;
    p[4]=c;
    for(int i=0;i<4;i++)
    {
        l[i].setColor(COLOR(225,225,102));
        l[i+4].setColor(COLOR(225,225,102));
        for(int j=1;j<=3;j++)
        {l[i].reset(p[i].x,p[i].y,p[i].x+(p[i+1].x-p[i].x)/3*j,p[i].y+(p[i+1].y-p[i].y)/3*j);
        l[i+4].reset(p[i].x+1.5,p[i].y,p[i].x+1.5+(p[i+1].x-p[i].x)/3*j,p[i].y+(p[i+1].y-p[i].y)/3*j);
        }
        wait(0.1);
    }
    points(t,t1,c,2);
}
void homingmissile(tank &t,tank &t1)
{


    int size=4;
    int col[]={0,0,255};
    coordinate c2={2*t.cr3.x-t.cr3end.x,2*t.cr3.y-t.cr3end.y};//change
    float a=t1.cr2.x-c2.x;
    Circle c(c2.x,c2.y,size);
    c.setColor(COLOR(col[0],col[1],col[2]));
    c.setFill(1);
    long double vx=0.065*t.power*cosine(t.angle),vy=0.065*t.power*sine(t.angle);

    if(a>0)
    {while(true)
    {
     c.move(vx,-vy);
     c2.x=c.getX(); c2.y=c.getY();
     if(c2.x<0||c2.x>t1.cr2.x||c2.y>575||exacthit(c2,t))
        break;
     vy-=(9.8*0.065*0.065);
    }

    if(c2.x>t1.cr2.x)
    {   vy=0;
        c.moveTo(t1.cr2.x,c2.y);
        while(true)
        {
            c2.y=c.getY();
            if(exacthit(c2,t1))
                break;
            c.move(0,vy);
            vy+=0.065*0.065*9.8;

        }
    }
    blast(c2,30);
    points(t,t1,c2,3);
    }
    else if(a<0)
      {while(true)
    {
     c.move(vx,-vy);
     c2.x=c.getX(); c2.y=c.getY();
     if(c2.x>1366||c2.x<t1.cr2.x||c2.y>575||exacthit(c2,t))
        break;
     vy-=(9.8*0.065*0.065);
    }

    if(c2.x<t1.cr2.x)
    {   vy=0;
        c.moveTo(t1.cr2.x,c2.y);
        while(true)
        {
            c2.y=c.getY();
            if(exacthit(c2,t1)||c2.y>575)
                break;
            c.move(0,vy);
            vy+=0.065*0.065*9.8;

        }
    }
    blast(c2,30);
    points(t,t1,c2,3);
    }

 }
void skipper(tank &t, tank &t1)
{
    coordinate c2;
    int col[]={255,255,0};
    int size=3;
    coordinate c1={2*t.cr3.x-t.cr3end.x,2*t.cr3.y-t.cr3end.y};//change
    Circle c(c1.x,c1.y,size);
    c.setColor(COLOR(col[0],col[1],col[2]));
    c.setFill(1);
    long double vx=0.065*t.power*cosine(t.angle),vy=0.065*t.power*sine(t.angle);
    for(int i=0;i<5;i++)
    {
        while(true)
        {
            c.move(vx,-vy);
            c2.x=c.getX();c2.y=c.getY();
            if(c2.x<0||c2.x>1366)
                goto end;
            if(exacthit(c2,t)||exacthit(c2,t1))
                {goto outfor;}
            else if(vy<0&&c2.y>575)
                 break;
            vy-=0.065*0.065*9.8;
        }
        vy=-0.6*vy;

    }

    outfor:
        blast(c2,20);
        points(t,t1,c2,2);
    end:;
}
void tripleshot(tank &t,tank &t1)
{   int i;
    coordinate c1[3];
    int col[]={105,105,105};
    for(i=0;i<3;i++)
        c1[i]={2*t.cr3.x-t.cr3end.x,2*t.cr3.y-t.cr3end.y};
    long double vx[3]={0.08*t.power*cosine(t.angle),0.08*t.power*cosine(t.angle-5),0.08*t.power*cosine(t.angle+5)};
    long double vy[3]={0.08*t.power*sine(t.angle),0.08*t.power*sine(t.angle-5),0.08*t.power*sine(t.angle+5)};
    Circle c[3];
    for(i=0;i<3;i++)
    {
         c[i].reset(c1[i].x,c1[i].y,2);
         c[i].setColor(COLOR(col[0],col[1],col[2]));
         c[i].setFill(1);
    }
    int stop[3]={0,0,0};
    int j=0;
    while(j<3)
    {
        for(i=0;i<3;i++)
        {   if(stop[i]==1)
                {wait(0.05);continue;};
            c[i].move(vx[i],-vy[i]);
            c1[i].x=c[i].getX();c1[i].y=c[i].getY();
            if(c1[i].x<0||c1[i].x>1366)
            {
               stop[i]=1;j++;
            }
            if(exacthit(c1[i],t)||exacthit(c1[i],t1)||c1[i].y>575)
                {
                    c[i].hide();
                    blast(c1[i],15);
                    points(t,t1,c1[i],4);
                    stop[i]=1;
                    j++;
                }
            vy[i]-=0.08*0.08*9.8;
        }

    }
}

void boomerang(tank &t, tank &t1)
{
    coordinate c2={2*t.cr3.x-t.cr3end.x,2*t.cr3.y-t.cr3end.y};
    int col[]={0,0,255};
    int size=4;
    Circle c(c2.x,c2.y,size);
    c.setColor(COLOR(col[0],col[1],col[2]));
    c.setFill(1);
    long double vx=0.065*t.power*cosine(t.angle),vy=0.065*t.power*sine(t.angle);
    while(true)
    {   c2.x=c.getX(); c2.y=c.getY();
        c.move(vx,-vy);
        if(c2.x<0||c2.x>1366)
            goto end;
        else if(exacthit(c2,t)||exacthit(c2,t1)||c2.y>575)
            break;
        vx-=0.065*0.065*9.8*cosine(t.angle);
        vy-=0.065*0.065*9.8;
    }
    blast(c2,20);
    points(t,t1,c2,2);
    end:
    ;
}
void spider(tank &t,tank &t1)

{
    coordinate c1={2*t.cr3.x-t.cr3end.x,2*t.cr3.y-t.cr3end.y};//change
    long double vx=0.065*t.power*cosine(t.angle),vy=0.065*t.power*sine(t.angle);
    int size =3;
    int col[]={105,105,105};
  { Circle c(c1.x,c1.y,size);
    c.setColor(COLOR(col[0],col[1],col[2]));
    c.setFill(1);

    while(true)
    {
        c.move(vx,-vy);
        c1.x=c.getX(); c1.y=c.getY();
        if(c1.x<0||c1.x>1366)
        {c1.x=0;c1.y=0;break;}

        else if(vy<0&&c1.y>500)//change
        break;                             //in checkclick the 20,35 and 10 are width and height of the tank's rectangle respectively

        vy-=(9.8*0.065*0.065);
   }
  }
    if(c1.x!=0||c1.y!=0)
    {
        const int nop=5;
        int countblast=0;
        coordinate c2[nop];
        Circle c[nop];
        for(int i=0;i<nop;i++)
        {
            c2[i]=c1;
            c[i].reset(c1.x,c1.y,2);
            c[i].setColor(COLOR("green"));
            c[i].setFill(1);
        }
        long double vx1[nop],vy1[nop];
        int stop[nop];
        for(int i=0;i<nop;i++)
        {
            stop[i]=0;
        }
        for(int i=0;i<nop;i++)
        {
            vx1[i]=vx-0.065*7*2+0.065*7*i;
            vy1[i]=vy-0.065*7*2+0.065*7*i;
        }
        while(countblast<nop)
        {
            for(int i=0;i<nop;i++)
            {   if(stop[i]==1)
                    continue;
                c2[i].x=c[i].getX();c2[i].y=c[i].getY();
                c[i].move(vx1[i],-vy1[i]);
                if(c2[i].x<0||c2[i].x>1366)
                {
                    countblast++;
                    stop[i]=1;
                }
                else if(exacthit(c2[i],t)||exacthit(c2[i],t1)||c2[i].y>575)
                {
                    c[i].hide();
                    blast(c2[i],20);
                    stop[i]=1;
                    countblast++;
                    points(t,t1,c2[i],2);

                }
            }
        }
    }
}

void bigshot(tank &t,tank &t1)
{
    coordinate c;
    int projcol[3]={64,64,64};
    c=projectile(t,t1,projcol,6);
    blast(c,60);
    points(t,t1,c,6);
}

int mysterybomb(tank &t,tank &t1)
{
    return rand()%20;
}
