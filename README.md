# Arduino Christmas Light Sequence Controller

Built on an Arduino Uno and SainSmart Relay Board. Triggered by a Particle Photon, Tasker (Android), IFTTT, and Pushbullet.

IFTT turns the lights on at sunset by sending a POST request to the Particle Photon. The lights can be triggered manually from Pushbullet or Amazon Echo. After sunset, the sequence plays automatically every 10 minutes via a simple Tasker profile.

The mp3 is stored on and played from the Android phone (Note 3) and the audio is split into two. One line goes into the speaker and the other into an analog input on the Arduino. The Arduino only listens for the start of the song only.

I've also set up a phone number (Twilio) that allows anyone to text the word "Start" to start the lights/music. That API is a simple node.js app accepting the GET requests from Twilio then POSTing to the PushBullet API which starts the song on the Android phone. :-)

This is version 1. The code is definitely not optomized yet.

