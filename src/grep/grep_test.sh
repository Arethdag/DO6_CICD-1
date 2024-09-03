#!/bin/bash

./s21_grep e test.txt > s21_grep.txt
grep e test.txt > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -e "for" test.txt > s21_grep.txt
grep -e "for" test.txt > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -i e test.txt > s21_grep.txt
grep -i e test.txt > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -v e test.txt > s21_grep.txt
grep -v e test.txt > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -c e test.txt > s21_grep.txt
grep -c e test.txt > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -l e test.txt test.txt test.txt > s21_grep.txt
grep -l e test.txt test.txt test.txt > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -n e test.txt > s21_grep.txt
grep -n e test.txt > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -h e test.txt > s21_grep.txt
grep -h e test.txt > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -s e test.txt > s21_grep.txt
grep -s e test.txt > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
