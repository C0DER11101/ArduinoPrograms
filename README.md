# Arduino programming

* This is preparation for mini-project of $7^{th}$ semester.

**Problems I am facing:**
* I have to calculate the ppm value from analog value returned by `analogRead()` method.

## Important: <ins>Calculating the ppm value from analog readings of MQ3 sensor</ins>
* Source-1: [https://ai.thestempedia.com/docs/evive-iot-kit/interfacing-mq-3-gas-sensor-with-evive/](https://ai.thestempedia.com/docs/evive-iot-kit/interfacing-mq-3-gas-sensor-with-evive/).
* Source-2: [https://www.youtube.com/watch?v=I7X39y8dqGE&t=433s](https://www.youtube.com/watch?v=I7X39y8dqGE&t=433s).

**Some more resources:**

* [http://www.mecinca.net/ALCOHOLIMETROS_Alcosim/BAC%20BrAC%20conversion%20table%5b1%5d.pdf](http://www.mecinca.net/ALCOHOLIMETROS_Alcosim/BAC%20BrAC%20conversion%20table%5b1%5d.pdf).
* [https://acoptex.com/wp/arduino-guide-for-mq3-alcohol-sensor/#:~:text=Now%20to%20calibrate%20the%20sensor%2C%20blow%20your%20alcohol,back%20counterclockwise%20just%20until%20the%20LED%20goes%20OFF.](https://acoptex.com/wp/arduino-guide-for-mq3-alcohol-sensor/#:~:text=Now%20to%20calibrate%20the%20sensor%2C%20blow%20your%20alcohol,back%20counterclockwise%20just%20until%20the%20LED%20goes%20OFF.).

* Some terms:
	* `Vin` $\rightarrow$ The input voltage for the sensor which is $5V$.
	* `Vout` $\rightarrow$ The analog reading from the sensor when converted to volts.
	* `Rs` $\rightarrow$ resistance of the sensor that changes depending on the concentration of the gas.
	* `R0` $\rightarrow$ resistance of the sensor at a known concentration without presence of other gases, or in the fresh air.
* For fresh air: `Rs/R0 = 60`.

---


* <ins>Step-1</ins>
	* Calculate the `R0` value. For that you need to find out `Rs`.
	* Note that for this step, you have to take the analog readings for certain times and then calculate the average of those obtained analog readings.
	* Convert the average into volts using this formula: `(5/1023) * analogReadings`.
	* Then calculate `Rs` using this formula: `(5-Vout)/Vout`.

* <ins>Step-2</ins>
	* Calculate the value of `R0` using this formula: `Rs/R0=60`.

* <ins>Step-3</ins>
	* Use the value of `R0` (obtained in the previous step) to find out the concentration of the gas in ppm. I got the value of `R0` to be $0.22$
	* For this step, you only need one analog reading.
	* Convert the obtained analog reading into volts using the formula given in step-1.
	* Now, calculate `Rs`.
	* Use this linear equation: `y=mx+b`, but since the graph from this [datasheet](https://www.sparkfun.com/datasheets/Sensors/MQ-3.pdf) is a log-log graph, the formula will become: `log(y)=m*log(x)+b`.
	* Now choose $(x,y)$, $(x0,y0)$ from the graph corresponding to the gas of your choice(mine is alcohol).
	* For me, I chose $x0=0.1$, $y0=2.4$, $x=10$ and $y=0.12$.
	* From here, I get `m` to be $-0.65$.
	* For calculating `b`, we need to choose one more point from the alcohol line of the graph. I chose $(4,0.2)$. We will use the formula: `b=log(y)-m*log(x)` to calculate the value of `b`. The value of `b` which I got is: $-0.31$.

# Collecting sensor data from arduino using Java.

* For this, `gnu.io` package is required.
* Here is the [download link](http://www.java2s.com/Code/Jar/r/Downloadrxtx217jar.htm).
* Download the zip file to a location of your choice and extract it to any location of your choice.
* Now, if you are on Linux, go to your `.bashrc` file and write this command:
	* `export PATH_TO_JAR=<path to your the unzipped jar file>`
	* After that, save and quit from your ide/editor and use the command: `source ~/.bashrc`.
* Now, to compile your java program, you will use the command as provided in [here](https://stackoverflow.com/questions/6066257/how-to-compile-java-program-with-jar-library):
	* `javac -cp $PATH_TO_JAR <yourJavaProgram.java>`. `cp` stands for _classpath_.
	* Running the program is simple: `java <yourJavaProgram>`

<p align="center">
&#9678; &#9678; &#9678;
</p>
