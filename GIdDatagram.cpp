//---------------------------------------------------------------------------
#pragma hdrstop
//---------------------------------------------------------------------------
#include "GIdDatagram.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
void GIdDatagram::CreateSock()
{
	if(INVALID_SOCKET == (sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)))
		GenerateException((char*)"Allocating socket failed!");
}
//---------------------------------------------------------------------------
GIdDatagram::GIdDatagram()
{
   CreateSock();
}
//---------------------------------------------------------------------------


