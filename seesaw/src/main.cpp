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
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
 
  double perr=0;
  double perr2=0;
  double perr3=0;
  double i=0;
  while(true) {
    Controller1.Screen.clearScreen();
    
    
    
      
    
    double doublep=0;
    double doubled=0;
    
    double p = Distance1.objectDistance(inches)-Distance10.objectDistance(inches);

    doublep = Motor9.position(degrees)*.2-p;


    Controller1.Screen.setCursor(1,1);
    Controller1.Screen.print(p);
    Controller1.Screen.setCursor(2,1);
    Controller1.Screen.print(Motor9.position(degrees));
    Controller1.Screen.setCursor(3,1);
    Controller1.Screen.print(doublep);

    if(fabs(Motor9.position(degrees))<50) {
    Motor9.spin(forward,doublep*.1,pct);//+doublep*.2+i*.001,pct);
    }
    else
    {
      Motor9.spin(forward,-Motor9.position(degrees)/5,pct);//+doublep*.2+i*.001,pct);
    }
    perr3=perr2;
    perr2=perr;
   
     perr=p;
    
    
    
    wait(10,msec);
  
}
}