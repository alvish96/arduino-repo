
void SWtimer(int seco, char c = 'm');


class Switch
{
  private:


  public:
    bool prtemp = 0;
    byte relay;
    bool relayon, relayoff;
    bool state , flag , relaytype ;
    unsigned long mark, period, total;
    unsigned int mark1, mark2;

    Switch(byte relay)
    {
      this->relay = relay;
    }

    void initialise()
    {
      Serial.print(F("relay pin "));
      Serial.println(relay);
      pinMode(relay, OUTPUT);
      digitalWrite(relay, relayoff);
    }

    void definetype(bool x )
    {
      relaytype = x;
      if (relaytype == 1) // normal
      {
        Serial.print(F("  relay type normal  "));
        relayon = 1;
        relayoff = 0;
      }
      else      //flip
      {
        Serial.print(F("  relay type flip  "));
        relayon = 0;
        relayoff = 1;
      }
    }


    void SWon()
    {
      digitalWrite(relay, relayon);
      Serial.print(F("  relay on  "));
      flag = LOW;
      period = 0;
      priority = prtemp;
    }
    void SWoff()
    {
      if (state == relayon)
      {
        if (ato == 0)
          priority = prtemp;
        if (ato == 1)
        {
          priority = priority;
          //          ato = 0;
        }
        //        checkmotion = !priority;
      }
      digitalWrite(relay, relayoff);
      Serial.print(F("  relay off  "));
      flag = LOW;
      period = 0;
      priority = prtemp;
    }

    void SW()
    {
      if (state == relayon)
      {
        if (ato == 0)
          priority = prtemp;
        if (ato == 1)
        {
          //          priority = priority;
          //          ato = 0;
          sync();
        }
        //        checkmotion = !priority;
      }
      state = !state;
      digitalWrite(relay, state);
      debug();
      if (state == relayon)Serial.println(F(" ON "));
      if (state == relayoff)Serial.println(F(" OFF "));
      period = 0;
      flag = LOW;
    }


    void SWtimer(int seco, char c = 'm')
    {
      tune(12);
      mark = 0;
      period = 0;
      if (c == 's')
        period = seco * 1000;
      else if (c == 'm')
        period = seco * 60000;
      else if (c == 'h')
        period = seco * 3600000;
      state = relayon;
      digitalWrite(relay, state);
      mark = millis();
      total = period + mark;
      prtemp = priority;
      priority = 1;

      flag = HIGH;
      Serial.print(F(" TIMER ON "));
      debug();
    }


    void down()
    {
      state = relayoff;
      mark = 0;
      period = 0;
      flag = 0;
    }

    void debug()
    {
      if(debugg)
      switch (relay)
      {
        case 30: Serial. println(F(" RESET ")); break;
        case 4: Serial. println(F(" MAIN LIGHT ")); break;
        case 11: Serial. println(F(" LED LIGHT ")); break;
        case 7: Serial. println(F(" FAN ")); break;
        case 8: Serial. println(F(" EXHAUST ")); break;
        case 14: Serial. println(F(" BT SPEAKER ")); break;
        case 15: Serial. println(F("  ")); break;
        case 16: Serial. println(F("  ")); break;
        case 17: Serial. println(F("  ")); break;
        case 19: Serial. println(F(" PROJECTOR ")); break;
        case 18: Serial. println(F(" NIGHT LIGHT ")); break;
        case 9: Serial. println(F("  ")); break;

      }
    }
    unsigned int timerdisp()
    {
      unsigned int  x = ((total - millis()) / 1000);
      return x;
    }

};







Switch mod[12] = {r, rel1, rel2, rel3, rel4, rel5, rel6, rel7, rel8, rel9, rel10, rel11};


void setup()
{
  mute = 0; //v
  tune(8);
  Serial.begin(9600);
  ir.enableIRIn();          // Start the receiver

  pinMode(ldr, INPUT);  //v
  pinMode(pirpin, INPUT); //v
  pinMode(buz, OUTPUT);   //v
  pinMode(led1, OUTPUT);   //v
  pinMode(led2, OUTPUT);   //v

  sequence();

  brttot = 0;
  deepc = 1;
  duration = 60;
  temp = 0;
  checkmotion = 1;
  sync();
  debugg=1;

}
