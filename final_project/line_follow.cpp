//#include "state.h"
//#include "driver.h"
//#include "light_module.h"
//#include "state.h"
// 
//void LineFollow::adjustLeft(Driver d){
//  d.adjustLeft();
////  if (!adjusting){ /* initialize adjust */
////     adjusting = true;
////     resetTimer(1, 300);
////     resetTimer(2, 700);
////     d.adjustLeft();
////  }else{ /* already adjusting */
////     if (timerExpired(1)){
////       d.straight();
////     }
////     if (timerExpired(2)){
////       adjusting = false;
////       d.straight();
////     }
////  }
//}
//
//void LineFollow::adjustRight(Driver d){
//  d.adjustRight();
////  if (!adjusting){ /* initialize adjust */
////     adjusting = true;
////     resetTimer(1, 300);
////     resetTimer(2, 700);
////     d.adjustRight();
////  }else{ /* already adjusting */
////     if (timerExpired(1)){
////       d.straight();
////     }
////     if (timerExpired(2)){
////       adjusting = false;
////       d.straight();
////     }
////  }
//}
//
//LineFollow::LineFollow(){
//  
//}
//
//LineFollow:alignSoft(Driver d, LightModule lm){
//    d.stop()
//    int oldL = lm._left.readRaw();
//    int oldR = lm._right.readRaw();
//    int oldM = lm._middle.readRaw();
//    d.straight();
//    delay(200);
//    
//    
//    Serial.println("STARTING SOFT ALIGNMNENT");
//    d.straight
//  
//  
//  started = true;
//}
//
//void LineFollow::execute(Driver d, LightModule m){
//    lm_res_t lm_res = m.measure();
//    int l = m.readLeft();
//    int r = m.readRight();
//    switch (lm_res){
// 	  case bbb:
// 	    d.straight();
//            return;
//          case www:
//            d.stop();
//            return;
//          case bbw:
//          case wbb:
//            alignSoft();
//            return;
//          
//          default:
//            d._leftMotor.move(l / 9 + 80);
//            Serial.println(l);
//            Serial.println(l / 9 + 80);
//            Serial.println(r);
//            d._rightMotor.move(r /9 + 80);
//            Serial.println(r / 9 + 80);
//            return;
//// 	  case bbw:
////            adjustLeft(d);
////            return;
//// 	  case wbw:
////            adjusting = false;
////            d.straight();
////            return;
//// 	  case wbb:
////            adjustRight(d);
////            return;
//// 	  case wwb:
////            adjustRight(d);
////            return;
//// 	  case bww:
////            adjustLeft(d);
////            return;
//// 	  case www:
////            d.back();
////            return;
////          default:
////            d.stop();
//      }
//}
//
//bool LineFollow::done(){
//  return false;
//}
