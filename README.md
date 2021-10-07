# quote-of-the-day-server

A very basic TCP server that accepts a single client, that by default returns a random quote parsed in from "wisdom.txt" to the client when the string "QUOTE" is sent to the server.

Built with the class from [tcp-listener](https://github.com/molnar-david/tcp-listener).

## Note:

If using PuTTY, make sure you enable the 'Implicit CR in every LF' option under the 'Terminal' menu, otherwise your received quote won't be formatted properly.

*Made with the help of the [Networking in C++](https://www.youtube.com/playlist?list=PLZo2FfoMkJeEogzRXEJeTb3xpA2RAzwCZ) YouTube series by [Sloan Kelly](https://www.youtube.com/c/sloankelly)*  
*The tutorial series didn't include a lot of error checking, so most of it I had to look up and write myself*
