# Webserv

# *Summary*:
This project is here to make you write your HTTP server. This multiplexing, multi-port, virtual-hosting server is basically running on a single thread, except for cgi handling.

# *Period*:
2021.08. ~ 2021.10

# *CMD*:
> `$> make all && ./webserv`
>
> `$> make debug && ./webserv`


## *Structure*:
![image](https://user-images.githubusercontent.com/3518710/149898433-d3d2b2ed-1d1c-4a70-89c3-6520850e78fd.png)

1. ServerFd ReadEvent 발생 -> `ClientFd 생성`
2. ClientFd ReadEvent 발생 -> `Client에서 Request 파싱`
3. Request(Clinet) -> Server
   1. Read 필요한 `Resource Fd Read Event 등록`, Server(ResourceFd) -> Client -> ServerManager
   2. ResourceFd ReadEvent 발생 -> `Resource를 Server로` 전달
4. `Server에서 Response 생성`
5. Client WriteEvent 발생 -> Client는 Response가 완성되어있는지 확인. -> `send`
6. Stderr WriteEvent 발생 -> stderr에 출력.

## *Goal*:
- [x] GET, POST, DELETE
- [x] multiple ports
- [x] CGI
- [x] multiplexing

## *Code Convention*:
> [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html#The__define_Guard)

## *Reference*:
> [HTTP](https://developer.mozilla.org/ko/docs/Web/HTTP)
> [Poller](http://openlook.org/src/articles/maso0109-kqueue.pdf)

## *Project Contribution*:

- *jolim*
	- ServerManager
		- poller: kqueue
		- multiplexing
	- ConfigParser
		- config parsing
	- TermPrinter

- *seohchoi*
	- Server
		- Request -> Response
		- Resource

- *jinbekim*
	- Client
		- Request parsing
	- CgiConnector
		- CGI
