#include <TFT_eSPI.h>
TFT_eSPI tft = TFT_eSPI();
TFT_eSprite sprite = TFT_eSprite(&tft);

#define blue TFT_NAVY
#define window1 0x671F
#define window2 0x0433
#define gray 0xDEDB
#define gray0 0xEF5D
#define gray1 0x94B2
#define gray2 0x39E7
#define orange 0xFD20
#define yellow 0xFEA6
#define red TFT_RED
#define bck 0x0C79
#define flor 0x022C


#define up2 21
#define up3 17
#define down3 16
#define down2 18
#define up1 43
#define down1 2
#define left 3
#define right 44

#define led 13

double rad=0.01745;
int x[3];
int y[3];

int power=2;

int r[3]={78,64,26};  //radius for each part
int sx=90; 
int sy=108;

int xx=264;
int yy=64;

int angle[3]={290,60,80};
int deb=0;

void setup() {
   pinMode(up1,INPUT_PULLUP);
   pinMode(down1,INPUT_PULLUP);
   pinMode(up2,INPUT_PULLUP);
   pinMode(up3,INPUT_PULLUP);
   pinMode(down2,INPUT_PULLUP);
   pinMode(down3,INPUT_PULLUP);
   pinMode(left,INPUT_PULLUP);
   pinMode(right,INPUT_PULLUP);
   pinMode(0,INPUT_PULLUP);

   pinMode(led,OUTPUT);

   pinMode(15,OUTPUT);
   digitalWrite(15,1);

  tft.init();
  tft.setRotation(1);
  
  tft.fillScreen(TFT_ORANGE);
  sprite.createSprite(320,170);
  
     sprite.setTextColor(TFT_WHITE,blue);

     ledcSetup(0, 10000, 8);
     ledcAttachPin(38, 0);
     ledcWrite(0, 92);
     
}

void draw()
  {
  
    sprite.fillSprite(TFT_WHITE);
    sprite.fillRect(0,140,320,30,flor);


    for(int i=0;i<21;i++){
    sprite.drawLine(i*16,0,i*16,140,0x66FF);
    sprite.drawLine(i*16,140,(i*16)-46,170,bck);}

     for(int i=0;i<10;i++)
     sprite.drawLine(0,140-i*16,320,140-i*16,0x66FF);

      for(int i=0;i<4;i++)
      sprite.drawLine(0,141+i*8,320,141+i*8,bck);

     //sprite.drawRect(192,28,7*16,6*16,gray2);

    sprite.drawWedgeLine(sx, sy, x[0], y[0], 12, 8, orange);
    sprite.drawWedgeLine(sx, sy, x[0], y[0], 10, 6, yellow);

    sprite.drawWedgeLine(x[0], y[0], x[1], y[1], 8, 4, orange);
    sprite.drawWedgeLine(x[0], y[0], x[1], y[1], 6, 2,yellow);
    
    sprite.drawWedgeLine(x[1], y[1], x[2], y[2], 4, 1, gray2);

    sprite.fillCircle(x[0], y[0],3,gray2);
    sprite.fillCircle(x[1], y[1],1,gray1);


    sprite.fillRect(sx-51, sy-36, 7, 12, gray1); 
    sprite.fillRect(sx-50, sy-46, 5, 10, gray1); 
    sprite.fillRect(sx-55, sy-51, 10, 5, gray1); 

    sprite.fillRoundRect(sx-40, sy-60, 40, 70, 4, gray2); 
    sprite.fillRoundRect(sx-40, sy-10, 60, 20, 4, gray2); 

    sprite.fillTriangle(sx, sy-58, sx, sy-8, sx+19, sy-8, gray2);

    sprite.fillRoundRect(sx-60, sy+8, 80, 8, 4, orange);
    sprite.fillRect(sx-60, sy-2, 80, 13, yellow);
    sprite.fillTriangle(sx-60, sy-8, sx+19, sy+4, sx+19, sy-8, gray2);
    sprite.fillRoundRect(sx-60, sy-30, 30, 40,4, yellow);

    sprite.fillRoundRect(sx-26, sy-54, 16, 24, 3, window2); 
    sprite.fillRoundRect(sx-24, sy-52, 12, 20, 3, window1); 
    sprite.fillRoundRect(sx-26, sy-28, 16, 20, 3, window2); 
    sprite.fillRoundRect(sx-24, sy-26, 12, 16, 3, window1); 
    sprite.fillTriangle(sx-5, sy-54, sx-5, sy-8, sx+14, sy-8, window2);
    sprite.fillTriangle(sx-2, sy-50, sx-2, sy-9, sx+14, sy-9, window1);

    sprite.fillTriangle(sx+14, sy-8, sx-2, sy-8, sx+16, sy-4, window1);
    
    sprite.fillRect(sx-54, sy-24, 18,2, orange);
    sprite.fillRect(sx-54, sy-20, 18,2, orange);
    sprite.fillRect(sx-54, sy-16, 18,2, orange);
    sprite.fillRect(sx-54, sy-12, 18,2, orange);
    
    sprite.fillRoundRect(sx-40, sy+15, 40, 8, 4, gray2); 
    sprite.fillRoundRect(sx-50, sy+19, 60, 8, 4, gray1); 

    sprite.fillRoundRect(sx-70, sy+24, 100, 32, 16, gray2);  /// gusjenica
    sprite.fillRoundRect(sx-65, sy+29, 90, 22, 11, orange);
    sprite.fillRoundRect(sx-64, sy+32, 86, 19, 9, yellow);

    sprite.fillCircle(sx-52, sy+40, 9, gray2);
    sprite.fillCircle(sx-52, sy+40, 6, gray1);
    sprite.fillCircle(sx-52, sy+40, 3, gray2);

    sprite.fillCircle(sx+10, sy+45, 5, gray2);
    sprite.fillCircle(sx-2, sy+45, 5, gray2);
    sprite.fillCircle(sx-14, sy+45, 5, gray2);

    sprite.fillCircle(sx+10, sy+45, 3, gray1);
    sprite.fillCircle(sx-2, sy+45, 3, gray1);
    sprite.fillCircle(sx-14, sy+45, 3, gray1);
    sprite.fillCircle(sx+10, sy+45, 2, gray2);
    sprite.fillCircle(sx-2, sy+45, 2, gray2);
    sprite.fillCircle(sx-14, sy+45, 2, gray2);

    sprite.fillRoundRect(sx-22, sy+35, 40, 6, 2, gray2);
    sprite.drawLine(sx-20,sy+37,sx+16,sy+37,gray1);


    sprite.fillRect(4,4,44,36,blue);

    sprite.setTextColor(TFT_WHITE,blue);
    for(int i=0;i<3;i++)
    sprite.drawString("A"+String(i+1)+":"+String(angle[i]),8,8+(i*10));
    
    sprite.setTextColor(TFT_BLACK,TFT_WHITE);
    sprite.drawString("ON/OFF",4,44);
    sprite.drawString("POWER:",52,4);
    
    sprite.drawString("X:"+String(x[2])+" Y:"+String(y[2]),234,124,2);

    for(int i=0;i<5;i++)
    sprite.fillRect(88+(i*5),4,3,7,gray0);

    for(int i=0;i<power;i++)
    sprite.fillRect(88+(i*5),4,3,7,gray2);

    sprite.fillRect(4,54,24,8,red);


sprite.fillCircle(xx,yy,2,red);
sprite.drawCircle(xx,yy,7,red);
sprite.drawCircle(xx,yy,6,red);

sprite.drawCircle(xx,yy,12,red);
sprite.drawCircle(xx,yy,11,red);

sprite.fillRect(xx-1,yy-16,3,10,red);
sprite.fillRect(xx-1,yy+6,3,10,red);

sprite.fillRect(xx-16,yy-1,10,3,red);
sprite.fillRect(xx+6,yy-1,10,3,red);

    sprite.pushSprite(0,0);
  
  }

void loop() {

power=map(analogRead(1),0,4095,1,5);

  if(digitalRead(0)==0)
  {
  if(deb==0){deb=1; xx=random(200,300); yy=random(25,114);}
  }else deb=0;

  if(digitalRead(up1)==0)
  {angle[0]=angle[0]+power;
  angle[1]=angle[1]+power;
  angle[2]=angle[2]+power;
  }

  if(digitalRead(down1)==0)
  {
  angle[0]=angle[0]-power;
  angle[1]=angle[1]-power;
  angle[2]=angle[2]-power;}

  if(digitalRead(up2)==0)
  {angle[1]=angle[1]+power;
  angle[2]=angle[2]+power;}

  if(digitalRead(down2)==0)
  {angle[1]=angle[1]-power;
  angle[2]=angle[2]-power;}

  if(digitalRead(up3)==0)
  {angle[2]=angle[2]+power;}

  if(digitalRead(down3)==0)
  {angle[2]=angle[2]-power;}

  if(digitalRead(right)==0)
  {sx=sx+power; }

   if(digitalRead(left)==0)
   {sx=sx-power; }  


  if(angle[0]>=359) angle[0]=0;
  if(angle[1]>=359) angle[1]=0;
  if(angle[2]>=359) angle[2]=0;

  if(angle[0]<0) angle[0]=359;
  if(angle[1]<0) angle[1]=359;
  if(angle[2]<0) angle[2]=359;
 
         x[0]=(r[0]*cos(rad*angle[0]))+sx;
         y[0]=(r[0]*sin(rad*angle[0]))+sy;

         x[1]=(r[1]*cos(rad*angle[1]))+x[0];
         y[1]=(r[1]*sin(rad*angle[1]))+y[0];

         x[2]=(r[2]*cos(rad*angle[2]))+x[1];
         y[2]=(r[2]*sin(rad*angle[2]))+y[1];

    if(x[2]>xx-5 && x[2]<xx+5 && y[2]>yy-5 && y[2]<yy+5)
    digitalWrite(led,1);
    else
    digitalWrite(led,0);

draw();
}
