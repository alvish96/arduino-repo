
/*start turn on for 30 sec
   start count
   if count increases more than 3 within 30
   keep on
   else
   turn off after 30

   if no motion for 4 mins
    turn off

dont


*/
byte lapse=7;



bool motion()
{ 
  if (millis() < 4000) goto there1;
  if((millis()/1000)<(lastmotion+lapse))
goto there1;
    if (checkmotion == 1)
    {
      pirval = digitalRead(pirpin);
      if (pirval == HIGH)
      {
        //motion detected
        if (motionstate == LOW)
        {
          motionstate = HIGH;
          Serial.print(F("MOTION DETECTED AT "));
          Serial.println(millis() / 1000);
          //        Serial.print(F(" sec"));
          if ((fromhere == 1) || (motioncount == 0)) motioncount++;
          
          delay(50);
        }
      }

      else
      {
        if (motionstate == HIGH)
        {
          motionstate = LOW;
          lastmotion = millis() / 1000;
          updatemotion();
          Serial.print(F("MOTION ENDED AT "));
          Serial.println(millis() / 1000);
          //        Serial.print(F(" sec"));
          delay(50);
        }
      }

    }
  return motionstate;
  there1:delay(0);
}
