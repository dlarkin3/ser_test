# Camera synch using arduino analysis code  
- The code listed below was run on an arduino Trinket M0 connected to a Ubuntu 18.04 laptop by USB3.  
- The arduino sends a single byte at 25hz thru the the USB connection and a sqaure wave to pins 3 and 4 at 25hz.  
- The arduino square wave frequency was validated using an Oscilloscope.  
- Analysis of the times printed to file by the CPP code running on the linux machine is below:  
## ======================================================
Number of records: 545  
Time between loops (25hz = 40 ms)  
### ------------------
Average (ms): 40.0189  
StdDev (ms): 0.1083  
Max (ms): 40.4101  
Min (ms): 39.603  

## ======================================================
To compile the CPP code  
- Clone, build and install this repo (Follow the readme):  
`git clone https://github.com/gbmhunter/CppLinuxSerial.git`  
- Compile the file sertest.cpp:  
`g++ sertest.cpp -lCppLinuxSerial`

## ======================================================
To run the arduino code use the arduino IDE to compile and send the code in dual_sig_trigger.ino

