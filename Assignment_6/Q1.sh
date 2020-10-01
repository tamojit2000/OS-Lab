read -p"Enter a number: " a 
i=1
fac=1
while [ $i -le $a ]
do
	fac=$((fac * i))
	i=$((i + 1))	
done
echo "$fac"