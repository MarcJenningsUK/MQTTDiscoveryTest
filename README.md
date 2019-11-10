# MQTTDiscoveryTest

A follow-up on last weekend.  I put together a very simnple ESP32 sketch to create a new Home Assitant, discoerable MQTT sensor device.

Set your wifi and mqtt details in the sketch
Upload to an ESP32
Run the sketch.

In HA, go to developer tools > states and search for testsensor.  You should find it and bve able to see the incoming state messages.

There's more to it than this for more comples scenarios, but I'll document that when I have more time
