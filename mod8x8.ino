void drawLevens(int i) {
   
  switch (i)  {
  
    case 0:
    break;
    
    case 1:  
    draw14Heart(0);
    break;
    
    case 2:
    draw12Heart(0);
    break;
    
    case 10:
    draw34Heart(0);
    break;
    
    case 3:
    drawFullHeart(0);
    break;
    case 4:
    drawFullHeart(0);
    draw14Heart(8);
    break;
    case 5:
    drawFullHeart(0);
    draw12Heart(8);
    break;
    case 11:
    drawFullHeart(0);
    draw34Heart(8);
    break;
    case 6:
    drawFullHeart(0);
    drawFullHeart(8);
    break;
    case 7:
    drawFullHeart(0);
    drawFullHeart(8);
    draw14Heart(16);
    break;
    case 8:
    drawFullHeart(0);
    drawFullHeart(8);
    draw12Heart(16);
    break;
    case 12:
    drawFullHeart(0);
    drawFullHeart(8);
    draw34Heart(16);
    break;
    case 9:
    drawFullHeart(0);
    drawFullHeart(8);
    drawFullHeart(16);
    break;
  }
 
    
}

void drawFullHeart(int i)  {
    
   color=1;
   i=i+32;
   drawPixel(i+2,8);drawPixel(i+7,8);
   drawPixel(i+1,7);drawPixel(i+2,7);drawPixel(i+3,7);drawPixel(i+6,7);drawPixel(i+7,7);drawPixel(i+8,7);
   drawPixel(i+1,6);drawPixel(i+2,6);drawPixel(i+3,6);drawPixel(i+4,6);drawPixel(i+5,6);drawPixel(i+6,6);drawPixel(i+7,6);drawPixel(i+8,6);
   drawPixel(i+1,5);drawPixel(i+2,5);drawPixel(i+3,5);drawPixel(i+4,5);drawPixel(i+5,5);drawPixel(i+6,5);drawPixel(i+7,5);drawPixel(i+8,5);
   drawPixel(i+2,4);drawPixel(i+3,4);drawPixel(i+4,4);drawPixel(i+5,4);drawPixel(i+6,4);drawPixel(i+7,4);
   drawPixel(i+3,3);drawPixel(i+4,3);drawPixel(i+5,3);drawPixel(i+6,3);drawPixel(i+4,2);drawPixel(i+5,2);drawPixel(i+4,1);drawPixel(i+5,1);
     
}

void draw34Heart(int i)  {
  color=1;
   i=i+32;
   drawPixel(i+1,6);drawPixel(i+2,6);drawPixel(i+3,6);drawPixel(i+4,6);drawPixel(i+5,6);drawPixel(i+6,6);drawPixel(i+7,6);drawPixel(i+8,6);
   drawPixel(i+1,5);drawPixel(i+2,5);drawPixel(i+3,5);drawPixel(i+4,5);drawPixel(i+5,5);drawPixel(i+6,5);drawPixel(i+7,5);drawPixel(i+8,5);
   drawPixel(i+2,4);drawPixel(i+3,4);drawPixel(i+4,4);drawPixel(i+5,4);drawPixel(i+6,4);drawPixel(i+7,4);
   drawPixel(i+3,3);drawPixel(i+4,3);drawPixel(i+5,3);drawPixel(i+6,3);drawPixel(i+4,2);drawPixel(i+5,2);drawPixel(i+4,1);drawPixel(i+5,1);
     
}
void draw12Heart(int i)  {
  color=1;
   i=i+32; 
   drawPixel(i+2,4);drawPixel(i+3,4);drawPixel(i+4,4);drawPixel(i+5,4);drawPixel(i+6,4);drawPixel(i+7,4);
   drawPixel(i+3,3);drawPixel(i+4,3);drawPixel(i+5,3);drawPixel(i+6,3);drawPixel(i+4,2);drawPixel(i+5,2);drawPixel(i+4,1);drawPixel(i+5,1);
     
}
void draw14Heart(int i)  {
  color=1;
   i=i+32;
   drawPixel(i+4,2);drawPixel(i+5,2);drawPixel(i+4,1);drawPixel(i+5,1);
   
}

void drawPower(int i)  {
  color=1
  ;
  for (int j=1;j<i;j++)  {
    
    drawPixel(j+56,1);drawPixel(j+56,2);drawPixel(j+56,3);drawPixel(j+56,4);drawPixel(j+56,5);drawPixel(j+56,6);drawPixel(j+56,7);drawPixel(j+56,8);
    
  }
}

void drawTeeth()  {
  
   color=4;
   // TAND 1  
   drawPixel(1,8);drawPixel(1,7);drawPixel(1,6);drawPixel(1,5);
   drawPixel(2,8);drawPixel(2,7);drawPixel(2,6);drawPixel(2,5);
   drawPixel(3,8);drawPixel(3,7);drawPixel(3,6);drawPixel(3,5);
   drawPixel(4,8);drawPixel(4,7);drawPixel(4,6);drawPixel(4,5);
   drawPixel(5,8);drawPixel(5,7);drawPixel(5,6);drawPixel(5,5);
   
   // TAND 2 
   drawPixel(6,8);drawPixel(6,7);drawPixel(6,6);
   drawPixel(7,8);drawPixel(7,7);drawPixel(7,6);
   drawPixel(8,8);drawPixel(8,7);drawPixel(8,6);
   drawPixel(9,8);drawPixel(9,7);drawPixel(9,6);
   drawPixel(10,8);drawPixel(10,7);drawPixel(10,6);
   
   // TAND 3
   drawPixel(11,8);drawPixel(11,7);drawPixel(11,6);drawPixel(11,5);drawPixel(11,4);drawPixel(11,3);
   drawPixel(12,8);drawPixel(12,7);drawPixel(12,6);drawPixel(12,5);drawPixel(12,4);drawPixel(12,3);
   drawPixel(13,8);drawPixel(13,7);drawPixel(13,6);drawPixel(13,5);drawPixel(13,4);drawPixel(13,3);
   drawPixel(14,8);drawPixel(14,7);drawPixel(14,6);drawPixel(14,5);drawPixel(14,4);drawPixel(14,3);
   drawPixel(15,8);drawPixel(15,7);drawPixel(15,6);drawPixel(15,5);drawPixel(15,4);drawPixel(15,3);
   
   // TAND 4
   drawPixel(16,8);drawPixel(16,7);drawPixel(16,6);drawPixel(16,5);
   drawPixel(17,8);drawPixel(17,7);drawPixel(17,6);drawPixel(17,5);
   drawPixel(18,8);drawPixel(18,7);drawPixel(18,6);drawPixel(18,5);
   drawPixel(19,8);drawPixel(19,7);drawPixel(19,6);drawPixel(19,5);
   
   // TAND 5
   drawPixel(21,8);drawPixel(21,7);drawPixel(21,6);drawPixel(21,5);drawPixel(21,4);
   drawPixel(22,8);drawPixel(22,7);drawPixel(22,6);drawPixel(22,5);drawPixel(22,4);
   drawPixel(23,8);drawPixel(23,7);drawPixel(23,6);drawPixel(23,5);drawPixel(23,4);
   drawPixel(24,8);drawPixel(24,7);drawPixel(24,6);drawPixel(24,5);drawPixel(24,4);
   
   
}

