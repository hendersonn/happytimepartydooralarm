# happytimepartydooralarm
Happy Time Party Door Alarm

You'll have to compile the source with the WiringPi library. Before doing that, though, edit the source to point mPlayer to where your audio tracks are located (mine were in a folder titled "bass").

To compile with WiringPi, run the following:
gcc -o sf sf.c -l wiringPi

Now you can execute the program with:
sudo ./sf
