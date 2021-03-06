#include "Response.hpp"

Response::Response() {}

Response::Response(Status status, std::string http_status_code,
std::map<std::string, std::string> headers, std::string body, std::string version)
:status(status), http_status_code(http_status_code), headers(headers), body(body), version(version) {
	this->head = "";
	this->makeHead();
}

Response::Response(const Response& ref) {
	this->status = ref.status;
	this->http_status_code = ref.http_status_code;
	this->headers = ref.headers;
	this->body = ref.body;
	this->version = ref.version;
	this->head = ref.head;
}

Response::~Response() {}

Response& Response::operator=(const Response& ref) {
	this->status = ref.status;
	this->http_status_code = ref.http_status_code;
	this->headers = ref.headers;
	this->body = ref.body;
	this->version = ref.version;
	this->head = ref.head;
	return *this;
}

// std::string Response::getResponseMessage() {
// 	std::string res;

// 	res = this->version + " " + this->http_status_code + "\r\n";
// 	for (std::map<std::string, std::string>::iterator iter = this->headers.begin();
// 	iter != this->headers.end(); ++iter)
// 		res += iter->first + ": " + iter->second + "\r\n";
// 	res += "\r\n" + this->body;
// 	return (res);
// }

//resource를 읽을때마다 body에 이어붙이기위함
void Response::appendBody(std::string buffer) {
	this->body += buffer;
}

void Response::addHeader(std::string key, std::string value) {
	this->headers[key] = value;
}

Status		Response::getStatus() {
	void*	ptr = this;
	if (ptr == NULL)
		assert(false);
	return this->status;
}

void	Response::setStatus(Status status) {
	this->status = status;
}

std::string& Response::getHead() {
	return this->head;
}

std::string& Response::getBody() {
	return this->body;
}

void	Response::makeHead() {
	if (this->head != "")
		return;
	std::string& str = this->head;
	str = this->version + " " + this->http_status_code + "\r\n";
	for (std::map<std::string, std::string>::iterator iter = this->headers.begin();
	iter != this->headers.end(); ++iter)
		str += iter->first + ": " + iter->second + "\r\n";
	str += "\r\n";
}
