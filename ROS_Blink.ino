 #include <ros.h>
 #include <std_msgs/Empty.h>
 #include<AFMotor.h>

 ros::NodeHandle nh;
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);


void messageCb( const std_msgs::Empty& toggle_msg){
  //digitalWrite(13, HIGH-digitalRead(13));   // blink the led
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);



 }
 
 

void stop_motor( const std_msgs::Empty& stop_motor){
  //digitalWrite(13, HIGH-digitalRead(13));   // blink the led
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);


 }
 
 ros::Subscriber<std_msgs::Empty> sub("toggle_led", &messageCb );
 ros::Subscriber<std_msgs::Empty> motor("stop_motor", &stop_motor);

 void setup()
   {
      motor1.setSpeed(255); 
      motor2.setSpeed(255); 
      motor3.setSpeed(255); 
      motor4.setSpeed(255); 


//     pinMode(13, OUTPUT);
    nh.initNode();
    nh.subscribe(sub);
    nh.subscribe(motor);
  }
  
   void loop()
  {
     nh.spinOnce();
    delay(1);
   }

