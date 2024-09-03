#!/bin/bash

./s21_cat testfail.txt >> log.txt
cat test.txt >> log1.txt
diff -s test.txt log.txt
rm log.txt log1.txt

./s21_cat -b test.txt >> log.txt
cat -b test.txt >> log1.txt
diff -s test.txt log.txt
rm log.txt log1.txt

./s21_cat -e test.txt >> log.txt
cat -e test.txt >> log1.txt
diff -s test.txt log.txt
rm log.txt log1.txt

./s21_cat -n test.txt >> log.txt
cat -n test.txt >> log1.txt
diff -s log.txt log.txt
rm log.txt log1.txt

./s21_cat -s test.txt >> log.txt
cat -s test.txt >> log1.txt
diff -s log.txt log.txt
rm log.txt log1.txt

./s21_cat -t test.txt >> log.txt
cat -t test.txt >> log1.txt
diff -s log.txt log.txt
rm log.txt log1.txt
