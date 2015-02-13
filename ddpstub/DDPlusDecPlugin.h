/** @file DDPlusDecPlugin.h The Dolby Digital Plus decoder plug-in interface.
 *
 * DDPlusDecPlugin.h declares the Dolby Digital Plus decoder plug-in interface.
 * - initializes/destroys the decoder plug-in.
 * - decodes compressed audio frames into 2-channels, 16-bits LPCM samples.
 */

#ifndef __DDPLUS_DEC_PLUGIN__
#define __DDPLUS_DEC_PLUGIN__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Initializing the decoder.
 *
 * @return an opaque context pointer which represents the decoder instance.
 */
void* ddplusdec_open(void);


/**
 * Destroying the decoder.
 *
 * The resource allocated by the decoder should be freed. The decoder should
 * discard any buffered data as well.
 *
 * @param context the opaque context pointer which was returned by
 *        ddplusdec_open().
 */
void ddplusdec_close(void* context);


/**
 * Decoding compressed audio frames into 2-channels, 16-bits LPCM samples.
 *
 * @param context the opaque context pointer which was returned by
 *        ddplusdec_open().
 * @param outputLpcmBuffer the output LPCM buffer. The output data format
 *        is 2-channel 16 bits PCM interleaved i.e. it's 2 bytes for the
 *        left channel follows by 2 bytes for the right channel,
 *        and so forth. Also, the caller guarantees that the output buffer
 *        size is large enough to hold the audio decoded from the input
 *        data. This requires the caller to know the maximum number of
 *        blocks or AUs in the input buffer. Byte ordering is native
 *        endian.
 * @param outputBufferBytes the size, in bytes, of the output LPCM buffer.
 * @param inputFrameData the input data qhich may consist of one or more
 *        DD+ complete sync frames. The decoder will continue to process
 *        the input buffer until it is exhausted. Byte ordering is native
 *        endian. A sync failure will occur if byte ordering is incorrect.
 * @param inputFrameBytes the size, in bytes, of the input data.
 *
 * @return the size of the decoded LPCM output in bytes; 0 on decoding
 *         error.
 */
uint32_t ddplusdec_decode(void* context,
                          unsigned char* outputLpcmBuffer,
                          uint32_t outputBufferBytes,
                          const unsigned char* inputFrameData,
                          uint32_t inputFrameBytes);

#ifdef __cplusplus
}
#endif

/*__DDPLUS_DEC_PLUGIN__*/
#endif 
