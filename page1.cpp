#include "tanks.h"
#include "weapons.h"
void firea(tank &,tank &);

const int n=20;
int page1()
{  int ch,ch1=0;
{   beginFrame();
    int l[5]={textWidth("TANKS101")+6,textWidth("START GAME")+6,textWidth("INSTRUCTIONS")+6,textWidth("OPTIONS")+6,textWidth("QUIT")+6};
    coordinate p[4]={{683,300},{100,650},{1266,650},{683,70}};
    int h=textHeight()+6;
    Text t1(p[3].x,p[3].y,"TANKS101");
    t1.setColor(COLOR("red"));
//  Rectangle r1(p[4].x,p[4].y,l[0],h);
    Text t2(p[0].x,p[0].y,"START GAME");
    Rectangle r2(p[0].x,p[0].y,l[1],h);
    t2.setColor(COLOR("green"));
    r2.setColor(COLOR("green"));
    Text t3(p[1].x,p[1].y,"INSTRUCTIONS");
    Rectangle r3(p[1].x,p[1].y,l[2],h);
    t3.setColor(COLOR("green"));
    r3.setColor(COLOR("green"));
  //  Text t4(p[2].x,p[2].y,"OPTIONS");
   // Rectangle r4(p[2].x,p[2].y,l[3],h);
  //  t4.setColor(COLOR("green"));
//    r4.setColor(COLOR("green"));
    Text t5(p[2].x,p[2].y,"QUIT");
    Rectangle r5(p[2].x,p[2].y,l[4],h);
    t5.setColor(COLOR("green"));
    r5.setColor(COLOR("green"));
    endFrame();
    ch=whichclick(3,l,p,0);
}
    switch(ch)//whichclick(4,l,p))
    {
        case 1:ch1=gameplay2();

               break;
        case 2:pageinst();
               endFrame();

               break;
        case 3:return 5;

    }

   return ch1;
}
int gameplay2()
{   beginFrame();
    int l[4]={textWidth("SINGLE PLAYER")+6,textWidth("DOUBLE PLAYER")+6,textWidth("PRACTICE")+6,textWidth("BACK")+6};
    int h=textHeight()+6;
    coordinate p[4]={{683,284},{683,384},{683,484},{100,668}};
    Text t1(p[0].x,p[0].y,"SINGLE PLAYER");
    Rectangle r1(p[0].x,p[0].y,l[0],h);
    t1.setColor(COLOR("green"));
    r1.setColor(COLOR("green"));
    Text t2(p[1].x,p[1].y,"DOUBLE PLAYER");
    Rectangle r2(p[1].x,p[1].y,l[1],h);
    t2.setColor(COLOR("green"));
    r2.setColor(COLOR("green"));
    Text t3(p[2].x,p[2].y,"PRACTICE");
    Rectangle r3(p[2].x,p[2].y,l[2],h);
    t3.setColor(COLOR("green"));
    r3.setColor(COLOR("green"));
    Text t4(p[3].x,p[3].y,"BACK");
    Rectangle r4(p[3].x,p[3].y,l[3],h);
    t4.setColor(COLOR("green"));
    r4.setColor(COLOR("green"));
    endFrame();
    return whichclick(4,l,p,0);
}
void pageinst()
{
    beginFrame();
    Text t1(1366/2-200,50,"-Select weapon,angle and power by clicking on the respeective buttons.");
    Text t2(1366/2-200,100,"-Click the Fire button to fire your weapon.");
    Text t3(1366/2-200,150,"-You can check how different weapons work in target practice.");
    Text t4(1366/2-200,200,"Go ahead and enjoy the game.");
    Text t5(1366/2,250,"Back");
    coordinate c[]={{1366/2,250}};
    int l[]={textWidth("Back")+4};

    Rectangle r(1366/2,250,l[0],textHeight()+6);
    endFrame();
    whichclick(1,l,c,0);
    beginFrame();

}
int gameplay3(int choice)
{
    char name[2][15],colr[2][10];
    strcpy(name[0],"Player1");
    strcpy(name[1],"Player2");
    strcpy(colr[0],"green");
    strcpy(colr[1],"blue");
    int nofweap=n;
    char p1[20][20],p2[20][20];
    char wpns[n][20]={"Single Shot","Triple Shot","Jackhammer","Acid Rain","Sniper","Canon ball","Pineapple","Lightning Strike","Zapper","Tracer","Skipper","Homing Missile","Boomerang","Spider","Big Shot","Tommy Gun","Chain Reaction","Bazooka","Phaser","Mystery Bomb"};
    for(int i=0;i<n;i++)
    {
        strcpy(p1[i],wpns[i]);
        strcpy(p2[i],wpns[i]);
    }
    if(choice==2)
 {

    nofweap=n/2;
    {Text t1(1366/2,50,"PLAYER 1");
     tank_color(colr[0],name[0]);
     endFrame();
    }
    {
     Text T1(1366/2,50,"PLAYER 2");
     tank_color(colr[1],name[1]);
     endFrame();
    }


    weapon_select(p1,p2,name);
    endFrame();


}
    coordinate bgr[]={{150,650},{997-textWidth("<<<")/2+150,650},
                      {1003+textWidth(">>>")/2+150,650},{1000+150,700},{230,650},{350,690},{1366/2,650}};

    Text load(1366/2,300,"Loading....");

    beginFrame();

 //   Rectangle backg[5];
 //   background(backg);
    tank T1(200,550,200,560,210,550,190,570,210,570,colr[0],name[0],p1,nofweap);
    tank T2(1100,550,1100,560,1090,550,1090,570,1110,570,colr[1],name[1],p2,nofweap);

    T2.angle=180;//for T2 the angle is 180 according to the game

    T1.cr3end.x=T1.cr3.x-10*cos(-T1.r3.getOrientation());//change
    T1.cr3end.y=T1.cr3.y+10*sin(-T1.r3.getOrientation());//change
    Line Base(0,575,1366,575);
    int lh=textHeight()+6;
    int l[]={textWidth("ANGLE")+6,textWidth("<<<")+6,textWidth(">>>")+6,textWidth("EXIT")+6,textWidth("POWER")+6,textWidth("FIRE")+6,textWidth("Weapons")+6};
    Text ang(bgr[0].x,bgr[0].y,"ANGLE"), fwd(bgr[1].x,bgr[1].y,"<<<"), bwd(bgr[2].x,bgr[2].y,">>>"),ex(bgr[3].x,bgr[3].y,"EXIT"),power(bgr[4].x,bgr[4].y,"POWER"),fire(bgr[5].x,bgr[5].y,"FIRE");
    Text wp(bgr[6].x,bgr[6].y,"Weapons");
    coordinate player[2]={{100,700},{1266,700}};
    Text player1(player[0].x,player[0].y-10,T1.p_name);
    Text player2(player[1].x,player[1].y-10,T2.p_name);
    Text pts[2];
    for(int a=0;a<2;a++)
        pts[a].reset(player[a].x,player[a].y+6,int(0));//player1[a].reset(player[a].x,player[a].y,name[a]);




    Rectangle ang1(bgr[0].x,bgr[0].y,l[0],lh),fwd1(bgr[1].x,bgr[1].y,l[1],lh),bwd1(bgr[2].x,bgr[2].y,l[2],lh),ex1(bgr[3].x,bgr[3].y,l[3],lh),power1(bgr[4].x,bgr[4].y,l[4],lh),fire1(bgr[5].x,bgr[5].y,l[5],lh);
    Rectangle wp1(bgr[6].x,bgr[6].y,l[6],lh);
    coordinate powe2={bgr[4].x+l[4]/2+200,650};
    int powe2l=200;
    Rectangle power2(powe2.x,powe2.y,powe2l,15);

    Rectangle powscale(0,0,0,0);//Required to show the previous value of power
    powscale.setFill(1);
    float powscalelen[2]={0,0},powscalec[2]={0,0};
    Text prevang(bgr[0].x,bgr[0].y+lh,T1.angle);//Required to print the previous angle For T2 it is done as in the game
    Text selected(bgr[6].x,bgr[6].y+textHeight()+6,T1.weaponlist[0]);

    T2.r3.left(180);
    T2.cr3end.x=T2.cr3.x-10*cos(-T2.r3.getOrientation());//change
    T2.cr3end.y=T2.cr3.y+10*sin(-T2.r3.getOrientation());//change
    Turtle t;
    t.setColor(COLOR(249,89,10));
    t.hide();
    t.penUp();
    t.left(90);
    wait(0.1);
    load.reset(0,0,"");
    endFrame();
     while(true){
    {


    t.moveTo(T1.cr1.x,T1.cr1.y+50);//change

    t.show();
    int m;
    tank1:
    m=whichclick(7,l,bgr,0);
    if(m==1)
    {
        ang1.setColor(COLOR("green"));
        T1.angselect();
        prevang.reset(bgr[0].x,bgr[0].y+lh,T1.angle);
        ang1.setColor(COLOR(0,0,0));
        goto tank1;
    }
    else if(m==2)
    {
        fwd1.setColor(COLOR("green"));
        T1.movetank('b');
        fwd1.setColor(COLOR(0,0,0));
        t.hide();
        t.moveTo(T1.cr1.x,T1.cr1.y+50);
        t.show();
        goto tank1;
    }
   else if(m==3)
   {
       bwd1.setColor(COLOR("green"));
       T1.movetank('f');
       bwd1.setColor(COLOR(0,0,0));
       t.hide();
       t.moveTo(T1.cr1.x,T1.cr1.y+50);
       t.show();
       goto tank1;
   }
   else if(m==4)
   { beginFrame();
     return 4;
   }
   else if(m==5)
    {
        power1.setColor(COLOR("green"));
        int c;
        po:
        c=getClick();
        coordinate click={c/65536,c%65536};
        if(checkclick(click.x,click.y,powe2.x,powe2.y,powe2l,lh))
            {   powscalec[0]=(click.x+powe2.x-powe2l/2)/2;
                powscalelen[0]=click.x-(powe2.x-powe2l/2);
                powscale.reset(powscalec[0],powe2.y,powscalelen[0],15);
                powscale.setColor(COLOR(255,7,173));
                T1.power=10*sqrt((click.x-(powe2.x-powe2l/2))/2*1.5);
            }
        else if(checkclick(click.x,click.y,bgr[4].x,bgr[4].y,l[4],lh))
                ;
        else   goto po;
        power1.setColor(COLOR(0,0,0));
        goto tank1;
    }
    else if(m==6)
    {
        fire.setColor(COLOR("green"));
        firea(T1,T2);
        pts[0].reset(player[0].x,player[0].y+6,T1.pts);
        fire.setColor(COLOR(0,0,0));
        if(choice==2)
        for(int i=0;i<T1.nofw;i++)
           {

            if(strcmp(T1.selwpn,T1.weaponlist[i])==0)
            {
                for(int j=i+1;j<T1.nofw;j++)
                    strcpy(T1.weaponlist[j-1],T1.weaponlist[j]);
            }
            else continue;
            T1.nofw--;
            break;
           }
    }
    else if(m==7)
    {  wp1.setColor(COLOR("green"));
       weaponselplay(T1);
       selected.reset(bgr[6].x,bgr[6].y+textHeight()+6,T1.selwpn);
       endFrame();
       wp1.setColor(COLOR(0,0,0));
       goto tank1;
    }


    t.hide();
    powscale.reset(powscalec[1],powe2.y,powscalelen[1],15);
                powscale.setColor(COLOR(255,7,173));
    prevang.reset(bgr[0].x,bgr[0].y+lh,T2.angle);
    selected.reset(bgr[6].x,bgr[6].y+textHeight()+6,T2.weaponlist[0]);
    strcpy(T2.selwpn,T2.weaponlist[0]);
    }
    {
        t.moveTo(T2.cr1.x,T2.cr1.y+50);//change
        t.show();
        int m;
        tank2:
        m=whichclick(7,l,bgr,0);
        if(m==1)
        {
            ang1.setColor(COLOR("green"));

            T2.angselect();
            prevang.reset(bgr[0].x,bgr[0].y+lh,T2.angle);
            ang1.setColor(COLOR(0,0,0));
            goto tank2;
        }
        else if(m==2)
        {
            fwd1.setColor(COLOR("green"));
            T2.movetank('b');
            fwd1.setColor(COLOR(0,0,0));
            t.hide();
            t.moveTo(T2.cr1.x,T2.cr1.y+50);
            t.show();
            goto tank2;
        }
        else if(m==3)
        {
            bwd1.setColor(COLOR("green"));
            T2.movetank('f');
            bwd1.setColor(COLOR(0,0,0));
            t.hide();
            t.moveTo(T2.cr1.x,T2.cr1.y+50);
            t.show();
            goto tank2;
        }
        else if(m==4)
        {   beginFrame();
             return 4;
        }
        else if(m==5)
    {
        power1.setColor(COLOR("green"));
        int c;
        po1:
        c=getClick();
        coordinate click={c/65536,c%65536};
        if(checkclick(click.x,click.y,powe2.x,powe2.y,powe2l,lh))
           {    powscalec[1]=(click.x+powe2.x-powe2l/2)/2;powscalelen[1]=click.x-(powe2.x-powe2l/2);
                powscale.reset(powscalec[1],powe2.y,powscalelen[1],15);
                powscale.setColor(COLOR(255,7,173));
               T2.power=10*sqrt((click.x-(powe2.x-powe2l/2))/2*1.5);
           }
        else if(checkclick(click.x,click.y,bgr[4].x,bgr[4].y,l[4],lh))
                ;

        else
           goto po1;
        power1.setColor(COLOR(0,0,0));
        goto tank2;
    }
      else if(m==6)
    {
        fire.setColor(COLOR("green"));
        firea(T2,T1);
        pts[1].reset(player[1].x,player[1].y+6,T2.pts);
        fire.setColor(COLOR(0,0,0));
    if(choice==2)
    for(int i=0;i<T2.nofw;i++)
           {

            if(strcmp(T2.selwpn,T2.weaponlist[i])==0)
            {
                for(int j=i+1;j<T2.nofw;j++)
                    strcpy(T2.weaponlist[j-1],T2.weaponlist[j]);
            }
            else continue;
            T2.nofw--;
            break;
           }

    }
     else if(m==7)
    {  wp1.setColor(COLOR("green"));
       weaponselplay(T2);
       selected.reset(bgr[6].x,bgr[6].y+textHeight()+6,T2.selwpn);
       endFrame();
       wp1.setColor(COLOR(0,0,0));
       goto tank2;
    }

     if(T2.nofw==0)
        break;
        t.hide();
    powscale.reset(powscalec[0],powe2.y,powscalelen[0],15);
                powscale.setColor(COLOR(255,7,173));
    prevang.reset(bgr[0].x,bgr[0].y+lh,T1.angle);
    selected.reset(bgr[6].x,bgr[6].y+textHeight()+6,T1.weaponlist[0]);

    strcpy(T1.selwpn,T1.weaponlist[0]);
    }


 }
 if(choice==2)
 {  Text win;
     win.setColor(COLOR("red"));
     if(T1.pts>T2.pts)
        win.reset(T1.cr2.x,T1.cr2.y-25,"WINNER");
     else if(T1.pts<T2.pts)
        win.reset(T2.cr2.x,T2.cr2.y-25,"WINNER");
     else
        win.reset(1366/2,250,"TIE");
Text con(1366/2,300,"CLICK TO CONTINUE");
getClick();
 }
 return 0;//to get rid of warning
 }



