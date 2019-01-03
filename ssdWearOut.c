//
// Created by sids on 1/3/19.
//
#include <stdio.h>
#include <stdlib.h>

int wearOut();

int main() {
    char consent;
    printf("\nDo you want to wear out your SSD before the warranty expires?\n\nDon't worry, we've all been there, this script uses state-of-the-art* SSD wearing technology using AI* and ML* to wear out your SSD.\n\n*These are utterly false and no test of ANY sort were conducted.\n\nPlease note that I am NOT responsibe for anything that may happen, use this script at your OWN risk and don't run it unless you understand what you are doing.\n\n");
    printf("Do you want to continue?(y/n): ");
    consent = getchar();
    if (consent == 'y') {
        printf("Press the interrupt hot keys to stop the script, it won't, otherwise; stop.");
        printf("\n");
        system("rm -rf .iAmNefarious;"); //Remove the file if it already exists.
        wearOut();
    }
    return 0;
}

int wearOut() {
    system("timeout 30s cat /dev/urandom > .iAmNefarious;");
    system("rm -rf .iAmNefarious;");
    wearOut();
    return 0;
}