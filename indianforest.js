//document objects
var something = document.getElementById('canvas');
var canvas = something.getContext('2d');
var wildc = document.getElementById('switch');

//variables
var manx;
var many;
var size=100;
var nsize;
var wildc;
var xcords = new Array(100);
var ycords = new Array(100);
var wild = new Array(100);
var type = new Array(100);
var animalkeyvalue = ["peacock","elephant","deer","horse","monkey","cheetah","lion","tiger","gorilla","wolf"];
var animalcolor = ["#FC04F2","#5E04FC","#047CFC","#04D9FC","#04FC6E","#FCED04","#FC9004","#FC3704","#7B7B7A","#000000"];
//function definitions



function manpos(evt){
  var rect = something.getBoundingClientRect();
  var xcoord =  evt.clientX - rect.left;
  var ycoord =  evt.clientY - rect.top;
   //var size = document.getElementById('').value;
   //var ycoord = document.getElementById('ycord').value;
   if(xcoord>600 || xcoord<0 || ycoord>600|| ycoord<0){
     //alert("input exceeds limit, please enter values from 0-600 only");
     return;
   }
  //console.log(xcoord+" "+ycoord);
  manx=xcoord;
  many=ycoord;
  drawman();
  drawanimals();
}

function update(){
 nsize = document.getElementById('size').value;
  if(nsize>300)
    nsize=300;
  if(nsize<0)
    nsize=0;
  size=nsize;
}

function initarray(){

  for(var i =0;i<100;i++){
    xcords[i] = Math.random()*600;
    ycords[i] = Math.random()*600;
    wild[i] = Math.round(Math.random());
    type[i] = wild[i]*4 + Math.round(Math.random()*4)+1;
    console.log(type[i]+" , "+ wild[i]);
  }
}

function drawanimals(){
  for(var i = 0;i<100;i++){
    if(dist(i)<size && (wildc.checked==0 || wild[i]==1)){
      canvas.beginPath();
      canvas.arc(xcords[i],ycords[i],3,0,Math.PI*2,0);
      canvas.fillStyle = animalcolor[type[i]];
      canvas.fill();
    }
  }
}

function dist(i){
  var dist = Math.sqrt((xcords[i]-manx)*(xcords[i]-manx)+ (ycords[i]-many)*(ycords[i]-many));
  return dist;
}

function drawman(){
  //draws circle at man's coordinates
  canvas.clearRect(0, 0, 600, 600);
  canvas.beginPath();
  canvas.arc(manx,many,5,0,Math.PI*2,0);
  canvas.fillStyle = "#B03A2E";
  canvas.fill();
  canvas.beginPath();
  canvas.arc(manx,many,size,0,Math.PI*2,0);
  canvas.strokeStyle = "#B03A2E";
  canvas.stroke();
}

//call functions
initarray();
