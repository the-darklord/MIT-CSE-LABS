echo "enter a number"
read num
fact=1
for i in $(seq 1 $num)
do
fact=`expr $fact \* $i`
done
echo factorial is $fact
