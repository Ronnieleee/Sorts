#!/usr/bin/env bash
######################################################################
# FileName:    Test.sh
# Author:      Lonely, CS0901, HUST
######################################################################

if test -z "$1"
    then size=10000
    else size=$1
fi

if test -z "$2"
    then testfile=*.cpp
    else testfile=$2
fi

# create test directory
mkdir -p Executable
mkdir -p Test

# generate random test data
echo " Generating test data..."
echo 'main(){int _='$size';srand(time(0));while(_--)printf("%d\n",(int)rand());}' > Test/-Rand.c
gcc Test/-Rand.c -o Test/-Rand 2> /dev/null
echo $size > Test/-TestData
Test/-Rand >> Test/-TestData

# generate answer data
echo " Generating answer..."
cat Test/-TestData | tail -n +2 | sort -n > Test/-Answer

# start test
TIMEFORMAT="%Us"
rm -f Test/-TestResult
for x in $testfile
do
    echo -n " Testing $x..."
    binname=Executable/`basename $x .cpp`
    if test $binname -ot $x; then g++ -O3 $x -o $binname; strip $binname; fi
    #cat $x | wc -c | tr -d "\n" >> Test/-TestResult
    printf "%-18s" "$x" >> Test/-TestResult
    (time $binname > Test/-Result < Test/-TestData) 2>&1 | tr -d "\n" >> Test/-TestResult
    #sa -a | grep -P "`basename $x .cpp`$" | awk '{print "\t\t"$5}' | tr -d "\n" >> Test/-TestResult
    echo "" >> Test/-TestResult
    diffmsg=$(diff -q Test/-Answer Test/-Result)
    if test -n "$diffmsg"
        then echo "Wrong Answer!" # & rm $binname
        else echo "OK!"
    fi
done
cat Test/-TestResult | sort -n -k2 > Test/-TestResult-Sorted

# display test result
echo -n -e "\033[1;35m"
echo "Sorting $size numbers ranged from 0 to 2147483647"
echo -n -e "\033[1;33m"
echo "====== Test Result ======"
echo -n -e "\033[1;34m"
printf "%-18s%s\n" "Filename" "Time"
#"Space"
echo -n -e "\033[1;32m"
cat Test/-TestResult-Sorted
echo -n -e "\033[0;0m"
exit
