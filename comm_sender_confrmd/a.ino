
/*
#include <SoftwareSerial.h>
SoftwareSerial SWsend(5, 6);

char mystr[5] = "Hello"; //String data
const int xs=10;
int x[256];

void setup() 
{
  pinMode(LED_BUILTIN, OUTPUT);
  // Begin the Serial at 9600 Baud
  Serial.begin(9600);
   SWsend.begin(9600);
   for(int i=0;i<256;i++)
   x[i]=i+1;
}

void loop() {
 //Write the serial data

SWsend.write("<");
for(int i=0;i<256;i++)
{

SWsend.write(x[i]);
SWsend.write(",");
}
SWsend.write(">");
delay(1000);

blin();
}


void blin()
{
   digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(100);  
}
*/
