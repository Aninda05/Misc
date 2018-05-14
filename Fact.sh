read a
f=1
i=1
for(( i=1; i<=a; i++ ))
do
	f=`expr $i \* $f`
done
echo $f

