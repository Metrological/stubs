#include <stdlib.h>

#include "Provisioning.h"

#ifdef __cplusplus
extern "C" {
#endif

static const char myStubbedMessage[] = "{ JSON MESSAGE }";

/*!
\brief Get the request provisioning as a string.
\param maxRequestLength length of the provisioningRequest buffer. If the buffer is too small to fit the request provisioning string, an error (-1) is returned.
\param provisioningRequest pointer to the buffer where the request provisioning string will be copied.
\return >=0  The return value indicates the number of successfully copied characters into the provisioningRequest buffer.
\return <0 an error occurred. -1 means the buffer is too small.
*/
int MLPD_getProvisioningRequest(int maxRequestLength, char *provisioningRequest)
{
	int result = -1; // Start with a no fit.

	if (sizeof (myStubbedMessage) <= maxRequestLength)
	{
		result = sizeof(myStubbedMessage);
		strncpy(provisioningRequest, myStubbedMessage, result);
	}

	return (result);
}

/*!
\brief Set the the provisioning data from the passed in string.
\param setRequestLength Length of the provisioning request string  in bytes.
\param provisioningRequest pointer to the buffer where the request  provisioning string is stored.
\return >=0  The return value indicates the number of successfully handled characters in the provisioningRequest buffer.
\return <0 an error occurred. -1 malformed data, -2 expired data
*/

int MLPD_setProvisioningRequest(int setRequestLength, char *provisioningRequest)
{
	int result = -1; // Start with a MALFORMED message

	// We expect an echo server kind of feedback, so what we send out should come back.
	if (sizeof (myStubbedMessage) == setRequestLength)
	{
		result = strncmp(provisioningRequest, myStubbedMessage, sizeof(myStubbedMessage)) == 0 ? 0 : -2);
	}

	return (result);
}

#ifdef __cplusplus
}
#endif
