//---------------------------------------------------------------------------
#ifndef ClientInterfaceH
#define ClientInterfaceH
//---------------------------------------------------------------------------
#include "AV2000Types.h"
#include "GSysConfig.h"
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

#ifdef export_dll_function
   export_dll_function is already defined
#endif

#ifdef _DLL
   #define export_dll_function __declspec(dllexport)
   #define STDCALL //__stdcall
#else
   #define export_dll_function
   #define STDCALL
#endif


//---------------------------------------------------------------------------
// definitions of memory manadgment functions
//---------------------------------------------------------------------------
typedef void (*PTR_Allocate)(char**, unsigned long*);
typedef void (*PTR_Deallocate)(char*);
typedef void (*PTR_Reinited)(int);
typedef int  (*PTR_TestCallback)(int, int, int, int);

extern "C"  void export_dll_function STDCALL UseDefaultAllocator();
extern "C"  void export_dll_function STDCALL SetCallbackFunction(PTR_TestCallback);

extern "C"  int export_dll_function STDCALL CreateClient(int);
extern "C"  void export_dll_function STDCALL DestroyClient(int);
extern "C"  export_dll_function STDCALL unsigned MaxClients();
extern "C"  const ClientError* const export_dll_function STDCALL GetLastClientError(int);
extern "C" int export_dll_function STDCALL SetClientIp(int, const char*);
extern "C" const char* export_dll_function STDCALL GetClientIp(int);
extern "C" void export_dll_function STDCALL SetClientPort(int, unsigned);
extern "C" unsigned export_dll_function STDCALL GetClientPort(int);
extern "C" void export_dll_function STDCALL SetClientTimeout(int, unsigned);
extern "C" unsigned export_dll_function STDCALL GetClientTimeout(int);
extern "C" int export_dll_function STDCALL TriggerSingleCapture(int);
extern "C" int export_dll_function STDCALL GetSingleCapture(int);
extern "C" int export_dll_function STDCALL SetSingleCapture(int, int);
extern "C" int export_dll_function STDCALL SetCalibrateFlash(int);
extern "C" int export_dll_function STDCALL GetCalibrationNumber(int);
extern "C" int export_dll_function STDCALL SetTriggerCapture(int);

//image functions
extern "C" int export_dll_function STDCALL GetImage(int number, char** pdata, unsigned long* size, IMAGE_RESOLUTION, float zoom, int dx, int dy);
extern "C" int export_dll_function STDCALL GetImage2(int number, char** pdata, unsigned long* size, unsigned long* capacity,  IMAGE_RESOLUTION, float zoom, int dx, int dy);
extern "C" int export_dll_function STDCALL GetWindowImage(int number, char** pdata, unsigned long* size, unsigned long* capacity,  IMAGE_RESOLUTION, int left, int top, int width, int height);
extern "C" int export_dll_function STDCALL GetWindowImageQ(int number, char** pdata, unsigned long* size, unsigned long* capacity,  IMAGE_RESOLUTION resolution, long IsDoubleScan, long Aquality, int left, int top, int width, int height);
extern "C" int export_dll_function STDCALL GetDefaultImage(int number, char** pdata, unsigned long* size, unsigned long* capacity);

extern "C" int export_dll_function STDCALL GetImageEx(int number, char** pdata, unsigned long* size, IMAGE_RESOLUTION, float zoom, int dx, int dy, int codec, int streamId, int* Ifarme);
extern "C" int export_dll_function STDCALL GetImage2Ex(int number, char** pdata, unsigned long* size, unsigned long* capacity,  IMAGE_RESOLUTION, float zoom, int dx, int dy, int codec, int streamId, int* Ifarme);
extern "C" int export_dll_function STDCALL GetWindowImageEx(int number, char** pdata, unsigned long* size, unsigned long* capacity,  IMAGE_RESOLUTION, int left, int top, int width, int height, int codec, int streamId, int* Ifarme);
extern "C" int export_dll_function STDCALL GetWindowImageQEx(int number, char** pdata, unsigned long* size, unsigned long* capacity,  IMAGE_RESOLUTION, long IsDoubleScan, long Aquality, int left, int top, int width, int height, int codec, int streamId, int* Ifarme, int kbps, int intraFramePeriod);
extern "C" int export_dll_function STDCALL GetDefaultImageEx(int number, char** pdata, unsigned long* size, unsigned long* capacity, int codec, int streamId, int* Ifarme);


extern "C" int export_dll_function STDCALL SetChannelNumber(int number, int channel);


extern "C" int export_dll_function STDCALL SetAV2000Register(int, unsigned char registr, unsigned char* value);
extern "C" int export_dll_function STDCALL GetAV2000Register(int, unsigned char registr, unsigned char* value);
extern "C" int export_dll_function STDCALL SetAV2000Parameter(int, CAMERA_PARAMETER, long*);
extern "C" int export_dll_function STDCALL GetAV2000Parameter(int, CAMERA_PARAMETER, long*);
extern "C" int export_dll_function STDCALL FactoryDefault(int);
extern "C" int export_dll_function STDCALL Permanently(int);
extern "C" int export_dll_function STDCALL UpdateVersion(int);
extern "C" unsigned long export_dll_function STDCALL Model(int);
extern "C" unsigned long export_dll_function STDCALL Version(int);
extern "C" unsigned long export_dll_function STDCALL Revision(int);
extern "C" unsigned long export_dll_function STDCALL Mini(int);
extern "C" unsigned long export_dll_function STDCALL DayNight(int);
extern "C" void export_dll_function STDCALL SetClientBuffer(int, char*, unsigned long);
extern "C" int export_dll_function STDCALL GetIrisStatus(int);
extern "C" int export_dll_function STDCALL CheckCamera(const char*);
extern "C" int export_dll_function STDCALL SetCustomMode(int number, long* pknee_point, long* pmax_analog_gain, long* pmax_knee_gain, long* pmax_exposure_time, long* pmax_digital_gain);
extern "C" int export_dll_function STDCALL GetCustomMode(int number, long* pknee_point, long* pmax_analog_gain, long* pmax_knee_gain, long* pmax_exposure_time, long* pmax_digital_gain);
extern "C" int export_dll_function STDCALL IsBlackWhite(int number, int* pblack_white);
extern "C" int export_dll_function STDCALL GetMac(AV2000Addr*);
extern "C" const unsigned char* export_dll_function STDCALL GetMotionArray(int number);
extern "C" const unsigned char* export_dll_function STDCALL GetLastPacket(int number);
extern "C" const unsigned char* export_dll_function STDCALL GetLastRequest(int number);
extern "C" int export_dll_function STDCALL GetSockets(int number, void*, unsigned char*);

extern "C" void export_dll_function STDCALL SetAllocateFunction(PTR_Allocate);
extern "C" void export_dll_function STDCALL SetDeallocateFunction(PTR_Deallocate);
extern "C" void export_dll_function STDCALL SetReinitedFunction(PTR_Reinited);

extern "C" void export_dll_function STDCALL DefineOnReceivePacket(PTR_ReceivePacket);
extern "C" void export_dll_function STDCALL DefineOnSendAck(PTR_SendAck);
extern "C" void export_dll_function STDCALL DefineInfoSetRegister(PTR_InfoSetRegister);
extern "C" void export_dll_function STDCALL DefineInfoGetRegister(PTR_InfoGetRegister);

//find cameras and set ip
extern "C" int export_dll_function STDCALL FindCameras(unsigned* number, unsigned timeout);
extern "C" int export_dll_function STDCALL GetCameras(AV2000Addr*, unsigned* psize);
extern "C" int export_dll_function STDCALL SetCameraIp(AV2000Addr*);
extern "C" const ClientError* const export_dll_function STDCALL GetLastSetError();

//Apr 9, 2007 Auxilary IO Functions
//non-overhead AuxIn status reporting, need firmware 64512 or later for non-overhead
extern "C" int export_dll_function STDCALL SetAuxIO(int, int);
extern "C" int export_dll_function STDCALL GetAuxIO(int);

//Nov 12, 2008 Auxilary IO Functions
//non-overhead AuxOut status reporting
//returns -1 if not support by firmware
extern "C" int export_dll_function STDCALL GetAuxOutStatus(int);

//Nov 12, 2008 TimeStamp Functions
//non-overhead timestamp reporting, need firmware 64512 or later
//if success, returns pointer to timestamp[8], big endian
//returns 0 if not support by firmware
extern "C" const unsigned char* export_dll_function STDCALL GetTimeStampBuffer(int number);

//Dec 2, 2008 MAKE Functions
//find camera make string like "AV", "CBC", "BOSCH", "GE", etc
//return NULL string if firmware version older than 64512 or not supported
extern "C" const unsigned char* export_dll_function STDCALL GetCameraMakeBuffer(int number);

//Jul 30, 2007 IR Filter Functions
extern "C" int export_dll_function STDCALL SetIRFilter(int, int);
extern "C" int export_dll_function STDCALL GetIRFilter(int);
extern "C" int export_dll_function STDCALL IrisPresent(int);

//Jul 6, 2008 exif functions
extern "C"  int export_dll_function STDCALL InitializeCopyRightStrings(int, EXIF_STRING_ID, unsigned char*);


//---------------------------------------------------------------------------
#endif
