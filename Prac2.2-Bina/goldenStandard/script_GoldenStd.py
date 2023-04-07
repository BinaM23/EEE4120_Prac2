# automatically Compiles and runs multiplicationGoldenStandard.cpp
# run command: python script_GoldenStd.py -i <filename> on terminal


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
            # for i in range(10):
            run(cppFile, exeFile)
            # time.sleep(1.1)
        else:
            sys.exit()

def run(cppFile, exeFile):
    os.system("echo Compiling " + cppFile)
    if os.system("gcc " + " -o " + exeFile  + " " + cppFile + " -lstdc++") == 0:
        os.system("echo Running " + exeFile)
        os.system("echo -------------------")
        # Run file once to warm up cache (not timed)
        os.system("./" + exeFile)
        time.sleep(1)
        # Run executable 10 times to get relable times or get the mean
        for i in range(10):
            os.system("./" + exeFile)
            time.sleep(1.1)
    else:
        print("Failed to compile - Check if <filename> is correct")

if __name__=='__main__':
    main(sys.argv[1:])