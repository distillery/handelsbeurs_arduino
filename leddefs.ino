void updateDIGITS(char c[3], int TYPE)  {
   boolean goodData = true;
   int ledbinaries[3];
   for (int i=0;i<3;i++)  {
   switch (c[i])  {
    
    case '1':
     ledbinaries[i]=een;
     break;  
    case '2':
     ledbinaries[i]=twee;
     break;
    case '3':
     ledbinaries[i]=drie;
     break;  
    case '4':
     ledbinaries[i]=vier;
     break;
    case '5':
     ledbinaries[i]=vijf;
     break;  
    case '6':
     ledbinaries[i]=zes;
     break;
    case '7':
     ledbinaries[i]=zeven;
     break;  
    case '8':
     ledbinaries[i]=acht;
     break;
    case '9':
     ledbinaries[i]=negen;
     break;  
    case '0':
     ledbinaries[i]=nul;
     break;
    default:
      goodData = false;
   }
   }
  if (goodData)  {
    
      switch (TYPE)  {
       
        case 0: // SCORE
         updateShiftRegisterSCORE(ledbinaries);
         break;
         
        case 1: // TOPSCORE
         updateShiftRegisterTOPSCORE(ledbinaries);
         break;
        
        case 2: // RANKING
         //updateShiftRegisterRANKING(ledbinaries);
         break;
        
      } 
  }
  
}

// SCORE
void updateShiftRegisterSCORE(int leds[3])
{
   digitalWrite(latchPinScore, LOW);
    shiftOut(dataPinScore, clockPinScore, MSBFIRST, leds[2]);
    shiftOut(dataPinScore, clockPinScore, MSBFIRST, leds[1]);
    shiftOut(dataPinScore, clockPinScore, MSBFIRST, leds[0]);
   digitalWrite(latchPinScore, HIGH);
}
// HIGH SCORE

void updateShiftRegisterTOPSCORE(int leds[3])
{
   digitalWrite(latchPinTopScore, LOW);
    shiftOut(dataPinTopScore, clockPinTopScore, MSBFIRST, leds[2]);
    shiftOut(dataPinTopScore, clockPinTopScore, MSBFIRST, leds[1]);
    shiftOut(dataPinTopScore, clockPinTopScore, MSBFIRST, leds[0]);
   digitalWrite(latchPinTopScore, HIGH);
}
/*
// RANKING

void updateShiftRegisterRANKING(int leds[3])
{
   digitalWrite(latchPinRanking, LOW);
    shiftOut(dataPinRanking, clockPinRanking, MSBFIRST, leds[2]);
    shiftOut(dataPinRanking, clockPinRanking, MSBFIRST, leds[1]);
    shiftOut(dataPinRanking, clockPinRanking, MSBFIRST, leds[0]);
   digitalWrite(latchPinRanking, HIGH);
}
*/

  
