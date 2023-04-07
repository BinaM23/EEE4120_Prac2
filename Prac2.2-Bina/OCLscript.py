# Compiles and runs multiplication.cpp
# run command: python OCLscript.py -i <filename> on terminal


import sys, os, getopt, time

def main (argv):
    cppFile = ""
    exeFile = ""

    try:
        opts, args = getopt.getopt(argv, "hi:", ["help", "ifile="])
    except getopt.GetoptError as err:
        # print help information and exit
        sys.exit(2)
    for o, a in opts:
        if o in ("-i", "--ifile"):
            cppFile = a + '.cpp'
            exeFile = a
            #os.system("rm ./*.txt")
            
            run(cppFile, exeFile)
               
        else:
            sys.exit()

def run(cppFile, exeFile):
    os.system("echo Compiling " + cppFile)
    if os.system("gcc " + " -o " + exeFile  + " " + cppFile + " -lOpenCL " + " -lstdc++") == 0:
        os.system("echo Running " + exeFile)
        os.system("echo -------------------")
        os.system("./" + exeFile)
        #runs kernel 10 times, get the mean yourself
        for i in range(10):
            os.system("./" + exeFile)
            time.sleep(1.1)
    else:
        print("Compilation Failed - Check <filename> is correct")

if __name__=='__main__':
    main(sys.argv[1:])