# ASXPM, C/CPP Linux Terminal XPM picture visualizer: 
	
Reads an xpm image to display it to the terminal in ASCII chars, the image is kinda
small so the downsampling value can be modified in #define SCALE_FAC in hpp file.

# Requirements

	- c++ compiler.
	- GNU stty

- The size of the picture is scaled with "stty size" output called from a child process
before the parsing of the file.
- I could modify the terminal size with stty col/row "sizeof pic" to scale the 
terminal directly instead of scaling the picture but idk atm.

# Build

	git clone https://github.com/gamabuntoo/ascxpm asxpm && cd asxpm
	make
	./ascxpm "file.xpm"

# Delete

-	make clean // remove .o files
-	make fclean// remove executable and .o files




# Warnings

	Some bugs might still be present I didnt tested every xpm possibilty but I've corrected some majors crashes rn.
	If u find one contact me pls.

- Small tty size :
![image](https://github.com/user-attachments/assets/e5745e02-6cc6-4bb8-b33e-128cd07fa341)
- Big tty size :
![image](https://github.com/user-attachments/assets/ab793805-0ac4-4ba8-a89c-82b7ac536a61)



old c version :![image](https://github.com/user-attachments/assets/7fb486b9-ec3c-450c-8550-15a6cf917d82)
