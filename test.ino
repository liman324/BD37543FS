#include <Wire.h> 
#include <BD37543FS.h>
BD37543FS bd; 

void setup(){
   Wire.begin();
   audio();
}

void loop(){}

void audio(){
   bd.setSetup_1(0,2,1); 
                   // default (0,2,1) | int 0...3, 0...3, 0...1
    bd.setSetup_2(0,0,0,0); 
                   // int sub_f ------ OFF 55Hz 85Hz 120Hz 160Hz = int 0...4
                   // int sub_out ---- LPF Front Rear Prohibition = int 0...3
                   // int level_metr - HOLD REST = int 0..1
                   // int faza ------- 0 180 = int 0...1
    bd.setSetup_3(0,0,0); 
                   // int f_r_hpf ---- 55Hz 85Hz 120Hz 160Hz = int 0...3
                   // int r_hpf ------ pass NOT_pass = int 0...1
                   // int f_hpf ------ pass NOT_pass = int 0...1
    bd.setIn(0); 
                   // 0...10 | in A B C = int 0 1 2 
    bd.setIn_gain(0,0); 
                   // in_gain -- 0...20 = 0...20 dB, mute -- 0 default 
    bd.setVol(0); 
                   // -79...+15 dB = int -79...15
    bd.setFront_1(0); 
                   // -79...+15 dB = int -79...15
    bd.setFront_2(0); 
                   // -79...+15 dB = int -79...15
    bd.setRear_1(0); 
                   // -79...+15 dB = int -79...15
    bd.setRear_2(0); 
                   // -79...+15 dB = int -79...15
    bd.setSub(0); 
                   // -79...+15 dB = int -79...15
    bd.setMix(-79);
                   // -79...+7 dB = int -79...7
    bd.setBass_setup(0, 0); 
                   // 0.5 1.0 1.5 2.0 --- int 0...3, 60Hz 80Hz 100Hz 120Hz --- int 0...3
    bd.setMiddle_setup(0,0); 
                   // 0.75 1.0 1.25 1.5 --- int 0...3, 500Hz 1kHz 1.5kHz 2.5kHz --- int 0...3
    bd.setTreble_setup(0,0); 
                   // 0.75 1.25  --- int 0...1, 7.5kHz 10kHz 12.5kHz 15kHz --- int 0...3
    bd.setBass_gain(0); 
                   // --20 ... +20 dB = int -20 ... 20    
    bd.setMiddle_gain(0); 
                   // --20 ... +20 dB = int -20 ... 20
    bd.setTreble_gain(0); 
                   // --20 ... +20 dB = int -20 ... 20        
    bd.setLoudness_gain(0,0); 
                   // Hicut1 Hicut2 Hicut3 Hicut4 = int 0...3
                   // 0 ... 20 dB = int 0 ... 20
  }
