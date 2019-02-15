//
// Created by sids on 1/3/19.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int wearOut(int childNumber);

int main(int argc, char *argv[]) {
    int numberOfChilds = (int) strtol(argv[1], NULL, 10);
    int childPIDs[numberOfChilds], i, childPipes[numberOfChilds][2], quitFlag = 0;
    char errString[150];
    char consent;
    char quitConsent;
    printf("\nDo you want to wear out your SSD before the warranty expires?\n\nDon't worry, we've all been there, this script uses state-of-the-art* SSD wearing technology using AI* and ML* to wear out your SSD.\n\n*These are utterly false and no test of ANY sort were conducted.\n\nPlease note that I am NOT responsibe for anything that may happen, use this script at your OWN risk and don't run it unless you understand what you are doing.\n\n");
    printf("Do you want to continue?(y/n): ");
    consent = getchar();
    if (consent == 'y') {
        for (i = 0; i < numberOfChilds; i++) {
            if (pipe(childPipes[i]) == -1) {
                fprintf(stderr, "%s",
                        "Creation of a pipe failed, cannot proceed without pipes as it may create zomblies, perhaps launching with less number of will help. exiting..\n");
                exit(1);
            } else {
                printf("Creation of pipe was successful.\n");
                printf("Arghh..\n");
            }
            childPIDs[i] = fork();
            if (childPIDs[i] == 0) {
                printf("Child %d was created.\n", i);
                close(childPipes[i][1]);//Close the writing end of pipe.
                while (quitFlag != 1) {
                    wearOut(i);
                    read(childPipes[i][0], &quitFlag, sizeof(quitFlag));
                }
                exit(0);
            } else if (childPIDs[i] == -1) {
                sprintf(errString,
                        "Creation of child number %d failed.. Perhaps launching with less number of will help.. exiting.. \n",
                        i);
                fprintf(stderr, "%s", errString);
                exit(1);
            }
            printf("Attempting to close pipes.\n");
            close(childPipes[i][0]);//Close the reading end of pipe.
            write(childPipes[i][1], &quitFlag, sizeof(quitFlag));
            printf("Closed pipes and written 1\n");
        }
        while (1) {
            printf("Please enter q whenever you with to quit and we'll clean everything up and quit!.\n");
            quitConsent = getchar();
            if (quitConsent == 'q') {
                for (i = 0; i < numberOfChilds; i++) {
                    quitFlag = 1;
                    write(childPipes[i][1], &quitFlag, sizeof(quitFlag));
                }
                printf("All children have been instructed to quit, waiting for them to do so, we don't wanna leave behind any zombies.\n");
                wait(NULL);
                exit(0);
            } else {
                printf("Uhh.. you need to type 'q' to quit.\n");
            }
        }
    } else {
        printf("Alright, exiting.\n");
    }
    return 0;
}

int wearOut(int childNumber) {
    char command[100];
    sprintf(command, "timeout 30s cat /dev/urandom > .iAmNefarious%d;", childNumber);
    system(command);
    sprintf(command, "rm -rf .iAmNefarious%d;", childNumber);
    system(command);
    return 0;
}