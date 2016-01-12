/*************************************************************
Quick and dirty script to play a random selection of base
jams from Seinfeld. Utilizes wiringPi for GPIO readings
and mplayer for audio output.

Purpose built as a door alarm; when somebody enters the room,
a "random" bass jam will play once, then reset the counter
when the door is closed and play another jam when reopened.
"randomness" is based on the counters position the moment
the door is opened.

Matthew Henderson, 2015
**************************************************************/

#include<stdio.h>
#include <wiringPi.h>

int main(void){
wiringPiSetupGpio();

int Ran = 0;            // Define random variable
pinMode(3, INPUT);


while (1){              // While GPIO is not being read, start looping
++Ran;                  // Increment variable by one
printf("%d \n", Ran);   // Print variable
if (Ran > 6){           // Is variable under 6?...
Ran = 0;                // ...if not, reset it to Zero.
}

while (digitalRead(3)){ // While GPIO Pin 3 is HIGH...

if (Ran == 1) {         //... Check variable against the following and play a file accordingly.
printf("%d \n", Ran);   // Print variable (for debugging)
system("mplayer bass/bass4.wav"); // Call mplayer to play audio file
Ran = 0;                // Reset variable to Zero so audio doesn't play again until we reset GPIO
}

if (Ran == 2) {
printf("%d \n", Ran);
system("mplayer bass/bass7.wav");
Ran = 0;
}

if (Ran == 3) {
printf("%d \n", Ran);
system("mplayer bass/bass8.wav");
Ran = 0;
}

if (Ran == 4) {
printf("%d \n", Ran);
system("mplayer bass/bass19.wav");
Ran = 0;
}

if (Ran == 5) {
printf("%d \n", Ran);
system("mplayer bass/bass23.wav");
Ran = 0;
}

if (Ran == 6) {
printf("%d \n", Ran);
system("mplayer bass/bass22.wav");
Ran = 0;
}

}
}
return 0;
}
