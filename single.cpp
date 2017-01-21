#include "tanks.h"
#include "weapons.h"
const int n=20;
int singleplayer()


{
    int level;
    float angc[3][5];
    for(int i=0;i<5;i++)
    {
        angc[0][i]=-5+11.0/5*i;
        angc[1][i]=-3+7.0/5*i;
        angc[2][i]=-1+3.0/5*i;
    }
    char name[2][15],colr[2][10];
    {
        Text t1(1366/2,50,"PLAYER 1");
        tank_color(colr[0],name[0]);
        endFrame();
        Text t3(300,370,"DIFFICULTY LEVEL:");
        coordinate p[3]={{400,370},{600,370},{800,370}};
        char c[][10]={"Easy","Medium","Difficult"};
        Text t[3];
        int l[3],h=textHeight()+6;
        Rectangle r[3];
        for(int i=0;i<3;i++)
        {
            l[i]=textWidth(c[i])+6;
            t[i].reset(p[i].x,p[i].y,c[i]);
            r[i].reset(p[i].x,p[i].y,l[i],h);
        }
        level=whichclick(3,l,p,0);
        strcpy(name[1],"CPU");
        strcpy(colr[1],"black");
    }
    char p1[20][20],p2[20][20];
    weapon_select(p1,p2,name,1);
    coordinate bgr[]={{150,650},{997-textWidth("<<<")/2+150,650},
                      {1003+textWidth(">>>")/2+150,650},{1000+150,700},{230,650},{350,690},{1366/2,600}};
    Text load(1366/2,300,"Loading....");

    beginFrame();
     tank T1(200,550,200,560,210,550,190,570,210,570,colr[0],name[0],p1,n/2);
    tank T2(1100,550,1100,560,1090,550,1090,570,1110,570,colr[1],name[1],p2,n/2);
    T2.angle=180;
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
    load.reset(0,0,"");
    endFrame();
    while(true)
    {
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
    return 4;
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
        else
           goto po;
        power1.setColor(COLOR(0,0,0));
        goto tank1;
    }
    else if(m==6)
    {
        fire.setColor(COLOR("green"));
        firea(T1,T2);
        pts[0].reset(player[0].x,player[0].y+6,T1.pts);
        fire.setColor(COLOR(0,0,0));
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
    {   wp1.setColor(COLOR("green"));
       weaponselplay(T1);
       selected.reset(bgr[6].x,bgr[6].y+textHeight()+6,T1.selwpn);
       endFrame();
       wp1.setColor(COLOR(0,0,0));
       goto tank1;
    }



     t.hide();
    powscale.reset(powscalec[1],powe2.y,powscalelen[1],15);
                powscale.setColor(COLOR(255,7,173));
    prevang.reset(bgr[0].x,bgr[0].y+lh,180-T2.angle);
    selected.reset(bgr[6].x,bgr[6].y+textHeight()+6,T2.weaponlist[0]);
    strcpy(T2.selwpn,T2.weaponlist[0]);
    }
    {
    t.moveTo(T2.cr1.x,T2.cr1.y+50);
    wait(0.5);
    long double a,b=(T2.cr2.x-T1.cr2.x-25)*9.8;
    a=abs(b) + rand()/(RAND_MAX+0.001)*abs(b/0.9-b);
    T2.power=pow(a,0.5);
    powscalelen[1]=a/100*2/1.5;
    powscalec[1]=powscalelen[1]/2+(powe2.x-powe2l/2);
    powscale.reset(powscalec[1],powe2.y,powscalelen[1],15);
    powscale.setColor(COLOR(255,7,173));
    wait(0.5);
    if(b>0)
    {if(rand()%2)
        T2.angle=180-arcsine(b/a)/2;
    else
        T2.angle=180-(180-arcsine(b/a))/2;
    }
    else
    {
        if(rand()%2)
            T2.angle=arcsine(-b/a)/2;
        else
            T2.angle=(180-arcsine(-b/a))/2;
    }
    T2.angle+=angc[level-1][rand()%5];

    T2.cr3.x=T2.cr3end.x+10*cosine(T2.angle);T2.cr3.y=T2.cr3end.y-10*sine(T2.angle);//change
    T2.r3.reset(T2.cr3.x,T2.cr3.y,20,3);//change
    T2.r3.left(T2.angle);
    prevang.reset(bgr[0].x,bgr[0].y+lh,T2.angle);
    wait(0.5);
    strcpy(T2.selwpn,T2.weaponlist[rand()%T2.nofw]);
    selected.reset(bgr[6].x,bgr[6].y+textHeight()+6,T2.selwpn);
    wait(0.5);
    for(int i=0;i<T2.nofw;i++)
            if(strcmp(T2.selwpn,T2.weaponlist[i])==0)
            {
                for(int j=i+1;j<T2.nofw;j++)
                    strcpy(T2.weaponlist[j-1],T2.weaponlist[j]);
            }
    T2.nofw--;
    if(!strcmp(T2.selwpn,"Bazooka"))
    {
        if(T2.cr2.x>T1.cr2.x)
            T2.angle=180;
        else
            T2.angle=0;
         T2.cr3.x=T2.cr3end.x+10*cosine(T2.angle);T2.cr3.y=T2.cr3end.y-10*sine(T2.angle);//change
    T2.r3.reset(T2.cr3.x,T2.cr3.y,20,3);//change
    T2.r3.left(T2.angle);
    prevang.reset(bgr[0].x,bgr[0].y+lh,T2.angle);
    wait(0.5);

    }
    fire.setColor(COLOR("green"));

    firea(T2,T1);
    fire.setColor(COLOR(0,0,0));
    pts[1].reset(player[1].x,player[1].y+6,T2.pts);

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
Text win;
     win.setColor(COLOR("red"));
     if(T1.pts>T2.pts)
        win.reset(T1.cr2.x,T1.cr2.y-25,"WINNER");
     else if(T1.pts<T2.pts)
        win.reset(T2.cr2.x,T2.cr2.y-25,"WINNER");
     else
        win.reset(1366/2,250,"TIE");
Text con(1366/2,300,"CLICK TO CONTINUE");
getClick();
return 0;
beginFrame();
}
