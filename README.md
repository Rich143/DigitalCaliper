# DigitalCaliper

Digital Caliper made using a rotating optical encoder from photo-interrupters.
Written for Arduino

<br><br> The mechanical design works as follows.The caliper uses a rack and pinion gear to turn an encoder ring. The encoder ring consists of a circle of with radial slots to alternatively let light through and block it. The rack moves back and forth and acts as the measuring stick. Two photointerupters are inserted over the encoder ring, so the phototransistors inside are alternatively open and closed as the slots in the ring pass by. All the mechanical components were first modelled in solidworks.

<br><br> The software for the arduino uses pin change interrupts for the pins connected to the photointerrupters. The photointerrupters send a falling edge as the encoder ring blocks the light from the phototransistor, which the arduino detects. The pulses are then converted into encoder ring rotations, then distance measurements.

![Digital-Caliper-Picture](https://github.com/Rich143/DigitalCaliper/blob/master/12837483_10153423779155814_1408371865_o-2.jpg)
