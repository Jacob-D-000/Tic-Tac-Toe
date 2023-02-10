# Toe Documentation.
This file will contain all documentation pertaining to my code for the tic tac toe project in C

I will do my best to keep a log of the times I work on this project. Look at the commit list to see how the work has developed.
## Feb 7
### 4:00 - 5:00
running into some issues with too many arrays. Going to work on it some more when I get home
## Feb 8
### 8:25 - 8:35 am
Started the Flowchart for the grid printer.
### probably 20 minutes of work during linux
I ran into a probably with the flowchart. Turns out I wasn't signed into lucid through my school account. Long story short, I couldn't make it the right size. I've fixed the issue though so there shouldn't be any issues with flowchart size. Still a work in process so ignore the version of the pdf found in this commit.
### Worked on the flow for about 45 mins
I think I have the charts logic mostly filled out. It might not be the most optimal, but I have enough information to write and implement the code. I'll start coding after class, and clean up the flowchart for later reference.
### 4:00 - 5:00pm
I was able to implement the flowchart, all be it there were come flaws with the ASCII art so I will fix that when I get home. I'll explain that in further detail then.
### 6:00 - 7:00pm
So, what was my issue? To put it simply, whitespace. The issues of primary came form how the "\n" was placed in the variable eline. Because eline had a return character and the loop put another return character after each loop of "i", the an extra line was placed of line 3 and 7 (see an ASCCI mock-up below in Fig 3). 

</br>![ASCCI_TICTACTOE](ASCCI_TERMINAL.png)
fig 1. ASCII Tic-Tac-Toe table in the terminal

</br>![ASCCI_TICTACTOE](ASCCI_TERMINAL_WITH_X.png)
fig 2. ASCII Tic-Tac-Toe table in the terminal with ASCII X

</br>![ASCCI_TICTACTOE](OLD_ASCCI.png)
fig 3. Previous ASCII art X with Current O as well as ASCII table with index that my for loop runs through

My time during this session was fixing the code and cleaning up my documentation to look better.
## Feb 9
### 3:00 - 4:00pm
I started working on the user input portion of the program and and into a major snag. There was a bug in how the program read input and it frustrated me to the point where I have to take a break for the day. I'll work on it tomorrow
## Feb 10
### 8:45 - 10:00am
The bug has been fixed! They were more problems in fixing it however. The first issue I ran into was a frustrating one. To make a long story short, the compiler wouldn't comply the program properly for whatever reason. It was solved by simply rebuilding the program, but my stubborn ass didn't think of that until Nathan Suggested it (Thanks Nathan ;). The second major issue was with how scanf worked. To put it simply, ive been using scanf wrong this entire time. Turns out, you scan and input into the pointer instead of into the variable. Needless to say that I appreciate the  learning experience. I think my next step is to create a way to insert a value into the grid. This should be interesting since I don't know how I'll be able to move the gird around properly.