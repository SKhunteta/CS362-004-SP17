/*
Shreyans Khunteta
CS 362

In inputChar, I tried to figure out what kinds of characters it wanted.
I found it could use both letters/symbols, so I looked it up on the ASCII table.
32-126 is the range we need, and that's 94 characters.
So I made rand() % 95 to give me something between 0 and 94, and added 32 to it.

In inputString, I realised that there are four different letters. So I'm randomly generating
a number from 0 to 4 and assigning a letter to it. This is generating a random string.
After about 2,000 of these strings, you usually get an error message.

*/
