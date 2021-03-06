#include "Request.hpp"

Request::Request()
	: status(kNothing), \
	method(0), \
	uri(""), \
	version(""), \
	body("") {}

Request::~Request() {
}

void	Request::setStatus(Status status) {
	this->status = status;
}

void	Request::setMethod(Method method) {
	this->method = method;
}

void	Request::setUri(std::string& uri) {
	this->uri = uri;
}

void	Request::setVersion(std::string& version) {
	this->version = version;
}

void	Request::insertHeader(std::string& key, std::string& value) {
	this->headers.insert(std::make_pair(key, value));
	// 회의 필요.
}

void	Request::appendBody(std::string& buffer) {
	this->body += buffer;
}

const Status&			Request::getStatus() const {
	return this->status;
}

const Method&				Request::getMethod() const {
	return this->method;
}

const std::string&		Request::getUri() const {
	return this->uri;
}

const std::string&		Request::getVersion() const {
	return this->version;
}

std::string				Request::getHeaderValue(const std::string& key) const {
	if (this->headers.count(key))
		return this->headers.find(key)->second;
	return "";
}

const std::string&		Request::getBody() const {
	return this->body;
}
void	Request::setQuery(std::string& query) {
	this->query_string = query;
}

const std::string&	Request::getQuery() const {
	return this->query_string;
}
