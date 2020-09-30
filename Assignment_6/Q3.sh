Prime() {
	l=$(( $1-1 ))
	for i in ` seq 2 $l `
	do
		if (( $1%i==0 ))
		then
			echo "$1 Not Prime"
			return
		fi
	done
	echo "$1 Prime"
}

x=2

while [ $x -le 100 ]
do
	Prime $x
	x=$(( $x+1 ))
done

