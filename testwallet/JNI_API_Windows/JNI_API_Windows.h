// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the JNI_API_WINDOWS_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// JNI_API_WINDOWS_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef JNI_API_WINDOWS_EXPORTS
#define JNI_API_WINDOWS_API __declspec(dllexport)
#else
#define JNI_API_WINDOWS_API __declspec(dllimport)
#endif

// This class is exported from the JNI_API_Windows.dll
class JNI_API_WINDOWS_API CJNI_API_Windows {
public:
	CJNI_API_Windows(void);
	// TODO: add your methods here.
};

extern JNI_API_WINDOWS_API int nJNI_API_Windows;

JNI_API_WINDOWS_API int fnJNI_API_Windows(void);
