String readString;
int UpperThreshold = 518;
int LowerThreshold = 490;
    int reading = 0;
    float BPM = 0.0;
    bool IgnoreReading = false;
    bool FirstPulseDetected = false;
    unsigned long FirstPulseTime = 0;
    unsigned long SecondPulseTime = 0;
    unsigned long PulseInterval = 0;

    void setup(){
      Serial.begin(9600);
    }

    void loop(){
      while(!Serial.available()) {}
      while (Serial.available())
      {
          if (Serial.available() >0)
          {
              char c = Serial.read();  //gets one byte from serial buffer
              readString += c; //makes the string readString
          }
      }
      if (readString.length() >0){
        while(PulseInterval==0){
          reading = analogRead(0); 
          if(reading > UpperThreshold && IgnoreReading == false){
            if(FirstPulseDetected == false){
              FirstPulseTime = millis();
              FirstPulseDetected = true;
            }
            else{
              SecondPulseTime = millis();
              PulseInterval = SecondPulseTime - FirstPulseTime;
              FirstPulseTime = SecondPulseTime;
            }
            IgnoreReading = true;
          }
          if(reading < LowerThreshold){
            IgnoreReading = false;
          }  
        }
          BPM = (1.0/PulseInterval) * 60.0 * 1000;
           // uncomment these lines in case you want to view the various values in the console.....
          Serial.print(BPM);
          Serial.flush();
          PulseInterval = 0;
        }
      delay(500);
    }
