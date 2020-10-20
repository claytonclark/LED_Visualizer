void LEDSetup(int data){
  bool isoff = true;
  if(data > 80){
      color(OFF, OFF, ON);
 /* }else if(data >60){
    for(int i = 0; i < 255;i++){
      color(i, 60, OFF);
      delay(0.1);
    }
  }else if(data >35){
    int b = 120;
    for(int i = 0; i < 255;i++){
      color(i, OFF, b);
      b--;
      delay(0.1);
    }
  }else if(data<100 && isoff == false){
     for(int i = 0; i < 255;i++){
      color(OFF, OFF, i);
      delay(0.1);
    }*/
  }else{
    color(OFF,OFF,OFF);
  }
}

void color(int r, int g, int b){
  analogWrite(red, r);
  analogWrite(green, g);
  analogWrite(blue, b);
}
