Menu() {
	echo "1. Enter letter: "
	echo "2. Exit"
}

CheckVowel() {
	Vowels="A E I O U a e i o u"
	for i in $Vowels
	do
		if [ $i == $1 ]
		then
			echo "Vowel"
			return
		fi
	done
	echo "Consonent"
}

while [ true ]
do
	Menu
	read -p "Choose option: " opt
	if (( opt==2 ))
	then
		break
	elif (( opt==1 ))
	then
		read -p "- Enter Character: " chr
		CheckVowel $chr
	else
		echo "Wrong Option"
	fi
done
