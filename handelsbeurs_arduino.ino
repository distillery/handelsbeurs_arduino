/* Include libraries */
/*********************/
#include "SPI.h"
#include "font.h"
#include "lcd8x8rgb.h"
#include "nerdwhacker.h"

// R8Q85c6U
/* Define arduino pins */
/*********************/

// TOPSCORE
#define dataPinTopScore 38
#define latchPinTopScore 36
#define clockPinTopScore 34

// SCORE
#define dataPinScore 26
#define latchPinScore 24
#define clockPinScore 22

// LEVENS
#define latchPinLevens 2

#define resetPin 9

#define SCORE 0
#define TOPSCORE 1
#define RANKING 2

#define BUFFERSIZE 7 // 3x voor score, 1 leven, 3x topscore
#define aantalPiezzos 12 //eerste piezo op analog0, 2e op analog1 enz
#define treshold 75

/* TODO */
/* START/RESET button: serial.write "r"; OF verwacht z\r\n */
/* TOP SCORE: 3 extra digits inlezen / gewoon wachten op newline */
/* PRINTER! iprototype */
/* speakers!! */

char bufferSERIAL[BUFFERSIZE]; // buffer voor seriele communicatie: 0,1,2 voor TOPSCORE, 3 voor aantal LEVENS
char plexi; 
unsigned long Timer;
unsigned long Timer2;
int val; // waarde vd piezo
int highest; // voor het bijhouden van de tot op een bepaald moment gemeten hoogste waarde
//int SCORE;
//int HIGHSCORE;
int LEVENS=9;
char dataFromOF[3];
int timeCount; // variabele om 'tijd bij te houden, en op die manier MODLEDS op te daten
boolean hold=false; // boolean om bij te houden of delay van 500ms moet toegepast worden
int reset = 0; // var voor inlezen van resetPin


void setup() 
{
  /* Setup arduino pins */
  
  pinMode(latchPinTopScore, OUTPUT);
  pinMode(dataPinTopScore, OUTPUT);  
  pinMode(clockPinTopScore, OUTPUT);
  pinMode(latchPinScore, OUTPUT);
  pinMode(dataPinScore, OUTPUT);  
  pinMode(clockPinScore, OUTPUT);
  pinMode(latchPinLevens, OUTPUT);
  pinMode(resetPin, INPUT);
  
  SPI.setDataMode(SPI_MODE1);
  SPI.setClockDivider(SPI_CLOCK_DIV64);
  SPI.begin();
  pinMode(chipSelectPin, OUTPUT);

   vClear();
  
  dataFromOF[0] = '0';dataFromOF[1] = '0';dataFromOF[2] = '0';
  
  updateDIGITS(dataFromOF, SCORE);
  updateDIGITS(dataFromOF, TOPSCORE);
  
  Serial.begin(115200);
  
}

void loop() 
{
     drawLevens(LEVENS);
     //drawTeeth();
     drawDistillery();
    /* 
      INLEZEN WAARDE RESETPIN (LOW/HIGH)
    */
    
    reset = digitalRead(resetPin);   // read the input pin
    if (reset == 1) {
      Serial.print('p');
      //Serial.println("/____Reset");
      delay(1000);
      
    }
    /*
      PIEZO'S ALLEEN LEZEN ALS HOLD=0 (= 500 ms delay na een hit)
    */
    
    if  ((millis() - Timer > 500 ) || !(hold)) {  
      
        Timer = millis();
        hold=false;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
        
        highest=0;
	val=0;
	plexi='y';  
        
        /* 
          // READ PIEZO'S
          Rijtje afgaan: als de gemeten waarde vd piezo groter is dan de treshold en groter dan de hoogste waarde wordt de highest aangepast
          en de piezo waarop is geslaan bijgehouden. Als er een hit is geweest: delay van 500ms - ervan uitgaande dat de piezo op de plexi
          waarop geslaan is ALTIJD de hoogste waarde zal zijn. De natrillingen worden opgevangen door de delay.
         */
        for (int i=0;i<aantalPiezzos;i++)  {
	    
            val = analogRead(i);
            
            if ((val > treshold) && (val > highest)) {
              plexi=plexis[i]; 
              highest=val;
              //Serial.println(highest);
            }
            delay(1);
	    
        }
        if (plexi != 'y') {  //oplossen!
          
          // debug
          Serial.print(plexi);
          drawPower(map(highest,0,1024,0,24));
          //Serial.print(" - ");
  	  //Serial.println(highest);
          hold=true;
          //delay(500);
          
        }
        
    } // END if millis
        // READ OPENFRAMEWORKS
         int i=0;
        // if data is available on hardwareserial port ==> data is comming from PC or notebook
        if (Serial.available())  {
          delay(1);
          while(Serial.available())          // reading data into char array 
            {
      
              bufferSERIAL[i]=Serial.read();     // writing data into array
              if (bufferSERIAL[i] == 13) break;
              i++;
            }
            // GET SCORE    
        dataFromOF[2]=bufferSERIAL[0];
        dataFromOF[1]=bufferSERIAL[1];
        dataFromOF[0]=bufferSERIAL[2];
        // DEBUG
      /*
        Serial.print(bufferSERIAL[0]);
        Serial.print(bufferSERIAL[1]);
        Serial.print(bufferSERIAL[2]);
        Serial.print(bufferSERIAL[3]);
        Serial.print(bufferSERIAL[4]);
        Serial.print(bufferSERIAL[5]);
        Serial.print(bufferSERIAL[6]);
        Serial.print(bufferSERIAL[7]);
        Serial.println();;
       
        */
      // SHOW SCORE ON DIGITS
      updateDIGITS(dataFromOF,SCORE);

      // GET aantal LEVENS & UPDATE LEVENS
      char life2=bufferSERIAL[3];  
      
      switch (life2)  {
         
                
         case '0':
           LEVENS=0;
           break;
         case '1':
           LEVENS=1;
           break;
         case '2':
           LEVENS=2;
           break;
         case '3':
           LEVENS=3;
           
           break;
         case '4':
           LEVENS=4;
           
           break;
         case '5':
           LEVENS=5;
           
           break;
         case '6':
           LEVENS=6;
           
           break;
         case '7':
           LEVENS=7;
           
           break;
         case '8':
           LEVENS=8;
           
           break;
         case '9':
           LEVENS=9;
                      
           break;
       }
  /*     
       char life1=bufferSERIAL[3];
       
         switch (life1) {
           
            case '1':
            LEVENS +=10;
           
         }
  */      
  
        
       // GET TOPSCORE & SHOW IT
       
        dataFromOF[2]=bufferSERIAL[4];
        dataFromOF[1]=bufferSERIAL[5];
        dataFromOF[0]=bufferSERIAL[6];
        updateDIGITS(dataFromOF,TOPSCORE);
        
        //showLevens(i);
        
        // GET RANKING & SHOW IT
        //dataFromOF[2]=bufferSERIAL[8];
        //dataFromOF[1]=bufferSERIAL[9];
        //dataFromOF[0]=bufferSERIAL[10];
        //updateDIGITS(dataFromOF,RANKING);
       /*
       // SHOW HIGHSCORE on DIGITS & UPDATE HIGH SCORE --- altijd op alleen op het einde..?
       if ((LEVENS == 0) && (SCORE > HIGHSCORE)) {
    
            HIGHSCORE = SCORE;
            
    
       }
       */
      // CLEAR SERIAL BUFFER
      for (int i=0;i<BUFFERSIZE;i++)  {
        bufferSERIAL[i]=NULL;     // writing data into array
      }
   } // EINDE VAN IF SERIAL AV -> pas hier op 't eind: indien geen data, moet er niets gedaan worden
   Transfer();
   delay(sdelay);
   vClear();
   //delay(1);
} //END OF VOID LOOP  
  







