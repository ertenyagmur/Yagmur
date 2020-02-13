//by Hani and Yagmur
//inspired from https://create.arduino.cc/projecthub/archievkumar19/lights-music-action-7c43b7 & https://www.youtube.com/watch?v=RwHGioglbk8


const int redPin = 11;
const int greenPin = 10;
const int bluePin = 9;
const int soundpin=A2;
const int threshold_B=200;
const int threshold_R=500;
const int threshold_G=800;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(soundpin, INPUT);

}

void loop() {

  // put your main code here, to run repeatedly:
  int soundsens=analogRead(soundpin);
  if (soundsens<=threshold_B) {
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, HIGH);
    
  } else if (soundsens>threshold_B && soundsens<=threshold_R) {
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, HIGH);
  
  } else if (soundsens>threshold_R && soundsens<=threshold_G) {
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, HIGH);
  
  } else if (soundsens>threshold_G && soundsens<=1000) {
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, LOW);    
  }
  //delay(50);
  Serial.println(soundsens);
  
}


void setColor(int red, int green, int blue)
{

    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
 
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}
