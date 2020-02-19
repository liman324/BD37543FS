#include <Arduino.h>
#include <Wire.h>
#include "BD37543FS.h"

BD37543FS::BD37543FS(){
    Wire.begin();
}

void BD37543FS::setSetup_1(int sw_time_mute, int sw_time, int sw_on_off){
       switch(sw_time){
         case 0: sw_time = 0b00000000;break;
         case 1: sw_time = 0b00010000;break;
         case 2: sw_time = 0b00100000;break;
         case 3: sw_time = 0b00110000;break;
  }    
       switch(sw_on_off){
         case 0: sw_on_off = 0b00000000;break;
         case 1: sw_on_off = 0b10000000;break;
  }
           writeWire(SETUP_1, 0b00000100 + sw_time_mute + sw_time + sw_on_off); 
  }

void BD37543FS::setSetup_2(int sub_f, int sub_out, int level_metr, int lpf_faza){
       switch(sub_out){
         case 0: sub_out = 0b00000000;break;
         case 1: sub_out = 0b00010000;break;
         case 2: sub_out = 0b00100000;break;
         case 3: sub_out = 0b00110000;break;  
  }
       switch(level_metr){
         case 0: level_metr = 0b00000000;break;
         case 1: level_metr = 0b01000000;break;
   }
       switch(lpf_faza){
         case 0: lpf_faza = 0b00000000;break;
         case 1: lpf_faza = 0b10000000;break;
   }
         writeWire(SETUP_2, sub_f + sub_out + level_metr + lpf_faza); 
   }
   
void BD37543FS::setSetup_3(int f_r_hpf, int r_hpf, int f_hpf){
       switch(f_r_hpf){
         case 0: f_r_hpf = 0b00000000;break;
         case 1: f_r_hpf = 0b00001000;break;
         case 2: f_r_hpf = 0b00110000;break;
         case 3: f_r_hpf = 0b00010000;break;  
   }
       switch(r_hpf){
         case 0: r_hpf = 0b00000000;break;
         case 1: r_hpf = 0b01000000;break;
   }
       switch(f_hpf){
         case 0: r_hpf = 0b00000000;break;
         case 1: r_hpf = 0b10000000;break;
       
   }   
         writeWire(SETUP_3, 0b00000010 + f_r_hpf + r_hpf + f_hpf); 
   }

void BD37543FS::setIn(int in){
       switch(in){
         case 0: in = 0b00000000;break;
         case 1: in = 0b00000001;break;
         case 2: in = 0b00000010;break;
         case 3: in = 0b00000011;break;
         case 4: in = 0b00001010;break;
         case 5: in = 0b00001011;break;
         case 6: in = 0b00001111;break;
         case 7: in = 0b00010000;break;
         case 8: in = 0b00000110;break;
         case 9: in = 0b00001000;break;
        case 10: in = 0b00001001;break;
   }  
         writeWire(INPUT_SELECT, in); 
   }


void BD37543FS::setIn_gain(int in_gain, int mute){
       switch(mute){
         case 0: mute = 0b00000000;break;
         case 1: mute = 0b10000000;break;
   }
         writeWire(INPUT_GAIN, in_gain + mute); 
   }

void BD37543FS::setVol(int vol){
       if(vol > 0){vol = 128 - vol;}
       if(vol <= 0){vol = abs(vol) + 128;}
       writeWire(VOLUME_GAIN, vol); 
   }

void BD37543FS::setFront_1(int front_1){
       if(front_1 > 0){front_1 = 128 - front_1;}
       if(front_1 <= 0){front_1 = abs(front_1) + 128;}
       writeWire(FADER_1_FRONT, front_1); 
   }

void BD37543FS::setFront_2(int front_2){
       if(front_2 > 0){front_2 = 128 - front_2;}
       if(front_2 <= 0){front_2 = abs(front_2) + 128;}
       writeWire(FADER_2_FRONT, front_2); 
   }

void BD37543FS::setRear_1(int rear_1){
       if(rear_1 > 0){rear_1 = 128 - rear_1;}
       if(rear_1 <= 0){rear_1 = abs(rear_1) + 128;}
       writeWire(FADER_1_REAR, rear_1); 
   }

void BD37543FS::setRear_2(int rear_2){
       if(rear_2 > 0){rear_2 = 128 - rear_2;}
       if(rear_2 <= 0){rear_2 = abs(rear_2) + 128;}
       writeWire(FADER_2_REAR, rear_2); 
   }

void BD37543FS::setSub(int sub){
       if(sub > 0){sub = 128 - sub;}
       if(sub <= 0){sub = abs(sub) + 128;}
       writeWire(FADER_SUB, sub); 
   }

void BD37543FS::setMix(int mix_gain){
       if(mix_gain > 0){mix_gain = 128 - mix_gain;}
       if(mix_gain <= 0){mix_gain = abs(mix_gain) + 128;}
            writeWire(MIXING, mix_gain); 
   }

void BD37543FS::setBass_setup(int bass_q, int bass_f){
       switch(bass_f){
         case 0: bass_f = 0b00000000;break;
         case 1: bass_f = 0b00010000;break;
         case 2: bass_f = 0b00100000;break;
         case 3: bass_f = 0b00110000;break;  
   }
         writeWire(BASS_SETUP, bass_q + bass_f); 
   }
   
void BD37543FS::setMiddle_setup(int mid_q, int mid_f){
       switch(mid_f){
         case 0: mid_f = 0b00000000;break;
         case 1: mid_f = 0b00010000;break;
         case 2: mid_f = 0b00100000;break;
         case 3: mid_f = 0b00110000;break;  
   }
         writeWire(MIDDLE_SETUP, mid_q + mid_f); 
   }
   

void BD37543FS::setTreble_setup(int treb_q, int treb_f){
       switch(treb_f){
         case 0: treb_f = 0b00000000;break;
         case 1: treb_f = 0b00010000;break;
         case 2: treb_f = 0b00100000;break;
         case 3: treb_f = 0b00110000;break;  
   }
         writeWire(TREBLE_SETUP, treb_q + treb_f); 
   }

void BD37543FS::setBass_gain(int bass_gain){
       if(bass_gain>0){bass_gain = bass_gain;}                     
       if(bass_gain<=0){bass_gain = abs(bass_gain) + 0b10000000;}  
       writeWire(BASS_GAIN, bass_gain);   
   }

void BD37543FS::setMiddle_gain(int mid_gain){
       if(mid_gain>0){mid_gain = mid_gain;}                     
       if(mid_gain<=0){mid_gain = abs(mid_gain) + 0b10000000;}  
       writeWire(MIDDLE_GAIN, mid_gain);   
   }

void BD37543FS::setTreble_gain(int treb_gain){
       if(treb_gain>0){treb_gain = treb_gain;}                     
       if(treb_gain<=0){treb_gain = abs(treb_gain) + 0b10000000;}  
       writeWire(TREBLE_GAIN, treb_gain);   
   }

void BD37543FS::setLoudness_gain(int loud_hicut, int loud_gain){
       switch(loud_hicut){
         case 0: loud_hicut = 0b00000000;break;
         case 1: loud_hicut = 0b00100000;break;
         case 2: loud_hicut = 0b01000000;break;
         case 3: loud_hicut = 0b01100000;break;
   }
         writeWire(LOUDNESS_GAIN, loud_hicut + loud_gain);  
   }

void BD37543FS::writeWire(char a, char b){
  Wire.beginTransmission(BD37543FS_address);
  Wire.write (a);
  Wire.write (b);
  Wire.endTransmission();
}
