var canvas = document.getElementById("c1");
if (canvas.getContext) 
{
  var ctx = canvas.getContext('2d');
  ctx.fillStyle="red";
  ctx.fillRect(10, 40, 140, 160); 
}
var canvas1 = document.getElementById("c2");
 if (canvas1.getContext)
{
  var ctx = canvas1.getContext('2d');
  ctx.fillStyle="blue";

  var deg = Math.PI/180;

ctx.save();
    ctx.translate(100, 10);
    ctx.rotate(40 * deg);
    ctx.fillRect(10, 40, 140, 160);
ctx.restore();

}