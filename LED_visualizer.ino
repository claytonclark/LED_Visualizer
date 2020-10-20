#include <arduinoFFT.h>

const int sound = A2;
double val, dat;
double im[128], data[128];

int blue = 11;
int red = 9;
int green = 7;

int ON = 0;
int OFF = 255;

void setup() {
  Serial.begin(9600);
  analogWrite(blue, 255);
  analogWrite(green, 255);
  analogWrite(red, 255);
}

void loop() {
  int min = 1024, max = 0;
  for(int i = 0; i < 128; i ++){
    val = analogRead(sound);
    data[i] = val /4 -128;
    im[i] = 0;
    if(val>max){
      max = val;
    }
    if(val<min){
      min = val;
    }
  }
  arduinoFFT(data, im, 7, 0);

  for(int i = 1; i < 128; i++){
    dat = sqrt(data[i] * data[i] + im[i] * im [i]);//elimates noise
    //dat = data[i]+im[i];
  }
  Serial.println(dat);
  LEDSetup(dat);
}
