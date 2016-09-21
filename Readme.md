Sorting Algorithms:
    Bubble
    Heap
    Insertion
    Merge
    Quick
    Radix
    Selection
    Shell

### Usage:

before you run the ShellTest.sh you need to remove the Executable directory.
then run the ./ShellTest.sh. because it is written by cpp. you need to compile
the sorting algorithms on your own operating system. the command ./ShellTest.sh
will help you to do this first.

First run the command:
```bash
rm ./Executable/*  ./Test/*
```
you just need to do this for only one time.

Then run the command:
```bash
./ShellTest.sh
```

the command can take two parameters:
    the first parameter is the numbers you want to sort. the default is ten
    thousand.
    the second parameter is the sorting algorithm name I have show you the head
    of this file. we test all the sorting algorithms by default.


you can test as:

    ./ShellTest.sh
    Test 10000 with all the sorting algorithms.

    ./ShellTest.sh 100000 
    Test 1E5 with all the sorting algorithms.

    ./ShellTest.sh 1000000 Quick
    Test 1E6 with the sorting algorithm Quick.


If you find any bugs or errors please send me an email by:
mailto:ronnie.lee@foxmail.com





