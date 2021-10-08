# quote-of-the-day-server

A basic TCP server that ~~accepts a single client~~ can now accept multiple clients! Upon joining, you receive a random quote from "wisdom.txt", and you can receive additional pieces of wisdom by sending "QUOTE" to the server.

Implemented using the [Windows Sockets 2](https://docs.microsoft.com/en-us/windows/win32/winsock/windows-sockets-start-page-2) library, with one thread, using the select() function.

Uses a class derived from my [tcp-listener](https://github.com/molnar-david/tcp-listener/) class.

## How to use:
0. If you don't have PuTTY or similar software, you can download PuTTY from [here](https://www.chiark.greenend.org.uk/~sgtatham/putty/), or use my TCP client [here](https://github.com/molnar-david/tcp-client)
1. Compile and run using Visual Studio (I used Visual Studio Community 2019)
2. In PuTTY, set Connection type to Raw, then connect to the server's IP address - or 127.0.0.1 (localhost) if it's running on the same network -, through the specified port (54000 by default)
3. Repeat step 2. as many times as you'd like
4. Type "QUOTE" to get a piece of wisdom
5. You can close down the server anytime you want by sending the '\quit' command. This will disconnect all clients

### Note:

If using PuTTY, make sure you enable the 'Implicit CR in every LF' option under the 'Terminal' menu, otherwise your received quote won't be formatted properly.

*Made with the help of the [Networking in C++](https://www.youtube.com/playlist?list=PLZo2FfoMkJeEogzRXEJeTb3xpA2RAzwCZ) YouTube series by [Sloan Kelly](https://www.youtube.com/c/sloankelly)*  
*The tutorial series didn't include a lot of error checking, so most of it I had to look up and write myself*
