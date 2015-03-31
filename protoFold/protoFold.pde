// for rapid prototyping fold functions
float step;
float pos;
int b = 30; // border

void setup()
{
  step = 6.0 / (0.5*width);
  pos = -PI;
  
  background(255); size(600,600);
  stroke(50,50,50); noFill();
}

void draw()
{
  beginShape();
  for(float i=-PI; i<PI ; i+=step) {
    setFold(i,pos);
  }
  pos += step;
  endShape();
  if (pos > PI) stop();
}

void setFold(float x, float y)
{
  PVector v = new PVector(x,y);
  v = protoFold(v);
  vertex(map(v.x,-PI,PI,b,width-b),map(v.y,-PI,PI,b,height-b));
  //ellipse(map(v.x,-PI,PI,b,width-b),map(v.y,-PI,PI,b,height-b),5,5);
}

PVector protoFold(PVector v)
{ 
  v.y -= round(v.x*2);
  v.y /= 4.0;
  float nx = v.y;
  v.y = v.x;
  v.x = nx;
  return v;
}

/* ideas :
hourglass(v): v.x = v.x*sin(v.y*0.7);
jupiterMission(v): v.y = v.x*cos(v.y);
perspective(v): v.y -= v.x*tan(v.y*0.16)-0.8;
                v.y /= 1.7;
gravity(v): v.y -= v.x*tan(v.x*0.18)-1;
            v.y /= 1.3;
creaseL(v): v.y -= v.x*floor(v.x*0.18)-1;
            v.y /= 1.7;
creaseR(v): v.y -= v.x*ceil(v.x*0.18)-1;
            v.y /= 1.7;
staircase(v): v.y -= round(v.x*2);
              v.y /= 4.0;
              float nx = v.y;
              v.y = v.x;
              v.x = nx;
              
           

*/




