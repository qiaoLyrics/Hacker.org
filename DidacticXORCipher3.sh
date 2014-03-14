# 枚举种子 x, b  因为shell太慢了，就叫neko给我种子，不用遍历太多了。。。
# 然后再grep -E "[a-zA-Z]{8,10}" 正则匹配一下
#!/bin/sh

for x in {1..256} ; do 
	for b in {1..256} ; do
		i=$b
		while read -n 2 var ; do 
			var=$(echo "ibase=16; $var" | bc)
			((var=var^$i))
			((i=(i+x)%256))
			echo "$var" | awk ' { printf("%c", $var); }'
		done < $1
		echo " ="
	done
done 
