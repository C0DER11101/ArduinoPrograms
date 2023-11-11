# Arduino programming

* This is preparation for mini-project of $7^{th}$ semester.

**Problems I am facing:**
* I have to calculate the ppm value from analog value returned by `analogRead()` method.

## Important: <ins>Calculating the ppm value from analog readings of MQ3 sensor</ins>
* Source: [https://ai.thestempedia.com/docs/evive-iot-kit/interfacing-mq-3-gas-sensor-with-evive/](https://ai.thestempedia.com/docs/evive-iot-kit/interfacing-mq-3-gas-sensor-with-evive/).

* Some terms:
	* `Vin` $\rightarrow$ The input voltage for the sensor which is $5V$.
	* `Vout` $\rightarrow$ The analog reading from the sensor when converted to volts.
	* `Rs` $\rightarrow$ resistance of the sensor that changes depending on the concentration of the gas.
	* `R0` $\rightarrow$ resistance of the sensor at a known concentration without presence of other gases, or in the fresh air.
* For fresh air: `Rs/R0 = 60`.

* <ins>Step-1</ins>
	* Calculate the `R0` value.
	* Note that for this step, you have to take the analog readings for certain times and then calculate the average of those obtained analog readings.
	* Convert the average into volts using this formula: `5/1013 * analogReadings`.
	* Then calculate `Rs` using this formula: `(5-Vout)/Vout`.
* <ins>Step-2</ins>
	* Use the value of `R0` (obtained in the previous step) to find out the concentration of the gas in ppm.
	* For this step, you only need one analog reading.
	* Convert the obtained analog reading into volts using the formula given in step-1.
	* Now, calculate `Rs`.

* <ins>Step-3</ins>
	* Use this linear equation: `y=mx+b`, but since the graph from [this](https://www.sparkfun.com/datasheets/Sensors/MQ-3.pdf) is a log-log graph, the formula will become: `log(y)=m*log(x)+b`.
	* Now choose $(x,y)$, $(x0,y0)$ from the graph corresponding to the gas of your choice(mine is alcohol).
	* For me, $x0=0.1$, $y0=2.4$, $x=10$ and $y=0.12$.
	* From here, I get `m` to be $-0.65$.
	* For calculating `b`, we need to choose one more point from the alcohol line of the graph. I chose $(6,0.16)$. We will use the formula: `b=log(y)-m*log(x)`.

<p align="center">
&#9678; &#9678; &#9678;
</p>
