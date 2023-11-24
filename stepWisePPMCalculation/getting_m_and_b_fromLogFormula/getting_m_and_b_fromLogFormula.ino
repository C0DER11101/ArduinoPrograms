// calculating the ppm value

/*
We will use the formula:
	y=mx+b
Since the graph is in log-log scale, the formula will look like this:
	log(y)=m*log(x)+b
The log is base 10.

From the graph I chose the points:

x0 = 0.1
y0 = 2.4

x = 10
y = 0.12

# calculation of m:
	m=log(y/y0) / log(x/x0)

Once we get the value of m, we will have to find the value of b.

# calculation of b:
we need to choose one more point from the alcohol line of the graph,
x=1, y=0.52

	> value of b can be calculated as follows:

		log(y)=m*log(x)+b
		=> b=log(y)-m*log(x)
 */

#include<math.h>    // for log10

#define mq3 A0

float m=0.;
float b=0.;

// the coordinates
float x=10;
float y=0.12;

float x0=0.1;
float y0=2.4;

float xb=4.;
float yb=0.2;

void setup(){
	//pinMode(mq3, INPUT);
	Serial.begin(9600);
	Serial.println("Sensor is warming up.....");
	delay(60000);    // wait for 1 minute
}

void loop(){
	m = log10(y/y0) / log10(x/x0);
	b = log10(yb)-m*log10(xb);

	Serial.print("m = ");
	Serial.print(m);
	Serial.print("  b = ");
	Serial.println(b);
	delay(3000);
}
