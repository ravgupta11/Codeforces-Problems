import os

while 1:
        # os.system('./generator ' + str(seed) + ' > input.txt')
        os.system('g++ -o sol sol.cpp')
        os.system('g++ -o generator generator.cpp')
        os.system('g++ -o bruteforce bruteforce.cpp')
        os.system('./generator > input.txt')
        os.system('./bruteforce < input.txt > bruteforce.txt')
        os.system('./sol < input.txt > fast_solution.txt')
        if open('bruteforce.txt').read() != open('fast_solution.txt').read():
                print 'WA'
                exit(0)
