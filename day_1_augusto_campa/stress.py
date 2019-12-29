import os


while 1:
        # os.system('./generator ' + str(seed) + ' > input.txt')
        os.system('g++ -o sol sol.cpp')#g++ sol.cpp -std=gnu++11 -o sol
        os.system('./sol < input.txt > output.txt')
        exit(0)
        #os.system('g++ -o generator generator.cpp')#g++ generator.cpp -std=gnu++11 -o sol
        #os.system('g++ -o bruteforce bruteforce.cpp')
        #os.system('./generator > input.txt')
        #os.system('./bruteforce < input.txt > bruteforce.txt')
        #os.system('./sol < input.txt > fast_solution.txt')
        #if open('output.txt').read() != open('coutput.txt').read():
         #       print 'WA'
         #       exit(0)
