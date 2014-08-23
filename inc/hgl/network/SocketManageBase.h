﻿#ifndef HGL_NETWORK_SOCKER_MANAGE_BASE_INCLUDE
#define HGL_NETWORK_SOCKER_MANAGE_BASE_INCLUDE

#include<hgl/type/List.h>
#include<hgl/network/SocketEvent.h>
namespace hgl
{
	namespace network
	{
		/**
		 * Socket管理线程
		 */
		class SocketManageBase
		{
		public:

			virtual ~SocketManageBase()HGL_DEFAULT_MEMFUNC;

			virtual bool Join(int)=0;																///<加入一个Socket
			virtual bool Join(int *,int)=0;                                                         ///<加入一批Socket
			virtual bool Unjoin(int)=0;																///<分离一个Socket

			virtual int GetCount()const=0;															///<取得Socket数量
			virtual void Clear()=0;																	///<清除所有Socket

			virtual int	Update(List<SocketEvent> &sock_list,										///<刷新并取得所有需要处理的IOSocket
							   List<SocketEvent> &error_list,
								const double time_out)=0;

			virtual int	Update(List<SocketEvent> &recv_list,										///<刷新并取得所有需要处理的IOSocket
							   List<SocketEvent> &send_list,
							   List<SocketEvent> &error_list,
								const double time_out)=0;
		};//class SocketManageBase

		SocketManageBase *CreateRecvSocketManage(int max_user);										///<创建一个只处理读取的Socket管理器
		SocketManageBase *CreateSendSocketManage(int max_user);										///<创建一个只处理发送的Socket管理器
		SocketManageBase *CreateSocketManage(int max_user);											///<创建一个读写均处理的Socket管理器
	}//namespace network
}//namespace hgl
#endif//HGL_NETWORK_SOCKER_MANAGE_BASE_INCLUDE
