  
#include <SoftwareSerial.h>

#include <HardwareSerial.h>

double VarCaracterDelPs;

HardwareSerial &bt_serial=Serial1;
int l298n_ena=10;
int l298n_in1=2;
int l298n_in2=3;
int l298n_in3=4;
int l298n_in4=5;
int l298n_enb=6;

void setup()
{
  bt_serial.begin(9600);

pinMode(10, OUTPUT);
pinMode(2, OUTPUT);
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
}


void loop()
{

    if ((bt_serial.available()>0)) {
      VarCaracterDelPs = bt_serial.read();
      if ((VarCaracterDelPs == ('s'))) {
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);

      }
      if ((VarCaracterDelPs == ('l'))) {
        digitalWrite(l298n_in1,LOW);
        digitalWrite(l298n_in2,HIGH);
        analogWrite(l298n_ena,(255));
        digitalWrite(l298n_in3,HIGH);
        digitalWrite(l298n_in4,LOW);
        analogWrite(l298n_enb,(255));

      }
      if ((VarCaracterDelPs == ('r'))) {
        digitalWrite(l298n_in1,HIGH);
        digitalWrite(l298n_in2,LOW);
        analogWrite(l298n_ena,(255));
        digitalWrite(l298n_in3,LOW);
        digitalWrite(l298n_in4,HIGH);
        analogWrite(l298n_enb,(255));

      }
      if ((VarCaracterDelPs == ('f'))) {
        digitalWrite(l298n_in1,HIGH);
        digitalWrite(l298n_in2,LOW);
        analogWrite(l298n_ena,(255));
        digitalWrite(l298n_in3,HIGH);
        digitalWrite(l298n_in4,LOW);
        analogWrite(l298n_enb,(255));

      }
      if ((VarCaracterDelPs == ('b'))) {
        digitalWrite(l298n_in1,LOW);
        digitalWrite(l298n_in2,HIGH);
        analogWrite(l298n_ena,(255));
        digitalWrite(l298n_in3,LOW);
        digitalWrite(l298n_in4,HIGH);
        analogWrite(l298n_enb,(255));

      }

    }

}
