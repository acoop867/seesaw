/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Student                                          */
/*    Created:      Sat Dec 30 2023                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Distance10           distance      10              
// Motor9               motor         7               
// Controller1          controller                    
// Distance1            distance      1               
// sense                potV2         A               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

void pid(double valp,double vali, double vald) {
  Motor9.spin(forward,(valp*-1.3+vali*.001+vald*25)-.4*(sense.angle(degrees)-70),pct);
}


int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
 
  double perr=0;
  double perr2=0;
  double perr3=0;
  double i=0;
  while(true) {
    Controller1.Screen.clearScreen();
    
    
    if(Distance1.objectDistance(inches)>30||Distance10.objectDistance(inches)>30) {
      //Controller1.rumble(rumbleLong);
    }
      
    
    double doublep=0;
    double doubled=0;
    
    double p = Distance1.objectDistance(inches)-Distance10.objectDistance(inches);

    


    doubled = (Distance1.objectVelocity()-Distance10.objectVelocity())/2;


    Controller1.Screen.setCursor(1,1);
    Controller1.Screen.print(p);
    Controller1.Screen.setCursor(2,1);
    Controller1.Screen.print(sense.angle(degrees));
    Controller1.Screen.setCursor(3,1);
    Controller1.Screen.print(doubled);

    
    //pid(p,0,doubled);//+doublep*.2+i*.001,pct);
    pid(0,0,0);
   
    perr3=perr2;
    perr2=perr;
   
     perr=p;
    
    
    
    wait(10,msec);
  
}
}