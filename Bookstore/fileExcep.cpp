#ifndef __FILE__EXCEPTION__CPP__
#define __FILE__EXCEPTION__CPP__

FileOpen_Error::FileOpen_Error(const std::string what_arg) : m_s_message(what_arg){

}

inline std::string FileOpen_Error::what(){
	return m_s_message;
}

#endif // __FILE__EXCEPTION__CPP__
