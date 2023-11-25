# Arduino programming

* This is preparation for mini-project of $7^{th}$ semester.

## Important: <ins>Calculating the ppm value from analog readings of MQ3 sensor</ins>
* Source-1: [https://ai.thestempedia.com/docs/evive-iot-kit/interfacing-mq-3-gas-sensor-with-evive/](https://ai.thestempedia.com/docs/evive-iot-kit/interfacing-mq-3-gas-sensor-with-evive/).
* Source-2: [https://www.youtube.com/watch?v=I7X39y8dqGE&t=433s](https://www.youtube.com/watch?v=I7X39y8dqGE&t=433s).

**Some more resources:**

* [http://www.mecinca.net/ALCOHOLIMETROS_Alcosim/BAC%20BrAC%20conversion%20table%5b1%5d.pdf](http://www.mecinca.net/ALCOHOLIMETROS_Alcosim/BAC%20BrAC%20conversion%20table%5b1%5d.pdf).
* [https://acoptex.com/wp/arduino-guide-for-mq3-alcohol-sensor/#:~:text=Now%20to%20calibrate%20the%20sensor%2C%20blow%20your%20alcohol,back%20counterclockwise%20just%20until%20the%20LED%20goes%20OFF.](https://acoptex.com/wp/arduino-guide-for-mq3-alcohol-sensor/#:~:text=Now%20to%20calibrate%20the%20sensor%2C%20blow%20your%20alcohol,back%20counterclockwise%20just%20until%20the%20LED%20goes%20OFF.).

* Some terms:
	* $V_{in}$ $\rightarrow$ The input voltage for the sensor which is $5V$.
	* $V_{out}$ $\rightarrow$ The analog reading from the sensor when converted to volts.
	* $R_s$ $\rightarrow$ resistance of the sensor that changes depending on the concentration of the gas.
	* $R_0$ $\rightarrow$ resistance of the sensor at a known concentration without presence of other gases, or in the fresh air.
* For fresh air: $R_s/R_0 = 60$.

---


* <ins>Step-1</ins>
	* Calculate the $R_0$ value. For that you need to find out $R_s$.
	* Note that for this step, you have to take the analog readings for certain times and then calculate the average of those obtained analog readings.
	* Convert the average into volts using this formula: $(5/1023) \times analogReadings$.
	* Then calculate $R_s$ using this formula: $(V_{in}-V_{out})/V_{out}$.

* <ins>Step-2</ins>
	* Calculate the value of $R_0$ using this formula: $R_s/R_0=60$.

* <ins>Step-3</ins>
	* Use the value of $R_0$ (obtained in the previous step) to find out the concentration of the gas in ppm.
	* For this step, you only need one analog reading(you might go for more than one analog reading).
	* Convert the obtained analog reading into volts using the formula given in step-1.
	* Now, calculate $R_s$.
	* Use this linear equation: $y=mx+b$, but since the graph from this [datasheet](https://www.sparkfun.com/datasheets/Sensors/MQ-3.pdf) is a log-log graph, the formula will become: $\log_{10}(y)=m\times\log_{10}(x)+b$.
	* Now choose $(x,y)$, $(x_0,y_0)$ from the graph corresponding to the gas of your choice(mine is alcohol).
	* Calculate the value of $m$ as: $m=(\log_{10}(y) - \log_{10}(y_0)) / (\log_{10}(x) - \log_{10}(x_0))$. If we apply the rules of logarithmic subtraction then the equation becomes: $m=\log_{10}(y/y_0) / \log_{10}(x/x_0)$.
	* For calculating $b$, we need to choose one more point from the alcohol line of the graph. We will use the formula: $b=\log_{10}(y)-m\times\log_{10}(x)$ to calculate the value of $b$.
 	* Now, we will use $m$, $b$ and $R_0$ to calculate the ppm value.
    	* Find the ratio: $R_s/R_0$ and find the formula: $ppm=10^{(\log_{10}(R_s/R_0)-b)/m}$.

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
