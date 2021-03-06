﻿#include "stdafx.h"
#include "httpserver.h"
#include "httphandler.h"
#include "net/tcpclient.h"
namespace Bear {
namespace Core {
namespace Net {
namespace Http {

HttpServer::HttpServer()
{
	SetObjectName("HttpServer");
	//DV("%s", __func__);
}

HttpServer::~HttpServer()
{
	//DV("%s", __func__);
}

std::shared_ptr<Channel> HttpServer::CreateChannel()
{
	//DV("%s",__func__);

	auto client(make_shared<Net::TcpClient>());
	client->SignalOnConnect.connect(this, &HttpServer::OnConnect);
	return client;
}

void HttpServer::OnConnect(Channel* endPoint, long error, ByteBuffer* pBox, Bundle*extraInfo)
{
	//DV("%s", __func__);

	TcpClient* client = (TcpClient*)endPoint;
	client->SignalOnConnect.disconnect(this);

	shared_ptr<HttpHandler> handler(make_shared<HttpHandler>());
	handler->mChannel = dynamic_pointer_cast<TcpClient>(client->shared_from_this());
	handler->SetConfig(mWebConfig);

	client->SignalOnSend.connect(handler.get(), &HttpHandler::OnSend);
	client->SignalOnReceive.connect(handler.get(), &HttpHandler::OnReceive);
	client->SignalOnClose.connect(handler.get(), &HttpHandler::OnClose);

	AddChild(handler);
	handler->OnConnect(endPoint, error, extraInfo);
}

}
}
}
}