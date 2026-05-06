/*
Name:
Student ID:
*/

#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {

    char buffer[100] = "";   // holds final string

    // loop through arguments (skip argv[0] which is program name)
    for (int i = 1; i < argc; i++) {

        strcat(buffer, argv[i]);   // add current argument

        // add "-" if it's NOT the last argument
        if (i < argc - 1) {
            strcat(buffer, "-");
        }
    }

    printf("%s\n", buffer); // DO NOT change this line

    return 0;
}