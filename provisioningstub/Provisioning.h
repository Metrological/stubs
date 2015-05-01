#ifndef __PROVISIONING_H
#define __PROVISIONING_H

#ifdef __cplusplus
extern "C" {
#endif

/*!
\brief Get the request provisioning as a string.
\param maxRequestLength length of the provisioningRequest buffer. If the buffer is too small to fit the request provisioning string, an error (-1) is returned.
\param provisioningRequest pointer to the buffer where the request provisioning string will be copied.
\return >=0  The return value indicates the number of successfully copied characters into the provisioningRequest buffer.
\return <0 an error occurred. -1 means the buffer is too small.
*/
int MLPD_getProvisioningRequest(int maxRequestLength, char *provisioningRequest);

/*!
\brief Set the the provisioning data from the passed in string.
\param setRequestLength Length of the provisioning request string  in bytes.
\param provisioningRequest pointer to the buffer where the request  provisioning string is stored.
\return >=0  The return value indicates the number of successfully handled characters in the provisioningRequest buffer.
\return <0 an error occurred. -1 malformed data, -2 expired data
*/
int MLPD_setProvisioningRequest(int setRequestLength, char *provisioningRequest);

#ifdef __cplusplus
}
#endif

/*__PROVISIONING_H */
#endif
