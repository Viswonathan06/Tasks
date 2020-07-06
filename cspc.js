var head=document.getElementById('heading');
var list=document.getElementById('list');
var result=document.getElementById('result')
var sA=0;
var cur;
var n;
var flag=0;
var i;
var j;
var vis=new Array(100);
for(var i=0;i<100;i++){
  vis[i]=0;
}
var ans=new Array(100);
for(var i=0;i<100;i++){
  ans[i]=-1;
}
var A = new Array(2);
A[0]=new Array(100);
for (var i = 0; i < A[0].length; i++) {
  A[0][i] = new Array(100);
  for(var j = 0; j <A[0].length;j++){
    A[0][i][j]=0;
  }
}

A[1]=new Array(100);
for (var i = 0; i < A[1].length; i++) {
  A[1][i] = new Array(100);
  for(var j = 0; j <A[1].length;j++){
    A[1][i][j]=0;
  }
}


function copy(){
  for (var i = 0; i < n; i++) {
    for(var j = 0; j <n;j++){
      A[1][i][j]=A[0][i][j];
    }
  }
}

function remove(x){
  for(var i=0;i<n;i++){
    A[1][i][x]=0;
    A[1][x][i]=0;
  }
}

class stack {
  constructor(){
  this.s= new Array(100);
  this.ptr = -1;
  }
  push(i){
        this.ptr++;
    s[this.ptr]=i;

  }
  pop(){
    this.ptr--;
    return s[this.ptr+1];
  }
  show(){
    return s[this.ptr];
  }
}

var s=new stack;

function numnodes(){
  console.log("entered numnodes");
  var ret=0;
  var hel=0;
  var temp1=0;
  var temp2=0;
  //console.log(temp1,temp2);
    for(temp1=0;temp1<n;temp1++){
      for(temp2=0;temp2<n;temp2++){
        if(A[1][temp1][temp2]==1){
          hel=1;
          break;
        }

      }
      if(hel==1)
      break;
    }
    if(hel==0)
      return n-1;
    s.push(temp1);
    vis[temp1]=1;
    ret++;
    while(s.ptr!=-1){
      if(hasunvisited()){
        visit();
        ret++;
      }
      else{
        s.pop();
      }
    }
    resetvis();
    return ret;
}

function hasunvisited(){
  console.log("enteredhas unvisited");
  var curnode=s.show();
  for(var i=0;i<n;i++){
    if(A[1][curnode][i]==1){
      if(vis[i]==0){
        return 1;
      }
    }
  }
  return 0;
}

function visit(){
    console.log("entered visit");
  var curnode=s.show();
  for(var i=0;i<n;i++){
    if(A[1][curnode][i]==1){
      if(vis[i]!=1){
        s.push(i);
        vis[i]=1;
        break;
      }
    }
  }
}
var solptr=0;

function resetvis(){
  for(var i=0;i<n;i++){
    vis[i]=0;
  }
}

function addsol(i){
  ans[solptr]=i;
  solptr++;
}

function check(){
  for(var i=0;i<n;i++)
    A[0][i][i]=1;
  for(var i=0;i<n;i++){
    copy();
    remove(i);
    if(numnodes()!=(n-1))
    {
      addsol(i);
    }
  }

  var res = document.createElement('p');
  if(ans[0]==-1){
    res.textContent = "There are no cut vertices.";
    result.appendChild(res);
    flag=0;
  }
  else{
    var t= "The Cut Vertices are:\n"
    var i=0;
    while(ans[i]!=-1){
      t=t+ "Node "+ (ans[i]+1) +"\n";
      i++;
    }
    res.textContent =t;
    result.appendChild(res);
    flag=0;
  }
}

function update(){
 n = document.getElementById('n').value;
 var btn= document.getElementById('btn1');
 btn.style.visibility="hidden";
 var sum = document.getElementById('btn2');
 sum.style.visibility="visible";
 var ser = document.getElementById('instruct');
 ser.style.visibility="visible";
 while(result.firstChild){
   result.removeChild(result.lastChild);
 }
 display();
}

function display(){
      while(heading.firstChild){
        heading.removeChild(heading.lastChild);
      }

  for(i=0;i<n;i++){
    var btn = document.createElement('button');
    btn.setAttribute('type','button');
    var t = 'lis('+ i +')';
    btn.setAttribute('onclick',t);
    btn.textContent="Node" + (i+1);
    if(i==0){
      btn.style.backgroundColor="#77D6F0";
    }
    heading.appendChild(btn);
  }

  while(list.firstChild){
    list.removeChild(list.lastChild);
  }

  for(i=0;i<n;i++){
    var btn = document.createElement('button');
    btn.id=i*100;
    btn.setAttribute('type','button');
    var t = 'makematrix('+i+')';
    btn.setAttribute('onclick',t);
    btn.textContent=" ";
    list.appendChild(btn);
  }
  lis(0);
}

function makematrix(j){

  var btn = document.getElementById(j*100);
  if(btn.textContent=="0")
  {A[sA][cur][j]=1;A[sA][j][cur]=1;btn.textContent=1;btn.style.backgroundColor="#CEF598";}
  else {
    A[sA][cur][j]=0;A[sA][j][cur]=0; btn.textContent=0;btn.style.backgroundColor="#DBDBDB";
  }
}

function lis(j){
  cur=j;
  var arr = heading.childNodes;
  for(var i=0;i<arr.length;i++){
    if(i==j){
      arr[i].style.backgroundColor="#77D6F0";
    }
    else {
      arr[i].style.backgroundColor="#DBDBDB";
    }
  }
  for(var i=0;i<n;i++){
    var btn = document.getElementById(i*100);
    btn.textContent=A[sA][j][i];
    if(A[sA][j][i])
      btn.style.backgroundColor="#CEF598";
    else {
      btn.style.backgroundColor="#DBDBDB";
    }
  }

}
