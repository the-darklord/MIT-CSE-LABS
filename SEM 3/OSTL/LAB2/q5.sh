sort $1 |cat > sort.txt
sort $2 |cat >> sort.txt
sort -n -u sort.txt > merge.txt
rm sort.txt
cat merge.txt

