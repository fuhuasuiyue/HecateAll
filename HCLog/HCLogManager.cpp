#include "HCLogManager.h"
#include <glog/logging.h>


namespace HCLOG {
	HCLogManager::HCLogManager()
	{
	}


	HCLogManager::~HCLogManager()
	{
	}

	void HCLogManager::initLog(const string& logPath, const string& programName, 
		const string& logFileName, bool logToStdErr /*= false*/, int stdErrThreshold /*= 2*/, 
		int logBufferLevel /*= 0*/, int logBufferSecs /*= 10*/, int logMinLevel /*= 0*/, 
		int logMaxSize /*= 20*/, int logMaxBackupIndex /*= 5*/, bool stopLoggingIfDiskFull /*= true */)
	{
		static bool isInit = false;
		if (!isInit)
		{
			google::InitGoogleLogging(programName.c_str());
			isInit = true;
		}

		FLAGS_log_dir = logPath;
		FLAGS_logtostderr = logToStdErr;
		FLAGS_stderrthreshold = stdErrThreshold;
		FLAGS_logbuflevel = logBufferLevel;
		FLAGS_logbufsecs = logBufferSecs;
		FLAGS_minloglevel = logMinLevel;
		FLAGS_max_log_size = logMaxSize;
		//FLAGS_max_backup_index = logMaxBackupIndex;
		FLAGS_stop_logging_if_full_disk = stopLoggingIfDiskFull;

		const string dest = FLAGS_log_dir + "//" + logFileName;
		google::SetLogDestination(INFO, dest.c_str());
		google::SetLogDestination(WARNING, "");
		google::SetLogDestination(ERROR, "");

	}

	void HCLogManager::uninitLog()
	{
		google::ShutdownGoogleLogging();
	}

	HCLogManager& HCLogManager::getInstance()
	{
		static HCLogManager logManaer;
		return logManaer;
	}

	HCLogStream::HCLogStream()
	{

	}

	HCLogStream::~HCLogStream()
	{

	}

	HCLogStream & HCLogStream::operator<<(bool val)
	{
		// TODO: 在此处插入 return 语句
		_stream << val;
		return *this;
	}
	HCLogStream & HCLogStream::operator<<(short val)
	{
		// TODO: 在此处插入 return 语句
		_stream << val;
		return *this;
	}
	HCLogStream & HCLogStream::operator<<(unsigned short val)
	{
		// TODO: 在此处插入 return 语句
		_stream << val;
		return *this;
	}
	HCLogStream & HCLogStream::operator<<(int val)
	{
		// TODO: 在此处插入 return 语句
		_stream << val;
		return *this;
	}
	HCLogStream & HCLogStream::operator<<(unsigned int val)
	{
		// TODO: 在此处插入 return 语句
		_stream << val;
		return *this;
	}
	HCLogStream & HCLogStream::operator<<(long val)
	{
		// TODO: 在此处插入 return 语句
		_stream << val;
		return *this;
	}
	HCLogStream & HCLogStream::operator<<(unsigned long val)
	{
		// TODO: 在此处插入 return 语句
		_stream << val;
		return *this;
	}
	HCLogStream & HCLogStream::operator<<(long long val)
	{
		// TODO: 在此处插入 return 语句
		_stream << val;
		return *this;
	}
	HCLogStream & HCLogStream::operator<<(unsigned long long val)
	{
		// TODO: 在此处插入 return 语句
		_stream << val;
		return *this;
	}
	HCLogStream & HCLogStream::operator<<(const void * val)
	{
		// TODO: 在此处插入 return 语句
		_stream << val;
		return *this;
	}
	HCLogStream & HCLogStream::operator<<(float val)
	{
		// TODO: 在此处插入 return 语句
		_stream << val;
		return *this;
	}
	HCLogStream & HCLogStream::operator<<(double val)
	{
		// TODO: 在此处插入 return 语句
		_stream << val;
		return *this;
	}
	HCLogStream & HCLogStream::operator<<(char val)
	{
		// TODO: 在此处插入 return 语句
		_stream << val;
		return *this;
	}
	HCLogStream & HCLogStream::operator<<(const char * val)
	{
		// TODO: 在此处插入 return 语句
		_stream << val;
		return *this;
	}
	HCLogStream & HCLogStream::operator<<(const string & val)
	{
		// TODO: 在此处插入 return 语句
		_stream << val;
		return *this;
	}
	HCLogStream & HCLogStream::operator<<(const wchar_t * val)
	{
		// TODO: 在此处插入 return 语句
		wstring info(val);

		return *this;
	}
	HCLogStream & HCLogStream::operator<<(const wstring & val)
	{
		// TODO: 在此处插入 return 语句
		//_stream << val;
		return *this;
	}
	HCLogStream & HCLogStream::operator<<(streambuf * val)
	{
		// TODO: 在此处插入 return 语句
		_stream << val;
		return *this;
	}

	HCLog::HCLog(const char* file, int line, HCLogLevel severity)
	{
		m_fileName = file;
		m_Line = line;
		m_Severity = severity;

	}


	HCLog::~HCLog()
	{
		int offset = 0;
		int length = 10000;
		string logInfo = m_Stream.getStream().str();
		while (offset < logInfo.length())
		{
			string data = logInfo.substr(offset, length);
				offset += length;
			google::LogMessage(m_fileName.c_str(), m_Line, m_Severity).stream() << data.c_str();
		}

	}


	void HCLog::flush(HCLogLevel level /*= INFO*/)
	{
		google::FlushLogFiles(level);
	}

}
