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
  ellipse(map(v.x,-PI,PI,b,width-b),map(v.y,-PI,PI,b,height-b),5,5);
}

PVector protoFold(PVector v)
{ 
  return v;
}
