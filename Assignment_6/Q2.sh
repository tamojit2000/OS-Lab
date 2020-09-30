Menu() {
	echo "1. Current working directory"
	echo "2. Odd or Even"
	echo "3. File Count"
	echo "4. Long list of all files"
	echo "5. Exit"
}

while [ true ]
do
	Menu
	read -p "Choose Option: " opt
	case $opt in
		1)
			pwd
		;;
		2)
			read -p "Enter Number: " num
			if (( num%2==0 ))
			then
				echo "Even"
			else
				echo "Odd"
			fi
		;;
		3)
			ls -l | grep -cv ^d
		;;
		4)
			ls -l
		;;
		5)
			break
		;;
		*)
			echo "Wrong option"
		;;
		esac
done
