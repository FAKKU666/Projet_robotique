//moteur droite
int motor1_activate = 2;//pin 2
int motor1_input1 = 3;//pin 3
int motor1_input2 = 4;//pin 4
//moteur gauche
int motor2_activate = 8;//pin 8
int motor2_input1 = 9;//pin 9
int motor2_input2 = 10;//pin 10
//capteur gauche brancher sur les pins 5 et 6
int capteur_gauche = 5; //trig
int capteur_gauche2 = 6; //echo
//capteur droit brancher sur les pins 11 et 12
int capteur_droit = 11; //trig
int capteur_droit2 = 12; //echo
//photoresistance brancher sur les pins A0 
int photoresistance = A0;

void setup() {//initialisation des pins
  pinMode(motor1_activate, OUTPUT);
  pinMode(motor1_input1, OUTPUT);
  pinMode(motor1_input2, OUTPUT);
  pinMode(motor2_activate, OUTPUT);
  pinMode(motor2_input1, OUTPUT);
  pinMode(motor2_input2, OUTPUT);
  pinMode(capteur_gauche, OUTPUT);
  pinMode(capteur_gauche2, INPUT);
  pinMode(capteur_droit, OUTPUT);
  pinMode(capteur_droit2, INPUT);
  pinMode(photoresistance, INPUT);
  Serial.begin(9600);
}

//fonction pour avancer
void avancer() {
    digitalWrite(motor1_activate, HIGH);
    digitalWrite(motor1_input1, HIGH);
    digitalWrite(motor1_input2, LOW);
    digitalWrite(motor2_activate, HIGH);
    digitalWrite(motor2_input1, HIGH);
    digitalWrite(motor2_input2, LOW);
    }
//fonction pour reculer
void reculer() {
    digitalWrite(motor1_activate, HIGH);
    digitalWrite(motor1_input1, LOW);
    digitalWrite(motor1_input2, HIGH);
    digitalWrite(motor2_activate, HIGH);
    digitalWrite(motor2_input1, LOW);
    digitalWrite(motor2_input2, HIGH);
    }
//fonction pour tourner a gauche
void gauche() {
  digitalWrite(motor1_activate, HIGH);
  digitalWrite(motor1_input1, HIGH);
  digitalWrite(motor1_input2, LOW);
  digitalWrite(motor2_activate, HIGH);
  digitalWrite(motor2_input1, LOW);
  digitalWrite(motor2_input2, HIGH);

}
//fonction pour tourner a droite
void droite() {
    digitalWrite(motor1_activate, HIGH);
  digitalWrite(motor1_input1, LOW);
  digitalWrite(motor1_input2, HIGH);
  digitalWrite(motor2_activate, HIGH);
  digitalWrite(motor2_input1, HIGH);
  digitalWrite(motor2_input2, LOW);
}
//fonction pour arreter
void arreter() {
    digitalWrite(motor1_activate, LOW);
    digitalWrite(motor2_activate, LOW);
    }
    
//fonction distance
long distance(int trig, int echo) {
  long duree, distance;
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duree = pulseIn(echo, HIGH);
  distance = duree / 58.2;
  return distance;
}
void loop()
{
  long distance_gauche = distance(capteur_gauche, capteur_gauche2);
  long distance_droit = distance(capteur_droit, capteur_droit2);
  Serial.print("distance gauche: ");
  Serial.print(distance_gauche);
  Serial.print(" distance droit: ");
  Serial.println(distance_droit);
    int lumiere = analogRead(photoresistance);
  if (lumiere > 500) {
      avancer();

  if (distance_gauche < 20) {
    reculer();
    delay(400);
    gauche();
        delay(400);
  }
  else if(distance_droit < 20) {
    reculer();
    delay(400);
    gauche();
        delay(400);
  }
  
  }
  else {
    arreter();
  }

  
}