# LED-MATRIX-32X32-CLOCK-THERMOMETER
Pin definitions in code are different from fritzing layout,please change accorind to your connections.
-----------------------SHORT DESCRIPTION OF THE IDEA-------------------------------------------------------

Three arduinos are used for this project.The Master,the "tunnel" and the slave.
The arduino mega  drives the led matrix and reads the current temp from a LM35 and it's also connected to the arduino "tunnel",simply is an arduino nano connected to the mega using serial communication.Another arduino reads the values from a DHT22 sensor and sends the data using a simple 433mhz rf module the arduino nano or "tunnel" receives that data and sends them through serial to the mega.Finally the mega update every N times the led matrix and shos the current values and time.
