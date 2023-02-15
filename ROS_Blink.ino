 #include <ros.h>
 #include <std_msgs/Empty.h>
#include<AFMotor.h>

 ros::NodeHandle nh;
AF_DCMotor motor1(1);

void messageCb( const std_msgs::Empty& toggle_msg){
  //digitalWrite(13, HIGH-digitalRead(13));   // blink the led
    motor1.run(FORWARD);

 }
 
 

void stop_motor( const std_msgs::Empty& stop_motor){
  //digitalWrite(13, HIGH-digitalRead(13));   // blink the led
    motor1.run(RELEASE);

 }
 
 ros::Subscriber<std_msgs::Empty> sub("toggle_led", &messageCb );
  ros::Subscriber<std_msgs::Empty> sub("stop_motor", &stop_motor);

 void setup()
   {
      motor1.setSpeed(255); 

//     pinMode(13, OUTPUT);
    nh.initNode();
    nh.subscribe(sub);
  }
  
   void loop()
  {
     nh.spinOnce();
    delay(1);
   }

