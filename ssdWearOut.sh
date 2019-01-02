#Created by Sid Sun on 3 January 2019
#Totally NOT based on a meme from, /r/ProgrammerHumor
welcome() {
	echo "Do you want to wear out your SSD before the warranty expires?"
	echo "Don't worry, we've all been there, this script uses state-of-the-art* SSD wearing technology using AI* and ML* to wear out your SSD." #I've never been there, but; hey. whatever.
	echo "*These are utterly false and no test of ANY sort were conducted."
	echo "Please note that I am NOT responsibe for anything that may happen, use this script at your OWN risk and don't run it unless you understand waht you are doing."
	echo "Press the interrupt hotkeys to stop the script, it won't, otherwist; stop."
	read -n 1 -s -r -p "Press any key to continue."
	wearOut;
}
wearOut() {
	timeout 30s cat /dev/urandom > .iAmNefarious; #We use hidden file because why not.
	rm -rf .iAmNefarious;
	wearOut; #Call the function endlessly until the user interfers.
}
welcome;