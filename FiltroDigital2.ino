float y1=0.0;
float y2=0.0;
float y3=0.0;
float van=0.0;
float x=0.0;
float t=0.0;
float arr[3];
float aux;
void setup(){
  pinMode(A0,INPUT);
  Serial.begin(9600);
  y3=analogRead(A0);
  van=y3*5/1023;
  x=(van*0.3)/5;
  t=x/0.01;
  y3=t;
   
}



void loop(){
  arr[0]=y1;
  arr[1]=y2;
  arr[2]=y3;


  for(int i=0; i<3;i++){
    if(arr[i+1]>arr[i]){
      aux=arr[i];
      arr[i]=arr[i+1];
      arr[i+1]=aux;
      if(arr[i+2]>arr[i+1]){
        aux=arr[i+1];
      arr[i+1]=arr[i+2];
      arr[i+2]=aux;
      }
    }
  }
 y1=arr[0];
 y2=arr[1];
 y3=arr[2];
  Serial.println(y2,9);
  Serial.println(y3,9);
  y1=y2;
  y2=y3;
  y3=analogRead(A0);
  van=y3*5/1023;
  x=(van*0.3)/5;
  t=x/0.01;
  y3=t;
}
