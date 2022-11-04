echo "enter a number"
read num
x=`expr $num \% 2`
if [ $x -eq 0 ]
then
echo "even number"
else
echo "odd number"
fi
