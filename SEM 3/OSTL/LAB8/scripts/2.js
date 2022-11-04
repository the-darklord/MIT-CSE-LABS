var size=prompt("Enter Array Size : ")
var arr=[]
for(let i=0;i<size;i++)
{
	arr[i]=prompt("Enter Element : "+(i+1))
}
var p=1
var s=0
for(let i=0;i<size;i++)
{
s+=arr[i]
p*=arr[i]
}
alert("Sum : "+s+"\nProduct : "+p) 