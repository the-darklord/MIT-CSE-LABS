echo "enter a number"
read num
val=`expr $num \* 2`
for i in $(seq 1 $val)
do
x=`expr $i \% 2`
if [ $x -eq 1 ]
then
echo $i
fi
done


