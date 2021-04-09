#include <FastLED.h>
#include <stdlib.h>
#include <time.h>

#define LED_PIN     5
#define NUM_LEDS    18

CRGB leds[NUM_LEDS];

void setup() {
  srand (time(NULL));
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  
}
void loop() {
//  RtoG(80);
//  int t = 50;
//  for(int i = 0; i < 9; i++){
//    forward(255, 30, 30, t);
//    reverse(30, 30, 255, t);
//    if(i < 3){
//      t -= 13;
//    }else{
//      t -= 1;
//    }
//  }
  bilnk(255, 0, 0, 40, 3);
  outBomb(61, 52, 139);
  inBomb(118, 120, 237);
  outBomb(247, 184, 1);
  inBomb(241, 135, 1);
  bilnk(243, 91, 4, 110, 2);
  randomFade(255, 0, 0);
}
void RtoG(int t){
  int r = 255, g = 0, b = 0;
  int delta = 14;
  int hue = 0;
  for(int i = 0; i < NUM_LEDS; i++){
    for(int j = 0; j < NUM_LEDS; j++){
      int count = i - j;
      leds[j] = CHSV(hue++, 255, 255);
    }
    FastLED.show();
    delay(t);
  }
}

void randomFade(int r, int g, int b){
  double mn = 0,mx =17;
  int x =0;
  for(int i = 0; i < NUM_LEDS; i++){
    leds[i] = CRGB(r, g, b);
  }
  FastLED.show();
  delay(400);
  for(int i = 0; i < 50; i++){
    if(leds[x] != (CRGB(0, 0, 0))){
      leds[x] = CRGB(0, 0, 0);
    }
    FastLED.show();
    delay(25);
    x =(int)(((mx-mn)*rand()/(RAND_MAX)+1.0)+mn);
  }
  delay(100);
}

void forward(int r, int g, int b, int t){
  for(int i = 1; i < NUM_LEDS - 2; i++){
    leds[i - 1] = CRGB(0, 0, 0);
    leds[i] = CRGB(r, g, b);
    leds[i + 1] = CRGB(r, g, b);
    leds[i + 2] = CRGB(r, g, b);
    FastLED.show();
    delay(t);
  }
}

void reverse(int r, int g, int b, int t){
  for(int i = NUM_LEDS - 1; i > 2; i--){
    leds[i + 1] = CRGB(0, 0, 0);
    leds[i] = CRGB(r, g, b);
    leds[i - 1] = CRGB(r, g, b);
    leds[i - 2] = CRGB(r, g, b);
    FastLED.show();
    delay(t);
  }
}
void bilnk(int r, int g, int b, int t, int repeat){
  for(int j = 0; j < repeat; j++){
    for(int i = 0; i < NUM_LEDS; i++){
      leds[i] = CRGB(r, g, b);
    }
    FastLED.show();
    delay(110);
    for(int i = 0; i < NUM_LEDS; i++){
      leds[i] = CRGB(0, 0, 0);
    }
    FastLED.show();
    delay(t);
  }
  
}
void outBomb(int r, int g, int b){
  int first = 8, last = 9;
  for(;first >= 0; first--, last++){
    for(int i =0; i < NUM_LEDS; i++){
      if(i >= first && i <= last){
        leds[i] = CRGB(r, g, b);
      }
    }
    delay(30);
    FastLED.show();
  }
}

void inBomb(int r, int g, int b){
  int first = 0, last = 17;
  for(;first <= 8; first++, last--){
    for(int i =0; i < NUM_LEDS; i++){
      if(i <= first || i >= last){
        leds[i] = CRGB(255, 20, 20);
      }
    }
    delay(30);
    FastLED.show();
  }
}
