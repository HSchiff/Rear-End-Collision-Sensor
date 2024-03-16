README

Rear End Collision Sensor
Hannah Schiffmacher

Setting Up Hardware:
	In the Phase 3 folder, there is a picture with
all of the wiring for the hardware, called hardware_layout.


Connecting Software to Elegoo Uno:
	Plug in the Elegoo Uno into the computer, and in 
the Arduino IDE at the top, select the board. Then in 
the upper left hand corner, click the check mark. This 
will verify that the code will run properly. Then click
the arrow.  This will send the code to the board and
the program will start running.

Running the Program:
	Go to tools and select 'Serial Monitor'. This
will show all of the distances being detected by the
ultrasonic sensor per loop. 

	The rear-end collision sensor will output
different warnings depending on the situation.  Use an
object to simulate a car and move it towards the sensor
in varying speeds and distances. If there are any 
warnings, the buzzer will beep and the LCD Display will
say a warning.


Troubleshooting:
	If the ultrasonic sensor is not being 
consistent, readjust the angle it is pointing and
test again.  If an object is less than 3 centimeters
away from the sensor, it will give inconsistent
numbers so this is expected.
