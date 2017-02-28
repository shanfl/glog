#include "glog/logging.h"
bool Init()
{
	google::InitGoogleLogging("");
#ifdef DEBUG_MODE
	google::SetStderrLogging(google::GLOG_INFO); //���ü������ google::INFO ����־ͬʱ�������Ļ
#else
	google::SetStderrLogging(google::GLOG_FATAL);//���ü������ google::FATAL ����־ͬʱ�������Ļ
#endif
	FLAGS_colorlogtostderr = true; //�����������Ļ����־��ʾ��Ӧ��ɫ
	//FLAGS_servitysinglelog = true;// �������յȼ�����log�ļ�
	google::SetLogDestination(google::GLOG_FATAL, "./log/log_fatal_"); // ���� google::FATAL �������־�洢·�����ļ���ǰ׺
	google::SetLogDestination(google::GLOG_ERROR, "./log/log_error_"); //���� google::ERROR �������־�洢·�����ļ���ǰ׺
	google::SetLogDestination(google::GLOG_WARNING, "./log/log_warning_"); //���� google::WARNING �������־�洢·�����ļ���ǰ׺
	google::SetLogDestination(google::GLOG_INFO, "./log_info_"); //���� google::INFO �������־�洢·�����ļ���ǰ׺
	FLAGS_logbufsecs = 0; //������־�����Ĭ��Ϊ30�룬�˴���Ϊ�������
	FLAGS_max_log_size = 100; //�����־��СΪ 100MB
	FLAGS_stop_logging_if_full_disk = true; //�����̱�д��ʱ��ֹͣ��־���
	//google::SetLogFilenameExtension("91_"); //�����ļ�����չ����ƽ̨����������Ҫ���ֵ���Ϣ
	//google::InstallFailureSignalHandler(); //��׽ core dumped (linux)
	//google::InstallFailureWriter(&Log); //Ĭ�ϲ�׽ SIGSEGV �ź���Ϣ���������� stderr (linux)

	return true;
}

int main()
{
	Init();
	LOG(INFO) << "This is a <Warn> log message..." <<std::endl ;
}
