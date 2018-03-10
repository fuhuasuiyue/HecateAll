#pragma once
#include "hclog_global.h"
#include <string>
#include <sstream>

namespace HCLOG {
	using namespace std;

// 定义log的级别

#undef ERROR

	enum HCLogLevel {
		INFO=0,
		WARNING,
		ERROR
	};
	


	class HCLOG_EXPORT HCLogManager
	{
	public:
		static HCLogManager& getInstance();
		virtual ~HCLogManager();

		void initLog(
			const string& logPath,
			const string& programName,
			const string& logFileName,
			bool logToStdErr = false,
			int stdErrThreshold = 2,
			int logBufferLevel = 0,
			int logBufferSecs = 10,
			int logMinLevel = 0,
			int logMaxSize = 20,
			int logMaxBackupIndex = 5,
			bool stopLoggingIfDiskFull = true
		);
		void uninitLog();
	private:
		HCLogManager();
		HCLogManager(const HCLogManager&);
		HCLogManager& operator=(const HCLogManager&);

	};

	class HCLog;
#define HC_LOG(severity) HC_LOG_##severity.Stream()
#define HC_LOG_INFO (HCLOG::HCLog(__FILE__, __LINE__, HCLOG::HCLogLevel(INFO)))
#define HC_LOG_WARNING (HCLOG::HCLog(__FILE__, __LINE__, HCLOG::HCLogLevel(WARNING)))
#define HC_LOG_ERROR (HCLOG::HCLog(__FILE__, __LINE__, HCLOG::HCLogLevel(ERROR)))

	class HCLOG_EXPORT HCLogStream
	{
	public:
		HCLogStream();
		~HCLogStream();
		HCLogStream& operator<< (bool val);
		HCLogStream& operator<< (short val);
		HCLogStream& operator<< (unsigned short val);
		HCLogStream& operator<< (int val);
		HCLogStream& operator<< (unsigned int val);
		HCLogStream& operator<< (long val);
		HCLogStream& operator<< (unsigned long val);
		HCLogStream& operator<< (long long val);
		HCLogStream& operator<< (unsigned long long val);
		HCLogStream& operator<< (const void* val);
		HCLogStream& operator<< (float val);
		HCLogStream& operator<< (double val);
		HCLogStream& operator<< (char val);
		HCLogStream& operator<< (const char* val);
		HCLogStream& operator<< (const string& val);
		HCLogStream& operator<< (const wchar_t* val);
		HCLogStream& operator<< (const wstring& val);
		HCLogStream& operator<< (streambuf* val);
		const stringstream& getStream() { return _stream; }
	private:
		stringstream _stream;
	};

	class HCLOG_EXPORT HCLog
	{	
	public:
		HCLog(const char* file, int line, HCLogLevel severity);
		~HCLog();

		HCLogStream& Stream() { return m_Stream;}
		static void flush(HCLogLevel level = INFO);


	private:
		string m_fileName;
		int m_Line;
		HCLogLevel m_Severity;
		HCLogStream m_Stream;
	
	};


};// namespase HCLOG
