/*
 * Copyright (C) 2024-2026 Luigi Sciolla
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

#include "config.h"

#include <dlfcn.h>
#include <stdarg.h>
#include <assert.h>
#include "windef.h"
#include "winbase.h"
#include "wine/debug.h"

#include "hip/hip_runtime_api.h"
#include "hip/hip_deprecated.h"

#include <pthread.h>

// #define HIPERR_ASSERT(x) assert(x)
#define HIPERR_ASSERT(x)

WINE_DEFAULT_DEBUG_CHANNEL(amdhip64);

#define TRACE_RET()                                                            \
  do {                                                                         \
    if (TRACE_ON(amdhip64)) {                                                  \
      TRACE(" : %s\n", hipGetErrorName(err));                                  \
    }                                                                          \
  } while (0)

void **__hipRegisterFatBinary(const void *data);
void ** WINAPI wine___hipRegisterFatBinary(const void *binary) {
  TRACE("(%p)", binary);
  void **ret = __hipRegisterFatBinary(binary);
  TRACE(" -> %p\n", ret);
  return ret;
}

void __hipRegisterFunction(void **modules, const void *hostFunction,
                           char *deviceFunction, const char *deviceName,
                           unsigned int threadLimit, uint3 *tid, uint3 *bid,
                           dim3 *blockDim, dim3 *gridDim, int *wSize);

void WINAPI wine___hipRegisterFunction(void **modules, const void *hostFunction,
                                       char *deviceFunction,
                                       const char *deviceName,
                                       unsigned int threadLimit, uint3 *tid,
                                       uint3 *bid, dim3 *blockDim,
                                       dim3 *gridDim, int *wSize) {
  __hipRegisterFunction(modules, hostFunction, deviceFunction, deviceName,
                        threadLimit, tid, bid, blockDim, gridDim, wSize);
  TRACE("\n");
}

void __hipUnregisterFatBinary(void **modules);
void WINAPI wine___hipUnregisterFatBinary(void **modules) {
  TRACE("(%p)\n", modules);
  __hipUnregisterFatBinary(modules);
}

hipError_t WINAPI wine_hipGetDevice(int *deviceId) {
  return hipGetDevice(deviceId);
}

hipError_t WINAPI wine_hipGetDeviceCount(int *count) {
  hipError_t err = hipGetDeviceCount(count);
  TRACE("(%p, %d)", count, *count);

  TRACE_RET();
  return err;
}

hipError_t WINAPI wine_hipDeviceGet(hipDevice_t *device, int ordinal) {
  TRACE("(%p, %d)", device, ordinal);
  hipError_t err = hipDeviceGet(device, ordinal);
  HIPERR_ASSERT(err == 0);
  TRACE_RET();
  return err;
}

hipError_t WINAPI wine_hipGetDeviceProperties(void *prop, int deviceId) {
  TRACE("Should not be called!");
  HIPERR_ASSERT(false);
  hipError_t err = hipGetDevicePropertiesR0000(prop, deviceId);
  HIPERR_ASSERT(err == 0);
  return err;
}

hipError_t WINAPI wine_hipGetDevicePropertiesR0600(hipDeviceProp_tR0600 *prop,
                                                   int deviceId) {
  TRACE("()");
  hipError_t err = hipGetDevicePropertiesR0600(prop, deviceId);
  HIPERR_ASSERT(err == 0);
  TRACE_RET();
  return err;
}

hipError_t WINAPI wine_hipInit(unsigned int flags) {
  TRACE("(%d)", flags);
  hipError_t err = hipInit(flags);
  HIPERR_ASSERT(err == 0);
  TRACE_RET();
  return err;
}

hipError_t WINAPI wine_hipDriverGetVersion(int *driverVersion) {
  hipError_t err = hipDriverGetVersion(driverVersion);
  TRACE("(%p): %d", driverVersion, *driverVersion);
  HIPERR_ASSERT(err == 0);
  TRACE_RET();
  return err;
}

hipError_t WINAPI wine_hipDeviceTotalMem(size_t *bytes, hipDevice_t device) {
  hipError_t err = hipDeviceTotalMem(bytes, device);
  TRACE("(%lld, %d)", *bytes, device);
  HIPERR_ASSERT(err == 0);
  TRACE_RET();
  return err;
}

hipError_t WINAPI wine_hipDeviceGetName(char *name, int len,
                                        hipDevice_t device) {
  TRACE("(%p, %d, %d)", name, len, device);
  hipError_t err = hipDeviceGetName(name, len, device);
  HIPERR_ASSERT(err == 0);
  TRACE_RET();
  return err;
}

hipError_t WINAPI wine_hipDeviceGetUuid(hipUUID *uuid, hipDevice_t device) {
  TRACE("()");
  hipError_t err = hipDeviceGetUuid(uuid, device);
  HIPERR_ASSERT(err == 0);
  TRACE_RET();
  return err;
}

hipError_t WINAPI wine_hipCtxCreate(hipCtx_t *ctx, unsigned int flags,
                                    hipDevice_t device) {
  TRACE("()");
  hipError_t err = hipCtxCreate(ctx, flags, device);
  HIPERR_ASSERT(err == 0);
  TRACE_RET();
  return err;
}
hipError_t WINAPI wine_hipRuntimeGetVersion(int *runtimeVersion) {
  TRACE("()");
  hipError_t err = hipRuntimeGetVersion(runtimeVersion);
  HIPERR_ASSERT(err == 0);
  TRACE_RET();
  return err;
}

hipError_t WINAPI wine_hipSetDevice(int deviceId) {
  TRACE("(%d)", deviceId);
  hipError_t err = hipSetDevice(deviceId);
  HIPERR_ASSERT(err == 0);
  TRACE_RET();
  return err;
}
hipError_t WINAPI wine_hipDeviceGetAttribute(int *pi, hipDeviceAttribute_t attr,
                                             int deviceId) {
  TRACE("()\n");
  hipError_t err = hipDeviceGetAttribute(pi, attr, deviceId);
  HIPERR_ASSERT(err == 0);
  TRACE_RET();
  return err;
}

hipError_t WINAPI wine_hipCtxPushCurrent(hipCtx_t ctx) {
  TRACE("()");
  hipError_t err = hipCtxPushCurrent(ctx);
  HIPERR_ASSERT(err == 0);
  TRACE_RET();
  return err;
}

hipError_t WINAPI wine_hipEventCreateWithFlags(hipEvent_t *event,
                                               unsigned int flags) {
  TRACE("()\n");
  hipError_t err = hipEventCreateWithFlags(event, flags);
  HIPERR_ASSERT(err == 0);
  TRACE_RET();
  return err;
}

hipError_t WINAPI wine_hipMalloc(void **ptr, size_t size) {
  TRACE("(%p, %ld)", ptr, size);
  hipError_t err = hipMalloc(ptr, size);
  HIPERR_ASSERT(err == 0);
  TRACE_RET();
  return err;
}

hipError_t WINAPI wine_hipHostMalloc(void **ptr, size_t size,
                                     unsigned int flags) {
  TRACE("(%p, %ld, %d)", ptr, size, flags);
  hipError_t err = hipHostMalloc(ptr, size, flags);
  HIPERR_ASSERT(err == 0);
  TRACE_RET();
  return err;
}

hipError_t WINAPI wine_hipEventRecord(hipEvent_t event, hipStream_t stream) {
  hipError_t err = hipEventRecord(event, stream);
  HIPERR_ASSERT(err == 0);
  return err;
}

hipError_t WINAPI wine_hipEventSynchronize(hipEvent_t event) {
  hipError_t err = hipEventSynchronize(event);
  HIPERR_ASSERT(err == 0);
  return err;
}

hipError_t WINAPI wine_hipStreamCreate(hipStream_t *stream) {
  TRACE("(%p)", stream);
  hipError_t err = hipStreamCreate(stream);
  HIPERR_ASSERT(err == 0);
  TRACE_RET();
  return err;
}
hipError_t WINAPI wine_hipStreamCreateWithFlags(hipStream_t *stream,
                                                unsigned int flags) {
  hipError_t err = hipStreamCreateWithFlags(stream, flags);
  HIPERR_ASSERT(err == 0);
  return err;
}
hipError_t WINAPI wine_hipMemcpyAsync(void *dst, const void *src,
                                      size_t sizeBytes, hipMemcpyKind kind,
                                      hipStream_t stream) {
  hipError_t err = hipMemcpyAsync(dst, src, sizeBytes, kind, stream);
  HIPERR_ASSERT(err == 0);
  return err;
}

hipError_t WINAPI wine_hipMemcpy(void *dst, const void *src, size_t sizeBytes,
                                 hipMemcpyKind kind) {
  TRACE("(%p, %p, %lld, %d)", dst, src, sizeBytes, kind);
  hipError_t err = hipMemcpy(dst, src, sizeBytes, kind);
  HIPERR_ASSERT(err == 0);
  TRACE_RET();
  return err;
}

hipError_t WINAPI wine_hipFree(void *ptr) {
  TRACE("(%p)", ptr);
  hipError_t err = hipFree(ptr);
  HIPERR_ASSERT(err == 0);
  TRACE_RET();
  return err;
}

hipError_t WINAPI wine_hipStreamDestroy(hipStream_t stream) {
  hipError_t err = hipStreamDestroy(stream);
  HIPERR_ASSERT(err == 0);
  return err;
}

hipError_t WINAPI wine_hipStreamQuery(hipStream_t stream) {
  hipError_t err = hipStreamQuery(stream);
  return err;
}

hipError_t WINAPI wine_hipEventDestroy(hipEvent_t event) {
  hipError_t err = hipEventDestroy(event);
  HIPERR_ASSERT(err == 0);
  return err;
}

hipError_t WINAPI wine_hipCtxPopCurrent(hipCtx_t *ctx) {
  TRACE("(%p)", ctx);
  hipError_t err = hipCtxPopCurrent(ctx);
  HIPERR_ASSERT(err == 0);
  TRACE_RET();
  return err;
}

hipError_t WINAPI wine_hipMemGetInfo(size_t *free, size_t *total) {
  hipError_t err = hipMemGetInfo(free, total);

  int64_t free_fix = *free - (1024l * 1024l * 1024l * 2l);

  if (free_fix > 0) {
    *free = free_fix;
  } else {
    *free = 0;
  }

  HIPERR_ASSERT(err == 0);
  TRACE("\nmemGetInfo: free (%.3fmb), total (%.3fmb)",
        (float)(*free) / (1024.f * 1024.f),
        (float)(*total) / (1024.f * 1024.f));
  TRACE_RET();
  return err;
}

hipError_t WINAPI wine_hipHostGetDevicePointer(void **devPtr, void *hstPtr,
                                               unsigned int flags) {
  TRACE("()");
  hipError_t err = hipHostGetDevicePointer(devPtr, hstPtr, flags);
  HIPERR_ASSERT(err == 0);
  TRACE_RET();
  return err;
}

hipError_t WINAPI wine_hipModuleLoadData(hipModule_t *module,
                                         const void *image) {
  TRACE("()");
  hipError_t err = hipModuleLoadData(module, image);
  HIPERR_ASSERT(err == 0);
  TRACE_RET();
  return err;
}

hipError_t WINAPI wine_hipModuleGetFunction(hipFunction_t *function,
                                            hipModule_t module,
                                            const char *kname) {
  TRACE("()");
  hipError_t err = hipModuleGetFunction(function, module, kname);
  TRACE_RET();
  return err;
}

hipError_t WINAPI wine_hipFuncGetAttribute(int *value,
                                           hipFunction_attribute attrib,
                                           hipFunction_t hfunc) {
  TRACE("()");
  hipError_t err = hipFuncGetAttribute(value, attrib, hfunc);
  TRACE_RET();
  return err;
}

hipError_t WINAPI wine_hipDeviceReset(void) {
  TRACE("()");
  hipError_t err = hipDeviceReset();
  HIPERR_ASSERT(err == 0);
  TRACE_RET();
  return err;
}

hipError_t WINAPI wine_hipDeviceSetCacheConfig(hipFuncCache_t cacheConfig) {
  TRACE("()");
  hipError_t err = hipDeviceSetCacheConfig(cacheConfig);
  HIPERR_ASSERT(err == 0);
  TRACE_RET();
  return err;
}

hipError_t WINAPI wine_hipDeviceSetLimit(enum hipLimit_t limit, size_t value) {
  TRACE("()");
  hipError_t err = hipDeviceSetLimit(limit, value);
  HIPERR_ASSERT(err == 0);
  TRACE_RET();
  return err;
}

hipError_t WINAPI wine_hipFuncSetCacheConfig(const void *func,
                                             hipFuncCache_t config) {
  TRACE("()");
  hipError_t err = hipFuncSetCacheConfig(func, config);
  HIPERR_ASSERT(err == 0);
  TRACE_RET();
  return err;
}

hipError_t WINAPI wine_hipMemcpyHtoD(hipDeviceptr_t dst, void *src,
                                     size_t sizeBytes) {
  TRACE("(%p, %p, %lld)", dst, src, sizeBytes);
  hipError_t err = hipMemcpyHtoD(dst, src, sizeBytes);
  HIPERR_ASSERT(err == 0);
  TRACE_RET();
  return err;
}

hipError_t WINAPI wine_hipModuleGetGlobal(hipDeviceptr_t *dptr, size_t *bytes,
                                          hipModule_t hmod, const char *name) {
  hipError_t err = hipModuleGetGlobal(dptr, bytes, hmod, name);
  HIPERR_ASSERT(err == 0);
  return err;
}

hipError_t WINAPI wine_hipMemsetD8(hipDeviceptr_t dest, unsigned char value,
                                   size_t count) {
  return hipMemsetD8(dest, value, count);
}

hipError_t WINAPI wine_hipMemsetD8Async(hipDeviceptr_t dest,
                                        unsigned char value, size_t count,
                                        hipStream_t stream) {
  TRACE("(%p, %d, %lld, %p)\n", dest, value, count, stream);
  hipError_t err = hipMemsetD8Async(dest, value, count, stream);
  TRACE_RET();
  return err;
}

hipError_t WINAPI wine_hipArrayCreate(
    hipArray_t *pHandle, const HIP_ARRAY_DESCRIPTOR *pAllocateArray) {
  hipError_t err = hipArrayCreate(pHandle, pAllocateArray);
  HIPERR_ASSERT(err == 0);
  return err;
}

hipError_t WINAPI wine_hipModuleUnload(hipModule_t module) {
  hipError_t err = hipModuleUnload(module);
  assert(err == 0);
  return err;
}

hipError_t WINAPI wine_hipHostFree(void *ptr) {
  hipError_t err = hipHostFree(ptr);
  assert(err == 0);
  return err;
}

hipError_t WINAPI
wine_hipDestroyTextureObject(hipTextureObject_t textureObject) {
  hipError_t err = hipDestroyTextureObject(textureObject);
  assert(err == 0);
  return err;
}

hipError_t WINAPI wine_hipDeviceComputeCapability(int *major, int *minor,
                                                  hipDevice_t device) {
  hipError_t err = hipDeviceComputeCapability(major, minor, device);
  assert(err == 0);
  return err;
}

hipError_t WINAPI wine_hipFreeArray(hipArray_t array) {
  hipError_t err = hipFreeArray(array);
  assert(err == 0);
  return err;
}

hipError_t WINAPI wine_hipCtxDestroy(hipCtx_t ctx) {
  hipError_t err = hipCtxDestroy(ctx);
  assert(err == 0);
  return err;
}

hipError_t WINAPI wine_hipModuleLaunchKernel(
    hipFunction_t f, unsigned int gridDimX, unsigned int gridDimY,
    unsigned int gridDimZ, unsigned int blockDimX, unsigned int blockDimY,
    unsigned int blockDimZ, unsigned int sharedMemBytes, hipStream_t stream,
    void **kernelParams, void **extra) {
  TRACE("()");
  hipError_t err = hipModuleLaunchKernel(
      f, gridDimX, gridDimY, gridDimZ, blockDimX, blockDimY, blockDimZ,
      sharedMemBytes, stream, kernelParams, extra);
  assert(err == 0);
  TRACE_RET();
  return err;
};

hipError_t WINAPI wine_hipMemcpyDtoH(void *dst, hipDeviceptr_t src,
                                     size_t sizeBytes) {
  hipError_t err = hipMemcpyDtoH(dst, src, sizeBytes);
  assert(err == 0);
  return err;
}

hipError_t WINAPI wine_hipMemcpyDtoDAsync(hipDeviceptr_t dst,
                                          hipDeviceptr_t src, size_t sizeBytes,
                                          hipStream_t stream) {
  hipError_t err = hipMemcpyDtoDAsync(dst, src, sizeBytes, stream);
  assert(err == 0);
  return err;
};

hipError_t WINAPI wine_hipMemcpyDtoHAsync(void *dst, hipDeviceptr_t src,
                                          size_t sizeBytes,
                                          hipStream_t stream) {
  hipError_t err = hipMemcpyDtoHAsync(dst, src, sizeBytes, stream);
  assert(err == 0);
  return err;
}

hipError_t WINAPI wine_hipStreamSynchronize(hipStream_t stream) {
  hipError_t err = hipStreamSynchronize(stream);
  assert(err == 0);
  return err;
}

hipError_t WINAPI wine_hipStreamWaitEvent(hipStream_t stream, hipEvent_t event,
                                          unsigned int flags) {
  hipError_t err = hipStreamWaitEvent(stream, event, flags);
  HIPERR_ASSERT(err == 0);
  return err;
}

hipError_t WINAPI wine_hipMemcpyParam2D(const hip_Memcpy2D *pCopy) {
  hipError_t err = hipMemcpyParam2D(pCopy);
  HIPERR_ASSERT(err == 0);
  return err;
}

hipError_t WINAPI wine_hipMemcpyParam2DAsync(const hip_Memcpy2D *pCopy,
                                             hipStream_t stream) {
  hipError_t err = hipMemcpyParam2DAsync(pCopy, stream);
  return err;
}

const char *WINAPI wine_hipGetErrorString(hipError_t hipError) {
  return hipGetErrorString(hipError);
}

hipError_t WINAPI wine_hipGetLastError(void) { return hipGetLastError(); }

hipError_t WINAPI wine_hipTexObjectCreate(
    hipTextureObject_t *pTexObject, const HIP_RESOURCE_DESC *pResDesc,
    const HIP_TEXTURE_DESC *pTexDesc,
    const HIP_RESOURCE_VIEW_DESC *pResViewDesc) {
  hipError_t err =
      hipTexObjectCreate(pTexObject, pResDesc, pTexDesc, pResViewDesc);
  HIPERR_ASSERT(err == 0);
  return err;
}

hipError_t WINAPI wine_hipMemcpyHtoDAsync(hipDeviceptr_t dst, void *src,
                                          size_t sizeBytes,
                                          hipStream_t stream) {
  hipError_t err = hipMemcpyHtoDAsync(dst, src, sizeBytes, stream);
  HIPERR_ASSERT(err == 0);
  return err;
}

hipError_t WINAPI wine_hipArray3DCreate(
    hipArray_t *array, const HIP_ARRAY3D_DESCRIPTOR *pAllocateArray) {
  hipError_t err = hipArray3DCreate(array, pAllocateArray);
  HIPERR_ASSERT(err == 0);
  return err;
}

hipChannelFormatDesc WINAPI wine_hipCreateChannelDesc(int x, int y, int z,
                                                      int w,
                                                      hipChannelFormatKind f) {
  return hipCreateChannelDesc(x, y, z, w, f);
}

hipError_t WINAPI wine_hipModuleGetTexRef(textureReference **texRef, hipModule_t hmod,
                                   const char *name) {
  return hipModuleGetTexRef(texRef, hmod, name);
}

hipError_t WINAPI wine_hipUnbindTexture(const textureReference* tex) {
  return hipUnbindTexture(tex);
}

hipError_t WINAPI wine_hipTexRefSetFormat(textureReference *texRef,
                                           hipArray_Format fmt,
                                           int NumPackedComponents) {
  return hipTexRefSetFormat(texRef, fmt, NumPackedComponents);
}

hipError_t WINAPI wine_hipTexRefSetAddress(size_t *ByteOffset,
                                            textureReference *texRef,
                                            hipDeviceptr_t dptr,
                                            size_t bytes) {
  return hipTexRefSetAddress(ByteOffset, texRef, dptr, bytes);
}

hipError_t WINAPI wine_hipTexRefSetFlags(textureReference *texRef,
                                          unsigned int Flags) {
  return hipTexRefSetFlags(texRef, Flags);
}

hipError_t WINAPI wine_hipDrvMemcpy3D(const HIP_MEMCPY3D *pCopy) {
  hipError_t err = hipDrvMemcpy3D(pCopy);
  HIPERR_ASSERT(err == 0);
  return err;
}
hipError_t WINAPI wine_hipEventQuery(hipEvent_t event) {
  return hipEventQuery(event);
}

hipError_t WINAPI wine_hipDeviceSynchronize() { return hipDeviceSynchronize(); }

hipError_t WINAPI wine_hipStreamIsCapturing(
    hipStream_t stream, hipStreamCaptureStatus *pCaptureStatus) {
  return hipStreamIsCapturing(stream, pCaptureStatus);
}

hipError_t WINAPI wine___hipPopCallConfiguration(dim3* gridDim, dim3* blockDim, size_t* sharedMem, hipStream_t* stream) {
  return __hipPopCallConfiguration(gridDim, blockDim, sharedMem, stream);
}

hipError_t WINAPI wine___hipPushCallConfiguration(dim3 gridDim, dim3 blockDim, size_t sharedMem, hipStream_t stream) {
  return __hipPushCallConfiguration(gridDim, blockDim, sharedMem, stream);
}

const char* WINAPI wine_hipApiName(uint32_t id) {
  return hipApiName(id);
}

hipError_t WINAPI wine_hipArray3DGetDescriptor(HIP_ARRAY3D_DESCRIPTOR* pArrayDescriptor, hipArray_t array) {
  return hipArray3DGetDescriptor(pArrayDescriptor, array);
}

hipError_t WINAPI wine_hipArrayDestroy(hipArray_t array) {
  return hipArrayDestroy(array);
}

hipError_t WINAPI wine_hipArrayGetDescriptor(HIP_ARRAY_DESCRIPTOR* pArrayDescriptor, hipArray_t array) {
  return hipArrayGetDescriptor(pArrayDescriptor, array);
}

hipError_t WINAPI wine_hipArrayGetInfo(hipChannelFormatDesc* desc, hipExtent* extent, unsigned int* flags, hipArray_t array) {
  return hipArrayGetInfo(desc, extent, flags, array);
}

hipError_t WINAPI wine_hipBindTexture(size_t* offset, const textureReference* tex, const void* devPtr, const hipChannelFormatDesc* desc, size_t size) {
  return hipBindTexture(offset, tex, devPtr, desc, size);
}

hipError_t WINAPI wine_hipBindTexture2D(size_t* offset, const textureReference* tex, const void* devPtr, const hipChannelFormatDesc* desc, size_t width, size_t height, size_t pitch) {
  return hipBindTexture2D(offset, tex, devPtr, desc, width, height, pitch);
}

hipError_t WINAPI wine_hipBindTextureToArray(const textureReference* tex, hipArray_const_t array, const hipChannelFormatDesc* desc) {
  return hipBindTextureToArray(tex, array, desc);
}

hipError_t WINAPI wine_hipBindTextureToMipmappedArray(const textureReference* tex, hipMipmappedArray_const_t mipmappedArray, const hipChannelFormatDesc* desc) {
  return hipBindTextureToMipmappedArray(tex, mipmappedArray, desc);
}

hipError_t WINAPI wine_hipChooseDevice(int* device, const hipDeviceProp_t* prop) {
  return hipChooseDevice(device, prop);
}

hipError_t WINAPI wine_hipChooseDeviceR0000(int* device, const hipDeviceProp_tR0000* prop) {
  return hipChooseDeviceR0000(device, prop);
}

hipError_t WINAPI wine_hipChooseDeviceR0600(int* device, const hipDeviceProp_t* prop) {
  return hipChooseDeviceR0600(device, prop);
}

hipError_t WINAPI wine_hipConfigureCall(dim3 gridDim, dim3 blockDim, size_t sharedMem, hipStream_t stream) {
  return hipConfigureCall(gridDim, blockDim, sharedMem, stream);
}

hipError_t WINAPI wine_hipCreateSurfaceObject(hipSurfaceObject_t* pSurfObject, const hipResourceDesc* pResDesc) {
  return hipCreateSurfaceObject(pSurfObject, pResDesc);
}

hipError_t WINAPI wine_hipCreateTextureObject(hipTextureObject_t* pTexObject, const hipResourceDesc* pResDesc, const hipTextureDesc* pTexDesc, const struct hipResourceViewDesc* pResViewDesc) {
  return hipCreateTextureObject(pTexObject, pResDesc, pTexDesc, pResViewDesc);
}

hipError_t WINAPI wine_hipCtxDisablePeerAccess(hipCtx_t peerCtx) {
  return hipCtxDisablePeerAccess(peerCtx);
}

hipError_t WINAPI wine_hipCtxEnablePeerAccess(hipCtx_t peerCtx, unsigned int flags) {
  return hipCtxEnablePeerAccess(peerCtx, flags);
}

hipError_t WINAPI wine_hipCtxGetApiVersion(hipCtx_t ctx, unsigned int* apiVersion) {
  return hipCtxGetApiVersion(ctx, apiVersion);
}

hipError_t WINAPI wine_hipCtxGetCacheConfig(hipFuncCache_t* cacheConfig) {
  return hipCtxGetCacheConfig(cacheConfig);
}

hipError_t WINAPI wine_hipCtxGetCurrent(hipCtx_t* ctx) {
  return hipCtxGetCurrent(ctx);
}

hipError_t WINAPI wine_hipCtxGetDevice(hipDevice_t* device) {
  return hipCtxGetDevice(device);
}

hipError_t WINAPI wine_hipCtxGetFlags(unsigned int* flags) {
  return hipCtxGetFlags(flags);
}

hipError_t WINAPI wine_hipCtxGetSharedMemConfig(hipSharedMemConfig* pConfig) {
  return hipCtxGetSharedMemConfig(pConfig);
}

hipError_t WINAPI wine_hipCtxSetCacheConfig(hipFuncCache_t cacheConfig) {
  return hipCtxSetCacheConfig(cacheConfig);
}

hipError_t WINAPI wine_hipCtxSetCurrent(hipCtx_t ctx) {
  return hipCtxSetCurrent(ctx);
}

hipError_t WINAPI wine_hipCtxSetSharedMemConfig(hipSharedMemConfig config) {
  return hipCtxSetSharedMemConfig(config);
}

hipError_t WINAPI wine_hipCtxSynchronize(void) {
  return hipCtxSynchronize();
}

hipError_t WINAPI wine_hipDestroyExternalMemory(hipExternalMemory_t extMem) {
  return hipDestroyExternalMemory(extMem);
}

hipError_t WINAPI wine_hipDestroyExternalSemaphore(hipExternalSemaphore_t extSem) {
  return hipDestroyExternalSemaphore(extSem);
}

hipError_t WINAPI wine_hipDestroySurfaceObject(hipSurfaceObject_t surfaceObject) {
  return hipDestroySurfaceObject(surfaceObject);
}

hipError_t WINAPI wine_hipDeviceCanAccessPeer(int* canAccessPeer, int deviceId, int peerDeviceId) {
  return hipDeviceCanAccessPeer(canAccessPeer, deviceId, peerDeviceId);
}

hipError_t WINAPI wine_hipDeviceDisablePeerAccess(int peerDeviceId) {
  return hipDeviceDisablePeerAccess(peerDeviceId);
}

hipError_t WINAPI wine_hipDeviceEnablePeerAccess(int peerDeviceId, unsigned int flags) {
  return hipDeviceEnablePeerAccess(peerDeviceId, flags);
}

hipError_t WINAPI wine_hipDeviceGetByPCIBusId(int* device, const char* pciBusId) {
  return hipDeviceGetByPCIBusId(device, pciBusId);
}

hipError_t WINAPI wine_hipDeviceGetCacheConfig(hipFuncCache_t* cacheConfig) {
  return hipDeviceGetCacheConfig(cacheConfig);
}

hipError_t WINAPI wine_hipDeviceGetDefaultMemPool(hipMemPool_t* mem_pool, int device) {
  return hipDeviceGetDefaultMemPool(mem_pool, device);
}

hipError_t WINAPI wine_hipDeviceGetGraphMemAttribute(int device, hipGraphMemAttributeType attr, void* value) {
  return hipDeviceGetGraphMemAttribute(device, attr, value);
}

hipError_t WINAPI wine_hipDeviceGetLimit(size_t* pValue, enum hipLimit_t limit) {
  return hipDeviceGetLimit(pValue, limit);
}

hipError_t WINAPI wine_hipDeviceGetMemPool(hipMemPool_t* mem_pool, int device) {
  return hipDeviceGetMemPool(mem_pool, device);
}

hipError_t WINAPI wine_hipDeviceGetP2PAttribute(int* value, hipDeviceP2PAttr attr, int srcDevice, int dstDevice) {
  return hipDeviceGetP2PAttribute(value, attr, srcDevice, dstDevice);
}

hipError_t WINAPI wine_hipDeviceGetPCIBusId(char* pciBusId, int len, int device) {
  return hipDeviceGetPCIBusId(pciBusId, len, device);
}

hipError_t WINAPI wine_hipDeviceGetSharedMemConfig(hipSharedMemConfig* pConfig) {
  return hipDeviceGetSharedMemConfig(pConfig);
}

hipError_t WINAPI wine_hipDeviceGetStreamPriorityRange(int* leastPriority, int* greatestPriority) {
  return hipDeviceGetStreamPriorityRange(leastPriority, greatestPriority);
}

hipError_t WINAPI wine_hipDeviceGraphMemTrim(int device) {
  return hipDeviceGraphMemTrim(device);
}

hipError_t WINAPI wine_hipDevicePrimaryCtxGetState(hipDevice_t dev, unsigned int* flags, int* active) {
  return hipDevicePrimaryCtxGetState(dev, flags, active);
}

hipError_t WINAPI wine_hipDevicePrimaryCtxRelease(hipDevice_t dev) {
  return hipDevicePrimaryCtxRelease(dev);
}

hipError_t WINAPI wine_hipDevicePrimaryCtxReset(hipDevice_t dev) {
  return hipDevicePrimaryCtxReset(dev);
}

hipError_t WINAPI wine_hipDevicePrimaryCtxRetain(hipCtx_t* pctx, hipDevice_t dev) {
  return hipDevicePrimaryCtxRetain(pctx, dev);
}

hipError_t WINAPI wine_hipDevicePrimaryCtxSetFlags(hipDevice_t dev, unsigned int flags) {
  return hipDevicePrimaryCtxSetFlags(dev, flags);
}

hipError_t WINAPI wine_hipDeviceSetGraphMemAttribute(int device, hipGraphMemAttributeType attr, void* value) {
  return hipDeviceSetGraphMemAttribute(device, attr, value);
}

hipError_t WINAPI wine_hipDeviceSetMemPool(int device, hipMemPool_t mem_pool) {
  return hipDeviceSetMemPool(device, mem_pool);
}

hipError_t WINAPI wine_hipDeviceSetSharedMemConfig(hipSharedMemConfig config) {
  return hipDeviceSetSharedMemConfig(config);
}

hipError_t WINAPI wine_hipDrvGetErrorName(hipError_t hipError, const char** errorString) {
  return hipDrvGetErrorName(hipError, errorString);
}

hipError_t WINAPI wine_hipDrvGetErrorString(hipError_t hipError, const char** errorString) {
  return hipDrvGetErrorString(hipError, errorString);
}

hipError_t WINAPI wine_hipDrvGraphAddMemcpyNode(hipGraphNode_t* phGraphNode, hipGraph_t hGraph, const hipGraphNode_t* dependencies, size_t numDependencies, const HIP_MEMCPY3D* copyParams, hipCtx_t ctx) {
  return hipDrvGraphAddMemcpyNode(phGraphNode, hGraph, dependencies, numDependencies, copyParams, ctx);
}

hipError_t WINAPI wine_hipDrvGraphAddMemsetNode(hipGraphNode_t* phGraphNode, hipGraph_t hGraph, const hipGraphNode_t* dependencies, size_t numDependencies, const hipMemsetParams* memsetParams, hipCtx_t ctx) {
  return hipDrvGraphAddMemsetNode(phGraphNode, hGraph, dependencies, numDependencies, memsetParams, ctx);
}

hipError_t WINAPI wine_hipDrvMemcpy2DUnaligned(const hip_Memcpy2D* pCopy) {
  return hipDrvMemcpy2DUnaligned(pCopy);
}

hipError_t WINAPI wine_hipDrvMemcpy3DAsync(const HIP_MEMCPY3D* pCopy, hipStream_t stream) {
  return hipDrvMemcpy3DAsync(pCopy, stream);
}


hipError_t WINAPI wine_hipDrvPointerGetAttributes(unsigned int numAttributes, hipPointer_attribute* attributes, void** data, hipDeviceptr_t ptr) {
  return hipDrvPointerGetAttributes(numAttributes, attributes, data, ptr);
}

hipError_t WINAPI wine_hipEventCreate(hipEvent_t* event) {
  return hipEventCreate(event);
}

hipError_t WINAPI wine_hipEventElapsedTime(float* ms, hipEvent_t start, hipEvent_t stop) {
  return hipEventElapsedTime(ms, start, stop);
}

hipError_t WINAPI wine_hipEventRecord_spt(hipEvent_t event, hipStream_t stream) {
  return hipEventRecord_spt(event, stream);
}

hipError_t WINAPI wine_hipExtGetLastError(void) {
  return hipExtGetLastError();
}

hipError_t WINAPI wine_hipExtGetLinkTypeAndHopCount(int device1, int device2, uint32_t* linktype, uint32_t* hopcount) {
  return hipExtGetLinkTypeAndHopCount(device1, device2, linktype, hopcount);
}

hipError_t WINAPI wine_hipExtLaunchKernel(const void* function_address, dim3 numBlocks, dim3 dimBlocks, void** args, size_t sharedMemBytes, hipStream_t stream, hipEvent_t startEvent, hipEvent_t stopEvent, int flags) {
  return hipExtLaunchKernel(function_address, numBlocks, dimBlocks, args, sharedMemBytes, stream, startEvent, stopEvent, flags);
}

hipError_t WINAPI wine_hipExtLaunchMultiKernelMultiDevice(hipLaunchParams* launchParamsList, int numDevices, unsigned int flags) {
  return hipExtLaunchMultiKernelMultiDevice(launchParamsList, numDevices, flags);
}

hipError_t WINAPI wine_hipExtMallocWithFlags(void** ptr, size_t sizeBytes, unsigned int flags) {
  return hipExtMallocWithFlags(ptr, sizeBytes, flags);
}

hipError_t WINAPI wine_hipExtStreamCreateWithCUMask(hipStream_t* stream, uint32_t cuMaskSize, const uint32_t* cuMask) {
  return hipExtStreamCreateWithCUMask(stream, cuMaskSize, cuMask);
}

hipError_t WINAPI wine_hipExtStreamGetCUMask(hipStream_t stream, uint32_t cuMaskSize, uint32_t* cuMask) {
  return hipExtStreamGetCUMask(stream, cuMaskSize, cuMask);
}

hipError_t WINAPI wine_hipExternalMemoryGetMappedBuffer(void** devPtr, hipExternalMemory_t extMem, const hipExternalMemoryBufferDesc* bufferDesc) {
  return hipExternalMemoryGetMappedBuffer(devPtr, extMem, bufferDesc);
}

hipError_t WINAPI wine_hipFreeAsync(void* dev_ptr, hipStream_t stream) {
  return hipFreeAsync(dev_ptr, stream);
}

hipError_t WINAPI wine_hipFreeHost(void* ptr) {
  return hipFreeHost(ptr);
}

hipError_t WINAPI wine_hipFreeMipmappedArray(hipMipmappedArray_t mipmappedArray) {
  return hipFreeMipmappedArray(mipmappedArray);
}

hipError_t WINAPI wine_hipFuncGetAttributes(struct hipFuncAttributes* attr, const void* func) {
  return hipFuncGetAttributes(attr, func);
}

hipError_t WINAPI wine_hipFuncSetAttribute(const void* func, hipFuncAttribute attr, int value) {
  return hipFuncSetAttribute(func, attr, value);
}

hipError_t WINAPI wine_hipFuncSetSharedMemConfig(const void* func, hipSharedMemConfig config) {
  return hipFuncSetSharedMemConfig(func, config);
}

hipError_t WINAPI wine_hipGetChannelDesc(hipChannelFormatDesc* desc, hipArray_const_t array) {
  return hipGetChannelDesc(desc, array);
}

hipError_t WINAPI wine_hipGetDeviceFlags(unsigned int* flags) {
  return hipGetDeviceFlags(flags);
}

hipError_t WINAPI wine_hipGetDevicePropertiesR0000(hipDeviceProp_tR0000* prop, int device) {
  return hipGetDevicePropertiesR0000(prop, device);
}

const char* WINAPI wine_hipGetErrorName(hipError_t hip_error) {
  return hipGetErrorName(hip_error);
}

hipError_t WINAPI wine_hipGetMipmappedArrayLevel(hipArray_t* levelArray, hipMipmappedArray_const_t mipmappedArray, unsigned int level) {
  return hipGetMipmappedArrayLevel(levelArray, mipmappedArray, level);
}

int WINAPI wine_hipGetStreamDeviceId(hipStream_t stream) {
  return hipGetStreamDeviceId(stream);
}

hipError_t WINAPI wine_hipGetSymbolAddress(void** devPtr, const void* symbol) {
  return hipGetSymbolAddress(devPtr, symbol);
}

hipError_t WINAPI wine_hipGetSymbolSize(size_t* size, const void* symbol) {
  return hipGetSymbolSize(size, symbol);
}

hipError_t WINAPI wine_hipGetTextureAlignmentOffset(size_t* offset, const textureReference* texref) {
  return hipGetTextureAlignmentOffset(offset, texref);
}

hipError_t WINAPI wine_hipGetTextureObjectResourceDesc(hipResourceDesc* pResDesc, hipTextureObject_t textureObject) {
  return hipGetTextureObjectResourceDesc(pResDesc, textureObject);
}

hipError_t WINAPI wine_hipGetTextureObjectResourceViewDesc(struct hipResourceViewDesc* pResViewDesc, hipTextureObject_t textureObject) {
  return hipGetTextureObjectResourceViewDesc(pResViewDesc, textureObject);
}

hipError_t WINAPI wine_hipGetTextureObjectTextureDesc(hipTextureDesc* pTexDesc, hipTextureObject_t textureObject) {
  return hipGetTextureObjectTextureDesc(pTexDesc, textureObject);
}

hipError_t WINAPI wine_hipGetTextureReference(const textureReference** texref, const void* symbol) {
  return hipGetTextureReference(texref, symbol);
}

hipError_t WINAPI wine_hipGraphAddChildGraphNode(hipGraphNode_t* pGraphNode, hipGraph_t graph, const hipGraphNode_t* pDependencies, size_t numDependencies, hipGraph_t childGraph) {
  return hipGraphAddChildGraphNode(pGraphNode, graph, pDependencies, numDependencies, childGraph);
}

hipError_t WINAPI wine_hipGraphAddDependencies(hipGraph_t graph, const hipGraphNode_t* from, const hipGraphNode_t* to, size_t numDependencies) {
  return hipGraphAddDependencies(graph, from, to, numDependencies);
}

hipError_t WINAPI wine_hipGraphAddEmptyNode(hipGraphNode_t* pGraphNode, hipGraph_t graph, const hipGraphNode_t* pDependencies, size_t numDependencies) {
  return hipGraphAddEmptyNode(pGraphNode, graph, pDependencies, numDependencies);
}

hipError_t WINAPI wine_hipGraphAddEventRecordNode(hipGraphNode_t* pGraphNode, hipGraph_t graph, const hipGraphNode_t* pDependencies, size_t numDependencies, hipEvent_t event) {
  return hipGraphAddEventRecordNode(pGraphNode, graph, pDependencies, numDependencies, event);
}

hipError_t WINAPI wine_hipGraphAddEventWaitNode(hipGraphNode_t* pGraphNode, hipGraph_t graph, const hipGraphNode_t* pDependencies, size_t numDependencies, hipEvent_t event) {
  return hipGraphAddEventWaitNode(pGraphNode, graph, pDependencies, numDependencies, event);
}

hipError_t WINAPI wine_hipGraphAddHostNode(hipGraphNode_t* pGraphNode, hipGraph_t graph, const hipGraphNode_t* pDependencies, size_t numDependencies, const hipHostNodeParams* pNodeParams) {
  return hipGraphAddHostNode(pGraphNode, graph, pDependencies, numDependencies, pNodeParams);
}

hipError_t WINAPI wine_hipGraphAddKernelNode(hipGraphNode_t* pGraphNode, hipGraph_t graph, const hipGraphNode_t* pDependencies, size_t numDependencies, const hipKernelNodeParams* pNodeParams) {
  return hipGraphAddKernelNode(pGraphNode, graph, pDependencies, numDependencies, pNodeParams);
}

hipError_t WINAPI wine_hipGraphAddMemAllocNode(hipGraphNode_t* pGraphNode, hipGraph_t graph, const hipGraphNode_t* pDependencies, size_t numDependencies, hipMemAllocNodeParams* pNodeParams) {
  return hipGraphAddMemAllocNode(pGraphNode, graph, pDependencies, numDependencies, pNodeParams);
}

hipError_t WINAPI wine_hipGraphAddMemFreeNode(hipGraphNode_t* pGraphNode, hipGraph_t graph, const hipGraphNode_t* pDependencies, size_t numDependencies, void* dev_ptr) {
  return hipGraphAddMemFreeNode(pGraphNode, graph, pDependencies, numDependencies, dev_ptr);
}

hipError_t WINAPI wine_hipGraphAddMemcpyNode(hipGraphNode_t* pGraphNode, hipGraph_t graph, const hipGraphNode_t* pDependencies, size_t numDependencies, const hipMemcpy3DParms* pCopyParams) {
  return hipGraphAddMemcpyNode(pGraphNode, graph, pDependencies, numDependencies, pCopyParams);
}

hipError_t WINAPI wine_hipGraphAddMemcpyNode1D(hipGraphNode_t* pGraphNode, hipGraph_t graph, const hipGraphNode_t* pDependencies, size_t numDependencies, void* dst, const void* src, size_t count, hipMemcpyKind kind) {
  return hipGraphAddMemcpyNode1D(pGraphNode, graph, pDependencies, numDependencies, dst, src, count, kind);
}

hipError_t WINAPI wine_hipGraphAddMemcpyNodeFromSymbol(hipGraphNode_t* pGraphNode, hipGraph_t graph, const hipGraphNode_t* pDependencies, size_t numDependencies, void* dst, const void* symbol, size_t count, size_t offset, hipMemcpyKind kind) {
  return hipGraphAddMemcpyNodeFromSymbol(pGraphNode, graph, pDependencies, numDependencies, dst, symbol, count, offset, kind);
}

hipError_t WINAPI wine_hipGraphAddMemcpyNodeToSymbol(hipGraphNode_t* pGraphNode, hipGraph_t graph, const hipGraphNode_t* pDependencies, size_t numDependencies, const void* symbol, const void* src, size_t count, size_t offset, hipMemcpyKind kind) {
  return hipGraphAddMemcpyNodeToSymbol(pGraphNode, graph, pDependencies, numDependencies, symbol, src, count, offset, kind);
}

hipError_t WINAPI wine_hipGraphAddMemsetNode(hipGraphNode_t* pGraphNode, hipGraph_t graph, const hipGraphNode_t* pDependencies, size_t numDependencies, const hipMemsetParams* pMemsetParams) {
  return hipGraphAddMemsetNode(pGraphNode, graph, pDependencies, numDependencies, pMemsetParams);
}

hipError_t WINAPI wine_hipGraphChildGraphNodeGetGraph(hipGraphNode_t node, hipGraph_t* pGraph) {
  return hipGraphChildGraphNodeGetGraph(node, pGraph);
}

hipError_t WINAPI wine_hipGraphClone(hipGraph_t* pGraphClone, hipGraph_t originalGraph) {
  return hipGraphClone(pGraphClone, originalGraph);
}

hipError_t WINAPI wine_hipGraphCreate(hipGraph_t* pGraph, unsigned int flags) {
  return hipGraphCreate(pGraph, flags);
}

hipError_t WINAPI wine_hipGraphDebugDotPrint(hipGraph_t graph, const char* path, unsigned int flags) {
  return hipGraphDebugDotPrint(graph, path, flags);
}

hipError_t WINAPI wine_hipGraphDestroy(hipGraph_t graph) {
  return hipGraphDestroy(graph);
}

hipError_t WINAPI wine_hipGraphDestroyNode(hipGraphNode_t node) {
  return hipGraphDestroyNode(node);
}

hipError_t WINAPI wine_hipGraphEventRecordNodeGetEvent(hipGraphNode_t node, hipEvent_t* event_out) {
  return hipGraphEventRecordNodeGetEvent(node, event_out);
}

hipError_t WINAPI wine_hipGraphEventRecordNodeSetEvent(hipGraphNode_t node, hipEvent_t event) {
  return hipGraphEventRecordNodeSetEvent(node, event);
}

hipError_t WINAPI wine_hipGraphEventWaitNodeGetEvent(hipGraphNode_t node, hipEvent_t* event_out) {
  return hipGraphEventWaitNodeGetEvent(node, event_out);
}

hipError_t WINAPI wine_hipGraphEventWaitNodeSetEvent(hipGraphNode_t node, hipEvent_t event) {
  return hipGraphEventWaitNodeSetEvent(node, event);
}

hipError_t WINAPI wine_hipGraphExecChildGraphNodeSetParams(hipGraphExec_t hGraphExec, hipGraphNode_t node, hipGraph_t childGraph) {
  return hipGraphExecChildGraphNodeSetParams(hGraphExec, node, childGraph);
}

hipError_t WINAPI wine_hipGraphExecDestroy(hipGraphExec_t graphExec) {
  return hipGraphExecDestroy(graphExec);
}

hipError_t WINAPI wine_hipGraphExecEventRecordNodeSetEvent(hipGraphExec_t hGraphExec, hipGraphNode_t hNode, hipEvent_t event) {
  return hipGraphExecEventRecordNodeSetEvent(hGraphExec, hNode, event);
}

hipError_t WINAPI wine_hipGraphExecEventWaitNodeSetEvent(hipGraphExec_t hGraphExec, hipGraphNode_t hNode, hipEvent_t event) {
  return hipGraphExecEventWaitNodeSetEvent(hGraphExec, hNode, event);
}

hipError_t WINAPI wine_hipGraphExecHostNodeSetParams(hipGraphExec_t hGraphExec, hipGraphNode_t node, const hipHostNodeParams* pNodeParams) {
  return hipGraphExecHostNodeSetParams(hGraphExec, node, pNodeParams);
}


hipError_t WINAPI wine_hipGraphExecKernelNodeSetParams(hipGraphExec_t hGraphExec, hipGraphNode_t node, const hipKernelNodeParams* pNodeParams) {
  return hipGraphExecKernelNodeSetParams(hGraphExec, node, pNodeParams);
}

hipError_t WINAPI wine_hipGraphExecMemcpyNodeSetParams(hipGraphExec_t hGraphExec, hipGraphNode_t node, hipMemcpy3DParms* pNodeParams) {
  return hipGraphExecMemcpyNodeSetParams(hGraphExec, node, pNodeParams);
}

hipError_t WINAPI wine_hipGraphExecMemcpyNodeSetParams1D(hipGraphExec_t hGraphExec, hipGraphNode_t node, void* dst, const void* src, size_t count, hipMemcpyKind kind) {
  return hipGraphExecMemcpyNodeSetParams1D(hGraphExec, node, dst, src, count, kind);
}

hipError_t WINAPI wine_hipGraphExecMemcpyNodeSetParamsFromSymbol(hipGraphExec_t hGraphExec, hipGraphNode_t node, void* dst, const void* symbol, size_t count, size_t offset, hipMemcpyKind kind) {
  return hipGraphExecMemcpyNodeSetParamsFromSymbol(hGraphExec, node, dst, symbol, count, offset, kind);
}

hipError_t WINAPI wine_hipGraphExecMemcpyNodeSetParamsToSymbol(hipGraphExec_t hGraphExec, hipGraphNode_t node, const void* symbol, const void* src, size_t count, size_t offset, hipMemcpyKind kind) {
  return hipGraphExecMemcpyNodeSetParamsToSymbol(hGraphExec, node, symbol, src, count, offset, kind);
}

hipError_t WINAPI wine_hipGraphExecMemsetNodeSetParams(hipGraphExec_t hGraphExec, hipGraphNode_t node, const hipMemsetParams* pNodeParams) {
  return hipGraphExecMemsetNodeSetParams(hGraphExec, node, pNodeParams);
}

hipError_t WINAPI wine_hipGraphExecUpdate(hipGraphExec_t hGraphExec, hipGraph_t hGraph, hipGraphNode_t* hErrorNode_out, hipGraphExecUpdateResult* updateResult_out) {
  return hipGraphExecUpdate(hGraphExec, hGraph, hErrorNode_out, updateResult_out);
}

hipError_t WINAPI wine_hipGraphGetEdges(hipGraph_t graph, hipGraphNode_t* from, hipGraphNode_t* to, size_t* numEdges) {
  return hipGraphGetEdges(graph, from, to, numEdges);
}

hipError_t WINAPI wine_hipGraphGetNodes(hipGraph_t graph, hipGraphNode_t* nodes, size_t* numNodes) {
  return hipGraphGetNodes(graph, nodes, numNodes);
}

hipError_t WINAPI wine_hipGraphGetRootNodes(hipGraph_t graph, hipGraphNode_t* pRootNodes, size_t* pNumRootNodes) {
  return hipGraphGetRootNodes(graph, pRootNodes, pNumRootNodes);
}

hipError_t WINAPI wine_hipGraphHostNodeGetParams(hipGraphNode_t node, hipHostNodeParams* pNodeParams) {
  return hipGraphHostNodeGetParams(node, pNodeParams);
}

hipError_t WINAPI wine_hipGraphHostNodeSetParams(hipGraphNode_t node, const hipHostNodeParams* pNodeParams) {
  return hipGraphHostNodeSetParams(node, pNodeParams);
}

hipError_t WINAPI wine_hipGraphInstantiate(hipGraphExec_t* pGraphExec, hipGraph_t graph, hipGraphNode_t* pErrorNode, char* pLogBuffer, size_t bufferSize) {
  return hipGraphInstantiate(pGraphExec, graph, pErrorNode, pLogBuffer, bufferSize);
}

hipError_t WINAPI wine_hipGraphInstantiateWithFlags(hipGraphExec_t* pGraphExec, hipGraph_t graph, unsigned long long flags) {
  return hipGraphInstantiateWithFlags(pGraphExec, graph, flags);
}

hipError_t WINAPI wine_hipGraphKernelNodeCopyAttributes(hipGraphNode_t hSrc, hipGraphNode_t hDst) {
  return hipGraphKernelNodeCopyAttributes(hSrc, hDst);
}

hipError_t WINAPI wine_hipGraphKernelNodeGetAttribute(hipGraphNode_t hNode, hipKernelNodeAttrID attr, hipKernelNodeAttrValue* value) {
  return hipGraphKernelNodeGetAttribute(hNode, attr, value);
}

hipError_t WINAPI wine_hipGraphKernelNodeGetParams(hipGraphNode_t node, hipKernelNodeParams* pNodeParams) {
  return hipGraphKernelNodeGetParams(node, pNodeParams);
}

hipError_t WINAPI wine_hipGraphKernelNodeSetAttribute(hipGraphNode_t hNode, hipKernelNodeAttrID attr, const hipKernelNodeAttrValue* value) {
  return hipGraphKernelNodeSetAttribute(hNode, attr, value);
}

hipError_t WINAPI wine_hipGraphKernelNodeSetParams(hipGraphNode_t node, const hipKernelNodeParams* pNodeParams) {
  return hipGraphKernelNodeSetParams(node, pNodeParams);
}

hipError_t WINAPI wine_hipGraphLaunch(hipGraphExec_t graphExec, hipStream_t stream) {
  return hipGraphLaunch(graphExec, stream);
}

hipError_t WINAPI wine_hipGraphLaunch_spt(hipGraphExec_t graphExec, hipStream_t stream) {
  return hipGraphLaunch_spt(graphExec, stream);
}

hipError_t WINAPI wine_hipGraphMemAllocNodeGetParams(hipGraphNode_t node, hipMemAllocNodeParams* pNodeParams) {
  return hipGraphMemAllocNodeGetParams(node, pNodeParams);
}

hipError_t WINAPI wine_hipGraphMemFreeNodeGetParams(hipGraphNode_t node, void* dev_ptr) {
  return hipGraphMemFreeNodeGetParams(node, dev_ptr);
}

hipError_t WINAPI wine_hipGraphMemcpyNodeGetParams(hipGraphNode_t node, hipMemcpy3DParms* pNodeParams) {
  return hipGraphMemcpyNodeGetParams(node, pNodeParams);
}

hipError_t WINAPI wine_hipGraphMemcpyNodeSetParams(hipGraphNode_t node, const hipMemcpy3DParms* pNodeParams) {
  return hipGraphMemcpyNodeSetParams(node, pNodeParams);
}

hipError_t WINAPI wine_hipGraphMemcpyNodeSetParams1D(hipGraphNode_t node, void* dst, const void* src, size_t count, hipMemcpyKind kind) {
  return hipGraphMemcpyNodeSetParams1D(node, dst, src, count, kind);
}

hipError_t WINAPI wine_hipGraphMemcpyNodeSetParamsFromSymbol(hipGraphNode_t node, void* dst, const void* symbol, size_t count, size_t offset, hipMemcpyKind kind) {
  return hipGraphMemcpyNodeSetParamsFromSymbol(node, dst, symbol, count, offset, kind);
}

hipError_t WINAPI wine_hipGraphMemcpyNodeSetParamsToSymbol(hipGraphNode_t node, const void* symbol, const void* src, size_t count, size_t offset, hipMemcpyKind kind) {
  return hipGraphMemcpyNodeSetParamsToSymbol(node, symbol, src, count, offset, kind);
}

hipError_t WINAPI wine_hipGraphMemsetNodeGetParams(hipGraphNode_t node, hipMemsetParams* pNodeParams) {
  return hipGraphMemsetNodeGetParams(node, pNodeParams);
}

hipError_t WINAPI wine_hipGraphMemsetNodeSetParams(hipGraphNode_t node, const hipMemsetParams* pNodeParams) {
  return hipGraphMemsetNodeSetParams(node, pNodeParams);
}

hipError_t WINAPI wine_hipGraphNodeFindInClone(hipGraphNode_t* pNode, hipGraphNode_t originalNode, hipGraph_t clonedGraph) {
  return hipGraphNodeFindInClone(pNode, originalNode, clonedGraph);
}

hipError_t WINAPI wine_hipGraphNodeGetDependencies(hipGraphNode_t node, hipGraphNode_t* pDependencies, size_t* pNumDependencies) {
  return hipGraphNodeGetDependencies(node, pDependencies, pNumDependencies);
}

hipError_t WINAPI wine_hipGraphNodeGetDependentNodes(hipGraphNode_t node, hipGraphNode_t* pDependentNodes, size_t* pNumDependentNodes) {
  return hipGraphNodeGetDependentNodes(node, pDependentNodes, pNumDependentNodes);
}

hipError_t WINAPI wine_hipGraphNodeGetEnabled(hipGraphExec_t hGraphExec, hipGraphNode_t hNode, unsigned int* isEnabled) {
  return hipGraphNodeGetEnabled(hGraphExec, hNode, isEnabled);
}

hipError_t WINAPI wine_hipGraphNodeGetType(hipGraphNode_t node, hipGraphNodeType* pType) {
  return hipGraphNodeGetType(node, pType);
}

hipError_t WINAPI wine_hipGraphNodeSetEnabled(hipGraphExec_t hGraphExec, hipGraphNode_t hNode, unsigned int isEnabled) {
  return hipGraphNodeSetEnabled(hGraphExec, hNode, isEnabled);
}

hipError_t WINAPI wine_hipGraphReleaseUserObject(hipGraph_t graph, hipUserObject_t object, unsigned int count) {
  return hipGraphReleaseUserObject(graph, object, count);
}

hipError_t WINAPI wine_hipGraphRemoveDependencies(hipGraph_t graph, const hipGraphNode_t* from, const hipGraphNode_t* to, size_t numDependencies) {
  return hipGraphRemoveDependencies(graph, from, to, numDependencies);
}

hipError_t WINAPI wine_hipGraphRetainUserObject(hipGraph_t graph, hipUserObject_t object, unsigned int count, unsigned int flags) {
  return hipGraphRetainUserObject(graph, object, count, flags);
}

hipError_t WINAPI wine_hipGraphUpload(hipGraphExec_t graphExec, hipStream_t stream) {
  return hipGraphUpload(graphExec, stream);
}

hipError_t WINAPI wine_hipGraphicsMapResources(int count, hipGraphicsResource_t* resources, hipStream_t stream) {
  return hipGraphicsMapResources(count, resources, stream);
}

hipError_t WINAPI wine_hipGraphicsResourceGetMappedPointer(void** devPtr, size_t* size, hipGraphicsResource_t resource) {
  return hipGraphicsResourceGetMappedPointer(devPtr, size, resource);
}

hipError_t WINAPI wine_hipGraphicsSubResourceGetMappedArray(hipArray_t* array, hipGraphicsResource_t resource, unsigned int arrayIndex, unsigned int mipLevel) {
  return hipGraphicsSubResourceGetMappedArray(array, resource, arrayIndex, mipLevel);
}

hipError_t WINAPI wine_hipGraphicsUnmapResources(int count, hipGraphicsResource_t* resources, hipStream_t stream) {
  return hipGraphicsUnmapResources(count, resources, stream);
}

hipError_t WINAPI wine_hipGraphicsUnregisterResource(hipGraphicsResource_t resource) {
  return hipGraphicsUnregisterResource(resource);
}

hipError_t WINAPI wine_hipHostAlloc(void** ptr, size_t size, unsigned int flags) {
  return hipHostAlloc(ptr, size, flags);
}

hipError_t WINAPI wine_hipHostGetFlags(unsigned int* flagsPtr, void* hostPtr) {
  return hipHostGetFlags(flagsPtr, hostPtr);
}

hipError_t WINAPI wine_hipHostRegister(void* hostPtr, size_t sizeBytes, unsigned int flags) {
  return hipHostRegister(hostPtr, sizeBytes, flags);
}

hipError_t WINAPI wine_hipHostUnregister(void* hostPtr) {
  return hipHostUnregister(hostPtr);
}

hipError_t WINAPI wine_hipImportExternalMemory(hipExternalMemory_t* extMem_out, const hipExternalMemoryHandleDesc* memHandleDesc) {
  return hipImportExternalMemory(extMem_out, memHandleDesc);
}

hipError_t WINAPI wine_hipImportExternalSemaphore(hipExternalSemaphore_t* extSem_out, const hipExternalSemaphoreHandleDesc* semHandleDesc) {
  return hipImportExternalSemaphore(extSem_out, semHandleDesc);
}

hipError_t WINAPI wine_hipIpcCloseMemHandle(void* devPtr) {
  return hipIpcCloseMemHandle(devPtr);
}

hipError_t WINAPI wine_hipIpcGetEventHandle(hipIpcEventHandle_t* handle, hipEvent_t event) {
  return hipIpcGetEventHandle(handle, event);
}

hipError_t WINAPI wine_hipIpcGetMemHandle(hipIpcMemHandle_t* handle, void* devPtr) {
  return hipIpcGetMemHandle(handle, devPtr);
}

hipError_t WINAPI wine_hipIpcOpenEventHandle(hipEvent_t* event, hipIpcEventHandle_t handle) {
  return hipIpcOpenEventHandle(event, handle);
}

hipError_t WINAPI wine_hipIpcOpenMemHandle(void** devPtr, hipIpcMemHandle_t handle, unsigned int flags) {
  return hipIpcOpenMemHandle(devPtr, handle, flags);
}

const char* WINAPI wine_hipKernelNameRef(const hipFunction_t f) {
  return hipKernelNameRef(f);
}

hipError_t WINAPI wine_hipLaunchByPtr(const void* func) {
  return hipLaunchByPtr(func);
}

hipError_t WINAPI wine_hipLaunchCooperativeKernel(const void* f, dim3 gridDim, dim3 blockDimX, void** kernelParams, unsigned int sharedMemBytes, hipStream_t stream) {
  return hipLaunchCooperativeKernel(f, gridDim, blockDimX, kernelParams, sharedMemBytes, stream);
}

hipError_t WINAPI wine_hipLaunchCooperativeKernelMultiDevice(hipLaunchParams* launchParamsList, int numDevices, unsigned int flags) {
  return hipLaunchCooperativeKernelMultiDevice(launchParamsList, numDevices, flags);
}


hipError_t WINAPI wine_hipLaunchCooperativeKernel_spt(const void* f, dim3 gridDim, dim3 blockDim, void** kernelParams, uint32_t sharedMemBytes, hipStream_t hStream) {
  return hipLaunchCooperativeKernel_spt(f, gridDim, blockDim, kernelParams, sharedMemBytes, hStream);
}

hipError_t WINAPI wine_hipLaunchHostFunc(hipStream_t stream, hipHostFn_t fn, void* userData) {
  return hipLaunchHostFunc(stream, fn, userData);
}

hipError_t WINAPI wine_hipLaunchHostFunc_spt(hipStream_t stream, hipHostFn_t fn, void* userData) {
  return hipLaunchHostFunc_spt(stream, fn, userData);
}

hipError_t WINAPI wine_hipLaunchKernel(const void* function_address, dim3 numBlocks, dim3 dimBlocks, void** args, size_t sharedMemBytes, hipStream_t stream) {
  return hipLaunchKernel(function_address, numBlocks, dimBlocks, args, sharedMemBytes, stream);
}

hipError_t WINAPI wine_hipLaunchKernel_spt(const void* function_address, dim3 numBlocks, dim3 dimBlocks, void** args, size_t sharedMemBytes, hipStream_t stream) {
  return hipLaunchKernel_spt(function_address, numBlocks, dimBlocks, args, sharedMemBytes, stream);
}

hipError_t WINAPI wine_hipMalloc3D(hipPitchedPtr* pitchedDevPtr, hipExtent extent) {
  return hipMalloc3D(pitchedDevPtr, extent);
}

hipError_t WINAPI wine_hipMalloc3DArray(hipArray_t* array, const struct hipChannelFormatDesc* desc, struct hipExtent extent, unsigned int flags) {
  return hipMalloc3DArray(array, desc, extent, flags);
}

hipError_t WINAPI wine_hipMallocArray(hipArray_t* array, const hipChannelFormatDesc* desc, size_t width, size_t height, unsigned int flags) {
  return hipMallocArray(array, desc, width, height, flags);
}

hipError_t WINAPI wine_hipMallocAsync(void** dev_ptr, size_t size, hipStream_t stream) {
  return hipMallocAsync(dev_ptr, size, stream);
}

hipError_t WINAPI wine_hipMallocFromPoolAsync(void** dev_ptr, size_t size, hipMemPool_t mem_pool, hipStream_t stream) {
  return hipMallocFromPoolAsync(dev_ptr, size, mem_pool, stream);
}

hipError_t WINAPI wine_hipMallocHost(void** ptr, size_t size) {
  return hipMallocHost(ptr, size);
}

hipError_t WINAPI wine_hipMallocManaged(void** dev_ptr, size_t size, unsigned int flags) {
  return hipMallocManaged(dev_ptr, size, flags);
}

hipError_t WINAPI wine_hipMallocMipmappedArray(hipMipmappedArray_t* mipmappedArray, const struct hipChannelFormatDesc* desc, struct hipExtent extent, unsigned int numLevels, unsigned int flags) {
  return hipMallocMipmappedArray(mipmappedArray, desc, extent, numLevels, flags);
}

hipError_t WINAPI wine_hipMallocPitch(void** ptr, size_t* pitch, size_t width, size_t height) {
  return hipMallocPitch(ptr, pitch, width, height);
}

hipError_t WINAPI wine_hipMemAddressFree(void* devPtr, size_t size) {
  return hipMemAddressFree(devPtr, size);
}

hipError_t WINAPI wine_hipMemAddressReserve(void** ptr, size_t size, size_t alignment, void* addr, unsigned long long flags) {
  return hipMemAddressReserve(ptr, size, alignment, addr, flags);
}

hipError_t WINAPI wine_hipMemAdvise(const void* dev_ptr, size_t count, hipMemoryAdvise advice, int device) {
  return hipMemAdvise(dev_ptr, count, advice, device);
}

hipError_t WINAPI wine_hipMemAllocHost(void** ptr, size_t size) {
  return hipMemAllocHost(ptr, size);
}

hipError_t WINAPI wine_hipMemAllocPitch(hipDeviceptr_t* dptr, size_t* pitch, size_t widthInBytes, size_t height, unsigned int elementSizeBytes) {
  return hipMemAllocPitch(dptr, pitch, widthInBytes, height, elementSizeBytes);
}

hipError_t WINAPI wine_hipMemCreate(hipMemGenericAllocationHandle_t* handle, size_t size, const hipMemAllocationProp* prop, unsigned long long flags) {
  return hipMemCreate(handle, size, prop, flags);
}

hipError_t WINAPI wine_hipMemExportToShareableHandle(void* shareableHandle, hipMemGenericAllocationHandle_t handle, hipMemAllocationHandleType handleType, unsigned long long flags) {
  return hipMemExportToShareableHandle(shareableHandle, handle, handleType, flags);
}

hipError_t WINAPI wine_hipMemGetAccess(unsigned long long* flags, const hipMemLocation* location, void* ptr) {
  return hipMemGetAccess(flags, location, ptr);
}

hipError_t WINAPI wine_hipMemGetAddressRange(hipDeviceptr_t* pbase, size_t* psize, hipDeviceptr_t dptr) {
  return hipMemGetAddressRange(pbase, psize, dptr);
}

hipError_t WINAPI wine_hipMemGetAllocationGranularity(size_t* granularity, const hipMemAllocationProp* prop, hipMemAllocationGranularity_flags option) {
  return hipMemGetAllocationGranularity(granularity, prop, option);
}

hipError_t WINAPI wine_hipMemGetAllocationPropertiesFromHandle(hipMemAllocationProp* prop, hipMemGenericAllocationHandle_t handle) {
  return hipMemGetAllocationPropertiesFromHandle(prop, handle);
}

hipError_t WINAPI wine_hipMemImportFromShareableHandle(hipMemGenericAllocationHandle_t* handle, void* osHandle, hipMemAllocationHandleType shHandleType) {
  return hipMemImportFromShareableHandle(handle, osHandle, shHandleType);
}

hipError_t WINAPI wine_hipMemMap(void* ptr, size_t size, size_t offset, hipMemGenericAllocationHandle_t handle, unsigned long long flags) {
  return hipMemMap(ptr, size, offset, handle, flags);
}

hipError_t WINAPI wine_hipMemMapArrayAsync(hipArrayMapInfo* mapInfoList, unsigned int count, hipStream_t stream) {
  return hipMemMapArrayAsync(mapInfoList, count, stream);
}

hipError_t WINAPI wine_hipMemPoolCreate(hipMemPool_t* mem_pool, const hipMemPoolProps* pool_props) {
  return hipMemPoolCreate(mem_pool, pool_props);
}

hipError_t WINAPI wine_hipMemPoolDestroy(hipMemPool_t mem_pool) {
  return hipMemPoolDestroy(mem_pool);
}

hipError_t WINAPI wine_hipMemPoolExportPointer(hipMemPoolPtrExportData* export_data, void* dev_ptr) {
  return hipMemPoolExportPointer(export_data, dev_ptr);
}

hipError_t WINAPI wine_hipMemPoolExportToShareableHandle(void* shared_handle, hipMemPool_t mem_pool, hipMemAllocationHandleType handle_type, unsigned int flags) {
  return hipMemPoolExportToShareableHandle(shared_handle, mem_pool, handle_type, flags);
}

hipError_t WINAPI wine_hipMemPoolGetAccess(hipMemAccessFlags* flags, hipMemPool_t mem_pool, hipMemLocation* location) {
  return hipMemPoolGetAccess(flags, mem_pool, location);
}

hipError_t WINAPI wine_hipMemPoolGetAttribute(hipMemPool_t mem_pool, hipMemPoolAttr attr, void* value) {
  return hipMemPoolGetAttribute(mem_pool, attr, value);
}

hipError_t WINAPI wine_hipMemPoolImportFromShareableHandle(hipMemPool_t* mem_pool, void* shared_handle, hipMemAllocationHandleType handle_type, unsigned int flags) {
  return hipMemPoolImportFromShareableHandle(mem_pool, shared_handle, handle_type, flags);
}

hipError_t WINAPI wine_hipMemPoolImportPointer(void** dev_ptr, hipMemPool_t mem_pool, hipMemPoolPtrExportData* export_data) {
  return hipMemPoolImportPointer(dev_ptr, mem_pool, export_data);
}

hipError_t WINAPI wine_hipMemPoolSetAccess(hipMemPool_t mem_pool, const hipMemAccessDesc* desc_list, size_t count) {
  return hipMemPoolSetAccess(mem_pool, desc_list, count);
}

hipError_t WINAPI wine_hipMemPoolSetAttribute(hipMemPool_t mem_pool, hipMemPoolAttr attr, void* value) {
  return hipMemPoolSetAttribute(mem_pool, attr, value);
}

hipError_t WINAPI wine_hipMemPoolTrimTo(hipMemPool_t mem_pool, size_t min_bytes_to_hold) {
  return hipMemPoolTrimTo(mem_pool, min_bytes_to_hold);
}

hipError_t WINAPI wine_hipMemPrefetchAsync(const void* dev_ptr, size_t count, int device, hipStream_t stream) {
  return hipMemPrefetchAsync(dev_ptr, count, device, stream);
}

hipError_t WINAPI wine_hipMemPtrGetInfo(void* ptr, size_t* size) {
  return hipMemPtrGetInfo(ptr, size);
}

hipError_t WINAPI wine_hipMemRangeGetAttribute(void* data, size_t data_size, hipMemRangeAttribute attribute, const void* dev_ptr, size_t count) {
  return hipMemRangeGetAttribute(data, data_size, attribute, dev_ptr, count);
}

hipError_t WINAPI wine_hipMemRangeGetAttributes(void** data, size_t* data_sizes, hipMemRangeAttribute* attributes, size_t num_attributes, const void* dev_ptr, size_t count) {
  return hipMemRangeGetAttributes(data, data_sizes, attributes, num_attributes, dev_ptr, count);
}

hipError_t WINAPI wine_hipMemRelease(hipMemGenericAllocationHandle_t handle) {
  return hipMemRelease(handle);
}

hipError_t WINAPI wine_hipMemRetainAllocationHandle(hipMemGenericAllocationHandle_t* handle, void* addr) {
  return hipMemRetainAllocationHandle(handle, addr);
}

hipError_t WINAPI wine_hipMemSetAccess(void* ptr, size_t size, const hipMemAccessDesc* desc, size_t count) {
  return hipMemSetAccess(ptr, size, desc, count);
}

hipError_t WINAPI wine_hipMemUnmap(void* ptr, size_t size) {
  return hipMemUnmap(ptr, size);
}

hipError_t WINAPI wine_hipMemcpy2D(void* dst, size_t dpitch, const void* src, size_t spitch, size_t width, size_t height, hipMemcpyKind kind) {
  return hipMemcpy2D(dst, dpitch, src, spitch, width, height, kind);
}

hipError_t WINAPI wine_hipMemcpy2DAsync(void* dst, size_t dpitch, const void* src, size_t spitch, size_t width, size_t height, hipMemcpyKind kind, hipStream_t stream) {
  return hipMemcpy2DAsync(dst, dpitch, src, spitch, width, height, kind, stream);
}

hipError_t WINAPI wine_hipMemcpy2DAsync_spt(void* dst, size_t dpitch, const void* src, size_t spitch, size_t width, size_t height, hipMemcpyKind kind, hipStream_t stream) {
  return hipMemcpy2DAsync_spt(dst, dpitch, src, spitch, width, height, kind, stream);
}

hipError_t WINAPI wine_hipMemcpy2DFromArray(void* dst, size_t dpitch, hipArray_const_t src, size_t wOffset, size_t hOffset, size_t width, size_t height, hipMemcpyKind kind) {
  return hipMemcpy2DFromArray(dst, dpitch, src, wOffset, hOffset, width, height, kind);
}

hipError_t WINAPI wine_hipMemcpy2DFromArrayAsync(void* dst, size_t dpitch, hipArray_const_t src, size_t wOffset, size_t hOffset, size_t width, size_t height, hipMemcpyKind kind, hipStream_t stream) {
  return hipMemcpy2DFromArrayAsync(dst, dpitch, src, wOffset, hOffset, width, height, kind, stream);
}

hipError_t WINAPI wine_hipMemcpy2DFromArrayAsync_spt(void* dst, size_t dpitch, hipArray_const_t src, size_t wOffsetSrc, size_t hOffsetSrc, size_t width, size_t height, hipMemcpyKind kind, hipStream_t stream) {
  return hipMemcpy2DFromArrayAsync_spt(dst, dpitch, src, wOffsetSrc, hOffsetSrc, width, height, kind, stream);
}

hipError_t WINAPI wine_hipMemcpy2DFromArray_spt(void* dst, size_t dpitch, hipArray_const_t src, size_t wOffset, size_t hOffset, size_t width, size_t height, hipMemcpyKind kind) {
  return hipMemcpy2DFromArray_spt(dst, dpitch, src, wOffset, hOffset, width, height, kind);
}

hipError_t WINAPI wine_hipMemcpy2DToArray(hipArray_t dst, size_t wOffset, size_t hOffset, const void* src, size_t spitch, size_t width, size_t height, hipMemcpyKind kind) {
  return hipMemcpy2DToArray(dst, wOffset, hOffset, src, spitch, width, height, kind);
}

hipError_t WINAPI wine_hipMemcpy2DToArrayAsync(hipArray_t dst, size_t wOffset, size_t hOffset, const void* src, size_t spitch, size_t width, size_t height, hipMemcpyKind kind, hipStream_t stream) {
  return hipMemcpy2DToArrayAsync(dst, wOffset, hOffset, src, spitch, width, height, kind, stream);
}

hipError_t WINAPI wine_hipMemcpy2DToArrayAsync_spt(hipArray_t dst, size_t wOffset, size_t hOffset, const void* src, size_t spitch, size_t width, size_t height, hipMemcpyKind kind, hipStream_t stream) {
  return hipMemcpy2DToArrayAsync_spt(dst, wOffset, hOffset, src, spitch, width, height, kind, stream);
}

hipError_t WINAPI wine_hipMemcpy2DToArray_spt(hipArray_t dst, size_t wOffset, size_t hOffset, const void* src, size_t spitch, size_t width, size_t height, hipMemcpyKind kind) {
  return hipMemcpy2DToArray_spt(dst, wOffset, hOffset, src, spitch, width, height, kind);
}

hipError_t WINAPI wine_hipMemcpy2D_spt(void* dst, size_t dpitch, const void* src, size_t spitch, size_t width, size_t height, hipMemcpyKind kind) {
  return hipMemcpy2D_spt(dst, dpitch, src, spitch, width, height, kind);
}

hipError_t WINAPI wine_hipMemcpy3D(const struct hipMemcpy3DParms* p) {
  return hipMemcpy3D(p);
}


hipError_t WINAPI wine_hipMemcpy3DAsync(const struct hipMemcpy3DParms* p, hipStream_t stream) {
  return hipMemcpy3DAsync(p, stream);
}

hipError_t WINAPI wine_hipMemcpy3DAsync_spt(const hipMemcpy3DParms* p, hipStream_t stream) {
  return hipMemcpy3DAsync_spt(p, stream);
}

hipError_t WINAPI wine_hipMemcpy3D_spt(const struct hipMemcpy3DParms* p) {
  return hipMemcpy3D_spt(p);
}

hipError_t WINAPI wine_hipMemcpyAsync_spt(void* dst, const void* src, size_t sizeBytes, hipMemcpyKind kind, hipStream_t stream) {
  return hipMemcpyAsync_spt(dst, src, sizeBytes, kind, stream);
}

hipError_t WINAPI wine_hipMemcpyAtoH(void* dst, hipArray_t srcArray, size_t srcOffset, size_t count) {
  return hipMemcpyAtoH(dst, srcArray, srcOffset, count);
}

hipError_t WINAPI wine_hipMemcpyDtoD(hipDeviceptr_t dst, hipDeviceptr_t src, size_t sizeBytes) {
  return hipMemcpyDtoD(dst, src, sizeBytes);
}

hipError_t WINAPI wine_hipMemcpyFromArray(void* dst, hipArray_const_t srcArray, size_t wOffset, size_t hOffset, size_t count, hipMemcpyKind kind) {
  return hipMemcpyFromArray(dst, srcArray, wOffset, hOffset, count, kind);
}

hipError_t WINAPI wine_hipMemcpyFromArray_spt(void* dst, hipArray_const_t src, size_t wOffsetSrc, size_t hOffset, size_t count, hipMemcpyKind kind) {
  return hipMemcpyFromArray_spt(dst, src, wOffsetSrc, hOffset, count, kind);
}

hipError_t WINAPI wine_hipMemcpyFromSymbol(void* dst, const void* symbol, size_t sizeBytes, size_t offset, hipMemcpyKind kind) {
  return hipMemcpyFromSymbol(dst, symbol, sizeBytes, offset, kind);
}

hipError_t WINAPI wine_hipMemcpyFromSymbolAsync(void* dst, const void* symbol, size_t sizeBytes, size_t offset, hipMemcpyKind kind, hipStream_t stream) {
  return hipMemcpyFromSymbolAsync(dst, symbol, sizeBytes, offset, kind, stream);
}

hipError_t WINAPI wine_hipMemcpyFromSymbolAsync_spt(void* dst, const void* symbol, size_t sizeBytes, size_t offset, hipMemcpyKind kind, hipStream_t stream) {
  return hipMemcpyFromSymbolAsync_spt(dst, symbol, sizeBytes, offset, kind, stream);
}

hipError_t WINAPI wine_hipMemcpyFromSymbol_spt(void* dst, const void* symbol, size_t sizeBytes, size_t offset, hipMemcpyKind kind) {
  return hipMemcpyFromSymbol_spt(dst, symbol, sizeBytes, offset, kind);
}

hipError_t WINAPI wine_hipMemcpyHtoA(hipArray_t dstArray, size_t dstOffset, const void* srcHost, size_t count) {
  return hipMemcpyHtoA(dstArray, dstOffset, srcHost, count);
}

hipError_t WINAPI wine_hipMemcpyPeer(void* dst, int dstDeviceId, const void* src, int srcDeviceId, size_t sizeBytes) {
  return hipMemcpyPeer(dst, dstDeviceId, src, srcDeviceId, sizeBytes);
}

hipError_t WINAPI wine_hipMemcpyPeerAsync(void* dst, int dstDeviceId, const void* src, int srcDevice, size_t sizeBytes, hipStream_t stream) {
  return hipMemcpyPeerAsync(dst, dstDeviceId, src, srcDevice, sizeBytes, stream);
}

hipError_t WINAPI wine_hipMemcpyToArray(hipArray_t dst, size_t wOffset, size_t hOffset, const void* src, size_t count, hipMemcpyKind kind) {
  return hipMemcpyToArray(dst, wOffset, hOffset, src, count, kind);
}

hipError_t WINAPI wine_hipMemcpyToSymbol(const void* symbol, const void* src, size_t sizeBytes, size_t offset, hipMemcpyKind kind) {
  return hipMemcpyToSymbol(symbol, src, sizeBytes, offset, kind);
}

hipError_t WINAPI wine_hipMemcpyToSymbolAsync(const void* symbol, const void* src, size_t sizeBytes, size_t offset, hipMemcpyKind kind, hipStream_t stream) {
  return hipMemcpyToSymbolAsync(symbol, src, sizeBytes, offset, kind, stream);
}

hipError_t WINAPI wine_hipMemcpyToSymbolAsync_spt(const void* symbol, const void* src, size_t sizeBytes, size_t offset, hipMemcpyKind kind, hipStream_t stream) {
  return hipMemcpyToSymbolAsync_spt(symbol, src, sizeBytes, offset, kind, stream);
}

hipError_t WINAPI wine_hipMemcpyToSymbol_spt(const void* symbol, const void* src, size_t sizeBytes, size_t offset, hipMemcpyKind kind) {
  return hipMemcpyToSymbol_spt(symbol, src, sizeBytes, offset, kind);
}

hipError_t WINAPI wine_hipMemcpyWithStream(void* dst, const void* src, size_t sizeBytes, hipMemcpyKind kind, hipStream_t stream) {
  return hipMemcpyWithStream(dst, src, sizeBytes, kind, stream);
}

hipError_t WINAPI wine_hipMemcpy_spt(void* dst, const void* src, size_t sizeBytes, hipMemcpyKind kind) {
  return hipMemcpy_spt(dst, src, sizeBytes, kind);
}

hipError_t WINAPI wine_hipMemset(void* dst, int value, size_t sizeBytes) {
  return hipMemset(dst, value, sizeBytes);
}

hipError_t WINAPI wine_hipMemset2D(void* dst, size_t pitch, int value, size_t width, size_t height) {
  return hipMemset2D(dst, pitch, value, width, height);
}

hipError_t WINAPI wine_hipMemset2DAsync(void* dst, size_t pitch, int value, size_t width, size_t height, hipStream_t stream) {
  return hipMemset2DAsync(dst, pitch, value, width, height, stream);
}

hipError_t WINAPI wine_hipMemset2DAsync_spt(void* dst, size_t pitch, int value, size_t width, size_t height, hipStream_t stream) {
  return hipMemset2DAsync_spt(dst, pitch, value, width, height, stream);
}

hipError_t WINAPI wine_hipMemset2D_spt(void* dst, size_t pitch, int value, size_t width, size_t height) {
  return hipMemset2D_spt(dst, pitch, value, width, height);
}

hipError_t WINAPI wine_hipMemset3D(hipPitchedPtr pitchedDevPtr, int value, hipExtent extent) {
  return hipMemset3D(pitchedDevPtr, value, extent);
}

hipError_t WINAPI wine_hipMemset3DAsync(hipPitchedPtr pitchedDevPtr, int value, hipExtent extent, hipStream_t stream) {
  return hipMemset3DAsync(pitchedDevPtr, value, extent, stream);
}

hipError_t WINAPI wine_hipMemset3DAsync_spt(hipPitchedPtr pitchedDevPtr, int value, hipExtent extent, hipStream_t stream) {
  return hipMemset3DAsync_spt(pitchedDevPtr, value, extent, stream);
}

hipError_t WINAPI wine_hipMemset3D_spt(hipPitchedPtr pitchedDevPtr, int value, hipExtent extent) {
  return hipMemset3D_spt(pitchedDevPtr, value, extent);
}

hipError_t WINAPI wine_hipMemsetAsync(void* dst, int value, size_t sizeBytes, hipStream_t stream) {
  return hipMemsetAsync(dst, value, sizeBytes, stream);
}

hipError_t WINAPI wine_hipMemsetAsync_spt(void* dst, int value, size_t sizeBytes, hipStream_t stream) {
  return hipMemsetAsync_spt(dst, value, sizeBytes, stream);
}

hipError_t WINAPI wine_hipMemsetD16(hipDeviceptr_t dest, unsigned short value, size_t count) {
  return hipMemsetD16(dest, value, count);
}

hipError_t WINAPI wine_hipMemsetD16Async(hipDeviceptr_t dest, unsigned short value, size_t count, hipStream_t stream) {
  return hipMemsetD16Async(dest, value, count, stream);
}

hipError_t WINAPI wine_hipMemsetD32(hipDeviceptr_t dest, int value, size_t count) {
  return hipMemsetD32(dest, value, count);
}

hipError_t WINAPI wine_hipMemsetD32Async(hipDeviceptr_t dst, int value, size_t count, hipStream_t stream) {
  return hipMemsetD32Async(dst, value, count, stream);
}

hipError_t WINAPI wine_hipMemset_spt(void* dst, int value, size_t sizeBytes) {
  return hipMemset_spt(dst, value, sizeBytes);
}

hipError_t WINAPI wine_hipMipmappedArrayCreate(hipMipmappedArray_t* pHandle, HIP_ARRAY3D_DESCRIPTOR* pMipmappedArrayDesc, unsigned int numMipmapLevels) {
  return hipMipmappedArrayCreate(pHandle, pMipmappedArrayDesc, numMipmapLevels);
}

hipError_t WINAPI wine_hipMipmappedArrayDestroy(hipMipmappedArray_t hMipmappedArray) {
  return hipMipmappedArrayDestroy(hMipmappedArray);
}

hipError_t WINAPI wine_hipMipmappedArrayGetLevel(hipArray_t* pLevelArray, hipMipmappedArray_t hMipMappedArray, unsigned int level) {
  return hipMipmappedArrayGetLevel(pLevelArray, hMipMappedArray, level);
}

hipError_t WINAPI wine_hipModuleLaunchCooperativeKernel(hipFunction_t f, unsigned int gridDimX, unsigned int gridDimY, unsigned int gridDimZ, unsigned int blockDimX, unsigned int blockDimY, unsigned int blockDimZ, unsigned int sharedMemBytes, hipStream_t stream, void** kernelParams) {
  return hipModuleLaunchCooperativeKernel(f, gridDimX, gridDimY, gridDimZ, blockDimX, blockDimY, blockDimZ, sharedMemBytes, stream, kernelParams);
}

hipError_t WINAPI wine_hipModuleLaunchCooperativeKernelMultiDevice(hipFunctionLaunchParams* launchParamsList, unsigned int numDevices, unsigned int flags) {
  return hipModuleLaunchCooperativeKernelMultiDevice(launchParamsList, numDevices, flags);
}

hipError_t WINAPI wine_hipModuleLoad(hipModule_t* module, const char* fname) {
  return hipModuleLoad(module, fname);
}

hipError_t WINAPI wine_hipModuleLoadDataEx(hipModule_t* module, const void* image, unsigned int numOptions, hipJitOption* options, void** optionValues) {
  return hipModuleLoadDataEx(module, image, numOptions, options, optionValues);
}

hipError_t WINAPI wine_hipModuleOccupancyMaxActiveBlocksPerMultiprocessor(int* numBlocks, hipFunction_t f, int blockSize, size_t dynSharedMemPerBlk) {
  return hipModuleOccupancyMaxActiveBlocksPerMultiprocessor(numBlocks, f, blockSize, dynSharedMemPerBlk);
}

hipError_t WINAPI wine_hipModuleOccupancyMaxActiveBlocksPerMultiprocessorWithFlags(int* numBlocks, hipFunction_t f, int blockSize, size_t dynSharedMemPerBlk, unsigned int flags) {
  return hipModuleOccupancyMaxActiveBlocksPerMultiprocessorWithFlags(numBlocks, f, blockSize, dynSharedMemPerBlk, flags);
}

hipError_t WINAPI wine_hipModuleOccupancyMaxPotentialBlockSize(int* gridSize, int* blockSize, hipFunction_t f, size_t dynSharedMemPerBlk, int blockSizeLimit) {
  return hipModuleOccupancyMaxPotentialBlockSize(gridSize, blockSize, f, dynSharedMemPerBlk, blockSizeLimit);
}

hipError_t WINAPI wine_hipModuleOccupancyMaxPotentialBlockSizeWithFlags(int* gridSize, int* blockSize, hipFunction_t f, size_t dynSharedMemPerBlk, int blockSizeLimit, unsigned int flags) {
  return hipModuleOccupancyMaxPotentialBlockSizeWithFlags(gridSize, blockSize, f, dynSharedMemPerBlk, blockSizeLimit, flags);
}

hipError_t WINAPI wine_hipOccupancyMaxActiveBlocksPerMultiprocessor(int* numBlocks, const void* f, int blockSize, size_t dynSharedMemPerBlk) {
  return hipOccupancyMaxActiveBlocksPerMultiprocessor(numBlocks, f, blockSize, dynSharedMemPerBlk);
}

hipError_t WINAPI wine_hipOccupancyMaxActiveBlocksPerMultiprocessorWithFlags(int* numBlocks, const void* f, int blockSize, size_t dynSharedMemPerBlk, unsigned int flags) {
  return hipOccupancyMaxActiveBlocksPerMultiprocessorWithFlags(numBlocks, f, blockSize, dynSharedMemPerBlk, flags);
}

hipError_t WINAPI wine_hipOccupancyMaxPotentialBlockSize(int* gridSize, int* blockSize, const void* f, size_t dynSharedMemPerBlk, int blockSizeLimit) {
  return hipOccupancyMaxPotentialBlockSize(gridSize, blockSize, f, dynSharedMemPerBlk, blockSizeLimit);
}

hipError_t WINAPI wine_hipPeekAtLastError(void) {
  return hipPeekAtLastError();
}

hipError_t WINAPI wine_hipPointerGetAttribute(void* data, hipPointer_attribute attribute, hipDeviceptr_t ptr) {
  return hipPointerGetAttribute(data, attribute, ptr);
}

hipError_t WINAPI wine_hipPointerGetAttributes(hipPointerAttribute_t* attributes, const void* ptr) {
  return hipPointerGetAttributes(attributes, ptr);
}

hipError_t WINAPI wine_hipProfilerStart(void) {
  return hipProfilerStart();
}

hipError_t WINAPI wine_hipProfilerStop(void) {
  return hipProfilerStop();
}

hipError_t WINAPI wine_hipSetDeviceFlags(unsigned flags) {
  return hipSetDeviceFlags(flags);
}

hipError_t WINAPI wine_hipSetupArgument(const void* arg, size_t size, size_t offset) {
  return hipSetupArgument(arg, size, offset);
}

hipError_t WINAPI wine_hipSignalExternalSemaphoresAsync(const hipExternalSemaphore_t* extSemArray, const hipExternalSemaphoreSignalParams* paramsArray, unsigned int numExtSems, hipStream_t stream) {
  return hipSignalExternalSemaphoresAsync(extSemArray, paramsArray, numExtSems, stream);
}


hipError_t WINAPI wine_hipStreamAddCallback(hipStream_t stream, hipStreamCallback_t callback, void* userData, unsigned int flags) {
  return hipStreamAddCallback(stream, callback, userData, flags);
}

hipError_t WINAPI wine_hipStreamAddCallback_spt(hipStream_t stream, hipStreamCallback_t callback, void* userData, unsigned int flags) {
  return hipStreamAddCallback_spt(stream, callback, userData, flags);
}

hipError_t WINAPI wine_hipStreamAttachMemAsync(hipStream_t stream, void* dev_ptr, size_t length, unsigned int flags) {
  return hipStreamAttachMemAsync(stream, dev_ptr, length, flags);
}

hipError_t WINAPI wine_hipStreamBeginCapture(hipStream_t stream, hipStreamCaptureMode mode) {
  return hipStreamBeginCapture(stream, mode);
}

hipError_t WINAPI wine_hipStreamBeginCapture_spt(hipStream_t stream, hipStreamCaptureMode mode) {
  return hipStreamBeginCapture_spt(stream, mode);
}

hipError_t WINAPI wine_hipStreamCreateWithPriority(hipStream_t* stream, unsigned int flags, int priority) {
  return hipStreamCreateWithPriority(stream, flags, priority);
}

hipError_t WINAPI wine_hipStreamEndCapture(hipStream_t stream, hipGraph_t* pGraph) {
  return hipStreamEndCapture(stream, pGraph);
}

hipError_t WINAPI wine_hipStreamEndCapture_spt(hipStream_t stream, hipGraph_t* pGraph) {
  return hipStreamEndCapture_spt(stream, pGraph);
}

hipError_t WINAPI wine_hipStreamGetCaptureInfo(hipStream_t stream, hipStreamCaptureStatus* pCaptureStatus, unsigned long long* pId) {
  return hipStreamGetCaptureInfo(stream, pCaptureStatus, pId);
}

hipError_t WINAPI wine_hipStreamGetCaptureInfo_spt(hipStream_t stream, hipStreamCaptureStatus* pCaptureStatus, unsigned long long* pId) {
  return hipStreamGetCaptureInfo_spt(stream, pCaptureStatus, pId);
}

hipError_t WINAPI wine_hipStreamGetCaptureInfo_v2(hipStream_t stream, hipStreamCaptureStatus* captureStatus_out, unsigned long long* id_out, hipGraph_t* graph_out, const hipGraphNode_t** dependencies_out, size_t* numDependencies_out) {
  return hipStreamGetCaptureInfo_v2(stream, captureStatus_out, id_out, graph_out, dependencies_out, numDependencies_out);
}

hipError_t WINAPI wine_hipStreamGetCaptureInfo_v2_spt(hipStream_t stream, hipStreamCaptureStatus* captureStatus_out, unsigned long long* id_out, hipGraph_t* graph_out, const hipGraphNode_t** dependencies_out, size_t* numDependencies_out) {
  return hipStreamGetCaptureInfo_v2_spt(stream, captureStatus_out, id_out, graph_out, dependencies_out, numDependencies_out);
}

hipError_t WINAPI wine_hipStreamGetDevice(hipStream_t stream, hipDevice_t* device) {
  return hipStreamGetDevice(stream, device);
}

hipError_t WINAPI wine_hipStreamGetFlags(hipStream_t stream, unsigned int* flags) {
  return hipStreamGetFlags(stream, flags);
}

hipError_t WINAPI wine_hipStreamGetFlags_spt(hipStream_t stream, unsigned int* flags) {
  return hipStreamGetFlags_spt(stream, flags);
}

hipError_t WINAPI wine_hipStreamGetPriority(hipStream_t stream, int* priority) {
  return hipStreamGetPriority(stream, priority);
}

hipError_t WINAPI wine_hipStreamGetPriority_spt(hipStream_t stream, int* priority) {
  return hipStreamGetPriority_spt(stream, priority);
}

hipError_t WINAPI wine_hipStreamIsCapturing_spt(hipStream_t stream, hipStreamCaptureStatus* pCaptureStatus) {
  return hipStreamIsCapturing_spt(stream, pCaptureStatus);
}

hipError_t WINAPI wine_hipStreamQuery_spt(hipStream_t stream) {
  return hipStreamQuery_spt(stream);
}

hipError_t WINAPI wine_hipStreamSynchronize_spt(hipStream_t stream) {
  return hipStreamSynchronize_spt(stream);
}

hipError_t WINAPI wine_hipStreamUpdateCaptureDependencies(hipStream_t stream, hipGraphNode_t* dependencies, size_t numDependencies, unsigned int flags) {
  return hipStreamUpdateCaptureDependencies(stream, dependencies, numDependencies, flags);
}

hipError_t WINAPI wine_hipStreamWaitEvent_spt(hipStream_t stream, hipEvent_t event, unsigned int flags) {
  return hipStreamWaitEvent_spt(stream, event, flags);
}

hipError_t WINAPI wine_hipStreamWaitValue32(hipStream_t stream, void* ptr, uint32_t value, unsigned int flags, uint32_t mask) {
  return hipStreamWaitValue32(stream, ptr, value, flags, mask);
}

hipError_t WINAPI wine_hipStreamWaitValue64(hipStream_t stream, void* ptr, uint64_t value, unsigned int flags, uint64_t mask) {
  return hipStreamWaitValue64(stream, ptr, value, flags, mask);
}

hipError_t WINAPI wine_hipStreamWriteValue32(hipStream_t stream, void* ptr, uint32_t value, unsigned int flags) {
  return hipStreamWriteValue32(stream, ptr, value, flags);
}

hipError_t WINAPI wine_hipStreamWriteValue64(hipStream_t stream, void* ptr, uint64_t value, unsigned int flags) {
  return hipStreamWriteValue64(stream, ptr, value, flags);
}

hipError_t WINAPI wine_hipTexObjectDestroy(hipTextureObject_t texObject) {
  return hipTexObjectDestroy(texObject);
}

hipError_t WINAPI wine_hipTexObjectGetResourceDesc(HIP_RESOURCE_DESC* pResDesc, hipTextureObject_t texObject) {
  return hipTexObjectGetResourceDesc(pResDesc, texObject);
}

hipError_t WINAPI wine_hipTexObjectGetResourceViewDesc(HIP_RESOURCE_VIEW_DESC* pResViewDesc, hipTextureObject_t texObject) {
  return hipTexObjectGetResourceViewDesc(pResViewDesc, texObject);
}

hipError_t WINAPI wine_hipTexObjectGetTextureDesc(HIP_TEXTURE_DESC* pTexDesc, hipTextureObject_t texObject) {
  return hipTexObjectGetTextureDesc(pTexDesc, texObject);
}

hipError_t WINAPI wine_hipTexRefGetAddress(hipDeviceptr_t* dev_ptr, const textureReference* texRef) {
  return hipTexRefGetAddress(dev_ptr, texRef);
}

hipError_t WINAPI wine_hipTexRefGetAddressMode(enum hipTextureAddressMode* pam, const textureReference* texRef, int dim) {
  return hipTexRefGetAddressMode(pam, texRef, dim);
}

hipError_t WINAPI wine_hipTexRefGetFilterMode(enum hipTextureFilterMode* pfm, const textureReference* texRef) {
  return hipTexRefGetFilterMode(pfm, texRef);
}

hipError_t WINAPI wine_hipTexRefGetFlags(unsigned int* pFlags, const textureReference* texRef) {
  return hipTexRefGetFlags(pFlags, texRef);
}

hipError_t WINAPI wine_hipTexRefGetFormat(hipArray_Format* pFormat, int* pNumChannels, const textureReference* texRef) {
  return hipTexRefGetFormat(pFormat, pNumChannels, texRef);
}

hipError_t WINAPI wine_hipTexRefGetMaxAnisotropy(int* pmaxAnsio, const textureReference* texRef) {
  return hipTexRefGetMaxAnisotropy(pmaxAnsio, texRef);
}

hipError_t WINAPI wine_hipTexRefGetMipMappedArray(hipMipmappedArray_t* pArray, const textureReference* texRef) {
  return hipTexRefGetMipMappedArray(pArray, texRef);
}

hipError_t WINAPI wine_hipTexRefGetMipmapFilterMode(enum hipTextureFilterMode* pfm, const textureReference* texRef) {
  return hipTexRefGetMipmapFilterMode(pfm, texRef);
}

hipError_t WINAPI wine_hipTexRefGetMipmapLevelBias(float* pbias, const textureReference* texRef) {
  return hipTexRefGetMipmapLevelBias(pbias, texRef);
}

hipError_t WINAPI wine_hipTexRefGetMipmapLevelClamp(float* pminMipmapLevelClamp, float* pmaxMipmapLevelClamp, const textureReference* texRef) {
  return hipTexRefGetMipmapLevelClamp(pminMipmapLevelClamp, pmaxMipmapLevelClamp, texRef);
}

hipError_t WINAPI wine_hipTexRefSetAddress2D(textureReference* texRef, const HIP_ARRAY_DESCRIPTOR* desc, hipDeviceptr_t dptr, size_t Pitch) {
  return hipTexRefSetAddress2D(texRef, desc, dptr, Pitch);
}

hipError_t WINAPI wine_hipTexRefSetAddressMode(textureReference* texRef, int dim, enum hipTextureAddressMode am) {
  return hipTexRefSetAddressMode(texRef, dim, am);
}

hipError_t WINAPI wine_hipTexRefSetArray(textureReference* tex, hipArray_const_t array, unsigned int flags) {
  return hipTexRefSetArray(tex, array, flags);
}

hipError_t WINAPI wine_hipTexRefSetBorderColor(textureReference* texRef, float* pBorderColor) {
  return hipTexRefSetBorderColor(texRef, pBorderColor);
}

hipError_t WINAPI wine_hipTexRefSetFilterMode(textureReference* texRef, enum hipTextureFilterMode fm) {
  return hipTexRefSetFilterMode(texRef, fm);
}

hipError_t WINAPI wine_hipTexRefSetMaxAnisotropy(textureReference* texRef, unsigned int maxAniso) {
  return hipTexRefSetMaxAnisotropy(texRef, maxAniso);
}

hipError_t WINAPI wine_hipTexRefSetMipmapFilterMode(textureReference* texRef, enum hipTextureFilterMode fm) {
  return hipTexRefSetMipmapFilterMode(texRef, fm);
}

hipError_t WINAPI wine_hipTexRefSetMipmapLevelBias(textureReference* texRef, float bias) {
  return hipTexRefSetMipmapLevelBias(texRef, bias);
}

hipError_t WINAPI wine_hipTexRefSetMipmapLevelClamp(textureReference* texRef, float minMipMapLevelClamp, float maxMipMapLevelClamp) {
  return hipTexRefSetMipmapLevelClamp(texRef, minMipMapLevelClamp, maxMipMapLevelClamp);
}

hipError_t WINAPI wine_hipTexRefSetMipmappedArray(textureReference* texRef, struct hipMipmappedArray* mipmappedArray, unsigned int Flags) {
  return hipTexRefSetMipmappedArray(texRef, mipmappedArray, Flags);
}

hipError_t WINAPI wine_hipThreadExchangeStreamCaptureMode(hipStreamCaptureMode* mode) {
  return hipThreadExchangeStreamCaptureMode(mode);
}

hipError_t WINAPI wine_hipUserObjectCreate(hipUserObject_t* object_out, void* ptr, hipHostFn_t destroy, unsigned int initialRefcount, unsigned int flags) {
  return hipUserObjectCreate(object_out, ptr, destroy, initialRefcount, flags);
}

hipError_t WINAPI wine_hipUserObjectRelease(hipUserObject_t object, unsigned int count) {
  return hipUserObjectRelease(object, count);
}

hipError_t WINAPI wine_hipUserObjectRetain(hipUserObject_t object, unsigned int count) {
  return hipUserObjectRetain(object, count);
}

hipError_t WINAPI wine_hipWaitExternalSemaphoresAsync(const hipExternalSemaphore_t* extSemArray, const hipExternalSemaphoreWaitParams* paramsArray, unsigned int numExtSems, hipStream_t stream) {
  return hipWaitExternalSemaphoresAsync(extSemArray, paramsArray, numExtSems, stream);
}


BOOL WINAPI DllMain(HINSTANCE instance, DWORD reason, LPVOID reserved) {
  switch (reason) {
  case DLL_PROCESS_ATTACH:
    break;
  case DLL_PROCESS_DETACH:
    if (reserved)
      break;
    break;
  case DLL_THREAD_ATTACH:
    break;
  case DLL_THREAD_DETACH:
    break;
  }

  return TRUE;
}
