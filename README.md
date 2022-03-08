# wordscapes_cheat


Build with the following on Linux:

`gcc -Wall gw.c -o gw`

Build with the following on Termux:

`clang gw.c -o gw`

Run like this to output all words that may fit:

`./gw xxxxxxx ...... <1>`

In the above example the `x` represents the letters of the level you are cheating on, and the `.` represent the letters you have as clues if any. For 7 letter words enter seven `.` for a 5 letter word enter 5 etc. Simply replace a `.` with each letter you have and hit enter. The program will search the words file for any matches and print them out. It is an instant result even on a mobile phone running in Termux. The `<1>` means an exhaustive search, if no word is found add `1` to the command line to search a longer word list. 

## Running on Termux on your phone. 

This is useful for when you are out of range or credit and cannot view ads or purchase coins for hints. Below is a rough guide for seting it up. 

Download F-Droid here: https://f-droid.org/

Install it once its downloaded. Open it, and let it update repos. Then search for and install Termux. 

Once Termux is installed open it and run the following commands: 

`pkg install git clang`

`git clone https://github.com/wbpxre150/wordscapes_cheat.git`

`cd wordscapes_cheat`

`clang gw.c -o gw`

You can now use with the above instructions `./gw xxxxxxx .......` 
