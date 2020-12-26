#define sol_motor_hiz 11 // Sol motor hız pini
#define sag_motor_hiz 10 // Sağ motor hız pini
#define sol_motor_1 8 // Sol motor pin 1
#define sol_motor_2 9 // Sol motor pin 2
#define sag_motor_1 7 //Sağ motor pin 1
#define sag_motor_2 6 // Sağ motor pin 2
 
int sag_sensor_echo = A0;// sağ sensör
int sag_sensor_trigger = A1;// sağ sensör
int sol_sensor_echo = A2;// sol sensör
int sol_sensor_trigger = A3;// sol sensör
int on_sensor_echo = A4; // Ön sensör
int on_sensor_trigger = A5; // Ön sensör
 
void setup()
{
pinMode(on_sensor_trigger, OUTPUT);
pinMode(on_sensor_echo, INPUT);
pinMode(sol_sensor_trigger, OUTPUT);
pinMode(sol_sensor_echo, INPUT);
pinMode(sag_sensor_trigger, OUTPUT);
pinMode(sag_sensor_echo, INPUT);
pinMode(sol_motor_hiz, OUTPUT);
pinMode(sag_motor_hiz, OUTPUT);
pinMode(sol_motor_1, OUTPUT);
pinMode(sol_motor_2, OUTPUT);
pinMode(sag_motor_1, OUTPUT);
pinMode(sag_motor_2, OUTPUT);
delay(5000);
}
 
void loop()
{
long on_sensor_zaman, sol_sensor_zaman, sag_sensor_zaman, sag_mesafe, sol_mesafe, on_mesafe;
digitalWrite(on_sensor_trigger, LOW);
delayMicroseconds(2);
digitalWrite(on_sensor_trigger, HIGH);
delayMicroseconds(5);
digitalWrite(on_sensor_trigger, LOW);
on_sensor_zaman = pulseIn(on_sensor_echo, HIGH);
on_mesafe = on_sensor_zaman/29/2;
digitalWrite(sol_sensor_trigger, LOW);
delayMicroseconds(2);
digitalWrite(sol_sensor_trigger, HIGH);
delayMicroseconds(5);
digitalWrite(sol_sensor_trigger, LOW);
sol_sensor_zaman = pulseIn(sol_sensor_echo, HIGH);
sol_mesafe = sol_sensor_zaman/29/2;
digitalWrite(sag_sensor_trigger, LOW);
delayMicroseconds(2);
digitalWrite(sag_sensor_trigger, HIGH);
delayMicroseconds(5);
digitalWrite(sag_sensor_trigger, LOW);
sag_sensor_zaman = pulseIn(sag_sensor_echo, HIGH);
sag_mesafe = sag_sensor_zaman/29/2;
analogWrite(sol_motor_hiz, 0);
analogWrite(sag_motor_hiz, 0);
analogWrite(sol_motor_1, 0);
analogWrite(sol_motor_2, 0);
analogWrite(sag_motor_1, 0);
analogWrite(sag_motor_2, 0);
 
if(on_mesafe >8)
{
if(sag_mesafe >7 && sag_mesafe< 13)
{
analogWrite(sol_motor_hiz, 120);
analogWrite(sag_motor_hiz, 150);
analogWrite(sol_motor_1, 255);
analogWrite(sol_motor_2, 0);
analogWrite(sag_motor_1, 0);
analogWrite(sag_motor_2, 255);
}
if(sag_mesafe >=13)
{
analogWrite(sol_motor_hiz, 255);
analogWrite(sag_motor_hiz, 60);
analogWrite(sol_motor_1, 255);
analogWrite(sol_motor_2, 0);
analogWrite(sag_motor_1, 0);
analogWrite(sag_motor_2, 255);
}
if(sag_mesafe <=7)
{
analogWrite(sol_motor_hiz, 60);
analogWrite(sag_motor_hiz, 255);
analogWrite(sol_motor_1, 255);
analogWrite(sol_motor_2, 0);
analogWrite(sag_motor_1, 0);
analogWrite(sag_motor_2, 255);
}
}
if(sol_mesafe <=20 && sag_mesafe>20 && on_mesafe <=8) { sag();}
if(sol_mesafe >20 && sag_mesafe>20 && on_mesafe <=8) { sag(); }
if(sag_mesafe <=20 && sol_mesafe>20 && on_mesafe <=8) { sol(); }
if(sag_mesafe<=20 && sol_mesafe<=20 && on_mesafe<=8) { tam_donus(); }
}
 
void sol()
{
analogWrite(sol_motor_hiz, 120);
analogWrite(sag_motor_hiz, 120);
analogWrite(sol_motor_1, 0);
analogWrite(sol_motor_2, 255);
analogWrite(sag_motor_1, 0);
analogWrite(sag_motor_2, 255);
delay(700);
}
 
void sag()
{
analogWrite(sol_motor_hiz, 120);
analogWrite(sag_motor_hiz, 120);
analogWrite(sol_motor_1, 255);
analogWrite(sol_motor_2, 0);
analogWrite(sag_motor_1, 255);
analogWrite(sag_motor_2, 0);
delay(800);
}
 
void tam_donus()
{
analogWrite(sol_motor_hiz, 120);
analogWrite(sag_motor_hiz, 120);
analogWrite(sol_motor_1, 255);
analogWrite(sol_motor_2, 0);
analogWrite(sag_motor_1, 255);
analogWrite(sag_motor_2, 0);
delay(1200);
}
void ileri()
{
analogWrite(sol_motor_hiz, 120);
analogWrite(sag_motor_hiz, 120);
analogWrite(sol_motor_1, 255);
analogWrite(sol_motor_2, 0);
analogWrite(sag_motor_1, 0);
analogWrite(sag_motor_2, 255);
delay(700);
}
