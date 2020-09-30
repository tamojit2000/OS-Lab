x=$1
if [ "$x" -ge 90 ] && [ "$x" -le 100 ]
then
	echo "A"
elif [ "$x" -ge 70 ] && [ $x -le 89 ]
then
	echo "B"
elif [ "$x" -ge 40 ] && [ "$x" -le 69 ]
then
	echo "C"
else
	echo "F"
fi
