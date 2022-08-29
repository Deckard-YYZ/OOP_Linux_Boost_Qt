1. In order to use the record button, you have to install the external library "sox" first

2. There are two absolute addresses in blackkey.cpp(line 28 and 43) and whitekey.cpp(line 18 and 31) files, make sure to change it to your actual addresses in order to access those sound files.

3. when input the filename on the UI, after typing your filename, please click on any other two textbrowser at the white space. So that the cursor not select on the lineEdit box, and the user could play the piano keys by using the keyboard.

4. Please make sure input filename each time the user want to record anything.

5. Inside the audioRecorder.cpp, for the 'playcommand' variable, please change the "play" command to the absolute address if the current command not working.

6. Make sure to install library "Multimedia" if current project cannot find files related to "Multimedia". Run commands below in terminal:
sudo apt-get install libqt5multimedia5-plugins qml-module-qtmultimedia

