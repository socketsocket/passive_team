#ifndef WEBSERV_RESPONSE_HPP
#define WEBSERV_RESPONSE_HPP

#include "Webserv.hpp"
#include <string>
#include <iostream>
#include <map>

class Response {
	private:
		//response를 쓰고있는 상태
		Status								status;
		//예시:200 OK
		std::string							http_status_code;
		std::map<std::string, std::string>	headers;
		std::string							body;
		std::string							version;
		std::string							head;

	public:
		Response();
		Response(Status status);
		Response(
			Status status,
			std::string http_status_code,
			std::map<std::string, std::string> headers,
			std::string body,
			std::string version);
		Response(const Response& ref);
		~Response();
		Response& operator=(const Response& ref);

		Status			getStatus();
		std::string&	getBody();
		std::string&	getHead();

		// std::string getResponseMessage();
		void	setStatus(Status);
		void	appendBody(std::string buffer);
		void	addHeader(std::string key, std::string value);
		void	makeHead();
};

#endif
