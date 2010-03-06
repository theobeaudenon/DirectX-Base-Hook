#ifndef INC_INJECTOR
#define INC_INJECTOR

#include <windows.h>
#include <string>
#include <map>
#include <list>

class CInjector {
	typedef std::map<std::wstring,HMODULE> ModuleMap_t;			// Map of all injected modules (by name) in a process

	struct Process_t {											// Structure to describe a process
		HANDLE hProc;			// Process handle
		std::wstring name;		// eg. notepad.exe
		ModuleMap_t modules;	// All injected modules
	};

	typedef std::map<std::wstring,Process_t> ProcessMap_t;		// Map (by name) of processes with injected dll's

	public:
		typedef std::list<std::wstring> ProcessList_t;			// List of all process names

	public:
		CInjector();
		~CInjector();

		int Inject(std::wstring dllPath, std::wstring processName);
		int Unload(std::wstring dllName, std::wstring processName);
		ProcessList_t GetProcessList();


	private:
		int RefreshProcessList();
		HANDLE GetProcessHandleByName(std::wstring processName);
		DWORD GetProcessIdByName(std::wstring processName);

		static ProcessMap_t processes;
		static ProcessList_t processNames;


};

#endif