/*
Number Sort Spell
Problem Description
Let's play the following game with two natural numbers (positive integers): Say, the two numbers are 5 and 6 and display them sorted as below in column A. We then spell the numbers and display them in column B. The spellings are then sorted and displayed in column C while column D displays the numerals corresponding to the sorted spellings:

Column A: Sorted numerals

Column B: Spelt numerals

Column C: Sorted Spelt numerals

Column D: Numerals corresponding to sorted spellings

Table 1:

A    B     C    D

5   Five  Five  5
6   Six   Six   6

Note that "Five" appears before "Six" in sorting order. Hence the numbers 5 and 6 are in the same order even when they are spelt!

Let's now generate two new numbers by adding up the corresponding numbers (in columns A and D) in the two rows in the table above: 
Table 2:

A     B     C     D

10   Ten   Ten    10
12  Twelve Twelve 12

Again the spelt numbers appear in the sorted order corresponding to the numbers themselves. Proceeding in this fashion, we get the 
following tables: 

Table 3:

A          B           C          D
20      Twenty       Twenty       20
24    Twenty Four   Twenty Four   24

Table 4:

A            B             C            D
40          Forty         Forty         40
48        Forty Eight    Forty Eight    48

Table 5:
A         B         C         D

80      Eighty    Eighty      80
96    Ninety Six  Ninety Six  96

Table 6:

A                    B                    C                    D
160     One Hundred Sixty        One Hundred Ninety Two       192
192    One Hundred Ninety Two     One Hundred Sixty           160

Table 7:
A                     B                   C                     D
352     Three Hundred Fifty Two   Three Hundred Fifty Two       352
352     Three Hundred Fifty Two   Three Hundred Fifty Two       352

We observe that the two numbers 5 and 6 have "converged" to 352.

Here's another example with the two numbers being 100 and 50:

Table 1:

A

B

C

D

50

Fifty

Fifty

50

100

One Hundred

One Hundred

100

Table 2:

A

B

C

D

100

One Hundred

One Hundred

100

200

Two Hundred

Two Hundred

200

Table 3:

A

B

C

D

200

Two Hundred

Four Hundred

400

400

Four Hundred

Two Hundred

200

Table 4:

A

B

C

D

600

Six Hundred

Six Hundred

600

600

Six Hundred

Six Hundred

600

Thus 50 and 100 "converge" to 600. Note that the numbers converge when the spelled order breaks from the numeric order.
Write a program to accept two natural numbers n1 and n2, perform the above calculations and output the "converged" number. 
The following are some example spellings of numbers - spell numbers in a similar fashion:

100: One Hundred

1729: One Thousand Seven Hundred Twenty Nine

99,999: Ninety Nine Thousand Nine Hundred Ninety Nine

output "Out of bounds" if any number exceeds 99,999 during calculations.

(Note: If the input numbers are the same, we would take the output to be that number itself.)

Constraints
N,M<=90000

Input Format
First Line contains two integers delimited by space <N M>

Output
Single line containing Converge number

"Out of bounds" if any number exceeds 99,999 during calculations.

Test Case

Explanation
Example 1: Input: 5 6 Output: 352

Example 2: Input: 1 1 Output: 1
*/
