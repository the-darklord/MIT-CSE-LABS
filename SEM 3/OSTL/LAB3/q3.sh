echo "enter coefficients of quadratic equation"
read a
read b
read c
d=$((b*b - 4*a*c))
if [ $d -gt 0 ]
then
	d1=$(echo "sqrt($d)" | bc)
	flag=1
	root1=$(((-b+d1)/(2*a)))
	root2=$(((-b-d1)/(2*a)))
elif [ $d -eq 0 ]
then
	flag=2
	r=$((-b/(2*a)))
elif [ $d -lt 0 ]
then
	flag=3
	d3=$((-1*d))
	d2=$(echo "sqrt($d3)" | bc)
	re=$((-b/(2*a)))
	im=$((d2/(2*a))) 
fi
echo 
case $flag in
	"1")
		echo "roots are $root1 , $root2"
		;;
	"2")
		echo "roots are $r , $r"
		;;
	"3")
		echo "roots are $re + i $im , $re - i $im"
		;;
	*)
		echo "invalid"
		;;
esac
