chmod u+x Q4.sh

x=$1
y=$2
z=$3

if [ "$x" -gt "$y" ]
then
	if [ "$x" -gt "$z" ]
	then
		echo "$x" 
	else
		echo "$z"
	fi
else
	if [ "$y" -gt "$z" ]
	then
		echo "$y"
	else
		echo "$z"
	fi
fi
