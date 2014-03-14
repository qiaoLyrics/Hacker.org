
ans=0
for((i=3; i<11; i++)) ; do
	tmp=`echo "$i ^ 4 - $i ^ 2" | bc `
	((ans=$ans+$tmp))
echo $ans
done

echo $ans
