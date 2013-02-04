#include <stdio.h>		// printf
#include <stdlib.h>		// atoi
#include "QRBG.h"

int main(int argc, char* argv[]) {
	//
	// parse the command line
	//
	int reqBlockSize = 1*1024*1024;
	if (argc == 2) {
		reqBlockSize = atoi(argv[1]);
	} else if (argc > 2) {
		// educate user! :-)
		printf("Usage: %s [requested_block_size] \n", argv[0]);
		return 0;
	}

	QRBG* rndService;
	try {
		rndService = new QRBG;
	} catch (QRBG::NetworkSubsystemError) {
		printf("Network error!");
		return 1;
	} catch (...) {
		printf("Failed to create QRBG client object!");
		return 1;
	}
	
	try {
		rndService->defineServer("random.irb.hr", 1227);
		rndService->defineUser("username", "password");
	} catch (QRBG::InvalidArgumentError e) {
		printf("Invalid hostname/port, or username/password specified! \n");
		delete rndService;
		return 1;
	}

	byte* buffer;
	try {
		buffer = new byte[reqBlockSize];
	} catch (...) {
		printf("Failed to allocate memory! \n");
		delete rndService;
		return 1;
	}

	try {
		printf("QRBG service returned byte: %x \n", rndService->getByte());
		printf("QRBG service returned integer: %x \n", rndService->getInt());
		printf("QRBG service returned long integer: %x \n", rndService->getLongInt());
		printf("QRBG service returned float: %f \n", rndService->getFloat());
		printf("QRBG service returned double: %f \n", rndService->getDouble());
		printf("Block of %d bytes (%.2f MiB) of data requested...\n", reqBlockSize, reqBlockSize / 1024.0 / 1024.0);
		rndService->getBytes(buffer, reqBlockSize);
		printf("QRBG service returned block of %d bytes (%.2f MiB) of data.\n", reqBlockSize, reqBlockSize / 1024.0 / 1024.0);
		delete rndService;
		return 0;

	} catch (QRBG::ConnectError e) {
		printf("Connect error! \n");
	} catch (QRBG::CommunicationError e) {
		printf("Communication error! \n");
	} catch (QRBG::ServiceDenied e) {
		printf("Service denied! \n", e.ServerResponse, e.RefusalReason);
		printf("--> %s! (%s.) \n", e.why(), e.cure());
	}

	delete rndService;
	return 1;
}
