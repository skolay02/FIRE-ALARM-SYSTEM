//TEMPERATURE DETECTOR AND FIRE ALARM SYSTEM!!

int readtemp=A0;
int readgas=A1;
int buzzpin=7;
int redled=11;
int blueled=8;

float tempval1;
float tempval2;
float temp;
float gasval;

float volt;
  


void setup()
{
  
  pinMode(readtemp,INPUT);
  pinMode(readgas,INPUT);
  pinMode(buzzpin,OUTPUT);
  pinMode(redled,OUTPUT);
  pinMode(blueled,OUTPUT);
  Serial.begin(9600);
 
}


void loop()
{
  //TEMPERATURE
  tempval1=analogRead(readtemp);
  tempval2=(tempval1/1023.0)*5000.0;
  temp=(tempval2-500)/10;
  
  //GAS CONCENTRATION
  gasval=analogRead(readgas);
  
  //NORMAL CONDITION: BLUE LED LIGHTS ON
  if(temp<55)
  {
    digitalWrite(blueled,HIGH);
  }
  
  else
  {
    digitalWrite(blueled,LOW);
  }
  
  
  //UNDER RISE IN TEMP ABOVE 55 DEGREE C RED LED BRIGHTENS UP ACCORDING TO THE TEMP
  if(temp>=55 && temp<80)
  {
    volt=(85.0/8.0)*temp-(4675.0/8.0);
    analogWrite(redled,volt);
  }
  
  else if(temp>=80)
  {
    digitalWrite(redled,HIGH);
    
  }
  
  else
  {
    digitalWrite(redled,LOW);
  }
    
  
  //DANGER: GAS/SMOKE DETECTED BUZZER TURNS ON AND RED LED BLINKS
  if(gasval>=100)
  {
    digitalWrite(buzzpin,HIGH);
    digitalWrite(redled,HIGH);
    delay(150);
    digitalWrite(redled,LOW);
    delay(150);
  }
  
  else
  {
    digitalWrite(buzzpin,LOW);
  }
  
  
  Serial.print("Temp. in DegreeC= ");
  Serial.print(temp);
  Serial.print("\t\t\t");
  Serial.print("Gas= ");
  Serial.println(gasval);
  delay(500);
  
}