# [BogoSort](https://en.wikipedia.org/wiki/Bogosort), the best sorting algorithm

Implemented here (badly) in C!

Compile: `gcc main.c -std=c99 -o bogosortc`

You can change the output filename (the bit after the -o) to whatever you want, I won't get angry I promise. But you'll have to 
update the 'usage' section below to match your filename. Also, you don't have to use GCC. Any C compiler will probably work.

Usage: `./bogosortc [num1] [num2] ... [numN]`

Depending on certain things, you might have to `chmod +x bogosortc` before you can run the program.

Non-integer strings will be interpreted as 0 due to the behavior of `atoi()`. 

Happy sorting!
