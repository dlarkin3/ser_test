#include <CppLinuxSerial/SerialPort.hpp>
#include <chrono>
#include <iostream>
#include <fstream>
#include <signal.h>

// https://github.com/gbmhunter/CppLinuxSerial
using namespace mn::CppLinuxSerial;
 
using namespace std;
 using namespace std::chrono;

static volatile sig_atomic_t keep_running = 1;

static void sig_handler(int _)
{
    (void)_;
    keep_running = 0;
}


int main() {
    signal(SIGINT, sig_handler);

    ofstream myfile;
    myfile.open ("times.csv");

	// Create serial port object and open serial port
    SerialPort serialPort("/dev/ttyACM0", BaudRate::B_9600);
	// SerialPort serialPort("/dev/ttyACM0", 13000);
    serialPort.SetTimeout(-1); // Block when reading until any data is received
	serialPort.Open();

	// Write some ASCII datae
	// serialPort0.Write("Hello");
    const char *sendString = "H\n"; 
    std::string readData;
long last = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::time_point_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now()).time_since_epoch()).count();

	// Read some data back
    while(keep_running) {

long start = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::time_point_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now()).time_since_epoch()).count();

        //std::cout << "Top of loop\n";
        serialPort.Read(readData);
        //std::cout << "Received data: " << readData;
        //auto end = chrono::steady_clock::now();
       myfile << start
             << ","
            << last
            << "," << std::endl;
last = start;
    }
//<< chrono::duration_cast<chrono::nanoseconds>(end - start).count()
cout << "exiting cleanly"<< std::endl;
myfile.close();
	// Close the serial port
	serialPort.Close();
}



// trinket udev rule
// SUBSYSTEM=="tty", ATTRS{idVendor}=="239a", ATTRS{idProduct}=="801e", GROUP="dialout", SYMLINK="trinket"
// https://www.geeksforgeeks.org/ipc-shared-memory/
