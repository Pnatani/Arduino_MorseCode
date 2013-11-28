Arduino_MorseCode
=================

Name: Pratibha Natani

Portland State University

Date: 03/12/2013


Project Description: 
A simple application is developed for Arduino Uno, that encodes serial input into Morse code. The on board LED (see reference material) is used to display the morse code output. The application conforms following requirements:

1. The application uses "International Morse Code" for alphanumeric encoding.

2. The application stores alphanumeric characters (a-z, 0-9). Upper case characters are used. Non-alphanumeric characters are ignored with the exception of the newline character '\n'.

3. When a user sends a newline character, the application encodes the stored message from (2) using either sound or light. The application then clears its backing store and then allows additional input.

4. The duration of a dash is three times the duration of a dot.

5. Each dot or dash is followed by a short silence, equal to the dot duration.

6. The letters of a word are separated by a space equal to three dots (one dash), and two words are separated by a space equal to seven dots.

7. The dot duration is the basic unit of time measurement in code transmission. This duration should not exceed 1000 milliseconds.

Testing Application: 
The application is tested on a variety of testcases. To check the Morse code format of the input letters, various Serial.print statements have been added in the code. These statements print the morse code of the letters from (0-9 and A-Z) on the Serial Monitor and thus confirm the correct translation. Tests are conducted to verify the gap between various words of a sentence and also to check that unrequired characters e.g. (;, :, @ etc) are ignored.


Files:

1) Arduino_MorseCode.ino contains code for converting input string into Morse code


Steps for Arduino Setup:

1) Get the latest version of Arduino for your PC from below website:
http://arduino.cc/en/Main/Software 

2) Connect the Arduino board to your PC using USB cable. The LED (labelled ON) should be turned on. 

3) Install drivers for the Arduino Uno for your Windows version. Open Device Manager from Start->Run->devmgmt.msc Check for Ports (COM & LPT), under this right click on “Arduino UNO (COMxx)” Refer link http://arduino.cc/en/Guide/windows for details. Below is the screenshot for reference.

4) Now we can launch the Arduino Application.


Compiling and Testing “Arduino_MorseCode.ino”:

1) Open the file with Arduino Application.

2) Click Sketch->Verify/Compile to compile the file.

3) Choose the Arduino Board, from Tools->Board->Arduino Uno

4) Click “->” icon to upload the file on Arduino board.

5) To test the program with Serial Monitor, click Tools->Serial Monitor. This opens the Serial Monitor window.

6) Modify settings of this windows. Choose “Newline” in the dropdown box of Serial Monitor to allow.

7) Provide Input in the window and click “Send”.


http://arduino.cc/en/Guide/windows

http://arduino.cc/en/Main/Software

http://ee.hawaii.edu/~tep/EE160/Book/chap4/subsection2.1.1.1.html

http://www.programmingforums.org/post178636.html http://en.wikipedia.org/wiki/Morse_code
