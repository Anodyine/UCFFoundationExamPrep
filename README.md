# UCF Foundation Exam Prep
This repo attempts to follow along with the UCF Foundation Exam Structure outline found here:

https://www.cs.ucf.edu/wp-content/uploads/2022/02/FE-ExamOutline.pdf

# Getting Started
Currently, only Windows quick start instructions are provided.

## Windows
To get started easily with Windows and Visual Studio Code follow the following steps:

### Installing Terminal and Compiler
1. Download and install MSYS2 from here: https://www.msys2.org/
2. Run MSYS2 Terminal
3. Run: "pacman -Syu" and type Y when prompted
4. Run: "pacman -S mingw-w64-x86_64-gcc" and type Y when prompted to install the compiler
5. Run: "gcc --version" to confirm that the compiler is installed
4. Run: "pacman -S mingw-w64-x86_64-gcc" and type Y when prompted to install the debugger
5. Open the Windows menu and type "Environment" then choose Edit the System and Environment Variables
6. Click on Environment Variables
7. Under System Variables, click on Path
8. Click Edit
9. Click New
10. Type in C:\msys64\mingw64\bin
11. Click Ok

### Installing Visual Studio and Extensions
7. Download and install Visual Studio Code from here: https://code.visualstudio.com/Download
8. Open Visual Studio Code
9. Click on the Extensions tab on the left bar. It is the one with 4 boxes. Three boxes connected in an L shape and one box is floating in the top right of the icon
10. Type "C C++" into the search
11. Click Install for the C/C++ plugin from Microsoft
12. Once the install is complete, search for "Code Runner" in the extensions tab
13. Install the one with .run in the icon
14. Restart Visual Studio Code

### Making a Test Project
16. Click on File -> Add Folder to Workspace
17. Right click in the window near the center in the blank space and select New -> Folder
18. Name it whatever you like (it can be just for testing)
19. Click Add in the bottom right of the window
20. In the top of the left pane, right click on the folder you created
21. Click New File
22. Name it test.c
23. Add the following program:
    
#include <stdio.h>

int main() {
    printf("hello world");
    return 0;
}

25. Near the top right corner, there should be a play button with a dropdown arrow next to it. Click the dropdown arrow. (This was added by .run extension)
26. Click run
27. You should see the code run in the bottom panel

### Set Up Run in Terminal (So we can receive user input)
29. Click on File -> Preferences -> Settings
30. Scroll down the Run Code configuration and click on it
31. Scroll down until you see Run in Terminal and click on that box to check it
32. Run the code as you did earlier in step 25 and see that it runs in the terminal

## Running Tests

1. In the terminal, navigate to the folder with the files you want to test. For example, enter "cd DataStructures/LinkedLists" without the quotes.
2. Run the command "gcc -o myName ./*.c && ./myName" 

The output of the tests should display in the console and file called "myName.exe" will be created in the current folder.

## Debugging Tests 

Debugging tests should be possible by opening the file you wish to run and clicking on the run and debug (shaped like a play button and a bug in the bottom right corner.)
The breakpoints that you set in the current file and all files in the same directory can be hit.

The configuration of the debugger is provided in ./vscode/tasks.json. Line 10 of that file causes all C files in the same directory as the currently opened file to be included
in the debugging. 