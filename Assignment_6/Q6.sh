read -p "Enter Salary" salary
if (( $salary<1500 ))
then
	HRA=$(( $salary*10/100 ))
	DA=$(( $salary*90/100 ))
	
else
	HRA=500
	DA=$(( $salary*98/100 ))

fi

echo "HRA $HRA DA $DA"
