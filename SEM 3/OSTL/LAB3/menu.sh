# menu program
echo "menu program"
stop=0
while test $stop -eq 0
do
cat << ENDMENU
1: print date
2: print working directory
3: create new directory of name menu in this directory
4: exit
ENDMENU
echo
echo "enter your choice"
read reply 
echo
case $reply in

"1")
date
echo
;;
"2")
pwd
echo 
;;
"3")
mkdir menu
echo
;;
"4")
stop=1
echo
;;
*)
echo "invalid choice"
echo
;;
esac
done
