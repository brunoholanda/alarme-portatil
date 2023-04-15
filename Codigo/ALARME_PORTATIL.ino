// CODIGO EM CC Criado POR NERDKINGTEAM
// VISITE: nerdking.net.br
// youtube.com/nerdkingteam
// Criador, Bruno de Holanda Rodrigues

int enviou = 0;
const int Sirene =  7;  //define em qual porta a sirene esta conectada
const int buzzer = 10;
int al=0;
int disp=0; //variavel que define se esta disparado ou não
int arma=0; //variavel que define se esta armado ou nao
int cnt=0; //contador para marcação do tempo

void setup()
{
  Serial.begin(9600);
  delay(500);
  Serial.println("INICIADO!");
pinMode(Sirene, OUTPUT);
pinMode(buzzer, OUTPUT);
}

void loop() {

char c = Serial.read();
if (c == 'A'){ //comando vindo do APP 
//Tempo até o alarme ser ativado apos dado o comando para ativamento
  tone(buzzer,1000);   
  delay(600);
  noTone(buzzer);
  delay(1000); 
  tone(buzzer,1000);   
  delay(600);
  noTone(buzzer);
  delay(1000); 
  tone(buzzer,1000);   
  delay(600);
  noTone(buzzer);
  delay(1000); 
  tone(buzzer,1000);   
  delay(600);
  noTone(buzzer);
  delay(1000); 
  tone(buzzer,1000);   
  delay(600);
  noTone(buzzer);
  delay(1000); 
  tone(buzzer,1000);
  delay(600);
  noTone(buzzer);
  delay(1000); 
      arma=1;
      digitalWrite(Sirene, HIGH);
      delay(500);
      digitalWrite(Sirene, LOW);  
   }
  
if (c == 'B'){ //comando vindo do APP 
//Tempo até o alarme ser ativado apos dado o comando para ativamento
     arma=0;
     cnt=0; 
     digitalWrite(Sirene,LOW);
     digitalWrite(Sirene,HIGH);
     delay(200);
     digitalWrite(Sirene,LOW);
     delay(100);
     digitalWrite(Sirene,HIGH);
     delay(200);
     digitalWrite(Sirene,LOW);
  }

      //Monitora Sensor 1
int sensorValue1 = analogRead(A0);
float voltage1= sensorValue1*(3.3/676);

      //Monitora Sensor 2 Remova a barra para adicionar mais sensores
//int sensorValue2 = analogRead(A1);  //monitora sensor2
//float voltage2= sensorValue2*(3.3/676); //Converte o valor da porta analogica para voltagem

      //Monitora Sensor3 
//int sensorValue3 = analogRead(A2); //Remova as barras no começo p. adc. mais sensores
//float voltage3= sensorValue3*(3.3/676); //Remova as barras no começo p. adc. mais sensores
  

if (c=='C'){
  arma=1;
}

//desarma o Sirene apos ser enviada a letra B pelo serial monitor e também coloca o contador para zero

if (c=='D'){
  arma=0;
  cnt=0;
}
//dispara o Sirene caso a voltagem do sensor seja menor ou igual a 3
if (arma==1){
if (voltage1 <= 3){
disp=1;
}
}
//if (arma==1){
//if (voltage2 <= 3){
//disp=1;
//}
//}
//if (arma==1){
//if (voltage3 <= 3){
//disp=1;
//}
//}
//ação que a variavel arma exerce quando igual a zero, deixa a sirene desligada
if (arma==0){
digitalWrite(Sirene, LOW);
disp=0;
} 

//ação da variavel disp quando igual a 1, ativa a sirene por 20 segundos usando o contador
if (disp==1){
  cnt=cnt+1;
  digitalWrite(Sirene, HIGH);
  if (cnt == 30){
  digitalWrite(Sirene, LOW);
  disp=0;
  }
}
}





