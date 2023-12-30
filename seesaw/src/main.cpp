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
// Distance7            distance      7               
// Motor9               motor         9               
// Controller1          controller                    
// Distance6            distance      6               
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
    Controller1.Screen.setCursor(1,1);
    
    double p2 = 4-Distance6.objectDistance(inches);
    double p = Distance7.objectDistance(inches)-4;
    
      
    Controller1.Screen.print(p);
    double doublep=0;
    double doubled=0;
    if(fabs(p)<5||fabs(p2)<5) {
    if(p<-.5) {
     doublep = (p*5-Motor9.position(degrees))*.1;
     doubled=((perr+perr2+perr3)/3*8)-Motor9.position(degrees);
     if (fabs(p)<1){
      i=0;
    }
    else{
      i+=p;
    }
    }
    else{
       doublep = (p2*5-Motor9.position(degrees))*.1;
       doubled=(((perr+perr2+perr3)/3-p2)*8)+-Motor9.position(degrees);
       if (fabs(p2)<1){
      i=0;
    }
    else{
      i+=p2;
    }
    }
    }
    
    

    Controller1.Screen.setCursor(2,1);
    Controller1.Screen.print(p2);
    Controller1.Screen.setCursor(3,1);
    Controller1.Screen.print(-doubled);
    Motor9.spin(forward,doubled*.1,pct);//+doublep*.2+i*.001,pct);
    
    perr3=perr2;
    perr2=perr;
    if(p<-.5) {
     perr=p;
    }
    else{
       perr=p2;
    }
    
    wait(10,msec);
  
}
}