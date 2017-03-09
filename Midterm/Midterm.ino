/**
 * Modified:
 * Example Sketch for the SparkFun MEMS Microphone Breakout Board
 * Written by jenfoxbot <jenfoxbot@gmail.com>
 * Code is open-source, beer/coffee-ware license.
 */
const int PURPLE1 = 13;
const int WHITE1 = 12;
const int WHITE2 = 11;
const int XWHITE1 = 10;
const int PURPLE2 = 9;
const int PURPLE3 = 8;
const int XWHITE2 = 7;
const int BLUE1 = 6;
const int BLUE2 = 5;
const int WHITE3 = 4;

int writeValue;
int readValue;
int mic = A0;
const int sampleTime = 50; 
int micOut;
int fadeValue;


void setup() {
  Serial.begin(9600);
}

void loop() {
   int micOutput = findPTPAmp();
   VUMeter(micOutput); 
   readValue = analogRead(mic); 
   writeValue = (255./1023.) * readValue;
   
 
}   

int findPTPAmp(){
// Time variables to find the peak-to-peak amplitude
   unsigned long startTime= millis(); 
   unsigned int PTPAmp = 0; 

// Signal variables to find the peak-to-peak amplitude
   unsigned int maxAmp = 0;
   unsigned int minAmp = 1023;

// Find the max and min of the mic output within the 50 ms timeframe
   while(millis() - startTime < sampleTime) 
   {
      micOut = analogRead(mic);
      if( micOut < 550) //prevent erroneous readings
      {
        if (micOut > maxAmp)
        {
          maxAmp = micOut; //save only the max reading
        }
        else if (micOut < minAmp)
        {
          minAmp = micOut; //save only the min reading
        }
      }
   }

  PTPAmp = maxAmp - minAmp; // (max amp) - (min amp) = peak-to-peak amplitude
  double micOut_Volts = (PTPAmp * 3.3) / 550; // Convert ADC into voltage

  //Serial.println(PTPAmp); 

  //Return the PTP amplitude to use in the soundLevel function. 
  // You can also return the micOut_Volts if you prefer to use the voltage level.
  return PTPAmp;   
}

// Volume Unit Meter function: map the PTP amplitude to a volume unit between 0 and 10.
int VUMeter(int micAmp){
  int preValue = 0;

  // Map the mic peak-to-peak amplitude to a volume unit between 0 and 10.
   // Amplitude is used instead of voltage to give a larger (and more accurate) range for the map function.
   // This is just one way to do this -- test out different approaches!
 int fill = map(micAmp, 5, 550, 0, 15); 

  // Only print the volume unit value if it changes from previous value
 while(fill != preValue)
  {
    Serial.println(fill);
    preValue = fill;
    }
  
float in, out;
  int fadeValue;
  
if(fill < 0){

    analogWrite(PURPLE1,0);
    analogWrite(PURPLE2,0);
    analogWrite(PURPLE3,0);
    
    analogWrite(WHITE1,50);
    analogWrite(WHITE2,50);
    analogWrite(WHITE3,50);
    
    analogWrite(XWHITE1,0);
    analogWrite(XWHITE2,0);
    
    analogWrite(BLUE1,0);
    analogWrite(BLUE2,0);
}

else if (fill >0 && fill <2){
  
}
 else if (fill > 0 && fill <2){
  analogWrite(13,160);
 }
 else if (fill > 2 && fill <4){
  analogWrite(13,175);
 }
  else if (fill > 4 && fill <6){
  for (in = 0; in < 6.283; in = in + 0.0015)
  {
    out = sin(in) * 127.5 + 127.5;
    
    analogWrite(PURPLE1,out);
    analogWrite(PURPLE2,out);
    analogWrite(PURPLE3,out);
    
    analogWrite(WHITE1,out);
    analogWrite(WHITE2,out);
    analogWrite(WHITE3,out);
    
    analogWrite(XWHITE1,out);
    analogWrite(XWHITE2,out);
    
    analogWrite (BLUE1,out);
    analogWrite(BLUE2,out);
  }
 }
  else if (fill > 7 && fill <12){
   analogWrite(PURPLE1,random(0,255));
    analogWrite(PURPLE2,random(0,255));
    analogWrite(PURPLE3,random(0,255));
    
    analogWrite(WHITE1,random(0,255));
    analogWrite(WHITE2,random(0,255));
    analogWrite(WHITE3,random(0,255));
    
    analogWrite(XWHITE1,random(0,255));
    analogWrite(XWHITE2,random(0,255));
    
    analogWrite (BLUE1,random(0,255));
    analogWrite(BLUE2,random(0,255));
 }
 else if (fill > 12 && fill <14){
    
    analogWrite(PURPLE1,255);
    analogWrite(PURPLE2,255);
    analogWrite(PURPLE3,255);
    
    analogWrite(WHITE1,120);
    analogWrite(WHITE2,120);
    analogWrite(WHITE3,120);
    
    analogWrite(XWHITE1,120);
    analogWrite(XWHITE2,120);
    
    analogWrite (BLUE1,255);
    analogWrite(BLUE2,255);

    analogWrite(PURPLE1,0);
    analogWrite(PURPLE2,0);
    analogWrite(PURPLE3,0);
    
    analogWrite(WHITE1,0);
    analogWrite(WHITE2,0);
    analogWrite(WHITE3,0);
    
    analogWrite(XWHITE1,0);
    analogWrite(XWHITE2,0);
    
    analogWrite (BLUE1,0);
    analogWrite(BLUE2,0);

  }}


