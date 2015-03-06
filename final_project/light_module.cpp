
/*
  TODO: think about adding history to each light sensor for more accurate pick ups of bad reads.
*/

#import "light_module.h"

LightModule::LightModule(){
  
} 


lm_res_t LightModule::measure(){
    tape_result_t l = _left.read();
    tape_result_t r = _right.read();
    tape_result_t m = _middle.read();

    if (l == black && m == black && r == black){
      return bbb;
    }   
    if (l == black && m == black && r == white){
      return bbw;
    }
    if (l == white && m == black && r == white){
      return wbw;
    }
    if (l == white && m == black && r == black){
      return wbb;
    }
    if (l == black && m == black && r == black){
      return bbb;
    }
    if (l == white && m == white && r == black){
      return wwb;
    }
    if (l == black && m == white && r == white){
      return bww;
    }
    if (l == white && m == white && r == white){
      return www;
    }
    return err;
}

String LightModule::toString(){
   String res = "==Left==";
   res += _left.toString();
   res += "\n";

   res += "==Middle==";
   res += _middle.toString();
   res += "\n";
   
   res += "==Right==";
   res += _right.toString();
   res += "\n";
   
   res += "RESULT: ";
   lm_res_t lm_res = this->measure();
   switch(lm_res){
     case bbb:
       res += "bbb";
       break;
     case bbw:
       res += "bbw";
       break;
     case wbw:
       res += "wbw";
       break;
     case wbb:
       res += "wbb";
       break;
     case wwb:
       res += "wwb";
       break;
     case bww:
       res += "bww";
       break;
     case www:
       res += "www";
       break;
     case err:
       res += "ERR";
       break;
     default:
       res += "n/a";
       break;
   }
   return res;
   
}

