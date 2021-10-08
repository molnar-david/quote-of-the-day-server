# quote-of-the-day-server

A very basic TCP server that accepts a single client, that by default returns a random quote parsed in from "wisdom.txt" to the client when the string "QUOTE" is sent to the server, implemented using [Windows Sockets 2](https://docs.microsoft.com/en-us/windows/win32/winsock/windows-sockets-start-page-2).

Built with the class from [tcp-listener](https://github.com/molnar-david/tcp-listener).

## How to use:
0. If you don't have PuTTY or similar software, you can download PuTTY from [here](https://www.chiark.greenend.org.uk/~sgtatham/putty/), or use my TCP client [here](https://github.com/molnar-david/tcp-client)
1. Compile and run using Visual Studio (I used Visual Studio Community 2019)
2. In PuTTY, set Connection type to Raw, then connect to the server's IP address - or 127.0.0.1 (localhost) if hosted on the same network -, through the specified port (54000 by default)
3. Send "QUOTE" to the server to get your random quote from "wisdom.txt

### Note:

If using PuTTY, make sure you enable the 'Implicit CR in every LF' option under the 'Terminal' menu, otherwise your received quote won't be formatted properly.

*Made with the help of the [Networking in C++](https://www.youtube.com/playlist?list=PLZo2FfoMkJeEogzRXEJeTb3xpA2RAzwCZ) YouTube series by [Sloan Kelly](https://www.youtube.com/c/sloankelly)*  
*The tutorial series didn't include a lot of error checking, so most of it I had to look up and write myself*
