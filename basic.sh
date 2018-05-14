echo 'Enter two numbers'
read a
read b
while [ 1 ] 
do
echo "1.Addition"
echo "2.Subtraction"
echo "3.Multiplication"
echo "4.Division"
echo "Enter choice"
read ch
case $ch in
		1)s=`expr $a + $b`
		echo "Result is $s"
		;;
		2)m=`expr $a - $b`
		echo "Result is $m"
		;;
		3)p=`expr $a \* $b`
		echo "Result is $p"
		;;
		4)d=`expr $a / $b`
		echo "Result is $d"
		;;
		*)echo "Invalid choice"
		break
esac
done
if [ $a -gt $b ]
then
	echo "$a is bigger"
else
	echo "$b is bigger"
fi

echo $s
echo $m
echo $p
echo $d

if [ `expr $a % 2` -eq 0 ]
then
	echo "Even"
else
	echo "Odd"
fi


i=1
s=0
while [ $i -le 10 ]
do
	s=`expr $s + $i`
	i=`expr $i + 1`
done
echo "Sum is $s"

s=1
i=1
for (( i=1; i<=b; i++ ))
do
	s=`expr $i \* $i`;
	echo $s
done

echo "Enter another number"
read c
z=$c
s=0
while [ $c -gt 0 ]
do
	p=`expr $c % 10`
	s=`expr $p + $s \* 10`
	c=`expr $c / 10`
done
if [ $s -eq $z ]
then
	echo "Palindrome"
else
	echo "Non Palindrome"
fi 
i=1
echo "Enter range"
read n
echo "Enter number"
for (( i=0; i<n; i++ ))
do
	read a[i]
done
max=0
min=${a[0]}
j=1
for (( i=0; i<n; i++ ))
do
	if [ ${a[i]} -gt $max ]
	then
		max=${a[i]}
	fi
	if [ ${a[i]} -lt $min ]
	then
		min=${a[i]}
	fi
	for (( j=i+1; j<n; j++ ))
	do
		if [ ${a[i]} -gt ${a[j]} ]
		then
			t=${a[i]}
			a[i]=${a[j]}
			a[j]=$t
		fi
	done
done	
echo "Maximum number is $max"
echo "Minimum number is $min"
echo "Sorted array is ${a[*]}"
