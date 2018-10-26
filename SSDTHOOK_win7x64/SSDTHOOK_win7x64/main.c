#include <hookssdt.h>


//����ж�غ���
VOID DriverUnload(PDRIVER_OBJECT pDriver)
{
	UnhookSSDT();
	DbgPrint("Driver Unload\n");
}

//������ں���
NTSTATUS DriverEntry(PDRIVER_OBJECT pDriver, PUNICODE_STRING pPath)
{
	DbgPrint("Hello World\n");
	//��ȡKeServiceDescriptorTable
	KeServiceDescriptorTable = (PSYSTEM_SERVICE_TABLE)GetKeServiceDescriptorTable64();
	//����Hook
	HookSSDT();
	pDriver->DriverUnload = DriverUnload;
	return STATUS_SUCCESS;
}