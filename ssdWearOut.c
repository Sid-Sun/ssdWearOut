//
// Created by sids on 1/3/19.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int wearOut(int childNumber);

int createChilds(int numberOfChilds, char *argv[]);

int main(int argc, char *argv[]) {
    int numberOfChilds = (int) strtol(argv[1], NULL, 10);
    int i, creatorParentComm[2], quitFlag = 0;
    int creatorPID;
    char consent;
    char quitConsent;
    printf("\nDo you want to wear out your SSD before the warranty expires?\n\nDon't worry, we've all been there, this script uses state-of-the-art* SSD wearing technology using AI* and ML* to wear out your SSD.\n\n*These are utterly false and no test of ANY sort were conducted.\n\nPlease note that I am NOT responsibe for anything that may happen, use this script at your OWN risk and don't run it unless you understand what you are doing.\n\n");
    printf("Do you want to continue?(y/n): ");
    consent = getchar();
    if (consent == 'y') {
        creatorPID = fork();
        if (creatorPID == 0) {
            close(creatorParentComm[1]);//Close the writing end of pipe.
            while (quitFlag != 1) {
                read(creatorParentComm[0], &quitFlag, sizeof(quitFlag));
                createChilds(numberOfChilds, argv);
            }
            exit(0);
        } else if (quitConsent == -1) {
            fprintf(stderr, "%s", "Unable to create child.. exiting.");
            exit(1);
        }
        close(creatorParentComm[0]);//Close the read end of pipe.
        write(creatorParentComm[1], &quitFlag, sizeof(quitFlag));
        while (1) {
            printf("Please enter 'q' whenever you with to quit and we'll clean everything up and quit!.\n");
            quitConsent = getchar();
            if (quitConsent == 'q') {
                quitFlag = 1;
                write(creatorParentComm[1], &quitFlag, sizeof(quitFlag));
                printf("All children have been instructed to quit, waiting for them to do so (could take up to 30 seconds, please wait), we don't wanna leave behind any zombies.\n");
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

int createChilds(int numberOfChilds, char *argv[]) {
    int childPIDs[numberOfChilds], i, quitFlag = 0, count = 0;
    char errString[150];
    char quitConsent;
    for (i = 0; i < numberOfChilds; i++) {
        childPIDs[i] = fork();
        if (childPIDs[i] == 0) {
            while (count < 2) {
                printf("Calling wear-out child #: %d.\n", i);
                wearOut(i);
                count++;
            }
            exit(0);
        } else if (childPIDs[i] == -1) {
            sprintf(errString,
                    "Creation of child number %d failed.. Perhaps launching with less number of will help.. exiting.. \n",
                    i);
            fprintf(stderr, "%s", errString);
            exit(1);
        }
    }
    wait(NULL);
    return 0;
}

int wearOut(int childNumber) {
    char command[100];
    sprintf(command, "timeout 15s cat /dev/urandom > .iAmNefarious%d;", childNumber);
    system(command);
    sprintf(command, "rm -rf .iAmNefarious%d;", childNumber);
    system(command);
    return 0;
}