import subprocess
import os

def cpile(cpp_file,exe_file):
	if os.system('g++ '+ cpp_file + ' -I/usr/include/CL -lOpenCL -o ' + exe_file)==0:
		line="./" + exe_file
		os.system(line)

#compile platforms.cpp
#cpile("platforms.cpp","p1")

#compile main.cpp
cpile("./goldenStandard/multiplicationGoldenStandard.cpp","./goldenStandard/main")
