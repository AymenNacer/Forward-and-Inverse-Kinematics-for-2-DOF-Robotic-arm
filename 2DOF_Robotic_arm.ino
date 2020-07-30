#include <Servo.h>
Servo motor1;
Servo motor2;
// angles in degree and radian

// length of links of robot arm
volatile float L1;       
volatile float L2;  
// end effector      


volatile float pi = 3.14159265359;


void setup() {
  motor1.attach(11);
  motor2.attach(3);
  Serial.begin(9600);
  motor1.write(0);
  motor2.write(0);
 Serial.println("Enter the length of first arm ");
 while(Serial.available()==0){}
 L1=Serial.parseFloat();
   
 Serial.println("Enter the length of second arm ");
 while(Serial.available()==0){}
 L2=Serial.parseFloat();
 
 
Serial.println("Enter Number 1 for ForwardKinematics");
Serial.println("Enter Number 0 for inverseKinematics");

   }

void loop() {

 if (Serial.available())  {
 
    char choice = Serial.read();
    if (choice == '1'){                //Forwad kinematics Case  
  motor1.write(0);
  motor2.write(0);         
     ForwardKinematics();
 }
 
else if(choice == '0'){
   motor1.write(0);
   motor2.write(0);
   inverseKinematics();                  //inverse kinematics case
   
 }
 
 }
 }

 void ForwardKinematics(){
float angle1 ;      
float angle2 ;       
float rad_angle1;  
float rad_angle2;
float x;
float y;    
 Serial.println("Enter the angle1 in degree ");
  while(Serial.available()==0){}
 angle1=Serial.parseFloat();

  
  Serial.println("Enter the angle2 in degree ");
  while(Serial.available()==0){}
  angle2=Serial.parseFloat();


  rad_angle1 = (angle1*pi)/180;    
  rad_angle2 = (angle2*pi)/180;

  motor1.write(angle1); 
  motor2.write(angle2);
  
  x = L1 * cos(rad_angle1) +L2 * cos(rad_angle1 + rad_angle2);
  y = L1 * sin(rad_angle1) +L2 * sin (rad_angle1 + rad_angle2);
  delay(1000);
 Serial.print("L1 =  "); 
 Serial.println(L1);
  Serial.print("L2 = "); 
 Serial.println(L2);
 Serial.print("x = "); 
 Serial.println(x);
 Serial.print("y = "); 
 Serial.println(y);
 Serial.print("angle1 is "); 
 Serial.println(angle1);
 Serial.print("angle2 is "); 
 Serial.println(angle2);

 
Serial.println("Enter Number 1 for ForwardKinematics");
Serial.println("Enter Number 0 for inverseKinematics");

 }

 void inverseKinematics(){
float angle1 ;      
float angle2 ;       
float rad_angle1;  
float rad_angle2; 
float x;
float y;   
   Serial.println("Enter the value x ");
      while(Serial.available()==0){}
      x=Serial.parseFloat();
     
      
      Serial.println("Enter the value y ");
      while(Serial.available()==0){}
      y=Serial.parseFloat();
     
      rad_angle2 = acos((sq(x)+ sq(y) - sq(L1) - sq(L2)) / (2*L1*L2));
      rad_angle1= atan(y / x) - atan((L2*sin(rad_angle2)) / (L1+ L2*cos(rad_angle2)));
      delay(1000);

      angle1= (rad_angle1*180)/pi;
      angle2= (rad_angle2*180)/pi;
      
      
 Serial.print("x is "); 
 Serial.println(x);
 Serial.print("y is "); 
 Serial.println(y);
 Serial.print("angle1 is  "); 
 Serial.println(angle1);
 Serial.print("angle2 is "); 
 Serial.println(angle2);
 Serial.println("Enter Number 1 for ForwardKinematics");
 Serial.println("Enter Number 0 for inverseKinematics");
motor1.write(angle1); 
motor2.write(angle2);
delay(2000);
 }