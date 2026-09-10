@ stub __gnu_f2h_ieee
@ stub __gnu_h2f_ieee
@ stdcall __hipPopCallConfiguration(ptr ptr ptr ptr) wine___hipPopCallConfiguration
@ stdcall __hipPushCallConfiguration(ptr ptr int64 ptr) wine___hipPushCallConfiguration
@ stdcall __hipRegisterFatBinary(ptr) wine___hipRegisterFatBinary
@ stdcall __hipRegisterFunction(ptr ptr ptr str long ptr ptr ptr ptr ptr) wine___hipRegisterFunction
@ stub __hipRegisterManagedVar
@ stub __hipRegisterSurface
@ stub __hipRegisterTexture
@ stub __hipRegisterVar
@ stdcall __hipUnregisterFatBinary(ptr) wine___hipUnregisterFatBinary
@ stub amd_dbgapi_get_build_id
@ stub amd_dbgapi_get_build_name
@ stub amd_dbgapi_get_git_hash
@ stdcall hipApiName(long) wine_hipApiName
@ stdcall hipArray3DCreate(ptr ptr) wine_hipArray3DCreate
@ stdcall hipArray3DGetDescriptor(ptr ptr) wine_hipArray3DGetDescriptor
@ stdcall hipArrayCreate(ptr ptr) wine_hipArrayCreate
@ stdcall hipArrayDestroy(ptr) wine_hipArrayDestroy
@ stdcall hipArrayGetDescriptor(ptr ptr) wine_hipArrayGetDescriptor
@ stdcall hipArrayGetInfo(ptr ptr ptr ptr) wine_hipArrayGetInfo
@ stdcall hipBindTexture(ptr ptr ptr ptr int64) wine_hipBindTexture
@ stdcall hipBindTexture2D(ptr ptr ptr ptr int64 int64 int64) wine_hipBindTexture2D
@ stdcall hipBindTextureToArray(ptr ptr ptr) wine_hipBindTextureToArray
@ stdcall hipBindTextureToMipmappedArray(ptr ptr ptr) wine_hipBindTextureToMipmappedArray
@ stdcall hipChooseDevice(ptr ptr) wine_hipChooseDevice
@ stdcall hipChooseDeviceR0000(ptr ptr) wine_hipChooseDeviceR0000
@ stdcall hipChooseDeviceR0600(ptr ptr) wine_hipChooseDeviceR0600
@ stdcall hipConfigureCall(ptr ptr int64 ptr) wine_hipConfigureCall
@ stdcall hipCreateChannelDesc(long long long long long) wine_hipCreateChannelDesc
@ stdcall hipCreateSurfaceObject(ptr ptr) wine_hipCreateSurfaceObject
@ stdcall hipCreateTextureObject(ptr ptr ptr ptr) wine_hipCreateTextureObject
@ stdcall hipCtxCreate(ptr long long) wine_hipCtxCreate
@ stdcall hipCtxDestroy(ptr) wine_hipCtxDestroy
@ stdcall hipCtxDisablePeerAccess(ptr) wine_hipCtxDisablePeerAccess
@ stdcall hipCtxEnablePeerAccess(ptr long) wine_hipCtxEnablePeerAccess
@ stdcall hipCtxGetApiVersion(ptr ptr) wine_hipCtxGetApiVersion
@ stdcall hipCtxGetCacheConfig(ptr) wine_hipCtxGetCacheConfig
@ stdcall hipCtxGetCurrent(ptr) wine_hipCtxGetCurrent
@ stdcall hipCtxGetDevice(ptr) wine_hipCtxGetDevice
@ stdcall hipCtxGetFlags(ptr) wine_hipCtxGetFlags
@ stdcall hipCtxGetSharedMemConfig(ptr) wine_hipCtxGetSharedMemConfig
@ stdcall hipCtxPopCurrent(ptr) wine_hipCtxPopCurrent
@ stdcall hipCtxPushCurrent(ptr) wine_hipCtxPushCurrent
@ stdcall hipCtxSetCacheConfig(long) wine_hipCtxSetCacheConfig
@ stdcall hipCtxSetCurrent(ptr) wine_hipCtxSetCurrent
@ stdcall hipCtxSetSharedMemConfig(long) wine_hipCtxSetSharedMemConfig
@ stdcall hipCtxSynchronize() wine_hipCtxSynchronize
@ stdcall hipDestroyExternalMemory(ptr) wine_hipDestroyExternalMemory
@ stdcall hipDestroyExternalSemaphore(ptr) wine_hipDestroyExternalSemaphore
@ stdcall hipDestroySurfaceObject(ptr) wine_hipDestroySurfaceObject
@ stdcall hipDestroyTextureObject(ptr) wine_hipDestroyTextureObject
@ stdcall hipDeviceCanAccessPeer(ptr long long) wine_hipDeviceCanAccessPeer
@ stdcall hipDeviceComputeCapability(ptr ptr long) wine_hipDeviceComputeCapability 
@ stdcall hipDeviceDisablePeerAccess(long) wine_hipDeviceDisablePeerAccess
@ stdcall hipDeviceEnablePeerAccess(long long) wine_hipDeviceEnablePeerAccess
@ stdcall hipDeviceGet(ptr long) wine_hipDeviceGet
@ stdcall hipDeviceGetAttribute(ptr long long) wine_hipDeviceGetAttribute
@ stdcall hipDeviceGetByPCIBusId(ptr ptr) wine_hipDeviceGetByPCIBusId
@ stdcall hipDeviceGetCacheConfig(ptr) wine_hipDeviceGetCacheConfig
@ stdcall hipDeviceGetDefaultMemPool(ptr long) wine_hipDeviceGetDefaultMemPool
@ stdcall hipDeviceGetGraphMemAttribute(long long ptr) wine_hipDeviceGetGraphMemAttribute
@ stdcall hipDeviceGetLimit(ptr long) wine_hipDeviceGetLimit
@ stdcall hipDeviceGetMemPool(ptr long) wine_hipDeviceGetMemPool
@ stdcall hipDeviceGetName(ptr long long) wine_hipDeviceGetName
@ stdcall hipDeviceGetP2PAttribute(ptr long long long) wine_hipDeviceGetP2PAttribute
@ stdcall hipDeviceGetPCIBusId(ptr long long) wine_hipDeviceGetPCIBusId
@ stdcall hipDeviceGetSharedMemConfig(ptr) wine_hipDeviceGetSharedMemConfig
@ stdcall hipDeviceGetStreamPriorityRange(ptr ptr) wine_hipDeviceGetStreamPriorityRange
@ stdcall hipDeviceGetUuid(ptr long) wine_hipDeviceGetUuid
@ stdcall hipDeviceGraphMemTrim(long) wine_hipDeviceGraphMemTrim
@ stdcall hipDevicePrimaryCtxGetState(long ptr ptr) wine_hipDevicePrimaryCtxGetState
@ stdcall hipDevicePrimaryCtxRelease(long) wine_hipDevicePrimaryCtxRelease
@ stdcall hipDevicePrimaryCtxReset(long) wine_hipDevicePrimaryCtxReset
@ stdcall hipDevicePrimaryCtxRetain(ptr long) wine_hipDevicePrimaryCtxRetain
@ stdcall hipDevicePrimaryCtxSetFlags(long long) wine_hipDevicePrimaryCtxSetFlags
@ stdcall hipDeviceReset() wine_hipDeviceReset
@ stdcall hipDeviceSetCacheConfig(long) wine_hipDeviceSetCacheConfig
@ stdcall hipDeviceSetGraphMemAttribute(long long ptr) wine_hipDeviceSetGraphMemAttribute
@ stdcall hipDeviceSetLimit(long int64) wine_hipDeviceSetLimit
@ stdcall hipDeviceSetMemPool(long ptr) wine_hipDeviceSetMemPool
@ stdcall hipDeviceSetSharedMemConfig(long) wine_hipDeviceSetSharedMemConfig
@ stdcall hipDeviceSynchronize() wine_hipDeviceSynchronize
@ stdcall hipDeviceTotalMem(ptr long) wine_hipDeviceTotalMem
@ stdcall hipDriverGetVersion(ptr) wine_hipDriverGetVersion
@ stdcall hipDrvGetErrorName(long ptr) wine_hipDrvGetErrorName
@ stdcall hipDrvGetErrorString(long ptr) wine_hipDrvGetErrorString
@ stdcall hipDrvGraphAddMemcpyNode(ptr ptr ptr int64 ptr ptr) wine_hipDrvGraphAddMemcpyNode
@ stdcall hipDrvGraphAddMemsetNode(ptr ptr ptr int64 ptr ptr) wine_hipDrvGraphAddMemsetNode
@ stdcall hipDrvMemcpy2DUnaligned(ptr) wine_hipDrvMemcpy2DUnaligned
@ stdcall hipDrvMemcpy3D(ptr) wine_hipDrvMemcpy3D
@ stdcall hipDrvMemcpy3DAsync(ptr ptr) wine_hipDrvMemcpy3DAsync
@ stdcall hipDrvPointerGetAttributes(long ptr ptr ptr) wine_hipDrvPointerGetAttributes
@ stdcall hipEventCreate(ptr) wine_hipEventCreate
@ stdcall hipEventCreateWithFlags(ptr long) wine_hipEventCreateWithFlags
@ stdcall hipEventDestroy(ptr) wine_hipEventDestroy
@ stdcall hipEventElapsedTime(ptr ptr ptr) wine_hipEventElapsedTime
@ stdcall hipEventQuery(ptr) wine_hipEventQuery
@ stdcall hipEventRecord(ptr ptr) wine_hipEventRecord
@ stdcall hipEventRecord_spt(ptr ptr) wine_hipEventRecord_spt
@ stdcall hipEventSynchronize(ptr) wine_hipEventSynchronize
@ stdcall hipExtGetLastError() wine_hipExtGetLastError
@ stdcall hipExtGetLinkTypeAndHopCount(long long ptr ptr) wine_hipExtGetLinkTypeAndHopCount
@ stdcall hipExtLaunchKernel(ptr ptr ptr ptr int64 ptr ptr ptr long) wine_hipExtLaunchKernel
@ stdcall hipExtLaunchMultiKernelMultiDevice(ptr long long) wine_hipExtLaunchMultiKernelMultiDevice
@ stdcall hipExtMallocWithFlags(ptr int64 long) wine_hipExtMallocWithFlags
@ stub hipExtModuleLaunchKernel
@ stdcall hipExtStreamCreateWithCUMask(ptr long ptr) wine_hipExtStreamCreateWithCUMask
@ stdcall hipExtStreamGetCUMask(ptr long ptr) wine_hipExtStreamGetCUMask
@ stdcall hipExternalMemoryGetMappedBuffer(ptr ptr ptr) wine_hipExternalMemoryGetMappedBuffer
@ stdcall hipFree(ptr) wine_hipFree
@ stdcall hipFreeArray(ptr) wine_hipFreeArray
@ stdcall hipFreeAsync(ptr ptr) wine_hipFreeAsync
@ stdcall hipFreeHost(ptr) wine_hipFreeHost
@ stdcall hipFreeMipmappedArray(ptr) wine_hipFreeMipmappedArray
@ stdcall hipFuncGetAttribute(ptr long ptr) wine_hipFuncGetAttribute
@ stdcall hipFuncGetAttributes(ptr ptr) wine_hipFuncGetAttributes
@ stdcall hipFuncSetAttribute(ptr long long) wine_hipFuncSetAttribute
@ stdcall hipFuncSetCacheConfig(ptr long) wine_hipFuncSetCacheConfig
@ stdcall hipFuncSetSharedMemConfig(ptr long) wine_hipFuncSetSharedMemConfig
@ stub hipGLGetDevices
@ stdcall hipGetChannelDesc(ptr ptr) wine_hipGetChannelDesc
@ stub hipGetCmdName
@ stdcall hipGetDevice(ptr) wine_hipGetDevice
@ stdcall hipGetDeviceCount(ptr) wine_hipGetDeviceCount
@ stdcall hipGetDeviceFlags(ptr) wine_hipGetDeviceFlags
@ stdcall hipGetDeviceProperties(ptr long) wine_hipGetDeviceProperties
@ stdcall hipGetDevicePropertiesR0000(ptr long) wine_hipGetDevicePropertiesR0000
@ stdcall hipGetDevicePropertiesR0600(ptr long) wine_hipGetDevicePropertiesR0600
@ stdcall hipGetErrorName(long) wine_hipGetErrorName
@ stdcall hipGetErrorString(long) wine_hipGetErrorString
@ stdcall hipGetLastError() wine_hipGetLastError
@ stdcall hipGetMipmappedArrayLevel(ptr ptr long) wine_hipGetMipmappedArrayLevel
@ stdcall hipGetStreamDeviceId(ptr) wine_hipGetStreamDeviceId
@ stdcall hipGetSymbolAddress(ptr ptr) wine_hipGetSymbolAddress
@ stdcall hipGetSymbolSize(ptr ptr) wine_hipGetSymbolSize
@ stdcall hipGetTextureAlignmentOffset(ptr ptr) wine_hipGetTextureAlignmentOffset
@ stdcall hipGetTextureObjectResourceDesc(ptr ptr) wine_hipGetTextureObjectResourceDesc
@ stdcall hipGetTextureObjectResourceViewDesc(ptr ptr) wine_hipGetTextureObjectResourceViewDesc
@ stdcall hipGetTextureObjectTextureDesc(ptr ptr) wine_hipGetTextureObjectTextureDesc
@ stdcall hipGetTextureReference(ptr ptr) wine_hipGetTextureReference
@ stdcall hipGraphAddChildGraphNode(ptr ptr ptr int64 ptr) wine_hipGraphAddChildGraphNode
@ stdcall hipGraphAddDependencies(ptr ptr ptr int64) wine_hipGraphAddDependencies
@ stdcall hipGraphAddEmptyNode(ptr ptr ptr int64) wine_hipGraphAddEmptyNode
@ stdcall hipGraphAddEventRecordNode(ptr ptr ptr int64 ptr) wine_hipGraphAddEventRecordNode
@ stdcall hipGraphAddEventWaitNode(ptr ptr ptr int64 ptr) wine_hipGraphAddEventWaitNode
@ stdcall hipGraphAddHostNode(ptr ptr ptr int64 ptr) wine_hipGraphAddHostNode
@ stdcall hipGraphAddKernelNode(ptr ptr ptr int64 ptr) wine_hipGraphAddKernelNode
@ stdcall hipGraphAddMemAllocNode(ptr ptr ptr int64 ptr) wine_hipGraphAddMemAllocNode
@ stdcall hipGraphAddMemFreeNode(ptr ptr ptr int64 ptr) wine_hipGraphAddMemFreeNode
@ stdcall hipGraphAddMemcpyNode(ptr ptr ptr int64 ptr) wine_hipGraphAddMemcpyNode
@ stdcall hipGraphAddMemcpyNode1D(ptr ptr ptr int64 ptr ptr int64 long) wine_hipGraphAddMemcpyNode1D
@ stdcall hipGraphAddMemcpyNodeFromSymbol(ptr ptr ptr int64 ptr ptr int64 int64 long) wine_hipGraphAddMemcpyNodeFromSymbol
@ stdcall hipGraphAddMemcpyNodeToSymbol(ptr ptr ptr int64 ptr ptr int64 int64 long) wine_hipGraphAddMemcpyNodeToSymbol
@ stdcall hipGraphAddMemsetNode(ptr ptr ptr int64 ptr) wine_hipGraphAddMemsetNode
@ stdcall hipGraphChildGraphNodeGetGraph(ptr ptr) wine_hipGraphChildGraphNodeGetGraph
@ stdcall hipGraphClone(ptr ptr) wine_hipGraphClone
@ stdcall hipGraphCreate(ptr long) wine_hipGraphCreate
@ stdcall hipGraphDebugDotPrint(ptr ptr long) wine_hipGraphDebugDotPrint
@ stdcall hipGraphDestroy(ptr) wine_hipGraphDestroy
@ stdcall hipGraphDestroyNode(ptr) wine_hipGraphDestroyNode
@ stdcall hipGraphEventRecordNodeGetEvent(ptr ptr) wine_hipGraphEventRecordNodeGetEvent
@ stdcall hipGraphEventRecordNodeSetEvent(ptr ptr) wine_hipGraphEventRecordNodeSetEvent
@ stdcall hipGraphEventWaitNodeGetEvent(ptr ptr) wine_hipGraphEventWaitNodeGetEvent
@ stdcall hipGraphEventWaitNodeSetEvent(ptr ptr) wine_hipGraphEventWaitNodeSetEvent
@ stdcall hipGraphExecChildGraphNodeSetParams(ptr ptr ptr) wine_hipGraphExecChildGraphNodeSetParams
@ stdcall hipGraphExecDestroy(ptr) wine_hipGraphExecDestroy
@ stdcall hipGraphExecEventRecordNodeSetEvent(ptr ptr ptr) wine_hipGraphExecEventRecordNodeSetEvent
@ stdcall hipGraphExecEventWaitNodeSetEvent(ptr ptr ptr) wine_hipGraphExecEventWaitNodeSetEvent
@ stdcall hipGraphExecHostNodeSetParams(ptr ptr ptr) wine_hipGraphExecHostNodeSetParams
@ stdcall hipGraphExecKernelNodeSetParams(ptr ptr ptr) wine_hipGraphExecKernelNodeSetParams
@ stdcall hipGraphExecMemcpyNodeSetParams(ptr ptr ptr) wine_hipGraphExecMemcpyNodeSetParams
@ stdcall hipGraphExecMemcpyNodeSetParams1D(ptr ptr ptr ptr int64 long) wine_hipGraphExecMemcpyNodeSetParams1D
@ stdcall hipGraphExecMemcpyNodeSetParamsFromSymbol(ptr ptr ptr ptr int64 int64 long) wine_hipGraphExecMemcpyNodeSetParamsFromSymbol
@ stdcall hipGraphExecMemcpyNodeSetParamsToSymbol(ptr ptr ptr ptr int64 int64 long) wine_hipGraphExecMemcpyNodeSetParamsToSymbol
@ stdcall hipGraphExecMemsetNodeSetParams(ptr ptr ptr) wine_hipGraphExecMemsetNodeSetParams
@ stdcall hipGraphExecUpdate(ptr ptr ptr ptr) wine_hipGraphExecUpdate
@ stdcall hipGraphGetEdges(ptr ptr ptr ptr) wine_hipGraphGetEdges
@ stdcall hipGraphGetNodes(ptr ptr ptr) wine_hipGraphGetNodes
@ stdcall hipGraphGetRootNodes(ptr ptr ptr) wine_hipGraphGetRootNodes
@ stdcall hipGraphHostNodeGetParams(ptr ptr) wine_hipGraphHostNodeGetParams
@ stdcall hipGraphHostNodeSetParams(ptr ptr) wine_hipGraphHostNodeSetParams
@ stdcall hipGraphInstantiate(ptr ptr ptr ptr int64) wine_hipGraphInstantiate
@ stdcall hipGraphInstantiateWithFlags(ptr ptr int64) wine_hipGraphInstantiateWithFlags
@ stdcall hipGraphKernelNodeCopyAttributes(ptr ptr) wine_hipGraphKernelNodeCopyAttributes
@ stdcall hipGraphKernelNodeGetAttribute(ptr long ptr) wine_hipGraphKernelNodeGetAttribute
@ stdcall hipGraphKernelNodeGetParams(ptr ptr) wine_hipGraphKernelNodeGetParams
@ stdcall hipGraphKernelNodeSetAttribute(ptr long ptr) wine_hipGraphKernelNodeSetAttribute
@ stdcall hipGraphKernelNodeSetParams(ptr ptr) wine_hipGraphKernelNodeSetParams
@ stdcall hipGraphLaunch(ptr ptr) wine_hipGraphLaunch
@ stdcall hipGraphLaunch_spt(ptr ptr) wine_hipGraphLaunch_spt
@ stdcall hipGraphMemAllocNodeGetParams(ptr ptr) wine_hipGraphMemAllocNodeGetParams
@ stdcall hipGraphMemFreeNodeGetParams(ptr ptr) wine_hipGraphMemFreeNodeGetParams
@ stdcall hipGraphMemcpyNodeGetParams(ptr ptr) wine_hipGraphMemcpyNodeGetParams
@ stdcall hipGraphMemcpyNodeSetParams(ptr ptr) wine_hipGraphMemcpyNodeSetParams
@ stdcall hipGraphMemcpyNodeSetParams1D(ptr ptr ptr int64 long) wine_hipGraphMemcpyNodeSetParams1D
@ stdcall hipGraphMemcpyNodeSetParamsFromSymbol(ptr ptr ptr int64 int64 long) wine_hipGraphMemcpyNodeSetParamsFromSymbol
@ stdcall hipGraphMemcpyNodeSetParamsToSymbol(ptr ptr ptr int64 int64 long) wine_hipGraphMemcpyNodeSetParamsToSymbol
@ stdcall hipGraphMemsetNodeGetParams(ptr ptr) wine_hipGraphMemsetNodeGetParams
@ stdcall hipGraphMemsetNodeSetParams(ptr ptr) wine_hipGraphMemsetNodeSetParams
@ stdcall hipGraphNodeFindInClone(ptr ptr ptr) wine_hipGraphNodeFindInClone
@ stdcall hipGraphNodeGetDependencies(ptr ptr ptr) wine_hipGraphNodeGetDependencies
@ stdcall hipGraphNodeGetDependentNodes(ptr ptr ptr) wine_hipGraphNodeGetDependentNodes
@ stdcall hipGraphNodeGetEnabled(ptr ptr ptr) wine_hipGraphNodeGetEnabled
@ stdcall hipGraphNodeGetType(ptr ptr) wine_hipGraphNodeGetType
@ stdcall hipGraphNodeSetEnabled(ptr ptr long) wine_hipGraphNodeSetEnabled
@ stdcall hipGraphReleaseUserObject(ptr ptr long) wine_hipGraphReleaseUserObject
@ stdcall hipGraphRemoveDependencies(ptr ptr ptr int64) wine_hipGraphRemoveDependencies
@ stdcall hipGraphRetainUserObject(ptr ptr long long) wine_hipGraphRetainUserObject
@ stdcall hipGraphUpload(ptr ptr) wine_hipGraphUpload
@ stub hipGraphicsGLRegisterBuffer
@ stub hipGraphicsGLRegisterImage
@ stdcall hipGraphicsMapResources(long ptr ptr) wine_hipGraphicsMapResources
@ stdcall hipGraphicsResourceGetMappedPointer(ptr ptr ptr) wine_hipGraphicsResourceGetMappedPointer
@ stdcall hipGraphicsSubResourceGetMappedArray(ptr ptr long long) wine_hipGraphicsSubResourceGetMappedArray
@ stdcall hipGraphicsUnmapResources(long ptr ptr) wine_hipGraphicsUnmapResources
@ stdcall hipGraphicsUnregisterResource(ptr) wine_hipGraphicsUnregisterResource
@ stub hipHccModuleLaunchKernel
@ stdcall hipHostAlloc(ptr int64 long) wine_hipHostAlloc
@ stdcall hipHostFree(ptr) wine_hipHostFree
@ stdcall hipHostGetDevicePointer(ptr ptr long) wine_hipHostGetDevicePointer
@ stdcall hipHostGetFlags(ptr ptr) wine_hipHostGetFlags
@ stdcall hipHostMalloc(ptr int64 long) wine_hipHostMalloc
@ stdcall hipHostRegister(ptr int64 long) wine_hipHostRegister
@ stdcall hipHostUnregister(ptr) wine_hipHostUnregister
@ stdcall hipImportExternalMemory(ptr ptr) wine_hipImportExternalMemory
@ stdcall hipImportExternalSemaphore(ptr ptr) wine_hipImportExternalSemaphore
@ stdcall hipInit(long) wine_hipInit
@ stdcall hipIpcCloseMemHandle(ptr) wine_hipIpcCloseMemHandle
@ stdcall hipIpcGetEventHandle(ptr ptr) wine_hipIpcGetEventHandle
@ stdcall hipIpcGetMemHandle(ptr ptr) wine_hipIpcGetMemHandle
@ stdcall hipIpcOpenEventHandle(ptr ptr) wine_hipIpcOpenEventHandle
@ stdcall hipIpcOpenMemHandle(ptr ptr long) wine_hipIpcOpenMemHandle
@ stdcall hipKernelNameRef(ptr) wine_hipKernelNameRef
@ stdcall hipLaunchByPtr(ptr) wine_hipLaunchByPtr
@ stdcall hipLaunchCooperativeKernel(ptr ptr ptr ptr long ptr) wine_hipLaunchCooperativeKernel
@ stdcall hipLaunchCooperativeKernelMultiDevice(ptr long long) wine_hipLaunchCooperativeKernelMultiDevice
@ stdcall hipLaunchCooperativeKernel_spt(ptr ptr ptr ptr long ptr) wine_hipLaunchCooperativeKernel_spt
@ stdcall hipLaunchHostFunc(ptr ptr ptr) wine_hipLaunchHostFunc
@ stdcall hipLaunchHostFunc_spt(ptr ptr ptr) wine_hipLaunchHostFunc_spt
@ stdcall hipLaunchKernel(ptr ptr ptr ptr int64 ptr) wine_hipLaunchKernel
@ stdcall hipLaunchKernel_spt(ptr ptr ptr ptr int64 ptr) wine_hipLaunchKernel_spt
@ stdcall hipMalloc(ptr int64) wine_hipMalloc
@ stdcall hipMalloc3D(ptr ptr) wine_hipMalloc3D
@ stdcall hipMalloc3DArray(ptr ptr ptr long) wine_hipMalloc3DArray
@ stdcall hipMallocArray(ptr ptr int64 int64 long) wine_hipMallocArray
@ stdcall hipMallocAsync(ptr int64 ptr) wine_hipMallocAsync
@ stdcall hipMallocFromPoolAsync(ptr int64 ptr ptr) wine_hipMallocFromPoolAsync
@ stdcall hipMallocHost(ptr int64) wine_hipMallocHost
@ stdcall hipMallocManaged(ptr int64 long) wine_hipMallocManaged
@ stdcall hipMallocMipmappedArray(ptr ptr ptr long long) wine_hipMallocMipmappedArray
@ stdcall hipMallocPitch(ptr ptr int64 int64) wine_hipMallocPitch
@ stdcall hipMemAddressFree(ptr int64) wine_hipMemAddressFree
@ stdcall hipMemAddressReserve(ptr int64 int64 ptr int64) wine_hipMemAddressReserve
@ stdcall hipMemAdvise(ptr int64 long long) wine_hipMemAdvise
@ stdcall hipMemAllocHost(ptr int64) wine_hipMemAllocHost
@ stdcall hipMemAllocPitch(ptr ptr int64 int64 long) wine_hipMemAllocPitch
@ stdcall hipMemCreate(ptr int64 ptr int64) wine_hipMemCreate
@ stdcall hipMemExportToShareableHandle(ptr ptr long int64) wine_hipMemExportToShareableHandle
@ stdcall hipMemGetAccess(ptr ptr ptr) wine_hipMemGetAccess
@ stdcall hipMemGetAddressRange(ptr ptr ptr) wine_hipMemGetAddressRange
@ stdcall hipMemGetAllocationGranularity(ptr ptr long) wine_hipMemGetAllocationGranularity
@ stdcall hipMemGetAllocationPropertiesFromHandle(ptr ptr) wine_hipMemGetAllocationPropertiesFromHandle
@ stdcall hipMemGetInfo(ptr ptr) wine_hipMemGetInfo
@ stdcall hipMemImportFromShareableHandle(ptr ptr long) wine_hipMemImportFromShareableHandle
@ stdcall hipMemMap(ptr int64 int64 ptr int64) wine_hipMemMap
@ stdcall hipMemMapArrayAsync(ptr long ptr) wine_hipMemMapArrayAsync
@ stdcall hipMemPoolCreate(ptr ptr) wine_hipMemPoolCreate
@ stdcall hipMemPoolDestroy(ptr) wine_hipMemPoolDestroy
@ stdcall hipMemPoolExportPointer(ptr ptr) wine_hipMemPoolExportPointer
@ stdcall hipMemPoolExportToShareableHandle(ptr ptr long long) wine_hipMemPoolExportToShareableHandle
@ stdcall hipMemPoolGetAccess(ptr ptr ptr) wine_hipMemPoolGetAccess
@ stdcall hipMemPoolGetAttribute(ptr long ptr) wine_hipMemPoolGetAttribute
@ stdcall hipMemPoolImportFromShareableHandle(ptr ptr long long) wine_hipMemPoolImportFromShareableHandle
@ stdcall hipMemPoolImportPointer(ptr ptr ptr) wine_hipMemPoolImportPointer
@ stdcall hipMemPoolSetAccess(ptr ptr int64) wine_hipMemPoolSetAccess
@ stdcall hipMemPoolSetAttribute(ptr long ptr) wine_hipMemPoolSetAttribute
@ stdcall hipMemPoolTrimTo(ptr int64) wine_hipMemPoolTrimTo
@ stdcall hipMemPrefetchAsync(ptr int64 long ptr) wine_hipMemPrefetchAsync
@ stdcall hipMemPtrGetInfo(ptr ptr) wine_hipMemPtrGetInfo
@ stdcall hipMemRangeGetAttribute(ptr int64 long ptr int64) wine_hipMemRangeGetAttribute
@ stdcall hipMemRangeGetAttributes(ptr ptr ptr int64 ptr int64) wine_hipMemRangeGetAttributes
@ stdcall hipMemRelease(ptr) wine_hipMemRelease
@ stdcall hipMemRetainAllocationHandle(ptr ptr) wine_hipMemRetainAllocationHandle
@ stdcall hipMemSetAccess(ptr int64 ptr int64) wine_hipMemSetAccess
@ stdcall hipMemUnmap(ptr int64) wine_hipMemUnmap
@ stdcall hipMemcpy(ptr ptr int64 long) wine_hipMemcpy
@ stdcall hipMemcpy2D(ptr int64 ptr int64 int64 int64 long) wine_hipMemcpy2D
@ stdcall hipMemcpy2DAsync(ptr int64 ptr int64 int64 int64 long ptr) wine_hipMemcpy2DAsync
@ stdcall hipMemcpy2DAsync_spt(ptr int64 ptr int64 int64 int64 long ptr) wine_hipMemcpy2DAsync_spt
@ stdcall hipMemcpy2DFromArray(ptr int64 ptr int64 int64 int64 int64 long) wine_hipMemcpy2DFromArray
@ stdcall hipMemcpy2DFromArrayAsync(ptr int64 ptr int64 int64 int64 int64 long ptr) wine_hipMemcpy2DFromArrayAsync
@ stdcall hipMemcpy2DFromArrayAsync_spt(ptr int64 ptr int64 int64 int64 int64 long ptr) wine_hipMemcpy2DFromArrayAsync_spt
@ stdcall hipMemcpy2DFromArray_spt(ptr int64 ptr int64 int64 int64 int64 long) wine_hipMemcpy2DFromArray_spt
@ stdcall hipMemcpy2DToArray(ptr int64 int64 ptr int64 int64 int64 long) wine_hipMemcpy2DToArray
@ stdcall hipMemcpy2DToArrayAsync(ptr int64 int64 ptr int64 int64 int64 long ptr) wine_hipMemcpy2DToArrayAsync
@ stdcall hipMemcpy2DToArrayAsync_spt(ptr int64 int64 ptr int64 int64 int64 long ptr) wine_hipMemcpy2DToArrayAsync_spt
@ stdcall hipMemcpy2DToArray_spt(ptr int64 int64 ptr int64 int64 int64 long) wine_hipMemcpy2DToArray_spt
@ stdcall hipMemcpy2D_spt(ptr int64 ptr int64 int64 int64 long) wine_hipMemcpy2D_spt
@ stdcall hipMemcpy3D(ptr) wine_hipMemcpy3D
@ stdcall hipMemcpy3DAsync(ptr ptr) wine_hipMemcpy3DAsync
@ stdcall hipMemcpy3DAsync_spt(ptr ptr) wine_hipMemcpy3DAsync_spt
@ stdcall hipMemcpy3D_spt(ptr) wine_hipMemcpy3D_spt
@ stdcall hipMemcpyAsync(ptr ptr int64 long ptr) wine_hipMemcpyAsync
@ stdcall hipMemcpyAsync_spt(ptr ptr int64 long ptr) wine_hipMemcpyAsync_spt
@ stdcall hipMemcpyAtoH(ptr ptr int64 int64) wine_hipMemcpyAtoH
@ stdcall hipMemcpyDtoD(ptr ptr int64) wine_hipMemcpyDtoD
@ stdcall hipMemcpyDtoDAsync(ptr ptr int64 ptr) wine_hipMemcpyDtoDAsync
@ stdcall hipMemcpyDtoH(ptr ptr int64) wine_hipMemcpyDtoH
@ stdcall hipMemcpyDtoHAsync(ptr ptr int64 ptr) wine_hipMemcpyDtoHAsync
@ stdcall hipMemcpyFromArray(ptr ptr int64 int64 int64 long) wine_hipMemcpyFromArray
@ stdcall hipMemcpyFromArray_spt(ptr ptr int64 int64 int64 long) wine_hipMemcpyFromArray_spt
@ stdcall hipMemcpyFromSymbol(ptr ptr int64 int64 long) wine_hipMemcpyFromSymbol
@ stdcall hipMemcpyFromSymbolAsync(ptr ptr int64 int64 long ptr) wine_hipMemcpyFromSymbolAsync
@ stdcall hipMemcpyFromSymbolAsync_spt(ptr ptr int64 int64 long ptr) wine_hipMemcpyFromSymbolAsync_spt
@ stdcall hipMemcpyFromSymbol_spt(ptr ptr int64 int64 long) wine_hipMemcpyFromSymbol_spt
@ stdcall hipMemcpyHtoA(ptr int64 ptr int64) wine_hipMemcpyHtoA
@ stdcall hipMemcpyHtoD(ptr ptr int64) wine_hipMemcpyHtoD
@ stdcall hipMemcpyHtoDAsync(ptr ptr int64 ptr) wine_hipMemcpyHtoDAsync
@ stdcall hipMemcpyParam2D(ptr) wine_hipMemcpyParam2D
@ stdcall hipMemcpyParam2DAsync(ptr ptr) wine_hipMemcpyParam2DAsync
@ stdcall hipMemcpyPeer(ptr long ptr long int64) wine_hipMemcpyPeer
@ stdcall hipMemcpyPeerAsync(ptr long ptr long int64 ptr) wine_hipMemcpyPeerAsync
@ stdcall hipMemcpyToArray(ptr int64 int64 ptr int64 long) wine_hipMemcpyToArray
@ stdcall hipMemcpyToSymbol(ptr ptr int64 int64 long) wine_hipMemcpyToSymbol
@ stdcall hipMemcpyToSymbolAsync(ptr ptr int64 int64 long ptr) wine_hipMemcpyToSymbolAsync
@ stdcall hipMemcpyToSymbolAsync_spt(ptr ptr int64 int64 long ptr) wine_hipMemcpyToSymbolAsync_spt
@ stdcall hipMemcpyToSymbol_spt(ptr ptr int64 int64 long) wine_hipMemcpyToSymbol_spt
@ stdcall hipMemcpyWithStream(ptr ptr int64 long ptr) wine_hipMemcpyWithStream
@ stdcall hipMemcpy_spt(ptr ptr int64 long) wine_hipMemcpy_spt
@ stdcall hipMemset(ptr long int64) wine_hipMemset
@ stdcall hipMemset2D(ptr int64 long int64 int64) wine_hipMemset2D
@ stdcall hipMemset2DAsync(ptr int64 long int64 int64 ptr) wine_hipMemset2DAsync
@ stdcall hipMemset2DAsync_spt(ptr int64 long int64 int64 ptr) wine_hipMemset2DAsync_spt
@ stdcall hipMemset2D_spt(ptr int64 long int64 int64) wine_hipMemset2D_spt
@ stdcall hipMemset3D(ptr long ptr) wine_hipMemset3D
@ stdcall hipMemset3DAsync(ptr long ptr ptr) wine_hipMemset3DAsync
@ stdcall hipMemset3DAsync_spt(ptr long ptr ptr) wine_hipMemset3DAsync_spt
@ stdcall hipMemset3D_spt(ptr long ptr) wine_hipMemset3D_spt
@ stdcall hipMemsetAsync(ptr long int64 ptr) wine_hipMemsetAsync
@ stdcall hipMemsetAsync_spt(ptr long int64 ptr) wine_hipMemsetAsync_spt
@ stdcall hipMemsetD16(ptr long int64) wine_hipMemsetD16
@ stdcall hipMemsetD16Async(ptr long int64 ptr) wine_hipMemsetD16Async
@ stdcall hipMemsetD32(ptr long int64) wine_hipMemsetD32
@ stdcall hipMemsetD32Async(ptr long int64 ptr) wine_hipMemsetD32Async
@ stdcall hipMemsetD8(ptr long int64) wine_hipMemsetD8
@ stdcall hipMemsetD8Async(ptr long int64 ptr) wine_hipMemsetD8Async
@ stdcall hipMemset_spt(ptr long int64) wine_hipMemset_spt
@ stdcall hipMipmappedArrayCreate(ptr ptr long) wine_hipMipmappedArrayCreate
@ stdcall hipMipmappedArrayDestroy(ptr) wine_hipMipmappedArrayDestroy
@ stdcall hipMipmappedArrayGetLevel(ptr ptr long) wine_hipMipmappedArrayGetLevel
@ stdcall hipModuleGetFunction(ptr ptr str) wine_hipModuleGetFunction
@ stdcall hipModuleGetGlobal(ptr ptr ptr str) wine_hipModuleGetGlobal
@ stdcall hipModuleGetTexRef(ptr ptr str) wine_hipModuleGetTexRef
@ stdcall hipModuleLaunchCooperativeKernel(ptr long long long long long long long ptr ptr) wine_hipModuleLaunchCooperativeKernel
@ stdcall hipModuleLaunchCooperativeKernelMultiDevice(ptr long long) wine_hipModuleLaunchCooperativeKernelMultiDevice
@ stdcall hipModuleLaunchKernel(ptr long long long long long long long ptr ptr ptr) wine_hipModuleLaunchKernel
@ stdcall hipModuleLoad(ptr ptr) wine_hipModuleLoad
@ stdcall hipModuleLoadData(ptr ptr) wine_hipModuleLoadData
@ stdcall hipModuleLoadDataEx(ptr ptr long ptr ptr) wine_hipModuleLoadDataEx
@ stdcall hipModuleOccupancyMaxActiveBlocksPerMultiprocessor(ptr ptr long int64) wine_hipModuleOccupancyMaxActiveBlocksPerMultiprocessor
@ stdcall hipModuleOccupancyMaxActiveBlocksPerMultiprocessorWithFlags(ptr ptr long int64 long) wine_hipModuleOccupancyMaxActiveBlocksPerMultiprocessorWithFlags
@ stdcall hipModuleOccupancyMaxPotentialBlockSize(ptr ptr ptr int64 long) wine_hipModuleOccupancyMaxPotentialBlockSize
@ stdcall hipModuleOccupancyMaxPotentialBlockSizeWithFlags(ptr ptr ptr int64 long long) wine_hipModuleOccupancyMaxPotentialBlockSizeWithFlags
@ stdcall hipModuleUnload(ptr) wine_hipModuleUnload
@ stdcall hipOccupancyMaxActiveBlocksPerMultiprocessor(ptr ptr long int64) wine_hipOccupancyMaxActiveBlocksPerMultiprocessor
@ stdcall hipOccupancyMaxActiveBlocksPerMultiprocessorWithFlags(ptr ptr long int64 long) wine_hipOccupancyMaxActiveBlocksPerMultiprocessorWithFlags
@ stdcall hipOccupancyMaxPotentialBlockSize(ptr ptr ptr int64 long) wine_hipOccupancyMaxPotentialBlockSize
@ stdcall hipPeekAtLastError() wine_hipPeekAtLastError
@ stdcall hipPointerGetAttribute(ptr long ptr) wine_hipPointerGetAttribute
@ stdcall hipPointerGetAttributes(ptr ptr) wine_hipPointerGetAttributes
@ stdcall hipProfilerStart() wine_hipProfilerStart
@ stdcall hipProfilerStop() wine_hipProfilerStop
@ stub hipRegisterTracerCallback
@ stdcall hipRuntimeGetVersion(ptr) wine_hipRuntimeGetVersion
@ stdcall hipSetDevice(long) wine_hipSetDevice
@ stdcall hipSetDeviceFlags(long) wine_hipSetDeviceFlags
@ stdcall hipSetupArgument(ptr int64 int64) wine_hipSetupArgument
@ stdcall hipSignalExternalSemaphoresAsync(ptr ptr long ptr) wine_hipSignalExternalSemaphoresAsync
@ stdcall hipStreamAddCallback(ptr ptr ptr long) wine_hipStreamAddCallback
@ stdcall hipStreamAddCallback_spt(ptr ptr ptr long) wine_hipStreamAddCallback_spt
@ stdcall hipStreamAttachMemAsync(ptr ptr int64 long) wine_hipStreamAttachMemAsync
@ stdcall hipStreamBeginCapture(ptr long) wine_hipStreamBeginCapture
@ stdcall hipStreamBeginCapture_spt(ptr long) wine_hipStreamBeginCapture_spt
@ stdcall hipStreamCreate(ptr) wine_hipStreamCreate
@ stdcall hipStreamCreateWithFlags(ptr long) wine_hipStreamCreateWithFlags
@ stdcall hipStreamCreateWithPriority(ptr long long) wine_hipStreamCreateWithPriority
@ stdcall hipStreamDestroy(ptr) wine_hipStreamDestroy
@ stdcall hipStreamEndCapture(ptr ptr) wine_hipStreamEndCapture
@ stdcall hipStreamEndCapture_spt(ptr ptr) wine_hipStreamEndCapture_spt
@ stdcall hipStreamGetCaptureInfo(ptr ptr ptr) wine_hipStreamGetCaptureInfo
@ stdcall hipStreamGetCaptureInfo_spt(ptr ptr ptr) wine_hipStreamGetCaptureInfo_spt
@ stdcall hipStreamGetCaptureInfo_v2(ptr ptr ptr ptr ptr ptr) wine_hipStreamGetCaptureInfo_v2
@ stdcall hipStreamGetCaptureInfo_v2_spt(ptr ptr ptr ptr ptr ptr) wine_hipStreamGetCaptureInfo_v2_spt
@ stdcall hipStreamGetDevice(ptr ptr) wine_hipStreamGetDevice
@ stdcall hipStreamGetFlags(ptr ptr) wine_hipStreamGetFlags
@ stdcall hipStreamGetFlags_spt(ptr ptr) wine_hipStreamGetFlags_spt
@ stdcall hipStreamGetPriority(ptr ptr) wine_hipStreamGetPriority
@ stdcall hipStreamGetPriority_spt(ptr ptr) wine_hipStreamGetPriority_spt
@ stdcall hipStreamIsCapturing(ptr ptr) wine_hipStreamIsCapturing
@ stdcall hipStreamIsCapturing_spt(ptr ptr) wine_hipStreamIsCapturing_spt
@ stdcall hipStreamQuery(ptr) wine_hipStreamQuery
@ stdcall hipStreamQuery_spt(ptr) wine_hipStreamQuery_spt
@ stdcall hipStreamSynchronize(ptr) wine_hipStreamSynchronize
@ stdcall hipStreamSynchronize_spt(ptr) wine_hipStreamSynchronize_spt
@ stdcall hipStreamUpdateCaptureDependencies(ptr ptr int64 long) wine_hipStreamUpdateCaptureDependencies
@ stdcall hipStreamWaitEvent(ptr ptr long) wine_hipStreamWaitEvent
@ stdcall hipStreamWaitEvent_spt(ptr ptr long) wine_hipStreamWaitEvent_spt
@ stdcall hipStreamWaitValue32(ptr ptr long long long) wine_hipStreamWaitValue32
@ stdcall hipStreamWaitValue64(ptr ptr int64 long int64) wine_hipStreamWaitValue64
@ stdcall hipStreamWriteValue32(ptr ptr long long) wine_hipStreamWriteValue32
@ stdcall hipStreamWriteValue64(ptr ptr int64 long) wine_hipStreamWriteValue64
@ stdcall hipTexObjectCreate(ptr ptr ptr ptr) wine_hipTexObjectCreate
@ stdcall hipTexObjectDestroy(ptr) wine_hipTexObjectDestroy
@ stdcall hipTexObjectGetResourceDesc(ptr ptr) wine_hipTexObjectGetResourceDesc
@ stdcall hipTexObjectGetResourceViewDesc(ptr ptr) wine_hipTexObjectGetResourceViewDesc
@ stdcall hipTexObjectGetTextureDesc(ptr ptr) wine_hipTexObjectGetTextureDesc
@ stdcall hipTexRefGetAddress(ptr ptr) wine_hipTexRefGetAddress
@ stdcall hipTexRefGetAddressMode(ptr ptr long) wine_hipTexRefGetAddressMode
@ stdcall hipTexRefGetFilterMode(ptr ptr) wine_hipTexRefGetFilterMode
@ stdcall hipTexRefGetFlags(ptr ptr) wine_hipTexRefGetFlags
@ stdcall hipTexRefGetFormat(ptr ptr ptr) wine_hipTexRefGetFormat
@ stdcall hipTexRefGetMaxAnisotropy(ptr ptr) wine_hipTexRefGetMaxAnisotropy
@ stdcall hipTexRefGetMipMappedArray(ptr ptr) wine_hipTexRefGetMipMappedArray
@ stdcall hipTexRefGetMipmapFilterMode(ptr ptr) wine_hipTexRefGetMipmapFilterMode
@ stdcall hipTexRefGetMipmapLevelBias(ptr ptr) wine_hipTexRefGetMipmapLevelBias
@ stdcall hipTexRefGetMipmapLevelClamp(ptr ptr ptr) wine_hipTexRefGetMipmapLevelClamp
@ stdcall hipTexRefSetAddress(ptr ptr ptr int64) wine_hipTexRefSetAddress
@ stdcall hipTexRefSetAddress2D(ptr ptr ptr int64) wine_hipTexRefSetAddress2D
@ stdcall hipTexRefSetAddressMode(ptr long long) wine_hipTexRefSetAddressMode
@ stdcall hipTexRefSetArray(ptr ptr long) wine_hipTexRefSetArray
@ stdcall hipTexRefSetBorderColor(ptr ptr) wine_hipTexRefSetBorderColor
@ stdcall hipTexRefSetFilterMode(ptr long) wine_hipTexRefSetFilterMode
@ stdcall hipTexRefSetFlags(ptr long) wine_hipTexRefSetFlags
@ stdcall hipTexRefSetFormat(ptr long long) wine_hipTexRefSetFormat
@ stdcall hipTexRefSetMaxAnisotropy(ptr long) wine_hipTexRefSetMaxAnisotropy
@ stdcall hipTexRefSetMipmapFilterMode(ptr long) wine_hipTexRefSetMipmapFilterMode
@ stdcall hipTexRefSetMipmapLevelBias(ptr float) wine_hipTexRefSetMipmapLevelBias
@ stdcall hipTexRefSetMipmapLevelClamp(ptr float float) wine_hipTexRefSetMipmapLevelClamp
@ stdcall hipTexRefSetMipmappedArray(ptr ptr long) wine_hipTexRefSetMipmappedArray
@ stdcall hipThreadExchangeStreamCaptureMode(ptr) wine_hipThreadExchangeStreamCaptureMode
@ stdcall hipUnbindTexture(ptr) wine_hipUnbindTexture
@ stdcall hipUserObjectCreate(ptr ptr ptr long long) wine_hipUserObjectCreate
@ stdcall hipUserObjectRelease(ptr long) wine_hipUserObjectRelease
@ stdcall hipUserObjectRetain(ptr long) wine_hipUserObjectRetain
@ stdcall hipWaitExternalSemaphoresAsync(ptr ptr long ptr) wine_hipWaitExternalSemaphoresAsync
