# wordscapes_cheat


Build with the following on Linux:

`gcc -Wall gw.c -o gw`

Build with the following on Termux:

`clang gw.c -o gw`

Run like this to output all words that may fit:

`./gw xxxxxxx ......`

In the above example the `x` represents the letters of the level you are cheating on, and the `.` represent the letters you have as clues if any. Simply replace a `.` with each letter you have and hit enter. The program will search the words file for any matches and print them out. It is an instant result even on a mobile phone running in Termux.

## Limitations

Currently the words list contains many words that are not acceptable by the game. I need to find a better word list to generate my words file from. If anyone knows one point me to it please! For very long words that are extremely hard to get without using coins this program excels. It works 100% of the time usually with only a single result. For 3 and 4 letter words however it returns too many results and you may need to try a lot of words until the game accepts the correct answer.
