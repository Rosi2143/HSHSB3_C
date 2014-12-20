#include <Max7312.h>
#include "Arduino.h"
#include <Wire.h>

// Comments
//
//...

Max7312::Max7312(){
	_chipAddress=MAX7312_ADDRESS;
	init(0x00, 0x00);
}
Max7312::Max7312(unsigned char chipAddress){
	_chipAddress=chipAddress;
	init(0x00, 0x00);
}
Max7312::Max7312(unsigned char chipAddress, unsigned char portDirection1, unsigned char portDirection2)
{
	_chipAddress=chipAddress;
	init(portDirection1, portDirection2);
}
Max7312::Max7312(unsigned char chipAddress, unsigned char portDirection1, unsigned char portDirection2, unsigned char timeoutFlag)
{
	_chipAddress=chipAddress;
	init(portDirection1, portDirection2, timeoutFlag);
}

void Max7312::init(unsigned char portDirection1, unsigned char portDirection2)
{
	init(portDirection1, portDirection2, 0x01);
}
void Max7312::init(unsigned char portDirection1, unsigned char portDirection2, unsigned char timeoutFlag)
{
	initDataBuffers();
	Wire.begin();
	configPort1(portDirection1);
	configPort2(portDirection2);
	configTimeout(timeoutFlag);
}


void Max7312::initDataBuffers(){
	_port1_data=0;
	_port2_data=0;
}


/********** high level commands, for the user! */

unsigned char Max7312::readPort1(){
	_port1_data=readChar(INPUT_PORT_1);
	return _port1_data;
}

unsigned char Max7312::readPort2(){
	_port2_data=readChar(INPUT_PORT_2);
	return _port2_data;
}

void Max7312::writePort1(unsigned char portData){
	writeChar(OUTPUT_PORT_1, portData);
}
void Max7312::writePort2(unsigned char portData){
	writeChar(OUTPUT_PORT_2, portData);
}

void Max7312::polarityInversionPort1(unsigned char portInversion){
	writeChar(OUTPUT_PORT_1, portInversion);
}
void Max7312::polarityInversionPort2(unsigned char portInversion){
	writeChar(OUTPUT_PORT_2, portInversion);
}

void Max7312::configPort1(unsigned char portDirection){
	writeChar(CONFIGURATION_PORT_1, portDirection);
}

void Max7312::configPort2(unsigned char portDirection){
	writeChar(CONFIGURATION_PORT_2, portDirection);
}

void Max7312::configTimeout(unsigned char timeoutFlag){
	writeChar(TIMEOUT_REGISTER, timeoutFlag);
}

void Max7312::readIntFlag(){}

/*********** mid level commands, for sending data/cmds */



/************ low level writing to i2c **********/

void Max7312::writeChar(unsigned char registerAddress, unsigned char charData){
  // todo implement i2c write from Wire library
}

unsigned char Max7312::readChar(unsigned char registerAddress){
  // todo implement i2c read from Wire library
}
