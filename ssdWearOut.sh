#Created by Sid Sun on 3 January 2019
#Totally NOT based on a meme from, /r/ProgrammerHumor
welcome() {
	clear;echo "";echo "Do you want to wear out your SSD before the warranty expires?";echo "";echo "Don't worry, we've all been there, this script uses state-of-the-art* SSD wearing technology using AI* and ML* to wear out your SSD.";echo "";echo "*These are utterly false and no test of ANY sort were conducted.";echo "";echo "Please note that I am NOT responsibe for anything that may happen, use this script at your OWN risk and don't run it unless you understand what you are doing.";echo "";
	read -n 1 -s -r -p "Press any key to continue.";
	echo "";echo "Press the interrupt hot keys to stop the script, it won't, otherwise; stop.";
	echo ""; #IT doesn't look good otherwise. UX is the top priority.
	rm -rf .iAmNefarious; #Remove the file if it already exists.
	wearOut;
}
wearOut() {
	timeout 30s cat /dev/urandom > .iAmNefarious; #We use hidden file because why not.
	rm -rf .iAmNefarious;
	wearOut; #Call the function recursively until user interferes or process if killed by the system or system dies
}
welcome;